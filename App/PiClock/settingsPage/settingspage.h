#ifndef SETTINGSPAGE_H
#define SETTINGSPAGE_H

#include "ui_piclockapp.h"
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
    QList<Alarm *> alarms;
    void loadSettings();
    void sortAlarms();
    void updateAlarmList();
    void setPageEnabled(bool);

signals:
    void chunkLoaded();

private slots:
    void showNewSlideDurationValue();
    void addAlarm();
    void navToMain();
    void cancel();
    void restore();
    void save();

};

#endif // SETTINGSPAGE_H
