#include "worldclockwidget.h"
#include "ui_worldclockwidget.h"

WorldClockWidget::WorldClockWidget(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::WorldClockWidget)
{
    ui->setupUi(this);

    service = new WorldClockWidgetService();
    service->moveToThread(&serviceThread);
    connect(service, &WorldClockWidgetService::updated, this, &WorldClockWidget::display);
    serviceThread.start();
    service->init();
}

WorldClockWidget::~WorldClockWidget()
{
    delete ui;
    serviceThread.quit();
    serviceThread.wait();
}

void WorldClockWidget::display() {
    ui->city0->setText(service->cities[0].name);
    ui->city1->setText(service->cities[1].name);
    ui->city2->setText(service->cities[2].name);
    ui->city3->setText(service->cities[3].name);
    ui->city4->setText(service->cities[4].name);
    ui->city5->setText(service->cities[5].name);

    ui->val0->setText(service->cities[0].time);
    ui->val1->setText(service->cities[1].time);
    ui->val2->setText(service->cities[2].time);
    ui->val3->setText(service->cities[3].time);
    ui->val4->setText(service->cities[4].time);
    ui->val5->setText(service->cities[5].time);
}
