#include "systemstatisticswidget.h"
#include "ui_systemstatisticswidget.h"

SystemStatisticsWidget::SystemStatisticsWidget(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::SystemStatisticsWidget)
{
    ui->setupUi(this);

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
    ui->cpuBar->setValue(service->cpuUsage + 1);
    setWarningColor(ui->cpuBar);
    ui->ramBar->setValue(service->memoryUsage + 1);
    setWarningColor(ui->ramBar);
    ui->discBar->setValue(service->discUsage + 1);
    setWarningColor(ui->discBar);
    ui->networkBar->setValue(service->networkUsage + 1);
    setWarningColor(ui->networkBar);
    QApplication::processEvents();
}

void SystemStatisticsWidget::setWarningColor(QProgressBar *bar) {
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
