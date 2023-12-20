#pragma once
#include "Board.h"
#include <string>

class InputHandler {
public:
    InputHandler(Board& board);
    char handleInput() const;

private:
    Board& board;

#ifdef _WIN32
    char handleWindowsInput() const;
#else
    char handleUnixInput() const;
#endif
    void processCommand(const std::string& command) const;
};

