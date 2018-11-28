#ifndef COMMUTEWIDGET_H
#define COMMUTEWIDGET_H

#include "widgets/commutewidgetservice.h"
#include "QWidget"
#include "QThread"

namespace Ui {
class CommuteWidget;
}

class CommuteWidget : public QWidget
{
    Q_OBJECT

public:
    explicit CommuteWidget(QWidget *parent = nullptr);
    ~CommuteWidget();

private:
    Ui::CommuteWidget *ui;
    CommuteWidgetService *service;
    QThread serviceThread;

private slots:
    void display();
};

#endif // COMMUTEWIDGET_H
