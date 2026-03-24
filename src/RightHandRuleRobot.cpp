#include "RightHandRuleRobot.h"

bool RightHandRuleRobot::isExitNear(const Maze& m) const {
    // Check all 8 directions for an exit
    for (int i = 1; i <= 8; i++) {
        if (m.getCharAround(static_cast<Direction>(i)) == 'E') {
            return true;
        }
    }
    return false;
}

void RightHandRuleRobot::goToExit(Maze& m) {
    for (int i = 1; i <= 8; i++) {
        Direction dir = static_cast<Direction>(i);
        if (m.getCharAround(dir) == 'E') {
            std::cout << "exit found! ";

            switch (dir) {
                case Direction::NorthWest: m.moveNorthWest(); break;
                case Direction::North:     m.moveUp(); break;
                case Direction::NorthEast: m.moveNorthEast(); break;
                case Direction::East:      m.moveRight(); break;
                case Direction::SouthEast: m.moveSouthEast(); break;
                case Direction::South:     m.moveDown(); break;
                case Direction::SouthWest: m.moveSouthWest(); break;
                case Direction::West:      m.moveLeft(); break;
            }

            m.printPosition();
            return;
        }
    }
}

void RightHandRuleRobot::goUp(Maze& m) {
    while (m.getCharAround(Direction::East) == '*' && m.getCharAround(Direction::North) != '*') {
        if (isExitNear(m)) { goToExit(m); return; }
        m.moveUp();
    }

    if (m.getCharAround(Direction::East) == '*' && m.getCharAround(Direction::North) == '*' && m.getCharAround(Direction::West) != '*') {
        goLeft(m);
    } else if (m.getCharAround(Direction::SouthEast) == '*' && m.getCharAround(Direction::East) != '*') {
        m.moveRight();
        goRight(m);
    } else if (m.getCharAround(Direction::West) == '*' && m.getCharAround(Direction::North) == '*' && m.getCharAround(Direction::East) == '*') {
        goDown(m);
    }
}

void RightHandRuleRobot::goRight(Maze& m) {
    while (m.getCharAround(Direction::South) == '*' && m.getCharAround(Direction::East) != '*') {
        if (isExitNear(m)) { goToExit(m); return; }
        m.moveRight();
    }

    if (m.getCharAround(Direction::SouthWest) == '*' && m.getCharAround(Direction::South) != '*') {
        m.moveDown();
        goDown(m);
    } else if (m.getCharAround(Direction::South) == '*' && m.getCharAround(Direction::East) == '*' && m.getCharAround(Direction::North) != '*') {
        goUp(m);
    } else if (m.getCharAround(Direction::South) == '*' && m.getCharAround(Direction::East) == '*' && m.getCharAround(Direction::North) == '*') {
        goLeft(m);
    }
}

void RightHandRuleRobot::goLeft(Maze& m) {
    while (m.getCharAround(Direction::North) == '*' && m.getCharAround(Direction::West) != '*') {
        if (isExitNear(m)) { goToExit(m); return; }
        m.moveLeft();
    }

    if (m.getCharAround(Direction::North) == '*' && m.getCharAround(Direction::West) == '*' && m.getCharAround(Direction::South) != '*') {
        goDown(m);
    } else if (m.getCharAround(Direction::North) != '*' && m.getCharAround(Direction::NorthEast) == '*') {
        m.moveUp();
        goUp(m);
    } else if (m.getCharAround(Direction::South) == '*' && m.getCharAround(Direction::West) == '*' && m.getCharAround(Direction::North) == '*') {
        goRight(m);
    }
}

void RightHandRuleRobot::goDown(Maze& m) {
    while (m.getCharAround(Direction::West) == '*' && m.getCharAround(Direction::South) != '*') {
        if (isExitNear(m)) { goToExit(m); return; }
        m.moveDown();
    }

    if (m.getCharAround(Direction::West) == '*' && m.getCharAround(Direction::South) == '*' && m.getCharAround(Direction::East) != '*') {
        goRight(m);
    } else if (m.getCharAround(Direction::West) != '*' && m.getCharAround(Direction::NorthWest) == '*') {
        m.moveLeft();
        goLeft(m);
    } else if (m.getCharAround(Direction::East) == '*' && m.getCharAround(Direction::South) == '*' && m.getCharAround(Direction::West) == '*') {
        goUp(m);
    }
}

void RightHandRuleRobot::startRight(Maze& m) {
    bool rightClear = true;
    while (rightClear) {
        if (m.getCharAround(Direction::East) == '*' || m.getCharAround(Direction::East) == 'E') {
            rightClear = false;
        } else {
            m.moveRight();
        }
    }
}

void RightHandRuleRobot::move(Maze& m) {
    startRight(m);

    if (isExitNear(m)) {
        goToExit(m);
        return;
    }
    goUp(m);
}