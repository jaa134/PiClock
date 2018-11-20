#include "databasemanagertests.h"
#include "QTime"
#include "QList"
#include "QTest"

void DatabaseManagerTests::initTestCase() {
    DatabaseManager::initDb();
}

void DatabaseManagerTests::cleanup() {

}

void DatabaseManagerTests::addAlarm() {
    Alarm a = Alarm(QTime::currentTime(), Game::Type::Math, Game::Hard);
    DatabaseManager::addAlarm(a);
    QList<Alarm> list = DatabaseManager::retrieveAlarms();
    QVERIFY2(list.size() == 1, "List should contain one alarm");
}

void DatabaseManagerTests::removeAlarm() {
    Alarm a = Alarm(QTime::currentTime(), Game::Type::Math, Game::Hard);
    DatabaseManager::addAlarm(a);
    DatabaseManager::removeAlarm(a);
    QList<Alarm> list = DatabaseManager::retrieveAlarms();
    QVERIFY2(list.size() == 0, "List should contain zero alarms");
}

void DatabaseManagerTests::removeAlarms() {
    Alarm a = Alarm(QTime::currentTime(), Game::Type::Math, Game::Hard);
    DatabaseManager::addAlarm(a);
    DatabaseManager::addAlarm(a);
    DatabaseManager::addAlarm(a);
    QList<Alarm> list = DatabaseManager::retrieveAlarms();
    QVERIFY2(list.size() == 3, "List should contain three alarms");
    DatabaseManager::removeAlarms();
    list = DatabaseManager::retrieveAlarms();
    QVERIFY2(list.size() == 0, "List should contain zero alarms");
}

void DatabaseManagerTests::retrieveAlarms() {
    Alarm a = Alarm(QTime::currentTime(), Game::Type::Math, Game::Hard);
    DatabaseManager::addAlarm(a);
    DatabaseManager::addAlarm(a);
    DatabaseManager::addAlarm(a);
    DatabaseManager::addAlarm(a);
    DatabaseManager::addAlarm(a);
    QList<Alarm> list = DatabaseManager::retrieveAlarms();
    QVERIFY2(list.size() == 5, "List should contain five alarms");
}
