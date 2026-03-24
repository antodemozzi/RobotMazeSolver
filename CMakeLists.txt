cmake_minimum_required(VERSION 3.10)
project(MazeSolver CXX)

# Require C++17 standard
set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED True)
set(CMAKE_CXX_EXTENSIONS OFF)

# Treat warnings as errors for a clean professional codebase
set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -Wall -Wextra")

# Define the source files
set(SOURCES
    src/main.cpp
    src/Maze.cpp
    src/RightHandRuleRobot.cpp
    src/RandomRobot.cpp
)

# Create the executable
add_executable(maze_solver ${SOURCES})

# Specify include directories
target_include_directories(maze_solver PRIVATE include)
