#ifndef RIGHT_HAND_RULE_ROBOT_H
#define RIGHT_HAND_RULE_ROBOT_H

#include "Robot.h"

/**
 * @brief A maze-solving robot that uses the right-hand rule algorithm.
 */
class RightHandRuleRobot : public Robot {
private:
    bool isExitNear(const Maze& m) const;
    void goToExit(Maze& m);

    void goUp(Maze& m);
    void goLeft(Maze& m);
    void goRight(Maze& m);
    void goDown(Maze& m);

    void startRight(Maze& m);

public:
    RightHandRuleRobot() = default;

    /** @brief Solves the maze using the right-hand rule. */
    void move(Maze& m) override;
};

#endif