#ifndef DATABASEMANAGER_H
#define DATABASEMANAGER_H

#include "models/alarm.h"
#include "QObject"
#include "QtSql"
#include "QList"

class DatabaseManager : public QObject
{
    Q_OBJECT

    friend class TestStub;

public:
    static void initDb();
    static void addAlarm(Alarm);
    static void removeAlarm(Alarm);
    static void removeAlarms();
    static QList<Alarm> retrieveAlarms();

private:
    static void createDb();
    static QSqlQuery execQuery(QString);
};

#endif // DATABASEMANAGER_H
