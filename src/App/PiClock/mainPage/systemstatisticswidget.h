#ifndef SYSTEMSTATISTICSWIDGET_H
#define SYSTEMSTATISTICSWIDGET_H

#include "widgets/systemstatisticswidgetservice.h"
#include "QWidget"
#include "QThread"
#include "QProgressBar"

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
    SystemStatisticsWidgetService *service;
    QThread serviceThread;
    void setWarningColor(QProgressBar *);

private slots:
    void display();
};

#endif // SYSTEMSTATISTICSWIDGET_H
