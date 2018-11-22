#ifndef WIDGETSERVICE_H
#define WIDGETSERVICE_H

#include "QObject"
#include "QTimer"

class WidgetService : public QObject
{
    Q_OBJECT

public:
    virtual ~WidgetService() {}
    virtual void init() {}
    virtual void update() {}

signals:
    void updated();

protected:
    QTimer updateTimer;
};

#endif // WIDGETSERVICE_H
