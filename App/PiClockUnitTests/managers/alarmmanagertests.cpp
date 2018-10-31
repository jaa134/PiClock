#include "alarmmanagertests.h"
#include "QTest"
#include "managers/alarmmanager.h"
#include "managers/settingsmanager.h"
#include "models/alarm.h"

void AlarmManagerTests::nextAlarmSetCorrectly() {
    SettingsManager::reset();
    AlarmManager *m = new AlarmManager();
    int offset = 10;
    QTime current = QTime::currentTime();
    Alarm *a = new Alarm(current.addSecs(offset), Alarm::GameType::Math, Alarm::GameDifficulty::Hard);
    SettingsManager::setAlarms(QList<Alarm *>({ a }));
    m->init();
    //QVERIFY2(m->nextAlarm()->data().time == a->data().time, "Alarm was not registered at the correct time");
    delete m;
    delete a;
}

void AlarmManagerTests::startTimerSetCorrectly() {
    SettingsManager::reset();
    AlarmManager *m = new AlarmManager();
    int offset = 10;
    QTime current = QTime::currentTime();
    Alarm *a = new Alarm(current.addSecs(offset), Alarm::GameType::Math, Alarm::GameDifficulty::Hard);
    SettingsManager::setAlarms(QList<Alarm *>({ a }));
    m->init();
    //QVERIFY2(m->stopTimer()->interval() == (5 * 60000), "Alarm should not repeat");
    delete m;
    delete a;
}

void AlarmManagerTests::stopTimerSetCorrectly() {
    SettingsManager::reset();
    AlarmManager *m = new AlarmManager();
    int offset = 10;
    QTime current = QTime::currentTime();
    Alarm *a = new Alarm(current.addSecs(offset), Alarm::GameType::Math, Alarm::GameDifficulty::Hard);
    SettingsManager::setAlarms(QList<Alarm *>({ a }));
    m->init();
    //QVERIFY2(m->stopTimer()->interval() == (5 * 60000), "Alarm should not repeat");
    delete m;
    delete a;
}
