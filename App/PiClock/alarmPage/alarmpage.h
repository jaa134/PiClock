#ifndef ALARMPAGE_H
#define ALARMPAGE_H

#include "ui_piclockapp.h"
#include "managers/alarmmanager.h"
#include "QObject"

class AlarmPage : public QObject
{
    Q_OBJECT

public:
    AlarmPage(Ui::PiClockApp *ui);
    void init();

private:
    Ui::PiClockApp *ui;
    AlarmManager *alarm_manager;

signals:
    void chunkLoaded();

private slots:
    void navToMain();
    void navToAlarm();

};

#endif // ALARMPAGE_H
