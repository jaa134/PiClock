#ifndef ALARMTESTS_H
#define ALARMTESTS_H

#include "QObject"

class AlarmTests : public QObject
{
    Q_OBJECT

private slots:
    void setsExecutionTime();
    void setsGameType();
    void setsGameDifficulty();

};

#endif // ALARMTESTS_H
