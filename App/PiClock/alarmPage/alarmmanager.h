#ifndef ALARMMANAGER_H
#define ALARMMANAGER_H

#include "alarm.h"
#include "QObject"
#include "QTimer"
#include "QList"

class AlarmManager : public QObject
{
    Q_OBJECT

public:
    AlarmManager();
    void init();

private:
    Alarm *nextAlarm;
    QTimer *startTimer;
    QTimer *stopTimer;
    QList<Alarm *> sortAlarms(QList<Alarm *>);

signals:
    void alarmStart();
    void alarmStop();

private slots:
    void startAlarm();
    void stopAlarm();

};

#endif // ALARMMANAGER_H
