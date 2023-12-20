#include "Cell.h"

Cell::Cell(): mine(false), revealed(false), flagged(false), adjacent_mines(0) {}

bool Cell::isMine() const { return mine; }
bool Cell::isRevealed() const { return revealed; }
bool Cell::isFlagged() const { return flagged; }
int Cell::adjacentMines() const { return adjacent_mines; }

void Cell::setMine(bool mine) { this->mine = mine; }
void Cell::setRevealed(bool revealed) { this->revealed = revealed; }
void Cell::setFlagged(bool flagged) { this->flagged = flagged; }
void Cell::setAdjacentMines(int count) { adjacent_mines = count; }
