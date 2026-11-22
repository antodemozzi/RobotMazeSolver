cmake_minimum_required(VERSION 3.10)
project(MazeSolver CXX)

set(SOURCES
    src/main.cpp
    src/Maze.cpp
    src/RightHandRuleRobot.cpp
    src/RandomRobot.cpp
)

add_executable(maze_solver ${SOURCES})

target_include_directories(maze_solver PRIVATE include)
target_compile_features(maze_solver PRIVATE cxx_std_17)

if(MSVC)
    target_compile_options(maze_solver PRIVATE /W4)
else()
    target_compile_options(maze_solver PRIVATE -Wall -Wextra)
endif()

file(COPY "${CMAKE_CURRENT_SOURCE_DIR}/data"
     DESTINATION "${CMAKE_CURRENT_BINARY_DIR}")
