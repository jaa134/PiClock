#ifndef SETTINGSPAGE_H
#define SETTINGSPAGE_H

#include "ui_piclockapp.h"
#include <QObject>

class SettingsPage : public QObject
{
    Q_OBJECT

public:
    SettingsPage(Ui::PiClockApp *ui);
    ~SettingsPage();
    void init();

private:
    Ui::PiClockApp *ui;
    void loadSettings();

signals:
    void chunkLoaded();

private slots:
    void showNewSlideDurationValue();
    void navToMain();
    void cancel();
    void restore();
    void save();

};

#endif // SETTINGSPAGE_H
