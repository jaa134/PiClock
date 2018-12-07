#include "systemstatisticswidget.h"
#include "ui_systemstatisticswidget.h"

SystemStatisticsWidget::SystemStatisticsWidget(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::SystemStatisticsWidget)
{
    ui->setupUi(this);

    //timer to update widget
    service = new SystemStatisticsWidgetService();
    service->moveToThread(&serviceThread);
    connect(service, &SystemStatisticsWidgetService::updated, this, &SystemStatisticsWidget::display);
    serviceThread.start();
    service->init();
}

SystemStatisticsWidget::~SystemStatisticsWidget()
{
    delete ui;
    serviceThread.quit();
    serviceThread.wait();
}

void SystemStatisticsWidget::display() {
    //show information in the ui
    int baseVal = 5;
    ui->cpuBar->setValue(service->cpuUsage + baseVal);
    setWarningColor(ui->cpuBar);
    ui->ramBar->setValue(service->memoryUsage + baseVal);
    setWarningColor(ui->ramBar);
    ui->discBar->setValue(service->discUsage + baseVal);
    setWarningColor(ui->discBar);
    ui->networkBar->setValue(service->networkUsage + baseVal);
    setWarningColor(ui->networkBar);
    QApplication::processEvents();
}

void SystemStatisticsWidget::setWarningColor(QProgressBar *bar) {
    //warning colors are in order of green, yellow, orange, red

    QString barStyle = "QProgressBar { border-radius: 5px; }";
    QString chunkColor = "";

    if (bar->value() < 0.25 * bar->maximum())
        chunkColor = "#77dd77";
    else if (bar->value() < 0.50 * bar->maximum())
        chunkColor = "#fcfc50";
    else if (bar->value() < 0.75 * bar->maximum())
        chunkColor = "#ffb347";
    else
        chunkColor = "#fb3232";

    bar->setStyleSheet(barStyle + " QProgressBar::chunk { border-radius: 5px; background-color: " + chunkColor + "; }");
}
