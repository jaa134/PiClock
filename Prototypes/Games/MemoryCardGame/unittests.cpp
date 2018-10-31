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
    m.initializeBoard();
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
    m.initializeBoard();
    m.flipCards(0,0,0,1);
    REQUIRE(m.cards[0][0] == m.cards[0][1]);
}

/*
 * test function to test the initializeBoard() function
 */
TEST_CASE("Initialize the board", "[InitializeBoard]") {
    MemoryCard m = MemoryCard();
    m.initializeBoard();
    REQUIRE(m.cards[0][0] == 0);
    REQUIRE(m.cards[0][1] == 0);
    REQUIRE(m.cards[1][0] == 1);
    REQUIRE(m.cards[1][1] == 1);
    REQUIRE(m.cards[2][0] == 2);
    REQUIRE(m.cards[2][1] == 2);
    REQUIRE(m.cards[3][0] == 3);
    REQUIRE(m.cards[3][1] == 3);
}

TEST_CASE("Shuffle the cards", "[ShuffleCards]") {
    
    
}

