# Minesweeper Game

## Overview
This project is a console-based implementation of the classic Minesweeper game. It features a grid of cells, some of which contain mines. The player navigates the grid, revealing cells while avoiding mines.

## Features
- Console-based gameplay.
- Use of WASD keys for navigation.
- Enter key to reveal cells.
- 'F' key to flag cells as mines.
- Cross-platform support for both Windows and Linux environments.

## Usage
To play the game, run the executable in your console. The game starts immediately upon running the binary.

### Controls
- `W`, `A`, `S`, `D`: Move cursor up, left, down, and right respectively.
- `Enter`: Reveal the cell at the cursor's current position.
- `F`: Flag a cell as a mine.

### Command Line Arguments
- `--help`: Display usage information.

## Environment
The game is designed to run in both Windows and Linux console environments. It uses platform-specific rendering to ensure compatibility.

### Windows
- Uses the Windows Console API for rendering.
- Compiled with [Your Windows Compiler Information].

### Linux
- Uses ANSI escape codes for console manipulation.
- Compiled with GCC version [Your Linux GCC Version].

## Building the Project
To build the project, use the provided Makefile:

```bash
make

