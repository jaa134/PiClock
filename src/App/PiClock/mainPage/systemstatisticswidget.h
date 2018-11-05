#ifndef SYSTEMSTATISTICSWIDGET_H
#define SYSTEMSTATISTICSWIDGET_H

#include <QWidget>

namespace Ui {
class SystemStatisticsWidget;
}

class SystemStatisticsWidget : public QWidget
{
    Q_OBJECT

public:
    explicit SystemStatisticsWidget(QWidget *parent = nullptr);
    ~SystemStatisticsWidget();

private:
    Ui::SystemStatisticsWidget *ui;
};

#endif // SYSTEMSTATISTICSWIDGET_H
