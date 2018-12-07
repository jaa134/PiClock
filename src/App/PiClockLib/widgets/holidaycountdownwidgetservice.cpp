#include "holidaycountdownwidgetservice.h"

#define DATEFORMAT "M_d_yyyy"

HolidayCountdownWidgetService::HolidayCountdownWidgetService()
{
    //create an update timer
    int secsPerMin = 3600;
    connect(&updateTimer, &QTimer::timeout, this, &HolidayCountdownWidgetService::update);
    updateTimer.setInterval(1000 * secsPerMin);
}

void HolidayCountdownWidgetService::init() {
    update();
    updateTimer.start();
}

void HolidayCountdownWidgetService::update() {
    //read all holidays in from file
    QFile f(":/json/holidays.json");
    f.open(QIODevice::ReadOnly);
    QString s = f.readAll();
    QJsonDocument jsonResponse = QJsonDocument::fromJson(s.toUtf8());
    QJsonObject jsonObject = jsonResponse.object();
    QStringList keys = jsonObject.keys();
    f.close();

    //sort the dates that havent already passed
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

    //grab the next upcoming holiday to use
    holiday.date = dates.first();
    holiday.name = jsonObject[dates.first().toString(DATEFORMAT)].toString();

    emit updated();
}
