# C++ Object-Oriented Maze Solver 🤖🏁

[![C++17](https://img.shields.io/badge/C++-17-blue.svg)](https://isocpp.org/)
[![Build Status](https://github.com/tuo-nome-utente/nome-della-repo/actions/workflows/build.yml/badge.svg)](https://github.com/tuo-nome-utente/nome-della-repo/actions)
[![License: MIT](https://img.shields.io/badge/License-MIT-yellow.svg)](https://opensource.org/licenses/MIT)

A modern, robust, and highly visual C++ application that simulates a robot autonomously navigating a maze. 

It demonstrates clean architecture, **Object-Oriented Programming (OOP)**, **polymorphism**, and includes a real-time **ANSI-colored console animation** of the robot searching for the exit.

*(Add a GIF here of the terminal animation!)*

---

## 🏗️ Architecture & OOP Principles

This project is built to demonstrate production-ready C++ practices:

- **Inheritance & Polymorphism**: A pure abstract `Robot` base class defines a strictly enforced `move()` contract. Derived classes (`RandomRobot`, `RightHandRuleRobot`) implement completely different decision trees while being treated uniformly by the caller.
- **Virtual Destructors**: The base class ensures safe polymorphic deletion via `virtual ~Robot() = default;`.
- **Strongly-typed Enums**: Directions are strictly scoped using `enum class Direction` instead of ambiguous raw integers, eliminating whole classes of logic bugs.
- **Modern PRNG**: Replaced unsafe legacy random functions with `<random>`'s `std::mt19937` (Mersenne Twister engine), seeded securely via `std::random_device`, instantiated efficiently as a class member.
- **Const Correctness & Encapsulation**: Method mutations are strictly locked down. The `Maze` acts as the single source of truth for map bounds (`constexpr`).

## 🗺️ Strategies

| Strategy | Engine Class | Algorithm Description |
|---|---|---|
| **Random Walk** | `RandomRobot` | Picks a valid neighboring cell at random. Brute-force simulation. |
| **Right-Hand Rule** | `RightHandRuleRobot` | A classic maze-solving heuristic. It keeps its "right hand" touching the wall at all times, guaranteeing an exit in standard contiguous mazes. |

## 🚀 Building the Project

This repository supports both standard `Make` and modern `CMake` build pipelines.

### Option A: CMake (Industry Standard)
```bash
# Generate build files
cmake -B build

# Compile the project
cmake --build build

# Run the executable
./build/maze_solver
```

### Option B: Make (Simple)
```bash
make
./maze_solver
```

## 🎥 Visual WOW Factor: ANSI Animations
Forget hunting raw coordinates in a log file. 
This solver utilizes **Virtual Terminal Processing** (compatible out-of-the-box with Unix and modern Windows CMD) to draw the maze using standard **ANSI color codes**.
- 🟦 **Walls (`*`)** are rendered in solid blue blocks.
- 🟨 **Endpoints (`S`, `E`)** are highlighted in yellow.
- 🟩 **Robot (`R`)** pulses in bold green as it traverses the map in real-time.

## 🛠️ Modifying the Maze
You can test the robots on your own layout by modifying `/data/maze.txt`.
Ensure your maze is a 9x9 grid, securely enclosed by walls (`*`), containing exactly one Start (`S`) and at least one Exit (`E`).
