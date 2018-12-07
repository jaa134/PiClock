#include "quoteswidgetservice.h"

QuotesWidgetService::QuotesWidgetService() {
    quote.content = "Content";
    quote.author = "Author";

    manager = nullptr;

    //create update timer
    connect(&updateTimer, &QTimer::timeout, this, &QuotesWidgetService::update);
    updateTimer.setInterval(SettingsManager::widgetTransitionDuration());
}

void QuotesWidgetService::init() {
    update();
    updateTimer.start();
}

void QuotesWidgetService::update() {
    //use quote from storage if possible, or make request if none left
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
    //valid quotes have a size contraint for the ui
    int maxContentLength = 80;
    int maxAuthorLength = 25;
    return quote.content.length() <= maxContentLength
            && quote.author.length() <= maxAuthorLength
            && !quote.content.isEmpty()
            && !quote.author.isEmpty();
}

void QuotesWidgetService::getQuotes() {
    //make a get request for the quote data
    delete manager;
    manager = new QNetworkAccessManager();
    connect(manager, &QNetworkAccessManager::finished, this, &QuotesWidgetService::generateQuotes);
    request.setUrl(QUrl("https://talaikis.com/api/quotes/"));
    manager->get(request);
}

void QuotesWidgetService::generateQuotes(QNetworkReply *reply) {
    //log any errors
    if (reply->error()) {
        qDebug() << reply->errorString();
        return;
    }

    //read network response and parse json
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

//remove any special characters
QString QuotesWidgetService::toPlainString(QString ques) {
    QTextDocument text;
    text.setHtml(ques);
    return text.toPlainText();
}
