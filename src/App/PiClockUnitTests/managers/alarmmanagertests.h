#ifndef ALARMMANAGERTESTS_H
#define ALARMMANAGERTESTS_H

#include "teststub.h"
#include "QObject"

class AlarmManagerTests : public TestStub
{
    Q_OBJECT

public:
    virtual ~AlarmManagerTests() {}

private slots:
    void Test();
};

#endif // ALARMMANAGERTESTS_H
