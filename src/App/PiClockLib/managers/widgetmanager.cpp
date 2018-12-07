#include "widgetmanager.h"
#include "settingsmanager.h"

#define NW 0
#define WEATHER 1
#define FORECAST 2
#define QUOTES 3
#define WCLOCK 4
#define HOLIDAYS 5
#define SYSSTATS 6
#define COMMUTE 7
#define NEWS 8

WidgetManager::WidgetManager() {}

WidgetManager::~WidgetManager() {}

void WidgetManager::start() {    
    //find whic widgets are enabled
    if (SettingsManager::isWeatherEnabled())
        enabled_widget_indexes.enqueue(WEATHER);
    if (SettingsManager::isForecastEnabled())
        enabled_widget_indexes.enqueue(FORECAST);
    if (SettingsManager::isQuotesEnabled())
        enabled_widget_indexes.enqueue(QUOTES);
    if (SettingsManager::isWorldClockEnabled())
        enabled_widget_indexes.enqueue(WCLOCK);
    if (SettingsManager::isHolidayCountdownEnabled())
        enabled_widget_indexes.enqueue(HOLIDAYS);
    if (SettingsManager::isSystemStatsEnabled())
        enabled_widget_indexes.enqueue(SYSSTATS);
    if (SettingsManager::isCommuteEnabled())
        enabled_widget_indexes.enqueue(COMMUTE);
    if (SettingsManager::isNewsEnabled())
        enabled_widget_indexes.enqueue(NEWS);

    //add in a no widgets slide if needed
    if (enabled_widget_indexes.size() == 0)
        enabled_widget_indexes.enqueue(NW);

    //create a timer that will transition between slides
    nextSlide();
    update_timer = new QTimer(this);
    update_timer->setInterval(SettingsManager::widgetTransitionDuration());
    connect(update_timer, SIGNAL(timeout()), this, SLOT(nextSlide()));
    update_timer->start();
}

void WidgetManager::nextSlide() {
    int slide_index;

    //find the next slide to show by using a circle queue
    slide_index = enabled_widget_indexes.dequeue();
    enabled_widget_indexes.enqueue(slide_index);
    emit changeWidgetSlide(slide_index);
}

void WidgetManager::stop() {
    update_timer->stop();
}
