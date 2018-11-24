#include "quoteswidgetservice.h"

QuotesWidgetService::QuotesWidgetService() {
    quote.content = "Content";
    quote.author = "Author";

    manager = nullptr;

    connect(&updateTimer, &QTimer::timeout, this, &QuotesWidgetService::update);
    updateTimer.setInterval(SettingsManager::widgetTransitionDuration());
}

void QuotesWidgetService::init() {
    update();
    updateTimer.start();
}

void QuotesWidgetService::update() {
    do {
        if (quotes.isEmpty()) {
            getQuotes();
            return;
        }
        else
            quote = quotes.takeFirst();
    } while (!isValidQuote());

    emit updated();
}

bool QuotesWidgetService::isValidQuote() {
    int maxContentLength = 80;
    int maxAuthorLength = 25;
    return quote.content.length() <= maxContentLength
            && quote.author.length() <= maxAuthorLength
            && !quote.content.isEmpty()
            && !quote.author.isEmpty();
}

void QuotesWidgetService::getQuotes() {
    delete manager;
    manager = new QNetworkAccessManager();
    connect(manager, &QNetworkAccessManager::finished, this, &QuotesWidgetService::generateQuotes);
    request.setUrl(QUrl("https://talaikis.com/api/quotes/"));
    manager->get(request);
}

void QuotesWidgetService::generateQuotes(QNetworkReply *reply) {
    if (reply->error()) {
        qDebug() << reply->errorString();
        return;
    }

    QString answer = reply->readAll();
    QJsonDocument jsonResponse = QJsonDocument::fromJson(answer.toUtf8());
    QJsonArray jsonArray = jsonResponse.array();
    foreach (const QJsonValue & value, jsonArray) {
        QJsonObject obj = value.toObject();
        Quote quote;
        quote.content = toPlainString(obj["quote"].toString());
        quote.author = toPlainString(obj["author"].toString());
        quotes.append(quote);
    }

    quote = quotes.takeFirst();
    emit updated();
}

QString QuotesWidgetService::toPlainString(QString ques) {
    QTextDocument text;
    text.setHtml(ques);
    return text.toPlainText();
}
