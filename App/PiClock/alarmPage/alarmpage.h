#ifndef ALARMPAGE_H
#define ALARMPAGE_H

#include "ui_piclockapp.h"
#include "alarmmanager.h"
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

private slots:
    void navToMain();
    void navToAlarm();

};

#endif // ALARMPAGE_H
