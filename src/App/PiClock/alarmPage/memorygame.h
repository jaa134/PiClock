#ifndef MEMORYGAME_H
#define MEMORYGAME_H

#include "models/game.h"
#include "games/memorygameservice.h"
#include "QWidget"
#include "QTimer"
#include "QLabel"

namespace Ui {
class MemoryGame;
}

class MemoryGame : public QWidget
{
    Q_OBJECT

public:
    explicit MemoryGame(QWidget *parent = nullptr);
    ~MemoryGame();
    void init(Game::Difficulty);

private:
    static const int  row0 = 0;
    static const int  row1 = 1;
    static const int  row2 = 2;
    static const int  row3 = 3;
    static const int  col0 = 0;
    static const int  col1 = 1;
    static const int  col2 = 2;
    static const int  col3 = 3;
    Ui::MemoryGame *ui;
    QTimer *timer;
    bool isAcceptingInput;
    void setInputEnabled(bool);
    void onPlayerMove();
    bool selectCard(int, int, QLabel *);
    bool unselectCard(int, int, QLabel *);
    void resetCard(QLabel *);
    void resetGameboardForNextGame();
    MemoryGameService *service;

signals:
    void pointsUpdated(int);
    void gameOver();

private slots:
    void onButton00();
    void onButton01();
    void onButton02();
    void onButton03();
    void onButton10();
    void onButton11();
    void onButton12();
    void onButton13();
    void onButton20();
    void onButton21();
    void onButton22();
    void onButton23();
    void onButton30();
    void onButton31();
    void onButton32();
    void onButton33();
    void resetGameboardForNextTurn();
};

#endif // MEMORYGAME_H
