#ifndef WIDGETMANAGERTESTS_H
#define WIDGETMANAGERTESTS_H

#include "teststub.h"
#include "QObject"

class WidgetManagerTests : public TestStub
{
    Q_OBJECT

public:
    virtual ~WidgetManagerTests() {}

private slots:
    void startSetsEnabledIndexesCorrectly();
    void startStartsTransitionTimer();

};

#endif // WIDGETMANAGERTESTS_H
