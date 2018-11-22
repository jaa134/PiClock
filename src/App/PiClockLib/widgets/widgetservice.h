#ifndef WIDGETSERVICE_H
#define WIDGETSERVICE_H

#include "QObject"

class WidgetService : public QObject
{
    Q_OBJECT

public:
    virtual ~WidgetService();
    virtual void update() {}
};

#endif // WIDGETSERVICE_H
