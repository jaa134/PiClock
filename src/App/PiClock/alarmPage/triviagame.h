#ifndef TRIVIAGAME_H
#define TRIVIAGAME_H

#include "games/triviagameservice.h"
#include "QWidget"
#include "QTimer"

namespace Ui {
class TriviaGame;
}

class TriviaGame : public QWidget
{
    Q_OBJECT

public:
    explicit TriviaGame(QWidget *parent = nullptr);
    ~TriviaGame();
    void init(Game::Difficulty);

private:
    static const int optionA = 0;
    static const int optionB = 1;
    static const int optionC = 2;
    static const int optionD = 3;
    Ui::TriviaGame *ui;
    TriviaGameService *service;
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

#endif // TRIVIAGAME_H
