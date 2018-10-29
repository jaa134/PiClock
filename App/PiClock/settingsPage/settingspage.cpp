#include "settingspage.h"
#include "settingsmanager.h"
#include "./mainPage/appclock.h"

SettingsPage::SettingsPage(Ui::PiClockApp *ui)
{
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

void SettingsPage::loadSettings() {
    QString timeFormat = SettingsManager::clockTimeFormat();
    if (timeFormat == AppClock::HourFormat_12)
        ui->clockTimeFormatOptions->setCurrentIndex(0);
    else if (timeFormat == AppClock::HourFormat_24)
        ui->clockTimeFormatOptions->setCurrentIndex(1);
    else
        ui->clockTimeFormatOptions->setCurrentIndex(-1);

    ui->slideDurationSlider->setValue(SettingsManager::widgetTransitionDuration() / 1000);
    showNewSlideDurationValue();

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
    loadSettings();
}

void SettingsPage::restore() {
    QString defaultClockTimeFormat = SettingsManager::defaultClockTimeFormat();
    if (defaultClockTimeFormat == AppClock::HourFormat_12)
        ui->clockTimeFormatOptions->setCurrentIndex(0);
    else if (defaultClockTimeFormat == AppClock::HourFormat_24)
        ui->clockTimeFormatOptions->setCurrentIndex(1);
    else
        ui->clockTimeFormatOptions->setCurrentIndex(-1);

    int defaultWidgetTransitionDuration = SettingsManager::defaultWidgetTransitionDuration();
    ui->slideDurationSlider->setValue(defaultWidgetTransitionDuration / 1000);

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

    save();
}

void SettingsPage::save() {
    if (ui->clockTimeFormatOptions->currentIndex() <= 0)
        SettingsManager::setClockTimeFormat(AppClock::HourFormat_12);
    else if (ui->clockTimeFormatOptions->currentIndex() == 1)
        SettingsManager::setClockTimeFormat(AppClock::HourFormat_24);

    SettingsManager::setWidgetTransitionDuration(ui->slideDurationSlider->value() * 1000);

    SettingsManager::setIsWeatherEnabled(ui->weatherCheckbox->isChecked());
    SettingsManager::setIsForecastEnabled(ui->forecastCheckbox->isChecked());
    SettingsManager::setIsQuotesEnabled(ui->quotesCheckbox->isChecked());
    SettingsManager::setIsWorldClockEnabled(ui->wclockCheckbox->isChecked());
    SettingsManager::setIsHolidayCountdownEnabled(ui->holidaysCheckbox->isChecked());
    SettingsManager::setIsSystemStatsEnabled(ui->sysstatsCheckbox->isChecked());
}
