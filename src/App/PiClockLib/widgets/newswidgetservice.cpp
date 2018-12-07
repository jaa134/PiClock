#include "newswidgetservice.h"

NewsWidgetService::NewsWidgetService() {
    newsStory.title = "Title";
    newsStory.source = "Source";

    manager = nullptr;

    apiKey = SettingsManager::newsApiKey();

    //create update timer
    connect(&updateTimer, &QTimer::timeout, this, &NewsWidgetService::update);
    updateTimer.setInterval(SettingsManager::widgetTransitionDuration());
}

void NewsWidgetService::init() {
    update();
    updateTimer.start();
}

void NewsWidgetService::update() {
    //use quote from storage if possible, or make request if none left
    do {
        if (newsStories.isEmpty()) {
            getNews();
            return;
        }
        else
            newsStory = newsStories.takeFirst();
    } while (!isValidNewsStory());

    emit updated();
}

bool NewsWidgetService::isValidNewsStory() {
    //validity depends on length per ui constraints
    int maxTitleLength = 80;
    int maxSourceLength = 25;
    return newsStory.title.length() <= maxTitleLength
            && newsStory.source.length() <= maxSourceLength
            && !newsStory.title.isEmpty()
            && !newsStory.source.isEmpty();
}

void NewsWidgetService::getNews() {
    //make http request for news data
    delete manager;
    manager = new QNetworkAccessManager();
    connect(manager, &QNetworkAccessManager::finished, this, &NewsWidgetService::generateNewsStories);
    request.setUrl(QUrl("https://newsapi.org/v2/top-headlines?country=us&apiKey=" + apiKey));
    manager->get(request);
}

void NewsWidgetService::generateNewsStories(QNetworkReply *reply) {
    //log any errors
    if (reply->error()) {
        qDebug() << reply->errorString();
        return;
    }

    //read network response and parse json
    QString answer = reply->readAll();
    QJsonObject jsonResponse = QJsonDocument::fromJson(answer.toUtf8()).object();
    QJsonArray jsonArray = jsonResponse["articles"].toArray();
    foreach (const QJsonValue & value, jsonArray) {
        QJsonObject obj = value.toObject();
        NewsStory newsStory;
        newsStory.title = toPlainString(obj["title"].toString());
        newsStory.source = toPlainString(obj["source"].toObject()["name"].toString());
        newsStories.append(newsStory);
    }

    newsStory = newsStories.takeFirst();
    emit updated();
}

//remove any special characters
QString NewsWidgetService::toPlainString(QString ques) {
    QTextDocument text;
    text.setHtml(ques);
    return text.toPlainText();
}
