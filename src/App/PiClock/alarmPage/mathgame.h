#ifndef MATHGAME_H
#define MATHGAME_H

#include "games/mathgameservice.h"
#include "QWidget"
#include "QTimer"

namespace Ui {
class MathGame;
}

class MathGame : public QWidget
{
    Q_OBJECT

public:
    explicit MathGame(QWidget *parent = nullptr);
    ~MathGame();
    void init(Game::Difficulty);

private:
    static const int optionA = 0;
    static const int optionB = 1;
    static const int optionC = 2;
    static const int optionD = 3;
    Ui::MathGame *ui;
    MathGameService *service;
    QTimer *timer;
    bool isAcceptingInput;
    void setInputEnabled(bool);
    void onAnswer(int);
    void setAnswerStyles(bool, int);
    void displayQuestion();
    void setDefaultStyles();

signals:
    void pointsUpdated(int);
    void gameOver();

private slots:
    void onButtonA();
    void onButtonB();
    void onButtonC();
    void onButtonD();
    void nextQuestion();
};

#endif // MATHGAME_H
