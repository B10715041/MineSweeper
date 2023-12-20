#pragma once
#include "Cell.h"
#include <vector>

class Board {
public:
    Board(int width, int height, int mines);
    void printBoard() const; // For debugging
    void revealCell(int x, int y);
    void toggleFlag(int x, int y);
    void firstClick(int x, int y);
    bool isGameWon() const;
    bool isGameOver() const;
    int getWidth() const;
    int getHeight() const;
    const Cell &getCell(int y, int x) const;

private:
    int width, height, mineCount;
    std::vector<std::vector<Cell>> cells;
    bool gameOver;
    bool minesPlaced;

    void placeMines();
    void calculateAdjacentMines();
    void placeMinesDeferred(int firstClickX, int firstClickY);
    int countAdjacentMines(int x, int y) const;
};
