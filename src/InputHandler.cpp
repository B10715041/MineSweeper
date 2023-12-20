#include "InputHandler.h"
#include "TerminalUtils.h"
#include <iostream>
#include <sstream>

InputHandler::InputHandler(Board& board) : board(board) {}

char InputHandler::handleInput() const {
    /* std::string input; */
    /* std::cout << "Enter command (e.g., 'r 3 4' to reveal cell at 3,4 or 'f 3 4' to flag cell): "; */
    /* std::getline(std::cin, input); */
    /* processCommand(input); */
    TerminalUtils::enableRawMode();
    char ch;
    read(STDIN_FILENO, &ch, 1);
    TerminalUtils::disableRawMode();
    return ch;
}

void InputHandler::processCommand(const std::string& command) const {
    std::istringstream iss(command);
    char action;
    int x, y;
    if (!(iss >> action >> x >> y)) {
        std::cout << "Invalid command format." << std::endl;
        return;
    }

    switch (action) {
        case 'r':
            board.revealCell(x, y);
            break;
        case 'f':
            board.toggleFlag(x, y);
            break;
        default:
            std::cout << "Unknown action." << std::endl;
    }
}

