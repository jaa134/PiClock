#include "settingspage.h"
#include "managers/settingsmanager.h"
#include "managers/alarmmanager.h"
#include "QTime"
#include "QMetaEnum"

SettingsPage::SettingsPage(Ui::PiClockApp *ui) {
    this->ui = ui;
}

SettingsPage::~SettingsPage() {

}

void SettingsPage::init() {
    //main button
    ui->mainButton->setStyleSheet("border-image: url(:/images/back.png);");
    connect(ui->mainButton, SIGNAL(released()),this, SLOT(navToMain()));
    emit chunkLoaded();

    //label
    ui->settingsHeader->setStyleSheet("color: #fff");
    emit chunkLoaded();

    //options
    ui->options->setStyleSheet("QTabBar::tab { height: 35px; width: 120px; }");
    ui->options->setCurrentIndex(0);
    emit chunkLoaded();

    ui->slideDurationSlider->setTickPosition(QSlider::TicksBothSides);
    ui->slideDurationSlider->setTickInterval(2);
    ui->slideDurationSlider->setRange(2,30);
    connect(ui->slideDurationSlider, SIGNAL(valueChanged(int)), this, SLOT(showNewSlideDurationValue()));

    ui->alarmTimeEdit->setDisplayFormat(SettingsManager::clockTimeFormat());
    ui->alarmTimeEdit->setTime(QTime(8, 0));
    QMetaEnum gameType = QMetaEnum::fromType<Alarm::GameType>();
    for(int i = 0; i < gameType.keyCount(); i++)
        ui->alarmGameEdit->addItem(Alarm::gameTypeValue(Alarm::GameType(i)));
    QMetaEnum gameDifficulty = QMetaEnum::fromType<Alarm::GameDifficulty>();
    for(int i = 0; i < gameDifficulty.keyCount(); i++)
        ui->alarmDifficultyEdit->addItem(Alarm::gameDifficultyValue(Alarm::GameDifficulty(i)));
    connect(ui->alarmSetButton, SIGNAL(released()), this, SLOT(addAlarm()));

    //set ui values
    loadSettings();
    emit chunkLoaded();

    //buttons
    connect(ui->settingsCancelButton, SIGNAL(released()), this, SLOT(cancel()));
    connect(ui->settingsRestoreButton, SIGNAL(released()), this, SLOT(restore()));
    connect(ui->settingsSaveButton, SIGNAL(released()), this, SLOT(save()));
    emit chunkLoaded();
}

void SettingsPage::showNewSlideDurationValue() {
    int newVal = ui->slideDurationSlider->value();
    ui->slideDurationValueLabel->setText("(" + QString::number(newVal) + " seconds)");
}

void SettingsPage::addAlarm() {
    QTime time = ui->alarmTimeEdit->time();
    foreach (Alarm *a, alarms) {
        if (a->data().time == time)
            return;
    }

    Alarm::GameType type = Alarm::GameType(ui->alarmGameEdit->currentIndex());
    Alarm::GameDifficulty difficulty = Alarm::GameDifficulty(ui->alarmDifficultyEdit->currentIndex());
    alarms.append(new Alarm(time, type, difficulty));
    sortAlarms();
    updateAlarmList();
    ui->alarmTimeEdit->setTime(QTime(8, 0));
    ui->alarmGameEdit->setCurrentIndex(0);
    ui->alarmDifficultyEdit->setCurrentIndex(0);
}

void SettingsPage::sortAlarms() {
    std::sort(alarms.begin(), alarms.end(), [](Alarm *a1, Alarm *a2){
        return a1->data().time < a2->data().time;
    });
}

void SettingsPage::updateAlarmList() {
    while(ui->alarmList->count()>0)
        ui->alarmList->takeItem(0);
    QString timeFormat = SettingsManager::clockTimeFormat();
    foreach (Alarm *a, alarms) {
        QString time = a->data().time.toString(timeFormat);
        QString type = Alarm::gameTypeValue(a->data().type);
        ui->alarmList->addItem(time + " - " + type);
    }
}

