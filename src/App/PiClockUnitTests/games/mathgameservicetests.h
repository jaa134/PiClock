#ifndef MATHGAMESERVICETESTS_H
#define MATHGAMESERVICETESTS_H

#include "teststub.h"

class MathGameServiceTests : public TestStub
{
    Q_OBJECT

public:
    virtual ~MathGameServiceTests() {}

private slots:
    void init();
    void cleanup();
};

#endif // MATHGAMESERVICETESTS_H
