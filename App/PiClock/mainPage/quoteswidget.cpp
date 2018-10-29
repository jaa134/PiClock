#include "quoteswidget.h"
#include "ui_quoteswidget.h"

QuotesWidget::QuotesWidget(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::QuotesWidget)
{
    ui->setupUi(this);
}

QuotesWidget::~QuotesWidget()
{
    delete ui;
}
