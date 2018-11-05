#include "settingsmanager.h"

#define COMPANY "393Team"
#define PRODUCT "PiClock"

#define GENERAL_KEY "tabgeneral"
#define CLOCKTIME_KEY "clocktime"
#define SLIDE_KEY "slide"

#define ALARM_KEY "alarm"

#define WIDGETS_KEY "tabwidgets"
#define WEATHER_KEY "weather"
#define FORECAST_KEY "forecast"
#define QUOTES_KEY "quotes"
#define WCLOCK_KEY "wclock"
#define HOLIDAYS_KEY "holidays"
#define SYSSTATS_KEY "sysstats"

void SettingsManager::reset() {
    QSettings settings(COMPANY, PRODUCT);
    settings.clear();
}


QString SettingsManager::defaultClockTimeFormat() {
    return HOURFORMAT12;
}

QString SettingsManager::clockTimeFormat() {
    QSettings settings(COMPANY, PRODUCT);
    QString key("");
    key += GENERAL_KEY "/" CLOCKTIME_KEY "/format";
    return settings.value(key, defaultClockTimeFormat()).toString();
}

void SettingsManager::setClockTimeFormat(QString format) {
    QSettings settings(COMPANY, PRODUCT);
    QString key("");
    key += GENERAL_KEY "/" CLOCKTIME_KEY "/format";
    settings.setValue(key, format);
}


int SettingsManager::defaultWidgetTransitionDuration() {
    return 10000;
}

int SettingsManager::widgetTransitionDuration() {
    QSettings settings(COMPANY, PRODUCT);
    QString key("");
    key += GENERAL_KEY "/" SLIDE_KEY "/duration";
    return settings.value(key, defaultWidgetTransitionDuration()).toInt();
}

void SettingsManager::setWidgetTransitionDuration(int duration) {
    QSettings settings(COMPANY, PRODUCT);
    QString key("");
    key += GENERAL_KEY "/" SLIDE_KEY "/duration";
    settings.setValue(key, duration);
}


bool SettingsManager::defaultIsWeatherEnabled() {
    return true;
}

bool SettingsManager::defaultIsForecastEnabled() {
    return true;
}

bool SettingsManager::defaultIsQuotesEnabled() {
    return true;
}

bool SettingsManager::defaultIsWorldClockEnabled() {
    return true;
}

bool SettingsManager::defaultIsHolidayCountdownEnabled() {
    return true;
}

bool SettingsManager::defaultIsSystemStatsEnabled() {
    return true;
}

bool SettingsManager::isWeatherEnabled() {
    QSettings settings(COMPANY, PRODUCT);
    QString key("");
    key += WIDGETS_KEY "/" WEATHER_KEY "/isEnabled";
    return settings.value(key, defaultIsWeatherEnabled()).toBool();
}

bool SettingsManager::isForecastEnabled() {
    QSettings settings(COMPANY, PRODUCT);
    QString key("");
    key += WIDGETS_KEY "/" FORECAST_KEY "/isEnabled";
    return settings.value(key, defaultIsForecastEnabled()).toBool();
}

bool SettingsManager::isQuotesEnabled() {
    QSettings settings(COMPANY, PRODUCT);
    QString key("");
    key += WIDGETS_KEY "/" QUOTES_KEY "/isEnabled";
    return settings.value(key, defaultIsQuotesEnabled()).toBool();
}

bool SettingsManager::isWorldClockEnabled() {
    QSettings settings(COMPANY, PRODUCT);
    QString key("");
    key += WIDGETS_KEY "/" WCLOCK_KEY "/isEnabled";
    return settings.value(key, defaultIsWorldClockEnabled()).toBool();
}

bool SettingsManager::isHolidayCountdownEnabled() {
    QSettings settings(COMPANY, PRODUCT);
    QString key("");
    key += WIDGETS_KEY "/" HOLIDAYS_KEY "/isEnabled";
    return settings.value(key, defaultIsHolidayCountdownEnabled()).toBool();
}

bool SettingsManager::isSystemStatsEnabled() {
    QSettings settings(COMPANY, PRODUCT);
    QString key("");
    key += WIDGETS_KEY "/" SYSSTATS_KEY "/isEnabled";
    return settings.value(key, defaultIsSystemStatsEnabled()).toBool();
}

void SettingsManager::setIsWeatherEnabled(bool isEnabled) {
    QSettings settings(COMPANY, PRODUCT);
    QString key("");
    key += WIDGETS_KEY "/" WEATHER_KEY "/isEnabled";
    settings.setValue(key, isEnabled);
}

void SettingsManager::setIsForecastEnabled(bool isEnabled) {
    QSettings settings(COMPANY, PRODUCT);
    QString key("");
    key += WIDGETS_KEY "/" FORECAST_KEY "/isEnabled";
    settings.setValue(key, isEnabled);
}

void SettingsManager::setIsQuotesEnabled(bool isEnabled) {
    QSettings settings(COMPANY, PRODUCT);
    QString key("");
    key += WIDGETS_KEY "/" QUOTES_KEY "/isEnabled";
    settings.setValue(key, isEnabled);
}

void SettingsManager::setIsWorldClockEnabled(bool isEnabled) {
    QSettings settings(COMPANY, PRODUCT);
    QString key("");
    key += WIDGETS_KEY "/" WCLOCK_KEY "/isEnabled";
    settings.setValue(key, isEnabled);
}

void SettingsManager::setIsHolidayCountdownEnabled(bool isEnabled) {
    QSettings settings(COMPANY, PRODUCT);
    QString key("");
    key += WIDGETS_KEY "/" HOLIDAYS_KEY "/isEnabled";
    settings.setValue(key, isEnabled);
}

void SettingsManager::setIsSystemStatsEnabled(bool isEnabled) {
    QSettings settings(COMPANY, PRODUCT);
    QString key("");
    key += WIDGETS_KEY "/" SYSSTATS_KEY "/isEnabled";
    settings.setValue(key, isEnabled);
}
