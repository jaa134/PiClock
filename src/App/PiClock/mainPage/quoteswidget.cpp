#include "quoteswidget.h"
#include "ui_quoteswidget.h"

QuotesWidget::QuotesWidget(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::QuotesWidget)
{
    ui->setupUi(this);

    //timer to update widget
    service = new QuotesWidgetService();
    service->moveToThread(&serviceThread);
    connect(service, &QuotesWidgetService::updated, this, &QuotesWidget::display);
    serviceThread.start();
    service->init();
}

QuotesWidget::~QuotesWidget()
{
    delete ui;
    serviceThread.quit();
    serviceThread.wait();
}

void QuotesWidget::display() {
    //show information in the ui
    ui->text->setHtml("<p align=\"center\"><span>" + service->quote.content + "</span></p>"
                    + "<p align=\"center\" style=\"font-size: 35px;\"><span><strong>" + service->quote.author + "</strong></span></p>");
}
