#ifndef SETTINGSPAGE_H
#define SETTINGSPAGE_H

#include "ui_piclockapp.h"
#include "alarmlistitem.h"
#include "models/alarm.h"
#include "QObject"
#include "QList"

class SettingsPage : public QObject
{
    Q_OBJECT

public:
    SettingsPage(Ui::PiClockApp *ui);
    ~SettingsPage();
    void init();

private:
    Ui::PiClockApp *ui;
    QString timeFormat;
    void loadSettings();
    void setPageEnabled(bool);

signals:
    void chunkLoaded();
    void settingsSaved();

private slots:
    void showNewSlideDurationValue();
    void setAlarm();
    void addAlarm(QTime, Game::Type, Game::Difficulty);
    void removeAlarm(AlarmListItem *);
    void navToMain();
    void cancel();
    void save();

};

#endif // SETTINGSPAGE_H
