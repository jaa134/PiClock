#include "systemstatisticswidget.h"
#include "ui_systemstatisticswidget.h"

SystemStatisticsWidget::SystemStatisticsWidget(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::SystemStatisticsWidget)
{
    ui->setupUi(this);
}

SystemStatisticsWidget::~SystemStatisticsWidget()
{
    delete ui;
}
