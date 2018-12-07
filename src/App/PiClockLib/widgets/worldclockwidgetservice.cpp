#include "worldclockwidgetservice.h"
#include "managers/settingsmanager.h"

#define DUB (+4)
#define UTC (0)
#define EST (-5)
#define PST (-8)
#define CCT (+8)
#define MST (-7)
#define TOK (+9)

WorldClockWidgetService::WorldClockWidgetService() {
    //set the name of each city
    cities[0].name = "Los Angeles";
    cities[1].name = "New York City";
    cities[2].name = "Beijing";
    cities[3].name = "London";
    cities[4].name = "Tokyo";
    cities[5].name = "Dubai";

    //setup a timer for updating the ui
    connect(&updateTimer, &QTimer::timeout, this, &WorldClockWidgetService::update);
    updateTimer.setInterval(1000);
}

void WorldClockWidgetService::init() {
    update();
    updateTimer.start();
}

void WorldClockWidgetService::update() {
    //find the time format
    QString format = SettingsManager::clockTimeFormat();
    QTime current = QDateTime::currentDateTimeUtc().time();

    int secsInHour = 3600;
    //set the time formatted for each city
    cities[0].time = current.addSecs(PST * secsInHour).toString(format);
    cities[1].time = current.addSecs(EST * secsInHour).toString(format);
    cities[2].time = current.addSecs(CCT * secsInHour).toString(format);
    cities[3].time = current.addSecs(UTC * secsInHour).toString(format);
    cities[4].time = current.addSecs(TOK * secsInHour).toString(format);
    cities[5].time = current.addSecs(DUB * secsInHour).toString(format);

    emit updated();
}
