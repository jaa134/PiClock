#ifndef FORECASTWIDGET_H
#define FORECASTWIDGET_H

#include <QWidget>

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
};

#endif // FORECASTWIDGET_H
