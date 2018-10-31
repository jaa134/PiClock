#ifndef WIDGETMANAGERTESTS_H
#define WIDGETMANAGERTESTS_H

#include "QObject"

class WidgetManagerTests : public QObject
{
    Q_OBJECT

private slots:
    void startSetsEnabledIndexesCorrectly();
    void startStartsTransitionTimer();

};

#endif // WIDGETMANAGERTESTS_H
