#ifndef ALARM_H
#define ALARM_H

#include "QObject"
#include "QTime"

class Alarm : public QObject
{
    Q_OBJECT

public:
    enum GameType {
        TicTacToe,
        Concentration,
        Math,
        Trivia,
        Simon
    };
    Q_ENUM(GameType)
    static QString gameTypeValue(GameType t) {
        switch (t) {
            case GameType::TicTacToe: return "Tic Tac Toe";
            case GameType::Concentration: return "Concentration";
            case GameType::Math: return "Math";
            case GameType::Trivia: return "Trivia";
            case GameType::Simon: return "Simon Says";
        }
        return "";
    }

    enum GameDifficulty {
        Easy,
        Medium,
        Hard
    };
    Q_ENUM(GameDifficulty)
    static QString gameDifficultyValue(GameDifficulty d) {
        switch (d) {
            case GameDifficulty::Easy: return "Easy";
            case GameDifficulty::Medium: return "Medium";
            case GameDifficulty::Hard: return "Hard";
        }
        return "";
    }

    struct Data {
        QTime time;
        GameType type;
        GameDifficulty difficulty;
    };

    friend QDataStream & operator << (QDataStream &out, const Data &d)
    {
        out << d.time;
        out << d.type;
        out << d.difficulty;
        return out;
    }

    friend QDataStream & operator >> (QDataStream &in, Data &d)
    {
        in >> d.time;
        QString type = "";
        in >> type;
        d.type = GameType(type.toInt());
        QString difficulty = "";
        in >> difficulty;
        d.difficulty = GameDifficulty(difficulty.toInt());
        return in;
    }

    Alarm(QTime time, GameType type, GameDifficulty difficulty);
    Alarm(Data data);
    Data data();

private:
    Data alarmData;

};

Q_DECLARE_METATYPE(Alarm::Data);

#endif // ALARM_H
