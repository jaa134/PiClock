#include "alarmmanager.h"
#include "databasemanager.h"
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

void AlarmManager::init() {
    start_timer->stop();

    QList<Alarm> alarms = DatabaseManager::retrieveAlarms();
    if (alarms.isEmpty())
        return;

    alarms = sortAlarms(alarms);
    Alarm a = alarms.first();
    next_alarm = new Alarm(a);

    int mSecs = QTime::currentTime().msecsTo(next_alarm->data().time);
    //add a day if that time has already passed
    if (mSecs < 0)
        mSecs += QDateTime::currentDateTime().msecsTo(QDateTime::currentDateTime().addDays(1));
    start_timer->setInterval(mSecs);
    start_timer->start();
}

QList<Alarm> AlarmManager::sortAlarms(QList<Alarm> alarms) {
    std::sort(alarms.begin(), alarms.end(), [](Alarm a1, Alarm a2){
        int mSecs1 = QTime::currentTime().msecsTo(a1.data().time);
        if (mSecs1 < 0)
            mSecs1 += QDateTime::currentDateTime().msecsTo(QDateTime::currentDateTime().addDays(1));

        int mSecs2 = QTime::currentTime().msecsTo(a2.data().time);
        if (mSecs2 < 0)
            mSecs2 += QDateTime::currentDateTime().msecsTo(QDateTime::currentDateTime().addDays(1));

        return mSecs1 < mSecs2;
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
    init();
    emit alarmStop();
}
