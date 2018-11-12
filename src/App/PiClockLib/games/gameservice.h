#ifndef GAMESERVICE_H
#define GAMESERVICE_H

#include "models/game.h"
#include "QObject"

class GameService : public QObject
{
Q_OBJECT

public:
    virtual ~GameService();
    bool isWinner();
    int numPointsNeeded();
    virtual void reset(Game::Difficulty) {}

protected:
    int pointsToWin;
    int currentPoints;
};

#endif // GAMESERVICE_H
