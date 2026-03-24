#ifndef MAZE_H
#define MAZE_H

#include <iostream>
#include <fstream>
#include <array>
#include <string>
#include <stdexcept>

/// Defines the fixed size of the maze grid (9x9).
constexpr size_t MAZE_SIZE = 9;

/**
 * @brief Strongly typed directions for inquiring cell neighbors.
 * Clockwise starting from NorthWest = 1 to map to original logic.
 */
enum class Direction {
    NorthWest = 1,
    North = 2,
    NorthEast = 3,
    East = 4,
    SouthEast = 5,
    South = 6,
    SouthWest = 7,
    West = 8
};

/**
 * @brief Represents a character-based maze.
 *
 * The maze is loaded from a text file where:
 *   '*' = wall
 *   ' ' = open path
 *   'S' = start position
 *   'E' = exit position
 */
class Maze {
private:
    int x_pos{0};
    int y_pos{0};
    std::array<std::array<char, MAZE_SIZE>, MAZE_SIZE> matrix{};

    void checkBorders() const;
    void checkStartAndExit() const;
    void checkPosition() const;

public:
    /**
     * @brief Constructs a Maze by reading a grid from a text file.
     * @param file_name Path to the maze definition file.
     */
    explicit Maze(const std::string& file_name);

    int getXpos() const;
    int getYpos() const;
    void printPosition() const;
    void printMaze() const;
    void animateStep() const;
    
    char getChar() const;
    char getCharAround(Direction dir) const;

    void moveUp();
    void moveDown();
    void moveLeft();
    void moveRight();
    void moveNorthWest();
    void moveNorthEast();
    void moveSouthWest();
    void moveSouthEast();
};

#endif