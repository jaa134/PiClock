#include "alarmmanager.h"
#include "databasemanager.h"
#include "QDateTime"

#include "QDebug"

AlarmManager::AlarmManager()
{
    //creates a timer that triggers the alarm
    start_timer = new QTimer();
    start_timer->setSingleShot(true);
    connect(start_timer, SIGNAL(timeout()), this, SLOT(startAlarm()));

    //creates a timer that will stop the alarm
    stop_timer = new QTimer();
    stop_timer->setSingleShot(true);
    connect(stop_timer, SIGNAL(timeout()), this, SLOT(stopAlarm()));

    //set a sound effect for the alarm
    sound = new QSoundEffect();
    sound->setSource(QUrl("qrc:/sounds/alarm.wav"));
    sound->setLoopCount(QSoundEffect::Infinite);
    sound->setVolume(1.0);
}

void AlarmManager::init() {
    start_timer->stop();

    QList<Alarm> alarms = DatabaseManager::retrieveAlarms();
    if (alarms.isEmpty())
        return;

    //sort alarms in order of next to trigger
    //find the next to trigger
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
        //add a day if that time has already passed
        if (mSecs1 < 0)
            mSecs1 += QDateTime::currentDateTime().msecsTo(QDateTime::currentDateTime().addDays(1));

        int mSecs2 = QTime::currentTime().msecsTo(a2.data().time);
        //add a day if that time has already passed
        if (mSecs2 < 0)
            mSecs2 += QDateTime::currentDateTime().msecsTo(QDateTime::currentDateTime().addDays(1));

        return mSecs1 < mSecs2;
    });
    return alarms;
}

void AlarmManager::startAlarm() {
    sound->play();
    emit alarmStarted(next_alarm->data().type, next_alarm->data().difficulty);
    int minutes = 5;
    stop_timer->setInterval(minutes * 60000);
    stop_timer->start();
}

void AlarmManager::stopAlarm() {
    sound->stop();
    stop_timer->stop();
    init();
    emit alarmStopped();
}

QString AlarmManager::timeRemaining() {
    int mSecsRemaining = stop_timer->remainingTime();
    QTime time(0, 0);
    return time.addMSecs(mSecsRemaining).toString("m:ss");
}
