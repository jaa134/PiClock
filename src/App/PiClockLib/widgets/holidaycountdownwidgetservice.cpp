#include "holidaycountdownwidgetservice.h"

#define DATEFORMAT "M_d_yyyy"

HolidayCountdownWidgetService::HolidayCountdownWidgetService()
{
    int secsPerMin = 3600;
    connect(&updateTimer, &QTimer::timeout, this, &HolidayCountdownWidgetService::update);
    updateTimer.setInterval(1000 * secsPerMin);
}

void HolidayCountdownWidgetService::init() {
    update();
    updateTimer.start();
}

void HolidayCountdownWidgetService::update() {
    QFile f(":/json/holidays.json");
    f.open(QIODevice::ReadOnly);
    QString s = f.readAll();
    QJsonDocument jsonResponse = QJsonDocument::fromJson(s.toUtf8());
    QJsonObject jsonObject = jsonResponse.object();
    QStringList keys = jsonObject.keys();
    f.close();

    QList<QDate> dates;
    QDate currentDate = QDate::currentDate();
    foreach (QString dateStr, keys) {
        QDate date = QDate::fromString(dateStr, DATEFORMAT);
        if (date >= currentDate)
            dates.append(date);
    }
    std::sort(dates.begin(), dates.end());

    if (dates.isEmpty())
        return;

    holiday.date = dates.first();
    holiday.name = jsonObject[dates.first().toString(DATEFORMAT)].toString();

    emit updated();
}
