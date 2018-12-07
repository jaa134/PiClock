#include "holidaycountdownwidget.h"
#include "ui_holidaycountdownwidget.h"

HolidayCountdownWidget::HolidayCountdownWidget(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::HolidayCountdownWidget)
{
    ui->setupUi(this);

    //timer to update widget
    service = new HolidayCountdownWidgetService();
    service->moveToThread(&serviceThread);
    connect(service, &HolidayCountdownWidgetService::updated, this, &HolidayCountdownWidget::display);
    serviceThread.start();
    service->init();
}

HolidayCountdownWidget::~HolidayCountdownWidget()
{
    delete ui;
    serviceThread.quit();
    serviceThread.wait();
}

#include "QDebug"

void HolidayCountdownWidget::display() {
    //show information in the ui
    QString numDaysUntil = QString::number(QDate::currentDate().daysTo(service->holiday.date));
    QString contentLeft = ""
              "<p align=\"center\" style=\"color: #fff;\">"
                  "<span style=\"font-size: 260px;\">"
                      "<strong>" + numDaysUntil + "</strong>"
                  "</span>"
              "</p>";
    ui->numberText->setHtml(contentLeft);

    QString name = service->holiday.name;
    QString contentRight = ""
              "<p align=\"center\" style=\"color: #fff;\">"
                  "<span style=\"font-size: 60px;\">"
                       "<p align=\"center\">"
                           "<span style=\"font-size: 40px;\">days until</span>"
                       "</p>"
                       "<p align=\"center\">"
                           "<span style=\"font-size: 70px;\"><strong>"
                               + name +
                           "</strong></span>"
                       "</p>"
                  "</span>"
              "</p>";
    ui->nameText->setHtml(contentRight);
}
