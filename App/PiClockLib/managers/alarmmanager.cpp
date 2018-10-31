#include "alarmmanager.h"
#include "settingsmanager.h"
#include "QDateTime"

AlarmManager::AlarmManager()
{
    start_timer = new QTimer();
    start_timer->setSingleShot(true);
    connect(start_timer, SIGNAL(timeout()), this, SLOT(startAlarm()));

    stop_timer = new QTimer();
    stop_timer->setSingleShot(true);
    connect(stop_timer, SIGNAL(timeout()), this, SLOT(stopAlarm()));
}

Alarm* AlarmManager::nextAlarm() {
    return next_alarm;
}

QTimer* AlarmManager::startTimer() {
    return start_timer;
}

QTimer* AlarmManager::stopTimer() {
    return stop_timer;
}

void AlarmManager::init() {
    start_timer->stop();

    QList<Alarm *> alarms = SettingsManager::alarms();
    if (alarms.isEmpty())
        return;

    alarms = sortAlarms(alarms);
    next_alarm = alarms.first();
    foreach (Alarm *a, alarms) {
        if (a != next_alarm)
            delete a;
    }

    int mSecs = QTime::currentTime().msecsTo(next_alarm->data().time);
    //add a day if that time has already passed
    if (mSecs < 0)
        mSecs += QDateTime::currentDateTime().msecsTo(QDateTime::currentDateTime().addDays(1));
    start_timer->setInterval(mSecs);
    start_timer->start();
}

QList<Alarm *> AlarmManager::sortAlarms(QList<Alarm *> alarms) {
    std::sort(alarms.begin(), alarms.end(), [](Alarm *a1, Alarm *a2){
        return a1->data().time < a2->data().time;
    });
    return alarms;
}

void AlarmManager::startAlarm() {
    emit alarmStart();
    int minutes = 5;
    stop_timer->setInterval(minutes * 60000);
    stop_timer->start();
}

void AlarmManager::stopAlarm() {
    stop_timer->stop();

    emit alarmStop();
}
