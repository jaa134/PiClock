#ifndef ALARMMANAGER_H
#define ALARMMANAGER_H

#include "models/alarm.h"
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
    Alarm *next_alarm;
    QTimer *start_timer;
    QTimer *stop_timer;
    QList<Alarm> sortAlarms(QList<Alarm>);

signals:
    void alarmStart();
    void alarmStop();

private slots:
    void startAlarm();
    void stopAlarm();

};

#endif // ALARMMANAGER_H
