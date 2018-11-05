#ifndef PICLOCKAPP_H
#define PICLOCKAPP_H

#include "mainPage/mainpage.h"
#include "settingsPage/settingspage.h"
#include "alarmPage/alarmpage.h"
#include "QMainWindow"
#include "QString"

namespace Ui {
    class PiClockApp;
}

class PiClockApp : public QMainWindow
{
    Q_OBJECT

public:
    explicit PiClockApp(QWidget *parent = nullptr);
    ~PiClockApp();
    void init();

private:
    Ui::PiClockApp *ui;
    MainPage *mainPage;
    SettingsPage *settingsPage;
    AlarmPage *alarmPage;
    void initWindow();

signals:
    void loadFinished();

private slots:
    void updateProgressBar();
    void transitionToMainPage();

};

#endif // PICLOCKAPP_H
