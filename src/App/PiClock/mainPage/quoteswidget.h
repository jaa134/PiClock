#ifndef QUOTESWIDGET_H
#define QUOTESWIDGET_H

#include <QWidget>

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
};

#endif // QUOTESWIDGET_H
