#include "settingsmanagertests.h"
#include "QTest"
#include "managers/settingsmanager.h"
#include "QString"

void SettingsManagerTests::init() {
    SettingsManager::reset();
}

void SettingsManagerTests::cleanup() {

}


void SettingsManagerTests::defaultClockTimeFormat() {
    QVERIFY2(SettingsManager::defaultClockTimeFormat() == HOURFORMAT12, "Default not set incorrectly");
}

void SettingsManagerTests::clockTimeFormat() {
    QString def = SettingsManager::defaultClockTimeFormat();
    QString actual = SettingsManager::clockTimeFormat();
    QString expected = HOURFORMAT24;
    QVERIFY2(actual == def, "Default value not being used when no previous value set");
    SettingsManager::setClockTimeFormat(expected);
    actual = SettingsManager::clockTimeFormat();
    QVERIFY2(actual == expected, "Retrieved value is incorrect");
}


void SettingsManagerTests::defaultWidgetTransitionDuration() {
    QVERIFY2(SettingsManager::defaultWidgetTransitionDuration() == 10000, "Default not set incorrectly");
}

void SettingsManagerTests::widgetTransitionDuration() {
    int def = SettingsManager::defaultWidgetTransitionDuration();
    int actual = SettingsManager::widgetTransitionDuration();
    int expected = 30000;
    QVERIFY2(actual == def, "Default value not being used when no previous value set");
    SettingsManager::setWidgetTransitionDuration(expected);
    actual = SettingsManager::widgetTransitionDuration();
    QVERIFY2(actual == expected, "Retrieved value is incorrect");
}


void SettingsManagerTests::defaultAlarms() {
    QVERIFY2(SettingsManager::defaultAlarms().isEmpty() == true, "Default not set incorrectly");
}

void SettingsManagerTests::alarms() {
    QList<Alarm *> def = SettingsManager::defaultAlarms();
    QList<Alarm *> actual = SettingsManager::alarms();
    QList<Alarm *> expected = QList<Alarm *>({ new Alarm(QTime::currentTime(), Alarm::GameType::Math, Alarm::GameDifficulty::Hard) });
    QVERIFY2(actual.length() == def.length(), "Default value not being used when no previous value set");
    SettingsManager::setAlarms(expected);
    actual = SettingsManager::alarms();
    QVERIFY2(actual.length() == expected.length(), "Retrieved value is incorrect");
    Alarm::Data a_data = actual.first()->data();
    Alarm::Data e_data = expected.first()->data();
    QVERIFY2(a_data.time == e_data.time && a_data.type == e_data.type && a_data.difficulty == e_data.difficulty, "");
}


void SettingsManagerTests::defaultIsWeatherEnabled() {
    QVERIFY2(SettingsManager::defaultIsWeatherEnabled() == true, "Default not set incorrectly");
}

void SettingsManagerTests::defaultIsForecastEnabled() {
    QVERIFY2(SettingsManager::defaultIsForecastEnabled() == true, "Default not set incorrectly");
}

void SettingsManagerTests::defaultIsQuotesEnabled() {
    QVERIFY2(SettingsManager::defaultIsQuotesEnabled() == true, "Default not set incorrectly");
}

void SettingsManagerTests::defaultIsWorldClockEnabled() {
    QVERIFY2(SettingsManager::defaultIsWorldClockEnabled() == true, "Default not set incorrectly");
}

void SettingsManagerTests::defaultIsHolidayCountdownEnabled() {
    QVERIFY2(SettingsManager::defaultIsHolidayCountdownEnabled() == true, "Default not set incorrectly");
}

void SettingsManagerTests::defaultIsSystemStatsEnabled() {
    QVERIFY2(SettingsManager::defaultIsSystemStatsEnabled() == true, "Default not set incorrectly");
}

void SettingsManagerTests::isWeatherEnabled() {
    bool def = SettingsManager::defaultIsWeatherEnabled();
    bool actual = SettingsManager::isWeatherEnabled();
    bool expected = 30000;
    QVERIFY2(actual == def, "Default value not being used when no previous value set");
    SettingsManager::setIsWeatherEnabled(expected);
    actual = SettingsManager::isWeatherEnabled();
    QVERIFY2(actual == expected, "Retrieved value is incorrect");
}

void SettingsManagerTests::isForecastEnabled() {
    bool def = SettingsManager::defaultIsForecastEnabled();
    bool actual = SettingsManager::isForecastEnabled();
    bool expected = 30000;
    QVERIFY2(actual == def, "Default value not being used when no previous value set");
    SettingsManager::setIsForecastEnabled(expected);
    actual = SettingsManager::isForecastEnabled();
    QVERIFY2(actual == expected, "Retrieved value is incorrect");
}

void SettingsManagerTests::isQuotesEnabled() {
    bool def = SettingsManager::defaultIsQuotesEnabled();
    bool actual = SettingsManager::isQuotesEnabled();
    bool expected = 30000;
    QVERIFY2(actual == def, "Default value not being used when no previous value set");
    SettingsManager::setIsQuotesEnabled(expected);
    actual = SettingsManager::isQuotesEnabled();
    QVERIFY2(actual == expected, "Retrieved value is incorrect");
}

void SettingsManagerTests::isWorldClockEnabled() {
    bool def = SettingsManager::defaultIsWorldClockEnabled();
    bool actual = SettingsManager::isWorldClockEnabled();
    bool expected = 30000;
    QVERIFY2(actual == def, "Default value not being used when no previous value set");
    SettingsManager::setIsWorldClockEnabled(expected);
    actual = SettingsManager::isWorldClockEnabled();
    QVERIFY2(actual == expected, "Retrieved value is incorrect");
}

void SettingsManagerTests::isHolidayCountdownEnabled() {
    bool def = SettingsManager::defaultIsHolidayCountdownEnabled();
    bool actual = SettingsManager::isHolidayCountdownEnabled();
    bool expected = 30000;
    QVERIFY2(actual == def, "Default value not being used when no previous value set");
    SettingsManager::setIsHolidayCountdownEnabled(expected);
    actual = SettingsManager::isHolidayCountdownEnabled();
    QVERIFY2(actual == expected, "Retrieved value is incorrect");
}

void SettingsManagerTests::isSystemStatsEnabled() {
    bool def = SettingsManager::defaultIsSystemStatsEnabled();
    bool actual = SettingsManager::isSystemStatsEnabled();
    bool expected = 30000;
    QVERIFY2(actual == def, "Default value not being used when no previous value set");
    SettingsManager::setIsSystemStatsEnabled(expected);
    actual = SettingsManager::isSystemStatsEnabled();
    QVERIFY2(actual == expected, "Retrieved value is incorrect");
}
