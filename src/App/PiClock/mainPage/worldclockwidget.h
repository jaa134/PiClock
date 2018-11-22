#ifndef WORLDCLOCKWIDGET_H
#define WORLDCLOCKWIDGET_H

#include "widgets/worldclockwidgetservice.h"
#include "QWidget"
#include "QThread"
#include "QTimer"

namespace Ui {
class WorldClockWidget;
}

class WorldClockWidget : public QWidget
{
    Q_OBJECT

public:
    explicit WorldClockWidget(QWidget *parent = nullptr);
    ~WorldClockWidget();

private:
    Ui::WorldClockWidget *ui;
    WorldClockWidgetService *service;
    QThread serviceThread;

private slots:
    void display();
};

#endif // WORLDCLOCKWIDGET_H
