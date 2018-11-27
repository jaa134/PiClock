#ifndef HOLIDAYCOUNTDOWNWIDGET_H
#define HOLIDAYCOUNTDOWNWIDGET_H

#include "widgets/holidaycountdownwidgetservice.h"
#include "QWidget"
#include "QThread"

namespace Ui {
class HolidayCountdownWidget;
}

class HolidayCountdownWidget : public QWidget
{
    Q_OBJECT

public:
    explicit HolidayCountdownWidget(QWidget *parent = nullptr);
    ~HolidayCountdownWidget();

private:
    Ui::HolidayCountdownWidget *ui;
    HolidayCountdownWidgetService *service;
    QThread serviceThread;

private slots:
    void display();
};

#endif // HOLIDAYCOUNTDOWNWIDGET_H
