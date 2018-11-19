/*
 * test class for the memory card game
 */
#include "memorycard.h"

#define CATCH_CONFIG_MAIN
#include "catch.hpp"

/*
 * test function to test the checkGameOver() function
 */
TEST_CASE("Check Game Over", "[GameOver]") {
    MemoryCard m = MemoryCard();
    for(int i = 0; i < 4; i++) {
        for(int j = 0; j < 2; j++) {
            m.cards[i][j] = i;
        }
    }
    m.flipCards(0,0,0,1);
    m.flipCards(1,0,1,1);
    m.flipCards(2,0,2,1);
    m.flipCards(3,0,3,1);
    m.checkGameOver();
    CHECK(m.gameOver == true);
}

/*
 * test function to test the flipCards() function
 */
TEST_CASE("Flip Cards", "[FlipCards]") {
    MemoryCard m = MemoryCard();
    m.createBoard();
    m.flipCards(1,0,1,1);
    bool card1 = m.cardstatus[1][0];
    bool card2 = m.cardstatus[1][1];
    printf("%d\n",card1);
    printf("%d\n", card2);
    REQUIRE(card1);
    REQUIRE(card2);
}

/*
 * test function to test the initializeBoard() function
 */
TEST_CASE("Shuffle the cards", "[ShuffleCards]") {
    //m.shuffleCards(m.cards);
    MemoryCard m = MemoryCard();
    bool noMatch = false;
    int deck[4][2], deck2[4][2];
    for(int i = 0; i < 4; i++) {
        for(int j = 0; j < 2; j++) {
            deck[i][j] = i;
            deck2[i][j] = i;
        }
    }
    m.shuffle(deck);
    for(int i = 0; i < 4; i++) {
        for(int j = 0; j < 2; j++) {
            if(deck2[i][j] == deck[i][j]) {
                noMatch = true;
            }
        }
    }
    REQUIRE(noMatch == true);
}

