#ifndef MEMORYGAMESERVICE_H
#define MEMORYGAMESERVICE_H

#include "gameservice.h"
#include "models/game.h"
#include "QString"
#include "QList"

class MemoryGameService : public GameService
{
    friend class TestStub;

public:
    struct Card {
        bool isSelected;
        bool isMatched;
        QString colorCode;
    };

    enum MoveOutcome {
        Match,
        Mismatch,
        Invalid
    };
    Q_ENUM(MoveOutcome)

    static QList<QString> cardColors;
    Card board[4][4];
    MemoryGameService();
    void reset(Game::Difficulty) Q_DECL_OVERRIDE;
    void generateBoard();
    MoveOutcome playerMove();
    QList<Card *> selectedCards();
};

#endif // MEMORYGAMESERVICE_H
