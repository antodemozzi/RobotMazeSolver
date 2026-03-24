#ifndef ROBOT_H
#define ROBOT_H

#include "Maze.h"

/**
 * @brief Abstract base class for maze-solving robots.
 *
 * Subclasses must override the move() method to implement
 * a specific maze-solving strategy.
 */
class Robot {
public:
    /** 
     * @brief Virtual destructor is mandatory for classes with virtual methods 
     * to ensure proper cleanup of derived objects through base pointers.
     */
    virtual ~Robot() = default;

    /**
     * @brief Attempts to navigate the robot through the maze to the exit.
     * @param m Reference to the Maze the robot operates in.
     */
    virtual void move(Maze& m) = 0;
};

#endif