#include "weatherwidget.h"
#include "ui_weatherwidget.h"

WeatherWidget::WeatherWidget(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::WeatherWidget)
{
    ui->setupUi(this);

    //timer to update widget
    service = new WeatherWidgetService();
    service->moveToThread(&serviceThread);
    connect(service, &WeatherWidgetService::updated, this, &WeatherWidget::display);
    serviceThread.start();
    service->init();
}

WeatherWidget::~WeatherWidget()
{
    delete ui;
    serviceThread.quit();
    serviceThread.wait();
}

void WeatherWidget::display() {
    //show information in the ui
    ui->weatherIconContainer->load(service->weather.type);
    ui->degreeValue->setText(service->weather.currentTemp);
    ui->locationValue->setText(service->weather.location + ", " + service->weather.region);
    ui->precipitationValue->setText(service->weather.precipitation + " in");
    ui->humidityValue->setText(service->weather.humidity + "%");
    ui->windValue->setText(service->weather.windSpeed + " mph " + service->weather.windDirection);
    ui->cloudCoverValue->setText(service->weather.cloudCoverage + "%");
    ui->visibilityValue->setText(service->weather.visibility + " mi");
}
