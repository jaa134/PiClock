#include "mainpage.h"
#include "weatherwidget.h"
#include "forecastwidget.h"
#include "quoteswidget.h"
#include "worldclockwidget.h"
#include "holidaycountdownwidget.h"
#include "systemstatisticswidget.h"
#include "commutewidget.h"

MainPage::MainPage(Ui::PiClockApp *ui)
{
    this->ui = ui;
    app_clock = new AppClock();
    widget_manager = new WidgetManager();
}

MainPage::~MainPage() {
    emit stopClock();
    clock_thread.quit();
    clock_thread.wait();

    emit stopWidgetManager();
    widget_thread.quit();
    widget_thread.wait();

    delete widget_manager;
}

void MainPage::init() {
    //setting button
    ui->settingsButton->setStyleSheet("border-image: url(:/images/settings.png);");
    connect(ui->settingsButton, SIGNAL(released()), this, SLOT(navToSettings()));
    emit chunkLoaded();

    //clock
    ui->clock->setStyleSheet("color: #fff");
    app_clock->moveToThread(&clock_thread);
    connect(this, SIGNAL(stopClock()), app_clock, SLOT(stop()));
    connect(this, SIGNAL(startClock()), app_clock, SLOT(start()));
    connect(app_clock, SIGNAL(changeDateTime(QString, QString)), this, SLOT(changeDateTime(QString, QString)));
    clock_thread.start();
    emit startClock();
    emit chunkLoaded();

    //slideshow
    ui->widgetSlideshow->addWidget(new WeatherWidget());
    ui->widgetSlideshow->addWidget(new ForecastWidget());
    ui->widgetSlideshow->addWidget(new QuotesWidget());
    ui->widgetSlideshow->addWidget(new WorldClockWidget());
    ui->widgetSlideshow->addWidget(new HolidayCountdownWidget());
    ui->widgetSlideshow->addWidget(new SystemStatisticsWidget());
    ui->widgetSlideshow->addWidget(new CommuteWidget());
    widget_manager->moveToThread(&widget_thread);
    connect(this, SIGNAL(stopWidgetManager()), widget_manager, SLOT(stop()));
    connect(this, SIGNAL(startWidgetManager()), widget_manager, SLOT(start()));
    connect(widget_manager, SIGNAL(changeWidgetSlide(int)), this, SLOT(changeWidgetSlide(int)));
    widget_thread.start();
    emit startWidgetManager();
    emit chunkLoaded();
}

void MainPage::navToSettings() {
    ui->layout->setCurrentIndex(2);
}

void MainPage::changeWidgetSlide(int slide_index) {
    ui->widgetSlideshow->setCurrentIndex(slide_index);
}

void MainPage::changeDateTime(QString date, QString time) {
    ui->date->setText(date);
    ui->time->setText(time);
}

