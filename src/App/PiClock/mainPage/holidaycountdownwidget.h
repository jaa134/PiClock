#ifndef HOLIDAYCOUNTDOWNWIDGET_H
#define HOLIDAYCOUNTDOWNWIDGET_H

#include <QWidget>

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
};

#endif // HOLIDAYCOUNTDOWNWIDGET_H
