#include "Maze.h"
#include "RandomRobot.h"
#include "RightHandRuleRobot.h"

#ifdef _WIN32
#include <windows.h>
#ifndef ENABLE_VIRTUAL_TERMINAL_PROCESSING
#define ENABLE_VIRTUAL_TERMINAL_PROCESSING 0x0004
#endif
#endif

/**
 * @brief Entry point — demonstrates two maze-solving strategies.
 *
 * Loads the same maze twice and solves it using:
 *   1. RandomRobot    — random walk until the exit is found.
 *   2. RightHandRuleRobot — deterministic right-hand rule algorithm.
 */
int main() {
#ifdef _WIN32
    // Enable Virtual Terminal Processing for ANSI escape codes on Windows CMD
    HANDLE hOut = GetStdHandle(STD_OUTPUT_HANDLE);
    DWORD dwMode = 0;
    GetConsoleMode(hOut, &dwMode);
    dwMode |= ENABLE_VIRTUAL_TERMINAL_PROCESSING;
    SetConsoleMode(hOut, dwMode);
#endif

    // Note that the path is relative to where the binary is executed (root of project)
    std::string file = "data/maze.txt";

    try {
        // --- Random Robot ---
        std::cout << "=== Random Robot ===" << std::endl;
        Maze lab(file);
        lab.printPosition();
        RandomRobot randomBot;
        randomBot.move(lab);

        std::cout << std::endl;

        // --- Right-Hand Rule Robot ---
        std::cout << "=== Right-Hand Rule Robot ===" << std::endl;
        Maze room(file);
        room.printPosition();
        RightHandRuleRobot wallFollower;
        wallFollower.move(room);

    } catch (const std::exception& e) {
        std::cerr << "Error: " << e.what() << std::endl;
        return 1;
    }

    return 0;
}
