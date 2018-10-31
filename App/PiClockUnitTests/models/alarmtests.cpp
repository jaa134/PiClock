#include "alarmtests.h"
#include "QTest"
#include "models/alarm.h"

void AlarmTests::setsExecutionTime() {
    QTime time = QTime::currentTime();
    Alarm::GameType type = Alarm::GameType::Math;
    Alarm::GameDifficulty difficulty = Alarm::GameDifficulty::Hard;
    Alarm *a = new Alarm(time, type, difficulty);
    QVERIFY2(a->data().time == time, "Execution time not set correctly: Alarm(QTime, GameType, GameDifficulty)");
    delete a;

    Alarm::Data data = Alarm::Data();
    data.time = time;
    data.type = type;
    data.difficulty = difficulty;
    a = new Alarm(data);
    QVERIFY2(a->data().time == time, "Execution time not set correctly: Alarm(Data)");
    delete a;
}

void AlarmTests::setsGameType() {
    QTime time = QTime::currentTime();
    Alarm::GameType type = Alarm::GameType::Math;
    Alarm::GameDifficulty difficulty = Alarm::GameDifficulty::Hard;
    Alarm *a = new Alarm(time, type, difficulty);
    QVERIFY2(a->data().type == type, "Game type not set correctly: Alarm(QTime, GameType, GameDifficulty)");
    delete a;

    Alarm::Data data = Alarm::Data();
    data.time = time;
    data.type = type;
    data.difficulty = difficulty;
    a = new Alarm(data);
    QVERIFY2(a->data().type == type, "Game type not set correctly: Alarm(Data)");
    delete a;
}

void AlarmTests::setsGameDifficulty() {
    QTime time = QTime::currentTime();
    Alarm::GameType type = Alarm::GameType::Math;
    Alarm::GameDifficulty difficulty = Alarm::GameDifficulty::Hard;
    Alarm *a = new Alarm(time, type, difficulty);
    QVERIFY2(a->data().difficulty == difficulty, "Game difficulty not set correctly: Alarm(QTime, GameType, GameDifficulty)");
    delete a;

    Alarm::Data data = Alarm::Data();
    data.time = time;
    data.type = type;
    data.difficulty = difficulty;
    a = new Alarm(data);
    QVERIFY2(a->data().difficulty == difficulty, "Game difficulty not set correctly: Alarm(Data)");
    delete a;
}
