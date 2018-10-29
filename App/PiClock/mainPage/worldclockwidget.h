#ifndef WORLDCLOCKWIDGET_H
#define WORLDCLOCKWIDGET_H

#include <QWidget>

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
};

#endif // WORLDCLOCKWIDGET_H
