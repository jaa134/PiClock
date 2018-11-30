#ifndef NEWSWIDGET_H
#define NEWSWIDGET_H

#include "widgets/newswidgetservice.h"
#include "QWidget"
#include "QThread"

namespace Ui {
class NewsWidget;
}

class NewsWidget : public QWidget
{
    Q_OBJECT

public:
    explicit NewsWidget(QWidget *parent = nullptr);
    ~NewsWidget();

private:
    Ui::NewsWidget *ui;
    NewsWidgetService *service;
    QThread serviceThread;

private slots:
    void display();
};

#endif // NEWSWIDGET_H
