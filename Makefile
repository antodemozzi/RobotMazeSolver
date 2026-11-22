# Compiler and flags
CXX ?= g++
CPPFLAGS += -Iinclude
CXXFLAGS += -Wall -Wextra -std=c++17
DEPFLAGS = -MMD -MP

# Directories
SRC_DIR = src
INC_DIR = include
BUILD_DIR = build
DATA_DIR = data

# Output binary name
TARGET := maze_solver

# Find all source files in the src directory
SRCS := $(wildcard $(SRC_DIR)/*.cpp)

# Map source files to object files in the build directory
OBJS := $(patsubst $(SRC_DIR)/%.cpp,$(BUILD_DIR)/%.o,$(SRCS))
DEPS := $(OBJS:.o=.d)

# Default target
all: $(TARGET)

# Create build directory if it doesn't exist
$(BUILD_DIR):
	mkdir -p $(BUILD_DIR)

# Link object files into the final executable
$(TARGET): $(OBJS)
	$(CXX) $(CXXFLAGS) $(LDFLAGS) -o $(TARGET) $(OBJS) $(LDLIBS)

# Compile each .cpp into a .o. Depends on header files as well.
$(BUILD_DIR)/%.o: $(SRC_DIR)/%.cpp | $(BUILD_DIR)
	$(CXX) $(CPPFLAGS) $(CXXFLAGS) $(DEPFLAGS) -c $< -o $@

-include $(DEPS)

# Run the program
run: all
	./$(TARGET)

# Remove build artifacts
clean:
	rm -rf $(BUILD_DIR)
	rm -f $(TARGET) $(TARGET).exe

.PHONY: all clean run
