#ifndef GAME_H
#define GAME_H

#include <QObject>

class Game : public QObject
{
    Q_OBJECT

    friend class TestStub;

public:
    enum Type {
        Math,
        TicTacToe,
        Memory,
        Trivia
    };
    Q_ENUM(Type)
    static QString gameTypeValue(Type t) {
        switch (t) {
            case Type::Math: return "Math";
            case Type::TicTacToe: return "Tic Tac Toe";
            case Type::Memory: return "Memory";
            case Type::Trivia: return "Trivia";
        }
        return "";
    }

    enum Difficulty {
        Easy,
        Medium,
        Hard
    };
    Q_ENUM(Difficulty)
    static QString gameDifficultyValue(Difficulty d) {
        switch (d) {
            case Difficulty::Easy: return "Easy";
            case Difficulty::Medium: return "Medium";
            case Difficulty::Hard: return "Hard";
        }
        return "";
    }

};

#endif // GAME_H
