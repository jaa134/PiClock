#include "memorygame.h"
#include "ui_memorygame.h"

MemoryGame::MemoryGame(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::MemoryGame)
{
    ui->setupUi(this);

    service = new MemoryGameService();

    //setup the pause timer in between moves
    timer = new QTimer();
    timer->setSingleShot(true);
    timer->setInterval(1500);
    connect(timer, &QTimer::timeout, this, &MemoryGame::resetGameboardForNextTurn);

    //setup button actions
    connect(ui->btn00, &QPushButton::released, this, &MemoryGame::onButton00);
    connect(ui->btn01, &QPushButton::released, this, &MemoryGame::onButton01);
    connect(ui->btn02, &QPushButton::released, this, &MemoryGame::onButton02);
    connect(ui->btn03, &QPushButton::released, this, &MemoryGame::onButton03);
    connect(ui->btn10, &QPushButton::released, this, &MemoryGame::onButton10);
    connect(ui->btn11, &QPushButton::released, this, &MemoryGame::onButton11);
    connect(ui->btn12, &QPushButton::released, this, &MemoryGame::onButton12);
    connect(ui->btn13, &QPushButton::released, this, &MemoryGame::onButton13);
    connect(ui->btn20, &QPushButton::released, this, &MemoryGame::onButton20);
    connect(ui->btn21, &QPushButton::released, this, &MemoryGame::onButton21);
    connect(ui->btn22, &QPushButton::released, this, &MemoryGame::onButton22);
    connect(ui->btn23, &QPushButton::released, this, &MemoryGame::onButton23);
    connect(ui->btn30, &QPushButton::released, this, &MemoryGame::onButton30);
    connect(ui->btn31, &QPushButton::released, this, &MemoryGame::onButton31);
    connect(ui->btn32, &QPushButton::released, this, &MemoryGame::onButton32);
    connect(ui->btn33, &QPushButton::released, this, &MemoryGame::onButton33);
}

MemoryGame::~MemoryGame()
{
    delete ui;
}

void MemoryGame::init(Game::Difficulty difficulty) {
    service->reset(difficulty);
    resetGameboardForNextGame();
    emit pointsUpdated(service->numPointsNeeded());
    isAcceptingInput = true;
}

void MemoryGame::setInputEnabled(bool isEnabled) {
    isAcceptingInput = isEnabled;
}


void MemoryGame::onButton00() {
    if (selectCard(row0, col0, ui->label00))
        onPlayerMove();
}

void MemoryGame::onButton01() {
    if (selectCard(row0, col1, ui->label01))
        onPlayerMove();
}

void MemoryGame::onButton02() {
    if (selectCard(row0, col2, ui->label02))
        onPlayerMove();
}

void MemoryGame::onButton03() {
    if (selectCard(row0, col3, ui->label03))
        onPlayerMove();
}

void MemoryGame::onButton10() {
    if (selectCard(row1, col0, ui->label10))
        onPlayerMove();
}

void MemoryGame::onButton11() {
    if (selectCard(row1, col1, ui->label11))
        onPlayerMove();
}

void MemoryGame::onButton12() {
    if (selectCard(row1, col2, ui->label12))
        onPlayerMove();
}

void MemoryGame::onButton13() {
    if (selectCard(row1, col3, ui->label13))
        onPlayerMove();
}

void MemoryGame::onButton20() {
    if (selectCard(row2, col0, ui->label20))
        onPlayerMove();
}

void MemoryGame::onButton21() {
    if (selectCard(row2, col1, ui->label21))
        onPlayerMove();
}

void MemoryGame::onButton22() {
    if (selectCard(row2, col2, ui->label22))
        onPlayerMove();
}

void MemoryGame::onButton23() {
    if (selectCard(row2, col3, ui->label23))
        onPlayerMove();
}

void MemoryGame::onButton30() {
    if (selectCard(row3, col0, ui->label30))
        onPlayerMove();
}

void MemoryGame::onButton31() {
    if (selectCard(row3, col1, ui->label31))
        onPlayerMove();
}

void MemoryGame::onButton32() {
    if (selectCard(row3, col2, ui->label32))
        onPlayerMove();
}

void MemoryGame::onButton33() {
    if (selectCard(row3, col3, ui->label33))
        onPlayerMove();
}

void MemoryGame::onPlayerMove() {
    //if two cards are flipped
    if (service->selectedCards().length() == 2) {
        setInputEnabled(false);
        //evaluate the outcome
        MemoryGameService::MoveOutcome outcome = service->playerMove();
        //if theres a match award points and possibly end game
        if (outcome == MemoryGameService::MoveOutcome::Match) {
            emit pointsUpdated(service->numPointsNeeded());
            QCoreApplication::processEvents();
            resetGameboardForNextTurn();
            if (service->isWinner()) {
                emit gameOver();
                return;
            }
        }
        //else start the pause timer that will hide the cards again after a set period
        else {
            timer->start();
        }
    }
}

bool MemoryGame::selectCard(int row, int col, QLabel *cardUI) {
    if (!isAcceptingInput)
        return false;

    MemoryGameService::Card *card = &service->board[row][col];

    if (card->isSelected || card->isMatched)
        return false;

    card->isSelected = true;
    cardUI->setStyleSheet("background-color: " + card->colorCode + ";"
                          "border-radius: 10px;"
                          "margin: 3px;"
                          "background-image: none;");
    return true;
}

//flip a card face down
bool MemoryGame::unselectCard(int row, int col, QLabel *cardUI) {
    MemoryGameService::Card *card = &service->board[row][col];

    if (!card->isSelected || card->isMatched)
        return false;

    card->isSelected = false;
    resetCard(cardUI);
    return true;
}

void MemoryGame::resetGameboardForNextTurn() {
    //flip every card face down
    unselectCard(row0, col0, ui->label00);
    unselectCard(row0, col1, ui->label01);
    unselectCard(row0, col2, ui->label02);
    unselectCard(row0, col3, ui->label03);
    unselectCard(row1, col0, ui->label10);
    unselectCard(row1, col1, ui->label11);
    unselectCard(row1, col2, ui->label12);
    unselectCard(row1, col3, ui->label13);
    unselectCard(row2, col0, ui->label20);
    unselectCard(row2, col1, ui->label21);
    unselectCard(row2, col2, ui->label22);
    unselectCard(row2, col3, ui->label23);
    unselectCard(row3, col0, ui->label30);
    unselectCard(row3, col1, ui->label31);
    unselectCard(row3, col2, ui->label32);
    unselectCard(row3, col3, ui->label33);

    setInputEnabled(true);
}

void MemoryGame::resetCard(QLabel *cardUI) {
    cardUI->setStyleSheet("background-color: rgb(250, 250, 250);"
                          "border-radius: 10px;"
                          "margin: 3px;"
                          "background-image: url(:/images/memory-logo.png);"
                          "background-repeat: no-repeat;"
                          "background-position: center;");
}

void MemoryGame::resetGameboardForNextGame() {
    resetCard(ui->label00);
    resetCard(ui->label01);
    resetCard(ui->label02);
    resetCard(ui->label03);
    resetCard(ui->label10);
    resetCard(ui->label11);
    resetCard(ui->label12);
    resetCard(ui->label13);
    resetCard(ui->label20);
    resetCard(ui->label21);
    resetCard(ui->label22);
    resetCard(ui->label23);
    resetCard(ui->label30);
    resetCard(ui->label31);
    resetCard(ui->label32);
    resetCard(ui->label33);

    setInputEnabled(true);
}

