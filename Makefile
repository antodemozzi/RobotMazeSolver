# Compiler and flags
CXX = g++
CXXFLAGS = -Wall -Wextra -std=c++17 -Iinclude

# Directories
SRC_DIR = src
INC_DIR = include
BUILD_DIR = build
DATA_DIR = data

# Output binary name
TARGET = maze_solver

# Find all source files in the src directory
SRCS = $(wildcard $(SRC_DIR)/*.cpp)

# Map source files to object files in the build directory
OBJS = $(patsubst $(SRC_DIR)/%.cpp,$(BUILD_DIR)/%.o,$(SRCS))

# Default target
all: dirs $(TARGET)

# Create build directory if it doesn't exist
dirs:
	@if not exist "$(BUILD_DIR)" mkdir "$(BUILD_DIR)"

# Link object files into the final executable
$(TARGET): $(OBJS)
	$(CXX) $(CXXFLAGS) -o $(TARGET) $(OBJS)

# Compile each .cpp into a .o. Depends on header files as well.
$(BUILD_DIR)/%.o: $(SRC_DIR)/%.cpp
	$(CXX) $(CXXFLAGS) -c $< -o $@

# Run the program
run: all
	./$(TARGET)

# Remove build artifacts
clean:
	@if exist "$(BUILD_DIR)" rmdir /s /q "$(BUILD_DIR)"
	@if exist "$(TARGET).exe" del /q "$(TARGET).exe"
	@if exist "$(TARGET)" del /q "$(TARGET)"

.PHONY: all clean run dirs
