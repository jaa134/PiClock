#include "memorycard.h"
#include "ui_memorycard.h"
#include <iostream>
#include <cstdlib>
#include <ctime>
#include <algorithm>


using namespace std;
void checkGameOver();
void initializeBoard();
void flipCards(int row, int col, int row2, int col2);
static int cards[4][2];
static bool cardstatus[4][2];  // array to store whether card is flipped or not, you can use char if bool doesn't work for you.
static bool gameOver = false; // if bool doesn't work for you, use char in same way I told for cardstatus.

void checkGameOver() {
    for(int i = 0; i < 4; i++) {
        for(int j = 0; j < 2; j++) {
            if(cardstatus[i][j] == true) {
                gameOver = true;
            }
            else {
                gameOver = false;
            }
        }
    }
}

void initializeBoard() {
    for(int i = 0; i < 4; i++) {
        for(int j = 0; j < 2; j++) {
            cards[i][j] = i;
        }
    }
    // shuffle cards
    random_shuffle(&cards[0][0], &cards[4][2]);
}
void flipCards(int row, int col, int row2, int col2) {
    if(row == row2 && col == col2) {
        throw "card can't be selected twice!\n";
    }
    bool firstCardStatus = cardstatus[row][col];
    bool secondCardStatus = cardstatus[row2][col2];
    if(firstCardStatus || secondCardStatus) {
        cout << "one or both of these cards are already flipped\n";
    }
    else {
        int firstCard = cards[row][col];
        int secondCard = cards[row2][col2];

        if(firstCard == secondCard) {
            cardstatus[row][col] = true;
            cardstatus[row2][col2] = true;
            checkGameOver();
        }

        else {
          cout << "cards didn't match\n";
        }
    }
}

int main()
{
    initializeBoard();
    while(!gameOver) {
        // get row/col for both cards
        // call flippedCards
        int row1,row2,col1,col2;


        char comma;
        cout<<"Please insert the first card row and column seperated by a comma.\n";
        cin>>row1>>comma>>col1;
        cout<<"Please insert the first card row and column seperated by a comma.\n";
        cin>>row2>>comma>>col2;
        try {
            flipCards(row1,col1,row2,col2);
        } catch (const char* msg) {
            cerr << msg << endl;
          }

    }
    cout << "Game Over!\n";
}



MemoryCard::MemoryCard(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MemoryCard)
{
    ui->setupUi(this);
}

MemoryCard::~MemoryCard()
{
    delete ui;
}
