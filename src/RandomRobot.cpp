#include "RandomRobot.h"

RandomRobot::RandomRobot() : rng(std::random_device{}()) {}

void RandomRobot::move(Maze& m) {
    while (m.getChar() != 'E') {
        Direction dir = randomDirection();

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
    }

    std::cout << "exit found! ";
    m.printPosition();
}

Direction RandomRobot::randomDirection() {
    // Generate uniform distribution between 1 and 8
    std::uniform_int_distribution<int> dist(1, 8);
    return static_cast<Direction>(dist(rng));
}