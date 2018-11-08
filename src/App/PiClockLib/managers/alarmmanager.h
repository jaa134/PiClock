#ifndef ALARMMANAGER_H
#define ALARMMANAGER_H

#include "models/alarm.h"
#include "QObject"
#include "QTimer"
#include "QList"
#include "QSoundEffect"

class AlarmManager : public QObject
{
    Q_OBJECT

public:
    AlarmManager();
    void init();
    QString timeRemaining();

private:
    Alarm *next_alarm;
    QTimer *start_timer;
    QTimer *stop_timer;
    QSoundEffect *sound;
    QList<Alarm> sortAlarms(QList<Alarm>);

signals:
    void alarmStarted(Game::Type, Game::Difficulty);
    void alarmStopped();

public slots:
    void stopAlarm();

private slots:
    void startAlarm();

};

#endif // ALARMMANAGER_H
