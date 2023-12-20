#include "Board.h"
#include <cstdlib>
#include <ctime>
#include <iostream>

Board::Board(int width, int height, int mines):
        width(width), height(height), mineCount(mines), gameOver(false), minesPlaced(false) {
    cells.resize(height, std::vector<Cell>(width));
    /* placeMines(); */
    /* calculateAdjacentMines(); */
}

void Board::firstClick(int x, int y) {
    if (!minesPlaced) {
        placeMinesDeferred(x, y);
        calculateAdjacentMines();
        minesPlaced = true;
    }
    revealCell(x, y);
}

void Board::placeMinesDeferred(int firstClickX, int firstClickY) {
    srand(time(nullptr));
    for (int i = 0; i < mineCount; ++i) {
        int x, y;
        do {
            x = rand() % width;
            y = rand() % height;
        } while (cells[y][x].isMine() || (x >= firstClickX - 1 && x <= firstClickX + 1 && y >= firstClickY - 1 && y <= firstClickY + 1));
        cells[y][x].setMine(true);
    }
}

void Board::placeMines() {
    srand(time(nullptr));
    for (int i = 0; i < mineCount; ++i) {
        int x, y;
        do {
            x = rand() % width;
            y = rand() % height;
        } while (cells[y][x].isMine());
        cells[y][x].setMine(true);
    }
}

void Board::calculateAdjacentMines() {
    for (int y = 0; y < height; ++y) {
        for (int x = 0; x < width; ++x) {
            if (!cells[y][x].isMine()) {
                cells[y][x].setAdjacentMines(countAdjacentMines(x, y));
            }
        }
    }
}

int Board::countAdjacentMines(int x, int y) const {
    int count = 0;
    for (int dy = -1; dy <= 1; ++dy) {
        for (int dx = -1; dx <= 1; ++dx) {
            int nx = x + dx, ny = y + dy;
            if (nx >= 0 && nx < width && ny >= 0 && ny < height && cells[ny][nx].isMine()) {
                ++count;
            }
        }
    }
    return count;
}

void Board::printBoard() const {
    for (int y = 0; y < height; ++y) {
        for (int x = 0; x < width; ++x) {
            const Cell& cell = cells[y][x];
            if (cell.isRevealed()) {
                if (cell.isMine()) {
                    std::cout << "* ";
                } else {
                    std::cout << cell.adjacentMines() << " ";
                }
            } else if (cell.isFlagged()) {
                std::cout << "F ";
            } else {
                std::cout << ". ";
            }
        }
        std::cout << std::endl;
    }
}

void Board::revealCell(int x, int y) {
    if (x < 0 || x >= width || y < 0 || y >= height || cells[y][x].isRevealed()) {
        return;
    }

    cells[y][x].setRevealed(true);

    if (cells[y][x].isMine()) {
        gameOver = true;
    } else if (cells[y][x].adjacentMines() == 0) {
        // Reveal adjacent cells if this cell has no adjacent mines
        for (int dy = -1; dy <= 1; ++dy) {
            for (int dx = -1; dx <= 1; ++dx) {
                if (dx != 0 || dy != 0) {
                    revealCell(x + dx, y + dy);
                }
            }
        }
    }
}

void Board::toggleFlag(int x, int y) {
    if (x < 0 || x >= width || y < 0 || y >= height || cells[y][x].isRevealed()) {
        return;
    }

    cells[y][x].setFlagged(!cells[y][x].isFlagged());
}

bool Board::isGameWon() const {
    for (int y = 0; y < height; ++y) {
        for (int x = 0; x < width; ++x) {
            const Cell& cell = cells[y][x];
            if (!cell.isMine() && !cell.isRevealed()) {
                return false;
            }
        }
    }
    return true;
}

bool Board::isGameOver() const {
    return gameOver;
}

int Board::getWidth() const {
    return width;
}

int Board::getHeight() const {
    return height;
}

const Cell &Board::getCell(int y, int x) const {
    return cells[y][x];
}


