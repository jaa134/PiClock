#ifndef TICTACTOEGAMESERVICETESTS_H
#define TICTACTOEGAMESERVICETESTS_H

#include "teststub.h"

class TicTacToeGameServiceTests : public TestStub
{
    Q_OBJECT

public:
    virtual ~TicTacToeGameServiceTests() {}

private slots:
    void init();
    void cleanup();
};

#endif // TICTACTOEGAMESERVICETESTS_H
