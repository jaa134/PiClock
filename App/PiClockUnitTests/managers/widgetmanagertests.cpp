#include "widgetmanagertests.h"
#include "QTest"
#include "managers/widgetmanager.h"
#include "managers/settingsmanager.h"

void WidgetManagerTests::startSetsEnabledIndexesCorrectly() {
    SettingsManager::reset();
    WidgetManager *m = new WidgetManager();
    m->start();
    int numWidgets = 6;
    QVERIFY2(m->enabledWidgetIndexes().length() == numWidgets, "Number of enabled widgets incorrect");
    delete m;

    SettingsManager::setIsWeatherEnabled(false);
    SettingsManager::setIsForecastEnabled(false);
    SettingsManager::setIsQuotesEnabled(false);
    SettingsManager::setIsWorldClockEnabled(false);
    SettingsManager::setIsHolidayCountdownEnabled(false);
    SettingsManager::setIsSystemStatsEnabled(false);
    m = new WidgetManager();
    m->start();
    numWidgets = 1;
    QVERIFY2(m->enabledWidgetIndexes().length() == numWidgets, "Number of enabled widgets incorrect");
    delete m;
}

void WidgetManagerTests::startStartsTransitionTimer() {
    SettingsManager::reset();
    WidgetManager *m = new WidgetManager();
    m->start();
    //QVERIFY2(m->updateTimer()->interval() == SettingsManager::widgetTransitionDuration(), "Interval for timer set incorrectly");
    delete m;
}
