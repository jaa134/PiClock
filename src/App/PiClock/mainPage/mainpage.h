#ifndef MAINPAGE_H
#define MAINPAGE_H

#include "ui_piclockapp.h"
#include "appclock.h"
#include "managers/widgetmanager.h"
#include "QObject"
#include "QThread"
#include "QString"

class MainPage : public QObject
{
    Q_OBJECT

public:
    MainPage(Ui::PiClockApp *ui);
    ~MainPage();
    void init();

private:
    Ui::PiClockApp *ui;
    AppClock *app_clock;
    QThread clock_thread;
    WidgetManager *widget_manager;
    QThread widget_thread;
    void initSettingsButton();
    void initClock();
    void initWidgetSlideshow();

signals:
    void chunkLoaded();
    void startClock();
    void stopClock();
    void startWidgetManager();
    void stopWidgetManager();

private slots:
    void navToSettings();
    void changeWidgetSlide(int);
    void changeDateTime(QString, QString);
};

#endif // MAINPAGE_H
