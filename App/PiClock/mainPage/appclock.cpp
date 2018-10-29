#include "appclock.h"
#include "settingsmanager.h"
#include "QTime"
#include "QDate"

AppClock::AppClock() {}

AppClock::~AppClock() {}

QString AppClock::HourFormat_12 = "h:mmap";
QString AppClock::HourFormat_24 = "HH:mm";

void AppClock::start() {
    time_format = new QString(SettingsManager::clockTimeFormat());

    updateDateTime();
    update_timer = new QTimer(this);
    update_timer->setInterval(1000);
    connect(update_timer, SIGNAL(timeout()), this, SLOT(updateDateTime()));
    update_timer->start();
}

void AppClock::updateDateTime() {
    QDate current_date = QDate::currentDate();
    QString date_text = current_date.toString("ddd, MMM d");

    QTime current_time = QTime::currentTime();
    QString time_text = current_time.toString(time_format->constData());

    emit changeDateTime(date_text, time_text);
}

void AppClock::stop() {
    update_timer->stop();
}
