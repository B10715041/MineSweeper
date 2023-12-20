#pragma once
#include "Board.h"
#include "Renderer.h"
#include "InputHandler.h"

class Game {
public:
    Game(int width, int height, int mines);
    void run();

private:
    Board board;
    Renderer renderer;
    InputHandler inputHandler;
    bool isGameOver;

    int cursorX, cursorY;

    void update();
    void checkGameOver();
    void moveCursor(char direction);
};

