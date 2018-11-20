#ifndef ALARMTESTS_H
#define ALARMTESTS_H

#include "teststub.h"
#include "QObject"

class AlarmTests : public TestStub
{
    Q_OBJECT

public:
    virtual ~AlarmTests() {}

private slots:
    void setsExecutionTime();
    void setsGameType();
    void setsGameDifficulty();
};

#endif // ALARMTESTS_H
