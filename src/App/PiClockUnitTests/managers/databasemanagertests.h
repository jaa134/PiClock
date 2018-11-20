#ifndef DATABASEMANAGERTESTS_H
#define DATABASEMANAGERTESTS_H

#include "teststub.h"
#include "managers/databasemanager.h"

class DatabaseManagerTests : public TestStub
{
    Q_OBJECT

public:
    virtual ~DatabaseManagerTests() {}

private:
    DatabaseManager *dbManager;

private slots:
    void initTestCase();
    void cleanup();

    void addAlarm();
    void removeAlarm();
    void removeAlarms();
    void retrieveAlarms();
};

#endif // DATABASEMANAGERTESTS_H
