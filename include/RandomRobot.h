#ifndef RANDOM_ROBOT_H
#define RANDOM_ROBOT_H

#include "Robot.h"
#include <random>

/**
 * @brief A maze-solving robot that moves in random directions.
 */
class RandomRobot : public Robot {
private:
    std::mt19937 rng; ///< Member RNG to avoid reseeding on every call

    /** @brief Generates a random Direction (1-8). */
    Direction randomDirection();

public:
    RandomRobot();

    /** @brief Moves randomly until the exit is reached. */
    void move(Maze& m) override;
};

#endif