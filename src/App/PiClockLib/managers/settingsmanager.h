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
    static bool defaultIsCommuteEnabled();
    static bool defaultIsNewsEnabled();
    static bool isWeatherEnabled();
    static bool isForecastEnabled();
    static bool isQuotesEnabled();
    static bool isWorldClockEnabled();
    static bool isHolidayCountdownEnabled();
    static bool isSystemStatsEnabled();
    static bool isCommuteEnabled();
    static bool isNewsEnabled();
    static void setIsWeatherEnabled(bool);
    static void setIsForecastEnabled(bool);
    static void setIsQuotesEnabled(bool);
    static void setIsWorldClockEnabled(bool);
    static void setIsHolidayCountdownEnabled(bool);
    static void setIsSystemStatsEnabled(bool);
    static void setIsCommuteEnabled(bool);
    static void setIsNewsEnabled(bool);

    static QString defaultWeatherApiKey();
    static QString weatherApiKey();
    static void setWeatherApiKey(QString);
    static QString defaultWeatherLocation();
    static QString weatherLocation();
    static void setWeatherLocation(QString);

    static QString defaultCommuteApiKey();
    static QString commuteApiKey();
    static void setCommuteApiKey(QString);
    static QString defaultCommuteStartLongitude();
    static QString defaultCommuteStartLatitude();
    static QString defaultCommuteEndLongitude();
    static QString defaultCommuteEndLatitude();
    static QString commuteStartLongitude();
    static QString commuteStartLatitude();
    static QString commuteEndLongitude();
    static QString commuteEndLatitude();
    static void setCommuteStartLongitude(QString);
    static void setCommuteStartLatitude(QString);
    static void setCommuteEndLongitude(QString);
    static void setCommuteEndLatitude(QString);

    static QString defaultNewsApiKey();
    static QString newsApiKey();
    static void setNewsApiKey(QString);
};

#endif // SETTINGSMANAGER_H
