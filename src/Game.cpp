#include "Game.h"

Game::Game(int width, int height, int mines)
    : board(width, height, mines), 
      renderer(board), 
      inputHandler(board), 
      isGameOver(false) {}

void Game::run() {
    while (!isGameOver) {
        renderer.displayBoard();
        inputHandler.handleInput();
        update();
        checkGameOver();
    }
    renderer.displayBoard(); // Display the final state of the board
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

