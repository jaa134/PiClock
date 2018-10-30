#include "alarmmanager.h"
#include "settingsmanager.h"
#include "QDateTime"

AlarmManager::AlarmManager()
{
    startTimer = new QTimer();
    startTimer->setSingleShot(true);
    connect(startTimer, SIGNAL(timeout()), this, SLOT(startAlarm()));

    stopTimer = new QTimer();
    stopTimer->setSingleShot(true);
    connect(stopTimer, SIGNAL(timeout()), this, SLOT(stopAlarm()));
}

void AlarmManager::init() {
    startTimer->stop();

    QList<Alarm *> alarms = SettingsManager::alarms();
    if (alarms.isEmpty())
        return;

    alarms = sortAlarms(alarms);
    nextAlarm = alarms.first();
    foreach (Alarm *a, alarms) {
        if (a != nextAlarm)
            delete a;
    }

    int mSecs = QTime::currentTime().msecsTo(nextAlarm->data().time);
    //add a day if that time has already passed
    if (mSecs < 0)
        mSecs += QDateTime::currentDateTime().msecsTo(QDateTime::currentDateTime().addDays(1));
    startTimer->setInterval(mSecs);
    startTimer->start();
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
    stopTimer->setInterval(minutes * 60000);
    stopTimer->start();
}

void AlarmManager::stopAlarm() {
    stopTimer->stop();

    emit alarmStop();
}
