#ifndef TICTACTOEGAME_H
#define TICTACTOEGAME_H

#include "models/game.h"
#include "games/tictactoegameservice.h"
#include "QWidget"
#include "QTimer"

namespace Ui {
class TicTacToeGame;
}

class TicTacToeGame : public QWidget
{
    Q_OBJECT

public:
    explicit TicTacToeGame(QWidget *parent = nullptr);
    ~TicTacToeGame();
    void init(Game::Difficulty);

private:
    static const int  row0 = 0;
    static const int  row1 = 1;
    static const int  row2 = 2;
    static const int  col0 = 0;
    static const int  col1 = 1;
    static const int  col2 = 2;
    Ui::TicTacToeGame *ui;
    TicTacToeGameService *service;
    QTimer *cpuMoveTimer;
    QTimer *gameBoardTimer;
    bool isAcceptingInput;
    void setInputEnabled(bool);
    void onPlayerMove(int, int);
    void updateGameBoard();

signals:
    void pointsUpdated(int);
    void gameOver();

private slots:
    void onButton00();
    void onButton01();
    void onButton02();
    void onButton10();
    void onButton11();
    void onButton12();
    void onButton20();
    void onButton21();
    void onButton22();
    void requestComputerMove();
    void requestNewGameBoard();
};

#endif // TICTACTOEGAME_H
