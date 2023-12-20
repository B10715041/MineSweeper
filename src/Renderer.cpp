#include "Renderer.h"

Renderer::Renderer(const Board& board) : board(board) {}
 
void Renderer::displayBoard(int cursorX, int cursorY) const {
    #ifdef _WIN32
    displayBoardWindows(cursorX, cursorY);
    #else
    displayBoardLinux(cursorX, cursorY);
    #endif
}

void Renderer::displayBoardLinux(int cursorX, int cursorY) const {
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
                    std::cout << "\033[31m*\033[0m "; // Red for mines
                } else {
                    int adjMines = board.getCell(y, x).adjacentMines();
                    std::cout << "\033[" << 31 + adjMines << "m"; // Different colors
                    std::cout << (adjMines > 0 ? std::to_string(adjMines) : " ") << "\033[0m ";
                }
            } else if (board.getCell(y, x).isFlagged()) {
                std::cout << "\033[31mF\033[0m "; // Red for flags
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

    displayDebugBoard();
}

void Renderer::displayDebugBoard() const {
    std::cout << std::endl << std::endl;
    for (int y = 0; y < board.getHeight(); ++y) {
        for (int x = 0; x < board.getWidth(); ++x) {
            const Cell& cell = board.getCell(y, x);

            // Displaying the actual mines
            if (cell.isMine()) {
                std::cout << "\033[31m*\033[0m "; // Red asterisk for mines
            } else {
                std::cout << ". "; // Placeholder for non-mine cells
            }
        }
        std::cout << std::endl;
    }
}


void Renderer::displayMessage(const std::string& message) const {
    std::cout << message << std::endl;
}


#ifdef _WIN32
void Renderer::displayBoardWindows(int cursorX, int cursorY) const {
    HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
    COORD pos;
    system("cls");  // Clear the console

    for (int y = 0; y < board.getHeight(); ++y) {
        for (int x = 0; x < board.getWidth(); ++x) {
            pos.X = x * 2;
            pos.Y = y;
            SetConsoleCursorPosition(hConsole, pos);

            const Cell& cell = board.getCell(y, x);

            // Highlight cursor position
            if (x == cursorX && y == cursorY) {
                SetConsoleTextAttribute(hConsole, BACKGROUND_BLUE | BACKGROUND_INTENSITY);
            }

            if (cell.isRevealed()) {
                if (cell.isMine()) {
                    SetConsoleTextAttribute(hConsole, FOREGROUND_RED);
                    std::cout << "* ";
                } else {
                    int adjacentMines = cell.adjacentMines();
                    SetConsoleTextAttribute(hConsole, FOREGROUND_GREEN); // Example color
                    std::cout << (adjacentMines > 0 ? std::to_string(adjacentMines) : " ") << " ";
                }
            } else if (cell.isFlagged()) {
                SetConsoleTextAttribute(hConsole, FOREGROUND_BLUE | FOREGROUND_INTENSITY);
                std::cout << "F ";
            } else {
                SetConsoleTextAttribute(hConsole, FOREGROUND_RED | FOREGROUND_GREEN | FOREGROUND_BLUE);
                std::cout << ". ";
            }

            // Reset to default color
            SetConsoleTextAttribute(hConsole, FOREGROUND_RED | FOREGROUND_GREEN | FOREGROUND_BLUE);
        }
        std::cout << std::endl;
    }
    // Reset cursor position after rendering
    pos.X = 0;
    pos.Y = board.getHeight();
    SetConsoleCursorPosition(hConsole, pos);
}
#endif

