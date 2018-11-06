#ifndef ALARMLISTITEM_H
#define ALARMLISTITEM_H

#include "models/alarm.h"
#include "QWidget"
#include "QPushButton"

namespace Ui {
class AlarmListItem;
}

class AlarmListItem : public QWidget
{
    Q_OBJECT

public:
    explicit AlarmListItem(QWidget *parent = nullptr);
    ~AlarmListItem();
    void makeAlarm(QTime, Game::Type, Game::Difficulty, QString);
    void saveAlarm();
    Alarm *a;

private:
    Ui::AlarmListItem *ui;

signals:
    void removeClicked(AlarmListItem *);

private slots:
    void onRemoveClicked();

};

#endif // ALARMLISTITEM_H
