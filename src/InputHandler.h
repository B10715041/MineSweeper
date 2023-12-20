#pragma once
#include "Board.h"
#include <string>

class InputHandler {
public:
    InputHandler(Board& board);
    char handleInput() const;

private:
    Board& board;

    void processCommand(const std::string& command) const;
};

