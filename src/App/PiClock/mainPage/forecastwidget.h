#ifndef FORECASTWIDGET_H
#define FORECASTWIDGET_H

#include "widgets/forecastwidgetservice.h"
#include "QWidget"
#include "QThread"

namespace Ui {
class ForecastWidget;
}

class ForecastWidget : public QWidget
{
    Q_OBJECT

public:
    explicit ForecastWidget(QWidget *parent = nullptr);
    ~ForecastWidget();

private:
    Ui::ForecastWidget *ui;
    ForecastWidgetService *service;
    QThread serviceThread;

private slots:
    void display();
};

#endif // FORECASTWIDGET_H
