#ifndef SETTINGSMANAGER_H
#define SETTINGSMANAGER_H

#include "alarmPage/alarm.h"
#include "QList"
#include "QSettings"
#include "QString"

class SettingsManager
{

public:
    static QString defaultClockTimeFormat();
    static QString clockTimeFormat();
    static void setClockTimeFormat(QString);

    static int defaultWidgetTransitionDuration();
    static int widgetTransitionDuration();
    static void setWidgetTransitionDuration(int);

    static QList<Alarm *> defaultAlarms();
    static QList<Alarm *> alarms();
    static void setAlarms(QList<Alarm *>);

    static bool defaultIsWeatherEnabled();
    static bool defaultIsForecastEnabled();
    static bool defaultIsQuotesEnabled();
    static bool defaultIsWorldClockEnabled();
    static bool defaultIsHolidayCountdownEnabled();
    static bool defaultIsSystemStatsEnabled();
    static bool isWeatherEnabled();
    static bool isForecastEnabled();
    static bool isQuotesEnabled();
    static bool isWorldClockEnabled();
    static bool isHolidayCountdownEnabled();
    static bool isSystemStatsEnabled();
    static void setIsWeatherEnabled(bool);
    static void setIsForecastEnabled(bool);
    static void setIsQuotesEnabled(bool);
    static void setIsWorldClockEnabled(bool);
    static void setIsHolidayCountdownEnabled(bool);
    static void setIsSystemStatsEnabled(bool);

};

#endif // SETTINGSMANAGER_H
