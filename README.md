# Maze Solver — Professional C++ OOP Project

A modern C++17 maze-solving project that demonstrates **object-oriented programming** and **polymorphism**. A robot navigates a 9×9 text-based maze using one of two interchangeable strategies.

| Strategy | Class | Description |
|---|---|---|
| **Random Walk** | `RandomRobot` | Picks a random direction each step until it stumbles upon the exit. Uses `std::mt19937` for uniform PRNG. |
| **Right-Hand Rule** | `RightHandRuleRobot` | Follows the wall with its right hand — a classic deterministic algorithm. |

## Project Structure

```
.
├── Makefile               # Build system
├── README.md              # Project documentation
├── .gitignore             # Git ignore file
├── include/               # Header files (.h)
│   ├── Maze.h
│   ├── Robot.h            # Abstract base class
│   ├── RandomRobot.h
│   └── RightHandRuleRobot.h
├── src/                   # Source files (.cpp)
│   ├── Maze.cpp
│   ├── RandomRobot.cpp
│   ├── RightHandRuleRobot.cpp
│   └── main.cpp           # Entry point
└── data/                  # Assets
    └── maze.txt           # Maze layout
```

## Maze Format

The maze is defined in a plain text file (`data/maze.txt`) as a 9×9 character grid:
- `*` : Wall
- ` ` : Open path
- `S` : Start position
- `E` : Exit

## Build & Run

### Using Make
To compile the project and place object files in a `build/` directory out of sight:
```bash
make
```

To run the compiled binary:
```bash
make run
# or simply
./maze_solver
```

To clean the build folder and binary:
```bash
make clean
```

## Example Output

```
=== Random Robot ===
position: x=4 y=7
exit found! position: x=0 y=6

=== Right-Hand Rule Robot ===
position: x=4 y=7
exit found! position: x=0 y=6
```
