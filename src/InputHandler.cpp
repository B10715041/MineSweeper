#include "InputHandler.h"
#include "TerminalUtils.h"
#include <iostream>
#include <sstream>

InputHandler::InputHandler(Board& board) : board(board) {}

char InputHandler::handleInput() const {
    #ifdef _WIN32
    return handleWindowsInput();
    #else
    return handleUnixInput();
    #endif
}

#ifdef _WIN32
char InputHandler::handleWindowsInput() const {
    HANDLE hStdin = GetStdHandle(STD_INPUT_HANDLE); 
    INPUT_RECORD irInBuf[128]; 
    DWORD cNumRead;

    while (true) {
        // Read console input buffer
        if (!ReadConsoleInput(hStdin, irInBuf, 128, &cNumRead)) {
            return 0; // Error handling
        }

        for (DWORD i = 0; i < cNumRead; i++) {
            if (irInBuf[i].EventType == KEY_EVENT && irInBuf[i].Event.KeyEvent.bKeyDown) {
                // Process the key event (irInBuf[i].Event.KeyEvent)
                // Return the character or control key pressed
                return irInBuf[i].Event.KeyEvent.uChar.AsciiChar;
            }
        }
    }
}
#else
char InputHandler::handleUnixInput() const {
    TerminalUtils::enableRawMode();
    char ch;
    read(STDIN_FILENO, &ch, 1);
    TerminalUtils::disableRawMode();
    return ch;
}
#endif

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

