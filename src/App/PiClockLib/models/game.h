#ifndef GAME_H
#define GAME_H

#include <QObject>

class Game : public QObject
{
    Q_OBJECT

public:
    enum Type {
        TicTacToe,
        Concentration,
        Math,
        Trivia
    };
    Q_ENUM(Type)
    static QString gameTypeValue(Type t) {
        switch (t) {
            case Type::TicTacToe: return "Tic Tac Toe";
            case Type::Concentration: return "Concentration";
            case Type::Math: return "Math";
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
