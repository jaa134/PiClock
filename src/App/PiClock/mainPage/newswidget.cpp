#include "newswidget.h"
#include "ui_newswidget.h"

NewsWidget::NewsWidget(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::NewsWidget)
{
    ui->setupUi(this);

    service = new NewsWidgetService();
    service->moveToThread(&serviceThread);
    connect(service, &NewsWidgetService::updated, this, &NewsWidget::display);
    serviceThread.start();
    service->init();
}

NewsWidget::~NewsWidget()
{
    delete ui;
    serviceThread.quit();
    serviceThread.wait();
}

void NewsWidget::display() {
    ui->text->setHtml("<p align=\"center\"><span>" + service->newsStory.title + "</span></p>"
                    + "<p align=\"center\" style=\"font-size: 35px;\"><span><strong>" + service->newsStory.source + "</strong></span></p>");
}
