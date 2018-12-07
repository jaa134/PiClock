#include "tictactoegame.h"
#include "ui_tictactoegame.h"

TicTacToeGame::TicTacToeGame(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::TicTacToeGame)
{
    ui->setupUi(this);

    service = new TicTacToeGameService();

    //setup timer that creates pause between user to cpu turns
    cpuMoveTimer = new QTimer();
    cpuMoveTimer->setSingleShot(true);
    cpuMoveTimer->setInterval(500);
    connect(cpuMoveTimer, &QTimer::timeout, this, &TicTacToeGame::requestComputerMove);

    //setup timer that creates pause in between game board reset
    gameBoardTimer = new QTimer();
    gameBoardTimer->setSingleShot(true);
    gameBoardTimer->setInterval(500);
    connect(gameBoardTimer, &QTimer::timeout, this, &TicTacToeGame::requestNewGameBoard);

    //setup game buttons actions
    connect(ui->btn00, &QPushButton::released, this, &TicTacToeGame::onButton00);
    connect(ui->btn01, &QPushButton::released, this, &TicTacToeGame::onButton01);
    connect(ui->btn02, &QPushButton::released, this, &TicTacToeGame::onButton02);
    connect(ui->btn10, &QPushButton::released, this, &TicTacToeGame::onButton10);
    connect(ui->btn11, &QPushButton::released, this, &TicTacToeGame::onButton11);
    connect(ui->btn12, &QPushButton::released, this, &TicTacToeGame::onButton12);
    connect(ui->btn20, &QPushButton::released, this, &TicTacToeGame::onButton20);
    connect(ui->btn21, &QPushButton::released, this, &TicTacToeGame::onButton21);
    connect(ui->btn22, &QPushButton::released, this, &TicTacToeGame::onButton22);
}

TicTacToeGame::~TicTacToeGame()
{
    delete ui;
}

void TicTacToeGame::init(Game::Difficulty difficulty) {
    service->reset(difficulty);
    updateGameBoard();
    emit pointsUpdated(service->numPointsNeeded());
    isAcceptingInput = true;
}

void TicTacToeGame::setInputEnabled(bool isEnabled) {
    isAcceptingInput = isEnabled;
}

void TicTacToeGame::onButton00() {
    onPlayerMove(row0, col0);
}

void TicTacToeGame::onButton01() {
    onPlayerMove(row0, col1);
}

void TicTacToeGame::onButton02() {
    onPlayerMove(row0, col2);
}

void TicTacToeGame::onButton10() {
    onPlayerMove(row1, col0);
}

void TicTacToeGame::onButton11() {
    onPlayerMove(row1, col1);
}

void TicTacToeGame::onButton12() {
    onPlayerMove(row1, col2);
}

void TicTacToeGame::onButton20() {
    onPlayerMove(row2, col0);
}

void TicTacToeGame::onButton21() {
    onPlayerMove(row2, col1);
}

void TicTacToeGame::onButton22() {
    onPlayerMove(row2, col2);
}

void TicTacToeGame::onPlayerMove(int row, int col) {
    if (!isAcceptingInput)
        return;

    isAcceptingInput = false;
    //make a move
    TicTacToeGameService::MoveOutcome outcome = service->playerMove(row, col);
    //dont do anything if the move is invalid
    if (outcome == TicTacToeGameService::MoveOutcome::Invalid) {
        isAcceptingInput = true;
        return;
    }

    //update the game board visuals
    updateGameBoard();

    //if there is not a win, start cpu move timer
    if (outcome == TicTacToeGameService::MoveOutcome::Inconclusive)
        cpuMoveTimer->start();
    //else update points
    else {
        emit pointsUpdated(service->numPointsNeeded());
        gameBoardTimer->start();
    }
}

void TicTacToeGame::requestComputerMove() {
    //make the computer move
    TicTacToeGameService::MoveOutcome outcome = service->computerMove();
    //update game board visuals
    updateGameBoard();

    //if there is not a win, let player move
    if (outcome == TicTacToeGameService::MoveOutcome::Inconclusive)
        isAcceptingInput = true;
    //else update points
    else {
        emit pointsUpdated(service->numPointsNeeded());
        gameBoardTimer->start();
    }
}

void TicTacToeGame::requestNewGameBoard() {
    //check if there is a winner, if there is, dont do anything
    if (service->isWinner()) {
        emit gameOver();
        return;
    }

    //reset the board
    service->newBoard();
    updateGameBoard();
    isAcceptingInput = true;
}

void TicTacToeGame::updateGameBoard() {
    //update visuals to game board
    ui->btn00->setText(QChar(service->board[0][0]));
    ui->btn01->setText(QChar(service->board[0][1]));
    ui->btn02->setText(QChar(service->board[0][2]));
    ui->btn10->setText(QChar(service->board[1][0]));
    ui->btn11->setText(QChar(service->board[1][1]));
    ui->btn12->setText(QChar(service->board[1][2]));
    ui->btn20->setText(QChar(service->board[2][0]));
    ui->btn21->setText(QChar(service->board[2][1]));
    ui->btn22->setText(QChar(service->board[2][2]));
}
