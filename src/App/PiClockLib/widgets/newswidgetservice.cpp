#include "newswidgetservice.h"

NewsWidgetService::NewsWidgetService() {
    newsStory.title = "Title";
    newsStory.source = "Source";

    manager = nullptr;

    connect(&updateTimer, &QTimer::timeout, this, &NewsWidgetService::update);
    updateTimer.setInterval(SettingsManager::widgetTransitionDuration());
}

void NewsWidgetService::init() {
    update();
    updateTimer.start();
}

void NewsWidgetService::update() {
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
    int maxTitleLength = 80;
    int maxSourceLength = 25;
    return newsStory.title.length() <= maxTitleLength
            && newsStory.source.length() <= maxSourceLength
            && !newsStory.title.isEmpty()
            && !newsStory.source.isEmpty();
}

void NewsWidgetService::getNews() {
    delete manager;
    manager = new QNetworkAccessManager();
    connect(manager, &QNetworkAccessManager::finished, this, &NewsWidgetService::generateNewsStories);
    request.setUrl(QUrl("https://newsapi.org/v2/top-headlines?country=us&apiKey=40d29d4a15e44563afdf0826bc61b64f"));
    manager->get(request);
}

void NewsWidgetService::generateNewsStories(QNetworkReply *reply) {
    if (reply->error()) {
        qDebug() << reply->errorString();
        return;
    }

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

QString NewsWidgetService::toPlainString(QString ques) {
    QTextDocument text;
    text.setHtml(ques);
    return text.toPlainText();
}
