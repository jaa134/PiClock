#ifndef MATHGAMESERVICE_H
#define MATHGAMESERVICE_H

#include "gameservice.h"
#include "models/game.h"
#include "QList"

class MathGameService : public GameService
{

public:
    struct Answer {
        bool isCorrect;
        QString text;
    };

    struct Question {
        QString text;
        QList<Answer> options;
    };

    MathGameService();
    Question question;
    void reset(Game::Difficulty) Q_DECL_OVERRIDE;

private:
    static const int minNum = -20;
    static const int maxNum = 20;
    static const int numOperators = 4;
    static QString operators[numOperators];
    bool generateQuestion();

public slots:
    bool answer(int);
};

#endif // MATHGAMESERVICE_H
