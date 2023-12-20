#include "Renderer.h"

Renderer::Renderer(const Board& board) : board(board) {}
 
void Renderer::displayBoard() const {
    for (int y = 0; y < board.getHeight(); ++y) {
        for (int x = 0; x < board.getWidth(); ++x) {
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
        }
        std::cout << std::endl;
    }
}

void Renderer::displayMessage(const std::string& message) const {
    std::cout << message << std::endl;
}

