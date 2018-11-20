#ifndef ALARM_H
#define ALARM_H

#include "game.h"
#include "QTime"

class Alarm
{
    friend class TestStub;

public:

    struct Data {
        QTime time;
        Game::Type type;
        Game::Difficulty difficulty;
    };

    Alarm(QTime time, Game::Type type, Game::Difficulty difficulty);
    Alarm(Data data);
    Data data();

private:
    Data alarmData;

};

#endif // ALARM_H
