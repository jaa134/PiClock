#include "worldclockwidget.h"
#include "ui_worldclockwidget.h"

WorldClockWidget::WorldClockWidget(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::WorldClockWidget)
{
    ui->setupUi(this);
}

WorldClockWidget::~WorldClockWidget()
{
    delete ui;
}
