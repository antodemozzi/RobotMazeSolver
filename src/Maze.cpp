#include "Maze.h"
#include <cstdlib>

#ifdef _WIN32
#include <windows.h>
#else
#include <unistd.h>
#endif

Maze::Maze(const std::string& file_name) {
    std::ifstream my_maze(file_name);
    if (!my_maze.is_open()) {
        throw std::runtime_error("Failed to open maze file: " + file_name);
    }

    for (size_t row = 0; row < MAZE_SIZE; ++row) {
        for (size_t col = 0; col < MAZE_SIZE; ++col) {
            matrix[row][col] = static_cast<char>(my_maze.get());

            if (matrix[row][col] == 'S') {
                x_pos = static_cast<int>(col);
                y_pos = static_cast<int>(row);
            }
        }
        // Consume the trailing newline character at end of each row.
        my_maze.get();
    }

    checkBorders();
    checkStartAndExit();
}

int Maze::getXpos() const { return x_pos; }
int Maze::getYpos() const { return y_pos; }

void Maze::checkBorders() const {
    bool allGood = true;
    for (size_t row = 0; row < MAZE_SIZE; ++row) {
        if (row == 0 || row == MAZE_SIZE - 1) {
            for (size_t col = 0; col < MAZE_SIZE; ++col) {
                if (matrix[row][col] != '*' && matrix[row][col] != 'S' && matrix[row][col] != 'E') {
                    allGood = false;
                }
            }
        } else {
            if (matrix[row][0] != '*' && matrix[row][0] != 'S' && matrix[row][0] != 'E') {
                allGood = false;
            }
            if (matrix[row][MAZE_SIZE - 1] != '*' && matrix[row][MAZE_SIZE - 1] != 'S' && matrix[row][MAZE_SIZE - 1] != 'E') {
                allGood = false;
            }
        }
    }
    if (!allGood) {
        throw std::invalid_argument("borders are not closed");
    }
}

char Maze::getChar() const {
    return matrix[y_pos][x_pos];
}

void Maze::checkPosition() const {
    if (x_pos >= static_cast<int>(MAZE_SIZE) || y_pos >= static_cast<int>(MAZE_SIZE) || x_pos < 0 || y_pos < 0) {
        throw std::invalid_argument("position out of bounds");
    }
}

void Maze::checkStartAndExit() const {
    int startCount = 0;
    int exitCount = 0;

    for (size_t i = 0; i < MAZE_SIZE; ++i) {
        for (size_t j = 0; j < MAZE_SIZE; ++j) {
            if (matrix[i][j] == 'E') exitCount++;
            if (matrix[i][j] == 'S') startCount++;
        }
    }

    if (startCount != 1) {
        throw std::invalid_argument("invalid start: exactly one 'S' required");
    }
    if (exitCount == 0) {
        throw std::invalid_argument("invalid maze: at least one 'E' (exit) required");
    }
}

void Maze::printPosition() const {
    std::cout << "position: x=" << x_pos << " y=" << y_pos << "\n";
}

void Maze::printMaze() const {
    // Clear the console for animation effect
#ifdef _WIN32
    std::system("cls");
#else
    std::system("clear");
#endif

    for (size_t i = 0; i < MAZE_SIZE; ++i) {
        for (size_t j = 0; j < MAZE_SIZE; ++j) {
            if (static_cast<int>(j) == x_pos && static_cast<int>(i) == y_pos) {
                // Highlight robot in bold green
                std::cout << "\033[1;32mR\033[0m";
            } else if (matrix[i][j] == '*') {
                // Walls in blue
                std::cout << "\033[1;34m*\033[0m";
            } else if (matrix[i][j] == 'S' || matrix[i][j] == 'E') {
                // Start/Exit in yellow
                std::cout << "\033[1;33m" << matrix[i][j] << "\033[0m";
            } else {
                std::cout << matrix[i][j];
            }
        }
        std::cout << '\n';
    }
    std::cout << std::flush;
}

void Maze::animateStep() const {
    printMaze();
#ifdef _WIN32
    Sleep(100);
#else
    usleep(100000); // 100ms
#endif
}

void Maze::moveUp() {
    if (matrix[y_pos - 1][x_pos] != '*' && matrix[y_pos - 1][x_pos] != 'S') {
        --y_pos;
    }
    checkPosition();
    animateStep();
}

void Maze::moveDown() {
    if (matrix[y_pos + 1][x_pos] != '*' && matrix[y_pos + 1][x_pos] != 'S') {
        ++y_pos;
    }
    checkPosition();
    animateStep();
}

void Maze::moveLeft() {
    if (matrix[y_pos][x_pos - 1] != '*' && matrix[y_pos][x_pos - 1] != 'S') {
        --x_pos;
    }
    checkPosition();
    animateStep();
}

void Maze::moveRight() {
    if (matrix[y_pos][x_pos + 1] != '*' && matrix[y_pos][x_pos + 1] != 'S') {
        ++x_pos;
    }
    checkPosition();
    animateStep();
}

void Maze::moveNorthWest() {
    if (matrix[y_pos - 1][x_pos - 1] != '*' && matrix[y_pos - 1][x_pos - 1] != 'S') {
        --y_pos; --x_pos;
    }
    checkPosition();
    animateStep();
}

void Maze::moveNorthEast() {
    if (matrix[y_pos - 1][x_pos + 1] != '*' && matrix[y_pos - 1][x_pos + 1] != 'S') {
        --y_pos; ++x_pos;
    }
    checkPosition();
    animateStep();
}

void Maze::moveSouthWest() {
    if (matrix[y_pos + 1][x_pos - 1] != '*' && matrix[y_pos + 1][x_pos - 1] != 'S') {
        ++y_pos; --x_pos;
    }
    checkPosition();
    animateStep();
}

void Maze::moveSouthEast() {
    if (matrix[y_pos + 1][x_pos + 1] != '*' && matrix[y_pos + 1][x_pos + 1] != 'S') {
        ++y_pos; ++x_pos;
    }
    checkPosition();
    animateStep();
}

char Maze::getCharAround(Direction dir) const {
    switch (dir) {
        case Direction::NorthWest: return matrix[y_pos - 1][x_pos - 1];
        case Direction::North:     return matrix[y_pos - 1][x_pos];
        case Direction::NorthEast: return matrix[y_pos - 1][x_pos + 1];
        case Direction::East:      return matrix[y_pos][x_pos + 1];
        case Direction::SouthEast: return matrix[y_pos + 1][x_pos + 1];
        case Direction::South:     return matrix[y_pos + 1][x_pos];
        case Direction::SouthWest: return matrix[y_pos + 1][x_pos - 1];
        case Direction::West:      return matrix[y_pos][x_pos - 1];
    }
    // Fallback for completeness, though enum guards against this
    return 'a';
}
