#include "Game.h"

Game::Game(int width, int height, int mines)
    : board(width, height, mines), 
      renderer(board), 
      inputHandler(board), 
      isGameOver(false),
      cursorX(0), cursorY(0) {}

void Game::run() {
    while (!isGameOver) {
        renderer.displayBoard(cursorX, cursorY);
        char input = inputHandler.handleInput();
        switch (input) {
            case 'w':
            case 'a':
            case 's':
            case'd':
                moveCursor(input);
                break;
            case '\n':
                board.revealCell(cursorX, cursorY);
                break;
            case 'f':
                board.toggleFlag(cursorX, cursorY);
                break;
            default:
                break;
        }
        update();
        checkGameOver();
    }
    renderer.displayBoard(cursorX, cursorY); // Display the final state of the board
    renderer.displayMessage(isGameOver ? "Game Over!" : "Congratulations! You won!");
}

void Game::update() {
    // Here, you might update game state, check for win/lose conditions, etc.
}

void Game::checkGameOver() {
    if (board.isGameOver()) {
        isGameOver = true;
    } else if (board.isGameWon()) {
        isGameOver = true;
    }
}

void Game::moveCursor(char direction) {
    switch (direction) {
        case 'w': // Move up
            if (cursorY > 0) cursorY--;
            break;
        case 's': // Move down
            if (cursorY < board.getHeight() - 1) cursorY++;
            break;
        case 'a': // Move left
            if (cursorX > 0) cursorX--;
            break;
        case 'd': // Move right
            if (cursorX < board.getWidth() - 1) cursorX++;
            break;
    }
}
