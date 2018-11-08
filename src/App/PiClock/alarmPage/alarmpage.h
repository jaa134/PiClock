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
    QTimer *timer_clock;
    AlarmManager *alarm_manager;

signals:
    void chunkLoaded();

public slots:
    void onSettingsSaved();

private slots:
    void navToMain();
    void navToAlarm(Game::Type, Game::Difficulty);
    void onGameOver();
    void updatePointsLabel(int);
    void updateRemainingTime();

};

#endif // ALARMPAGE_H
