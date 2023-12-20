#pragma once
#include "Board.h"
#include <iostream>

class Renderer {
public:
    Renderer(const Board& board);
    void displayBoard(int cursorX, int cursorY) const;
    void displayDebugBoard() const;
    void displayMessage(const std::string& message) const;

private:
    const Board& board;
};

