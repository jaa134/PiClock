#ifndef HOLIDAYCOUNTDOWNWIDGETSERVICE_H
#define HOLIDAYCOUNTDOWNWIDGETSERVICE_H

#include "widgetservice.h"
#include "QTime"
#include "QString"
#include "QFile"
#include "QJsonDocument"
#include "QJsonObject"
#include "QJsonArray"
#include "QTextStream"

class HolidayCountdownWidgetService : public WidgetService
{
    Q_OBJECT

public:
    struct Holiday {
        QDate date;
        QString name;
    };

    Holiday holiday;
    HolidayCountdownWidgetService();
    void init() Q_DECL_OVERRIDE;

private slots:
    void update() Q_DECL_OVERRIDE;
};

#endif // HOLIDAYCOUNTDOWNWIDGETSERVICE_H
