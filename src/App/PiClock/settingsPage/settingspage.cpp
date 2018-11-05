#include "settingspage.h"
#include "managers/settingsmanager.h"
#include "managers/alarmmanager.h"
#include "managers/databasemanager.h"
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

    ui->alarmList->setVerticalScrollMode(QAbstractItemView::ScrollPerPixel);
    ui->alarmList->setHorizontalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
    ui->alarmList->setVerticalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
    ui->alarmTimeEdit->setDisplayFormat(SettingsManager::clockTimeFormat());
    ui->alarmTimeEdit->setTime(QTime(8, 0));
    QMetaEnum gameType = QMetaEnum::fromType<Game::Type>();
    for(int i = 0; i < gameType.keyCount(); i++)
        ui->alarmGameEdit->addItem(Game::gameTypeValue(Game::Type(i)));
    QMetaEnum gameDifficulty = QMetaEnum::fromType<Game::Difficulty>();
    for(int i = 0; i < gameDifficulty.keyCount(); i++)
        ui->alarmDifficultyEdit->addItem(Game::gameDifficultyValue(Game::Difficulty(i)));
    connect(ui->alarmSetButton, SIGNAL(released()), this, SLOT(setAlarm()));
    //set ui values
    loadSettings();
    emit chunkLoaded();

    //buttons
    connect(ui->settingsCancelButton, SIGNAL(released()), this, SLOT(cancel()));
    connect(ui->settingsSaveButton, SIGNAL(released()), this, SLOT(save()));
    emit chunkLoaded();
}

void SettingsPage::showNewSlideDurationValue() {
    int newVal = ui->slideDurationSlider->value();
    ui->slideDurationValueLabel->setText("(" + QString::number(newVal) + " seconds)");
}

void SettingsPage::setAlarm() {
    QTime time = ui->alarmTimeEdit->time();
    for (int i = 0; i < ui->alarmList->count(); i++) {
        QListWidgetItem *itemAtRow = ui->alarmList->item(i);
        QWidget *currentWidget = ui->alarmList->itemWidget(itemAtRow);
        if (static_cast<AlarmListItem *>(currentWidget)->a->data().time == time)
            return;
    }

    Game::Type type = Game::Type(ui->alarmGameEdit->currentIndex());
    Game::Difficulty difficulty = Game::Difficulty(ui->alarmDifficultyEdit->currentIndex());
    addAlarm(time, type, difficulty);
    ui->alarmTimeEdit->setTime(QTime(8, 0));
    ui->alarmGameEdit->setCurrentIndex(0);
    ui->alarmDifficultyEdit->setCurrentIndex(0);
}

void SettingsPage::addAlarm(QTime time, Game::Type type, Game::Difficulty difficulty) {
    AlarmListItem *widget = new AlarmListItem();
    widget->makeAlarm(time, type, difficulty);
    widget->setFixedSize(350, 60);

    QListWidgetItem *item = new QListWidgetItem(ui->alarmList);
    item->setSizeHint(QSize(350, 60));
    item->setText(time.toString());
    item->setTextColor(Qt::transparent);

    ui->alarmList->addItem(item);
    ui->alarmList->setItemWidget(item, widget);
    ui->alarmList->sortItems();

    connect(widget, SIGNAL(removeClicked(AlarmListItem *)), this, SLOT(removeAlarm(AlarmListItem *)));
}

void SettingsPage::removeAlarm(AlarmListItem *widget) {
    for (int i = 0; i < ui->alarmList->count(); i++) {
        QListWidgetItem *itemAtRow = ui->alarmList->item(i);
        QWidget *currentWidget = ui->alarmList->itemWidget(itemAtRow);
        if (currentWidget == widget) {
            ui->alarmList->removeItemWidget(itemAtRow);
            delete ui->alarmList->takeItem(i);
            return;
        }
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

    QList<Alarm> alarms = DatabaseManager::retrieveAlarms();
    QListWidgetItem *item;
    while((item = ui->alarmList->takeItem(0)) != nullptr)
        delete item;
    foreach (Alarm a, alarms)
        addAlarm(a.data().time, a.data().type, a.data().difficulty);

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

void SettingsPage::save() {
    setPageEnabled(false);

    if (ui->clockTimeFormatOptions->currentIndex() <= 0)
        SettingsManager::setClockTimeFormat(HOURFORMAT12);
    else if (ui->clockTimeFormatOptions->currentIndex() == 1)
        SettingsManager::setClockTimeFormat(HOURFORMAT24);

    SettingsManager::setWidgetTransitionDuration(ui->slideDurationSlider->value() * 1000);

    DatabaseManager::removeAlarms();
    int numAlarmsToSave = ui->alarmList->count();
    for(int i = 0; i < numAlarmsToSave; i++) {
        QListWidgetItem* item = ui->alarmList->item(i);
        AlarmListItem *widget = static_cast<AlarmListItem*>(ui->alarmList->itemWidget(item));
        DatabaseManager::addAlarm(*widget->a);
    }

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
    ui->settingsSaveButton->setEnabled(isEnabled);
}
