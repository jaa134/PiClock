#include "alarm.h"

Alarm::Alarm(QTime time, Alarm::GameType type, Alarm::GameDifficulty difficulty) {
    Alarm::Data d;
    d.time = time;
    d.type = type;
    d.difficulty = difficulty;
    alarmData = d;
}

Alarm::Alarm(Alarm::Data alarmData) {
    this->alarmData = alarmData;
}

Alarm::Data Alarm::data() {
    return alarmData;
}

