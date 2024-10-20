# Tetris - C++ Project

## Description

This project is a C++ implementation of the classic Tetris game. It features two versions:
1. **Console View**: A text-based version of the game playable in the terminal.
2. **Graphical View**: A graphical version using QtCreator for the interface.

The goal of this project is to master object-oriented programming in C++ while exploring graphical user interface development with Qt.

## Features

### Console View
- Keyboard controls to move and rotate the pieces.
- Display of blocks using ASCII characters.
- Scoring system with points incremented based on the number of completed lines.

### Graphical View (QtCreator)
- Graphical user interface with colored blocks representing the game pieces.
- Keyboard controls to manipulate the pieces.
- Scoring system and speed display.
- Game speed increases progressively over time.
- Event handling through Qt for an interactive experience.

## Requirements

To compile and run this project, you will need:

- **C++11 or higher**
- **Qt 5.x or 6.x**
- **QtCreator** (for the graphical version)
- A compatible C++ compiler like GCC, Clang, or MSVC.

## Installation and Compilation

### 1. Console Version

To compile the console version, follow these steps:

```bash
# Clone the repository
git clone https://github.com/user/tetris-cpp.git

# Navigate to the project folder
cd tetris-cpp/console

# Compile the project
g++ -std=c++11 -o tetris tetris.cpp

# Run the game
./tetris
