#include "Game.h"

int main() {
    int width = 10; // Board width
    int height = 10; // Board height
    int mines = 20; // Number of mines

    Game minesweeperGame(width, height, mines);
    minesweeperGame.run();

    return 0;
}

