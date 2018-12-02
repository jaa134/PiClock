#include "settingsmanager.h"

#define COMPANY "393Team"
#define PRODUCT "PiClock"

#define GENERAL_KEY "tabgeneral"
#define WIDGETS_KEY "tabwidgets"

void SettingsManager::reset() {
    QSettings settings(COMPANY, PRODUCT);
    settings.clear();
}

#define CLOCK_SECTION_START {

#define CLOCKTIME_KEY "clocktime"
#define SLIDE_KEY "slide"

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

#define CLOCK_SECTION_END }

#define WIDGETTRANSITION_SECTION_START {

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

#define WIDGETTRANSITION_SECTION_END }

#define WIDGETENABLED_SECTION_START {

#define WEATHER_KEY "weather"
#define FORECAST_KEY "forecast"
#define QUOTES_KEY "quotes"
#define WCLOCK_KEY "wclock"
#define HOLIDAYS_KEY "holidays"
#define SYSSTATS_KEY "sysstats"
#define COMMUTE_KEY "commute"
#define NEWS_KEY "news"

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

bool SettingsManager::defaultIsCommuteEnabled() {
    return true;
}

bool SettingsManager::defaultIsNewsEnabled() {
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

bool SettingsManager::isCommuteEnabled() {
    QSettings settings(COMPANY, PRODUCT);
    QString key("");
    key += WIDGETS_KEY "/" COMMUTE_KEY "/isEnabled";
    return settings.value(key, defaultIsCommuteEnabled()).toBool();
}

bool SettingsManager::isNewsEnabled() {
    QSettings settings(COMPANY, PRODUCT);
    QString key("");
    key += WIDGETS_KEY "/" NEWS_KEY "/isEnabled";
    return settings.value(key, defaultIsNewsEnabled()).toBool();
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

void SettingsManager::setIsCommuteEnabled(bool isEnabled) {
    QSettings settings(COMPANY, PRODUCT);
    QString key("");
    key += WIDGETS_KEY "/" COMMUTE_KEY "/isEnabled";
    settings.setValue(key, isEnabled);
}

void SettingsManager::setIsNewsEnabled(bool isEnabled) {
    QSettings settings(COMPANY, PRODUCT);
    QString key("");
    key += WIDGETS_KEY "/" NEWS_KEY "/isEnabled";
    settings.setValue(key, isEnabled);
}

#define WIDGETENABLED_SECTION_END }

#define WIDGETAPI_SECTION_START {

#define WEATHER_API "weatherAPI"
#define WEATHER_LOCATION "weatherLocation"
#define COMMUTE_API "commuteAPI"
#define COMMUTE_START_LONG "commuteStartLong"
#define COMMUTE_START_LAT "commuteStartLat"
#define COMMUTE_END_LONG "commuteEndLong"
#define COMMUTE_END_LAT "commuteEndLat"
#define NEWS_API "newsAPI"


QString SettingsManager::defaultWeatherApiKey() {
    return "c7e7a336a66244cd81641549180911";
}

QString SettingsManager::weatherApiKey() {
    QSettings settings(COMPANY, PRODUCT);
    QString key("");
    key += WIDGETS_KEY "/" WEATHER_API;
    return settings.value(key, defaultWeatherApiKey()).toString();
}

void SettingsManager::setWeatherApiKey(QString apiKey) {
    QSettings settings(COMPANY, PRODUCT);
    QString key("");
    key += WIDGETS_KEY "/" WEATHER_API;
    settings.setValue(key, apiKey);
}

QString SettingsManager::defaultWeatherLocation() {
    return "44101";
}

QString SettingsManager::weatherLocation() {
    QSettings settings(COMPANY, PRODUCT);
    QString key("");
    key += WIDGETS_KEY "/" WEATHER_LOCATION;
    return settings.value(key, defaultWeatherLocation()).toString();
}

void SettingsManager::setWeatherLocation(QString location) {
    QSettings settings(COMPANY, PRODUCT);
    QString key("");
    key += WIDGETS_KEY "/" WEATHER_LOCATION;
    settings.setValue(key, location);
}


QString SettingsManager::defaultCommuteApiKey() {
    return "AoqKK9JbiMuCDMht8ZrRUajildqZDGNZlSe-omiay7n3x7k13Pnxz_WI_pucpASD";
}

QString SettingsManager::commuteApiKey() {
    QSettings settings(COMPANY, PRODUCT);
    QString key("");
    key += WIDGETS_KEY "/" COMMUTE_API;
    return settings.value(key, defaultCommuteApiKey()).toString();
}

void SettingsManager::setCommuteApiKey(QString apiKey) {
    QSettings settings(COMPANY, PRODUCT);
    QString key("");
    key += WIDGETS_KEY "/" COMMUTE_API;
    settings.setValue(key, apiKey);
}

QString SettingsManager::defaultCommuteStartLongitude() {
    return "41.499803183159976";
}

QString SettingsManager::defaultCommuteStartLatitude() {
    return "-81.59453630447389";
}

QString SettingsManager::defaultCommuteEndLongitude() {
    return "41.46306273702346";
}

QString SettingsManager::defaultCommuteEndLatitude() {
    return "-81.9564950466156";
}

QString SettingsManager::commuteStartLongitude() {
    QSettings settings(COMPANY, PRODUCT);
    QString key("");
    key += WIDGETS_KEY "/" COMMUTE_START_LONG;
    return settings.value(key, defaultCommuteStartLongitude()).toString();
}

QString SettingsManager::commuteStartLatitude() {
    QSettings settings(COMPANY, PRODUCT);
    QString key("");
    key += WIDGETS_KEY "/" COMMUTE_START_LAT;
    return settings.value(key, defaultCommuteStartLatitude()).toString();
}

QString SettingsManager::commuteEndLongitude() {
    QSettings settings(COMPANY, PRODUCT);
    QString key("");
    key += WIDGETS_KEY "/" COMMUTE_END_LONG;
    return settings.value(key, defaultCommuteEndLongitude()).toString();
}

QString SettingsManager::commuteEndLatitude() {
    QSettings settings(COMPANY, PRODUCT);
    QString key("");
    key += WIDGETS_KEY "/" COMMUTE_END_LAT;
    return settings.value(key, defaultCommuteEndLatitude()).toString();
}

void SettingsManager::setCommuteStartLongitude(QString apiKey) {
    QSettings settings(COMPANY, PRODUCT);
    QString key("");
    key += WIDGETS_KEY "/" COMMUTE_START_LONG;
    settings.setValue(key, apiKey);
}

void SettingsManager::setCommuteStartLatitude(QString apiKey) {
    QSettings settings(COMPANY, PRODUCT);
    QString key("");
    key += WIDGETS_KEY "/" COMMUTE_START_LAT;
    settings.setValue(key, apiKey);
}

void SettingsManager::setCommuteEndLongitude(QString apiKey) {
    QSettings settings(COMPANY, PRODUCT);
    QString key("");
    key += WIDGETS_KEY "/" COMMUTE_END_LONG;
    settings.setValue(key, apiKey);
}

void SettingsManager::setCommuteEndLatitude(QString apiKey) {
    QSettings settings(COMPANY, PRODUCT);
    QString key("");
    key += WIDGETS_KEY "/" COMMUTE_END_LAT;
    settings.setValue(key, apiKey);
}


QString SettingsManager::defaultNewsApiKey() {
    return "40d29d4a15e44563afdf0826bc61b64f";
}

QString SettingsManager::newsApiKey() {
    QSettings settings(COMPANY, PRODUCT);
    QString key("");
    key += WIDGETS_KEY "/" NEWS_API;
    return settings.value(key, defaultNewsApiKey()).toString();
}

void SettingsManager::setNewsApiKey(QString apiKey) {
    QSettings settings(COMPANY, PRODUCT);
    QString key("");
    key += WIDGETS_KEY "/" NEWS_API;
    settings.setValue(key, apiKey);
}

#define WIDGETAPI_SECTION_END }
