#ifndef TESTSTUB_H
#define TESTSTUB_H

#include "QObject"

//Framing class intended to give private member access
class TestStub : public QObject
{
    Q_OBJECT

public:
    TestStub() {}
    virtual ~TestStub() {}
};

#endif // TESTSTUB_H
