#include "holidaycountdownwidget.h"
#include "ui_holidaycountdownwidget.h"

HolidayCountdownWidget::HolidayCountdownWidget(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::HolidayCountdownWidget)
{
    ui->setupUi(this);
}

HolidayCountdownWidget::~HolidayCountdownWidget()
{
    delete ui;
}
