#ifndef GAMESERVICE_H
#define GAMESERVICE_H

#include "models/game.h"

class GameService
{

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
