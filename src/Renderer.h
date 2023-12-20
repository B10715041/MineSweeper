#pragma once
#include "Board.h"
#include <iostream>

#ifdef _WIN32
#include <windows.h>
#endif


class Renderer {
public:
    Renderer(const Board& board);
    void displayBoard(int cursorX, int cursorY) const;
    void displayMessage(const std::string& message) const;

private:
    const Board& board;

    void displayBoardLinux(int cursorX, int cursorY) const;
    void displayDebugBoard() const;
    void displayBoardWindows(int cursorX, int cursorY) const;
};

