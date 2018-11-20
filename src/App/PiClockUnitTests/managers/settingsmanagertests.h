#ifndef SETTINGSMANAGERTESTS_H
#define SETTINGSMANAGERTESTS_H

#include "teststub.h"
#include "QObject"

class SettingsManagerTests : public TestStub
{
    Q_OBJECT

public:
    virtual ~SettingsManagerTests() {}

private slots:
    void init();
    void cleanup();

    void defaultClockTimeFormat();
    void clockTimeFormat();

    void defaultWidgetTransitionDuration();
    void widgetTransitionDuration();

    void defaultIsWeatherEnabled();
    void defaultIsForecastEnabled();
    void defaultIsQuotesEnabled();
    void defaultIsWorldClockEnabled();
    void defaultIsHolidayCountdownEnabled();
    void defaultIsSystemStatsEnabled();
    void isWeatherEnabled();
    void isForecastEnabled();
    void isQuotesEnabled();
    void isWorldClockEnabled();
    void isHolidayCountdownEnabled();
    void isSystemStatsEnabled();
};

#endif // SETTINGSMANAGERTESTS_H
