#ifndef MEMORYCARD_H
#define MEMORYCARD_H

#include <iostream>
#include <cstdlib>
#include <ctime>
#include <algorithm>

/*
 * class for the memory card game
 */
class MemoryCard
{

/*
 * all public global variables and functions
 */
public:
    MemoryCard();   // constructor for the memory card game
    void checkGameOver();   // function to check if the game is over
    void initializeBoard(); // function to initialize the board
    void flipCards(int row, int col, int row2, int col2);   // function to flip the cards
    void shuffle(int card[4][2]);
    int exec(); // function to execute the game
    int cards[4][2];    // variable for the card
    bool cardstatus[4][2];  // variable to check the card status of each card
    bool gameOver;  // variable to check if the game is over

};

#endif // MEMORYCARD_H
