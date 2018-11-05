#include "alarmlistitem.h"
#include "ui_alarmlistitem.h"
#include "managers/databasemanager.h"
#include "managers/settingsmanager.h"

AlarmListItem::AlarmListItem(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::AlarmListItem)
{
    ui->setupUi(this);
    connect(ui->removeButton, SIGNAL(released()), this, SLOT(onRemoveClicked()));
}

AlarmListItem::~AlarmListItem()
{
    delete a;
    delete ui;
}

void AlarmListItem::makeAlarm(QTime time, Game::Type type, Game::Difficulty difficulty) {
    this->a = new Alarm(time, type, difficulty);
    QString timeFormat = SettingsManager::clockTimeFormat();
    ui->label->setText(time.toString(timeFormat) + "  " + Game::gameTypeValue(type));
}

void AlarmListItem::onRemoveClicked() {
    emit removeClicked(this);
}
