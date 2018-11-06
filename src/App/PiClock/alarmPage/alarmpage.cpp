#include "alarmpage.h"

AlarmPage::AlarmPage(Ui::PiClockApp *ui) {
    this->ui = ui;
    alarm_manager = new AlarmManager();
}

void AlarmPage::init() {
    connect(alarm_manager, SIGNAL(alarmStop()), this, SLOT(navToMain()));
    connect(alarm_manager, SIGNAL(alarmStart()), this, SLOT(navToAlarm()));
    alarm_manager->init();
    emit chunkLoaded();
}

void AlarmPage::onSettingsSaved() {
    alarm_manager->init();
}

void AlarmPage::navToMain() {
    ui->layout->setCurrentIndex(1);
}

void AlarmPage::navToAlarm() {
    ui->layout->setCurrentIndex(3);
}
