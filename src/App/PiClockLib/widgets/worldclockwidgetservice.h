#ifndef WORLDCLOCKWIDGETSERVICE_H
#define WORLDCLOCKWIDGETSERVICE_H

#include "widgetservice.h"
#include "QTime"
#include "QString"

class WorldClockWidgetService : public WidgetService
{
    Q_OBJECT

public:
    struct City {
        QString time;
        QString name;
    };

    City cities[6];
    WorldClockWidgetService();
    void init() Q_DECL_OVERRIDE;

private slots:
    void update() Q_DECL_OVERRIDE;
};

#endif // WORLDCLOCKWIDGETSERVICE_H
