#include "gameservice.h"

GameService::~GameService()
{ }

bool GameService::isWinner() {
    return currentPoints >= pointsToWin;
}

int GameService::numPointsNeeded() {
    return std::max(pointsToWin - currentPoints, 0);
}
