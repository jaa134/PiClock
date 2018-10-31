#ifndef ALARMMANAGERTESTS_H
#define ALARMMANAGERTESTS_H

#include "QObject"

class AlarmManagerTests : public QObject
{
    Q_OBJECT

private slots:
    void nextAlarmSetCorrectly();
    void startTimerSetCorrectly();
    void stopTimerSetCorrectly();
};

#endif // ALARMMANAGERTESTS_H
