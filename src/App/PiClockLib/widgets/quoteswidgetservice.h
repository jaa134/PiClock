#ifndef QUOTESWIDGETSERVICE_H
#define QUOTESWIDGETSERVICE_H

#include "widgetservice.h"
#include "managers/settingsmanager.h"
#include "QTime"
#include "QString"
#include "QList"
#include "QDebug"
#include "QNetworkAccessManager"
#include "QNetworkReply"
#include "QJsonDocument"
#include "QJsonObject"
#include "QJsonArray"
#include "QTextDocument"

class QuotesWidgetService : public WidgetService
{
    Q_OBJECT

public:
    struct Quote {
        QString content;
        QString author;
    };

    Quote quote;
    QuotesWidgetService();
    void init() Q_DECL_OVERRIDE;

private:
    QNetworkAccessManager *manager;
    QNetworkRequest request;
    QList<Quote> quotes;
    bool isValidQuote();
    void getQuotes();
    QString toPlainString(QString);

private slots:
    void update() Q_DECL_OVERRIDE;
    void generateQuotes(QNetworkReply *);

};

#endif // QUOTESWIDGETSERVICE_H