void SettingsPage::loadSettings() {
    QString timeFormat = SettingsManager::clockTimeFormat();
    if (timeFormat == HOURFORMAT12)
        ui->clockTimeFormatOptions->setCurrentIndex(0);
    else if (timeFormat == HOURFORMAT24)
        ui->clockTimeFormatOptions->setCurrentIndex(1);
    else
        ui->clockTimeFormatOptions->setCurrentIndex(-1);

    ui->slideDurationSlider->setValue(SettingsManager::widgetTransitionDuration() / 1000);
    showNewSlideDurationValue();

    ui->alarmTimeEdit->setTime(QTime(8, 0));
    ui->alarmGameEdit->setCurrentIndex(0);
    ui->alarmDifficultyEdit->setCurrentIndex(0);

    foreach (Alarm *a, alarms)
        delete a;
    alarms = SettingsManager::alarms();
    sortAlarms();
    updateAlarmList();

    ui->weatherCheckbox->setChecked(SettingsManager::isWeatherEnabled());
    ui->forecastCheckbox->setChecked(SettingsManager::isForecastEnabled());
    ui->quotesCheckbox->setChecked(SettingsManager::isQuotesEnabled());
    ui->wclockCheckbox->setChecked(SettingsManager::isWorldClockEnabled());
    ui->holidaysCheckbox->setChecked(SettingsManager::isHolidayCountdownEnabled());
    ui->sysstatsCheckbox->setChecked(SettingsManager::isSystemStatsEnabled());
}

void SettingsPage::navToMain() {
    cancel();
    ui->layout->setCurrentIndex(1);
}

void SettingsPage::cancel() {
    setPageEnabled(false);
    loadSettings();
    setPageEnabled(true);
}

void SettingsPage::restore() {
    setPageEnabled(false);

    QString defaultClockTimeFormat = SettingsManager::defaultClockTimeFormat();
    if (defaultClockTimeFormat == HOURFORMAT12)
        ui->clockTimeFormatOptions->setCurrentIndex(0);
    else if (defaultClockTimeFormat == HOURFORMAT24)
        ui->clockTimeFormatOptions->setCurrentIndex(1);
    else
        ui->clockTimeFormatOptions->setCurrentIndex(-1);

    int defaultWidgetTransitionDuration = SettingsManager::defaultWidgetTransitionDuration();
    ui->slideDurationSlider->setValue(defaultWidgetTransitionDuration / 1000);

    foreach (Alarm *a, alarms)
        delete a;
    alarms = SettingsManager::defaultAlarms();
    sortAlarms();
    updateAlarmList();

    bool defaultIsWeatherEnabled = SettingsManager::defaultIsWeatherEnabled();
    ui->weatherCheckbox->setChecked(defaultIsWeatherEnabled);
    bool defaultIsForecastEnabled = SettingsManager::defaultIsForecastEnabled();
    ui->forecastCheckbox->setChecked(defaultIsForecastEnabled);
    bool defaultIsQuotesEnabled = SettingsManager::defaultIsQuotesEnabled();
    ui->quotesCheckbox->setChecked(defaultIsQuotesEnabled);
    bool defaultIsWorldClockEnabled = SettingsManager::defaultIsWorldClockEnabled();
    ui->wclockCheckbox->setChecked(defaultIsWorldClockEnabled);
    bool defaultIsHolidayCountdownEnabled = SettingsManager::defaultIsHolidayCountdownEnabled();
    ui->holidaysCheckbox->setChecked(defaultIsHolidayCountdownEnabled);
    bool defaultIsSystemStatsEnabled = SettingsManager::defaultIsSystemStatsEnabled();
    ui->sysstatsCheckbox->setChecked(defaultIsSystemStatsEnabled);

    setPageEnabled(true);
}

void SettingsPage::save() {
    setPageEnabled(false);

    if (ui->clockTimeFormatOptions->currentIndex() <= 0)
        SettingsManager::setClockTimeFormat(HOURFORMAT12);
    else if (ui->clockTimeFormatOptions->currentIndex() == 1)
        SettingsManager::setClockTimeFormat(HOURFORMAT24);

    SettingsManager::setWidgetTransitionDuration(ui->slideDurationSlider->value() * 1000);

    SettingsManager::setAlarms(alarms);

    SettingsManager::setIsWeatherEnabled(ui->weatherCheckbox->isChecked());
    SettingsManager::setIsForecastEnabled(ui->forecastCheckbox->isChecked());
    SettingsManager::setIsQuotesEnabled(ui->quotesCheckbox->isChecked());
    SettingsManager::setIsWorldClockEnabled(ui->wclockCheckbox->isChecked());
    SettingsManager::setIsHolidayCountdownEnabled(ui->holidaysCheckbox->isChecked());
    SettingsManager::setIsSystemStatsEnabled(ui->sysstatsCheckbox->isChecked());

    setPageEnabled(true);
}

void SettingsPage::setPageEnabled(bool isEnabled) {
    ui->options->setEnabled(isEnabled);
    ui->settingsCancelButton->setEnabled(isEnabled);
    ui->settingsRestoreButton->setEnabled(isEnabled);
    ui->settingsSaveButton->setEnabled(isEnabled);
}
