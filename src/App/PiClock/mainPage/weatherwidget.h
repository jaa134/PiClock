#ifndef WEATHERWIDGET_H
#define WEATHERWIDGET_H

#include "widgets/weatherwidgetservice.h"
#include "QWidget"
#include "QThread"

namespace Ui {
class WeatherWidget;
}

class WeatherWidget : public QWidget
{
    Q_OBJECT

public:
    explicit WeatherWidget(QWidget *parent = nullptr);
    ~WeatherWidget();

private:
    Ui::WeatherWidget *ui;
    WeatherWidgetService *service;
    QThread serviceThread;

private slots:
    void display();
};

#endif // WEATHERWIDGET_H
