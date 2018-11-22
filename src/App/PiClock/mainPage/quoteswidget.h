#ifndef QUOTESWIDGET_H
#define QUOTESWIDGET_H

#include "widgets/quoteswidgetservice.h"
#include "QWidget"
#include "QThread"

namespace Ui {
class QuotesWidget;
}

class QuotesWidget : public QWidget
{
    Q_OBJECT

public:
    explicit QuotesWidget(QWidget *parent = nullptr);
    ~QuotesWidget();

private:
    Ui::QuotesWidget *ui;
    QuotesWidgetService *service;
    QThread serviceThread;

private slots:
    void display();
};

#endif // QUOTESWIDGET_H
