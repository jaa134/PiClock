#ifndef SETTINGSMANAGER_H
#define SETTINGSMANAGER_H

#define HOURFORMAT12 "h:mmap"
#define HOURFORMAT24 "HH:mm"

#include "models/alarm.h"
#include "QList"
#include "QSettings"
#include "QString"

class SettingsManager
{
    friend class TestStub;

public:
    static void reset();

    static QString defaultClockTimeFormat();
    static QString clockTimeFormat();
    static void setClockTimeFormat(QString);

    static int defaultWidgetTransitionDuration();
    static int widgetTransitionDuration();
    static void setWidgetTransitionDuration(int);

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
