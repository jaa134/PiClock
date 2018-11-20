#ifndef TICTACTOEGAMESERVICE_H
#define TICTACTOEGAMESERVICE_H

#include "gameservice.h"
#include "models/game.h"
#include "QList"

class TicTacToeGameService : public GameService
{
    friend class TestStub;

public:
    enum MoveOutcome {
        Invalid,
        Win,
        Tie,
        Loss,
        Inconclusive
    };
    Q_ENUM(MoveOutcome)

    char board[3][3];
    TicTacToeGameService();
    void reset(Game::Difficulty) Q_DECL_OVERRIDE;
    MoveOutcome playerMove(int, int);
    MoveOutcome computerMove();
    void newBoard();

private:
    static const char default_symbol = ' ';
    static const char cpu_symbol = 'o';
    static const char player_symbol = 'x';
    static const int rowWidth = 3;
    static const int colHeight = 3;
    MoveOutcome makeMove(char, int, int);
    bool boardHasThreeInRow();
    bool areSameValue(char, char, char);
};

#endif // TICTACTOEGAMESERVICE_H
