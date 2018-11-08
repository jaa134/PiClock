#include "databasemanager.h"
#include "models/game.h"
#include "QTime"
#include "QDebug"
#include "QFileInfo"

#define CONNECTION "PiClock"

void DatabaseManager::initDb() {
    QSqlDatabase db = QSqlDatabase::addDatabase("QSQLITE", CONNECTION);
    QString dbPath = QCoreApplication::applicationDirPath() + "/../../db/PiClock.db";
    db.setDatabaseName(dbPath);

    if (db.tables().isEmpty())
        createDb();
}

QSqlQuery DatabaseManager::execQuery(QString content) {
    QSqlQuery query(QSqlDatabase::database(CONNECTION));
    if (!query.exec(content)) {
        qDebug() << "ERROR: Query failed to execute...";
        qDebug() << "Last executed query: " + query.lastQuery();
        QSqlDatabase db = QSqlDatabase::database(CONNECTION);

        QString queryText = query.lastError().text();
        if (!queryText.isEmpty())
            qDebug() << "Query text: " + queryText;
        QString dbText = db.driver()->lastError().databaseText();
        if (!dbText.isEmpty())
            qDebug() << "Database text: " + dbText;
        QString driverText = db.driver()->lastError().driverText();
        if (!driverText.isEmpty())
            qDebug() << "Diver text: " + driverText;
    }

    return query;
}

void DatabaseManager::createDb() {
    QString query = ""
                    "CREATE TABLE 'Alarm' ("
                    "'Time' TEXT NOT NULL,"
                    "'Type' INTEGER NOT NULL,"
                    "'Difficulty' INTEGER NOT NULL"
                    ");";
    execQuery(query);
}

void DatabaseManager::addAlarm(Alarm a) {
    QString query = QString("INSERT INTO Alarm VALUES('%1', %2, %3)")
        .arg(a.data().time.toString())
        .arg(static_cast<int>(a.data().type))
        .arg(static_cast<int>(a.data().difficulty));
    execQuery(query);
}

void  DatabaseManager::removeAlarm(Alarm a) {
    QString query = QString("DELETE FROM Alarm WHERE Time = '%1' AND Type = %2 AND Difficulty = %3")
        .arg(a.data().time.toString())
        .arg(static_cast<int>(a.data().type))
        .arg(static_cast<int>(a.data().difficulty));
    execQuery(query);
}

void  DatabaseManager::removeAlarms() {
    QString query = QString("DELETE FROM Alarm");
    execQuery(query);
}

QList<Alarm> DatabaseManager::retrieveAlarms() {
    QString query = QString("SELECT * FROM Alarm");
    QSqlQuery result = execQuery(query);
    QList<Alarm> alarms = QList<Alarm>();
    while (result.next()) {
        QTime time = QTime::fromString(result.value("Time").toString());
        Game::Type type = Game::Type(result.value("Type").toInt());
        Game::Difficulty difficulty = Game::Difficulty(result.value("Difficulty").toInt());
        alarms.append(Alarm(time, type, difficulty));
    }
    return alarms;
}
