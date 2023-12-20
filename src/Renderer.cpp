#include "Renderer.h"

Renderer::Renderer(const Board& board) : board(board) {}
 
void Renderer::displayBoard(int cursorX, int cursorY) const {
    // Clear the screen and move the cursor to the top-left corner
    std::cout << "\033[2J\033[H";

    for (int y = 0; y < board.getHeight(); ++y) {
        for (int x = 0; x < board.getWidth(); ++x) {

            if (x == cursorX && y == cursorY) {
                // Highlight cell
                std::cout << "\033[30;47m";
            }

            if (board.getCell(y, x).isRevealed()) {
                if (board.getCell(y, x).isMine()) {
                    std::cout << "* ";
                } else {
                    int adjMines = board.getCell(y, x).adjacentMines();
                    std::cout << (adjMines > 0 ? std::to_string(adjMines) : " ") << " ";
                }
            } else if (board.getCell(y, x).isFlagged()) {
                std::cout << "F ";
            } else {
                std::cout << ". ";
            }

            if (x == cursorX && y == cursorY) {
                // Reset color
                std::cout << "\033[0m";
            }
        }
        std::cout << std::endl;
    }
}

void Renderer::displayMessage(const std::string& message) const {
    std::cout << message << std::endl;
}

