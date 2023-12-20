#pragma once

class Cell {
public:
    Cell();

    bool isMine() const;
    bool isRevealed() const;
    bool isFlagged() const;
    int adjacentMines() const;

    void setMine(bool mine);
    void setRevealed(bool revealed);
    void setFlagged(bool flagged);
    void setAdjacentMines(int count);

private:
    bool mine;
    bool revealed;
    bool flagged;
    int adjacent_mines;
};
