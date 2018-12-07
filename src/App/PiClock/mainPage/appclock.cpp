#include "appclock.h"
#include "managers/settingsmanager.h"
#include "QTime"
#include "QDate"

AppClock::AppClock() {}

AppClock::~AppClock() {}

void AppClock::start() {
    time_format = new QString(SettingsManager::clockTimeFormat());

    //create a timer that will update the ui at an interval
    updateDateTime();
    update_timer = new QTimer(this);
    update_timer->setInterval(1000);
    connect(update_timer, SIGNAL(timeout()), this, SLOT(updateDateTime()));
    update_timer->start();
}

void AppClock::updateDateTime() {
    //find the formatted date
    QDate current_date = QDate::currentDate();
    QString date_text = current_date.toString("ddd, MMM d");

    //find the formatted time
    QTime current_time = QTime::currentTime();
    QString time_text = current_time.toString(time_format->constData());

    emit changeDateTime(date_text, time_text);
}

void AppClock::stop() {
    update_timer->stop();
}
