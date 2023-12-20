#include "Game.h"

int main(int argc, char *argv[]) {
    // Check if '--help' is one of the command line arguments
    for (int i = 1; i < argc; ++i) {
        std::string arg = argv[i];
        if (arg == "--help") {
            std::cout << "Minesweeper Game Usage:\n";
            std::cout << "  Simply run the binary to start the game.\n";
            std::cout << "  Use the WASD keys to move the cursor.\n";
            std::cout << "  Press 'Enter' to reveal a cell.\n";
            std::cout << "  Press 'F' to flag a cell as a mine.\n";
            std::cout << "  The goal is to reveal all cells without mines.\n";
            return 0;
        }
    }

    // Regular game initialization and execution
    int width = 10; // Board width
    int height = 10; // Board height
    int mines = 20; // Number of mines

    Game minesweeperGame(width, height, mines);
    minesweeperGame.run();

    return 0;
}

