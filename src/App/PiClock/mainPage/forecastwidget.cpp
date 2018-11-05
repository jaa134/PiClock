#include "forecastwidget.h"
#include "ui_forecastwidget.h"

ForecastWidget::ForecastWidget(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::ForecastWidget)
{
    ui->setupUi(this);
}

ForecastWidget::~ForecastWidget()
{
    delete ui;
}
