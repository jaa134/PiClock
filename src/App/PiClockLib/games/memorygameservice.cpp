#include "memorygameservice.h"

QList<QString> MemoryGameService::cardColors = {
    "#9400d3", //violet
    "#4b0082", //indigo
    "#0000ff", //blue
    "#00ff00", //green
    "#ffff00", //yellow
    "#ff7f00", //orange
    "#ff0000", //red
    "#ffffff", //white
};

MemoryGameService::MemoryGameService()
{ }

void MemoryGameService::reset(Game::Difficulty difficulty) {
    currentPoints = 0;

    if (difficulty == Game::Difficulty::Easy)
        pointsToWin = 4;
    if (difficulty == Game::Difficulty::Medium)
        pointsToWin = 6;
    if (difficulty == Game::Difficulty::Hard)
        pointsToWin = 8;

    generateBoard();
}

void MemoryGameService::generateBoard() {
    QList<Card> deck;
    foreach (QString hexColor, cardColors) {
        Card c;
        c.isMatched = false;
        c.isSelected = false;
        c.colorCode = hexColor;
        deck.append(c);
        deck.append(c);
    }

    std::srand(time(nullptr));
    int numRows = 4;
    int numCols = 4;
    for (int r = 0; r < numRows; r++) {
        for (int c = 0; c < numCols; c++) {
            board[r][c] = deck.takeAt(rand() % deck.length());
        }
    }
}

QList<MemoryGameService::Card *> MemoryGameService::selectedCards() {
    QList<Card *> selected;
    int numRows = 4;
    int numCols = 4;
    for (int r = 0; r < numRows; r++) {
        for (int c = 0; c < numCols; c++) {
            if (board[r][c].isSelected)
                selected.append(&board[r][c]);
        }
    }
    return selected;
}

MemoryGameService::MoveOutcome MemoryGameService::playerMove() {
    QList<Card *> selected = selectedCards();
    if (selected.length() != 2)
        return Invalid;
    Card *c1 = selected.at(0);
    Card *c2 = selected.at(1);

    if (!c1->isSelected || !c2->isSelected || c1->isMatched || c2->isMatched)
        return Invalid;

    if (c1->colorCode == c2->colorCode) {
        currentPoints += 2;
        c1->isSelected = false;
        c2->isSelected = false;
        c1->isMatched = true;
        c2->isMatched = true;
        return Match;
    }
    else {
        currentPoints += 0;
        return Mismatch;
    }
}