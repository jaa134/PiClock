#include "gameservice.h"

GameService::~GameService()
{ }

bool GameService::isWinner() {
    return currentPoints == pointsToWin;
}

int GameService::numPointsNeeded() {
    return pointsToWin - currentPoints;
}
