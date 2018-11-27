#include "forecastwidget.h"
#include "ui_forecastwidget.h"

ForecastWidget::ForecastWidget(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::ForecastWidget)
{
    ui->setupUi(this);

    service = new ForecastWidgetService();
    service->moveToThread(&serviceThread);
    connect(service, &ForecastWidgetService::updated, this, &ForecastWidget::display);
    serviceThread.start();
    service->init();
}

ForecastWidget::~ForecastWidget()
{
    delete ui;
    serviceThread.quit();
    serviceThread.wait();
}

void ForecastWidget::display() {
    ui->dateLabel_1->setText(service->forecast[1].date);
    ui->dateLabel_2->setText(service->forecast[2].date);
    ui->dateLabel_3->setText(service->forecast[3].date);
    ui->dateLabel_4->setText(service->forecast[4].date);

    ui->dayIcon_1->load(service->forecast[1].type);
    ui->dayIcon_2->load(service->forecast[2].type);
    ui->dayIcon_3->load(service->forecast[3].type);
    ui->dayIcon_4->load(service->forecast[4].type);

    ui->highLabel_1->setText(service->forecast[1].high);
    ui->highLabel_2->setText(service->forecast[2].high);
    ui->highLabel_3->setText(service->forecast[3].high);
    ui->highLabel_4->setText(service->forecast[4].high);

    ui->lowLabel_1->setText(service->forecast[1].low);
    ui->lowLabel_2->setText(service->forecast[2].low);
    ui->lowLabel_3->setText(service->forecast[3].low);
    ui->lowLabel_4->setText(service->forecast[4].low);
}
