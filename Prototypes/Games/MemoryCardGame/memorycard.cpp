/*
 * class for the memory card game
 */
#include "memorycard.h"

using namespace std;

/*
 * constructor for the memory card game
 */
MemoryCard::MemoryCard() {
    gameOver = false;   // variable to see if game is over
}

/*
 * function to check of the game is over
 */
void MemoryCard::checkGameOver() {
    for(int i = 0; i < 4; i++) {
        for(int j = 0; j < 2; j++) {                // for each card check card status
            if(cardstatus[i][j] == true) {
                gameOver = true;
            }
            else {
                gameOver = false;
            }
        }
    }
}

/*
 * function to create a temporary board
 */
void MemoryCard::createBoard() {
    for(int i = 0; i < 4; i++) {
        for(int j = 0; j < 2; j++) {
            cards[i][j] = i;
        }
    }
}
/*
 * function to check of the game is over
 */
void MemoryCard::initializeBoard() {
     // for each card,initialize each card and set card status to false
    for(int i = 0; i < 4; i++) {
        for(int j = 0; j < 2; j++) {
            cards[i][j] = i;
            cardstatus[i][j] = false;
        }
    }
    shuffle(cards);
    for(int i = 0; i < 4; i++) {
        for(int j = 0; j < 2; j++) {
            cout << cards[i][j];
            cout << "\n";
        }
    }
}

/*
 * function to flip the cards
 */
void MemoryCard::flipCards(int row, int col, int row2, int col2) {
    if(row == row2 && col == col2) {
        throw "card can't be selected twice!\n";
    }
    bool firstCardStatus = cardstatus[row][col];        // the status of the first card selected
    bool secondCardStatus = cardstatus[row2][col2]; // the status of the second card selected
    if(firstCardStatus || secondCardStatus) {
        cout << "one or both of these cards are already flipped\n";
    }
    else {
        int firstCard = cards[row][col];        // the first card selected
        int secondCard = cards[row2][col2];     // the second card selected

        if(firstCard == secondCard) {
            cardstatus[row][col] = true;
            cardstatus[row2][col2] = true;
            cout << "Match found! \n";
            checkGameOver();
        }

        else {
          cout << "cards didn't match\n";
        }
    }
}

/*
 * function to shuffle the cards
 */
void MemoryCard::shuffle(int deck[4][2])
{
    // Initialize seed randomly
    srand(time(0));
    for (int i = 0; i < 4;i++)
    {
        for(int j = 0; j < 2; j++) {
            // Random for remaining positions.
            int r = i + (rand() % (4 - i));
            int r2 = j + (rand() % (2 - j));
            swap(deck[i][j], deck[r][r2]);
        }
    }
}
/*
 * fucntion to run the game
 */
int MemoryCard::exec()
{
    initializeBoard();
    while(!gameOver) {
        // get row/col for both cards
        // call flippedCards
        int row1,row2,col1,col2;
        char comma;
        
        cout<<"Please insert the first card row and column seperated by a comma.\n";
        cin>>row1>>comma>>col1;
        cout<<"Please insert the second card row and column seperated by a comma.\n";
        cin>>row2>>comma>>col2;
        try {
            flipCards(row1,col1,row2,col2);
        } catch (const char* msg) {
            cerr << msg << endl;
          }

    }
    cout << "Game Over!\n";
    return 0;
}
