#include "commutewidgetservice.h"

CommuteWidgetService::CommuteWidgetService()
{
    manager = nullptr;

    apiKey = SettingsManager::commuteApiKey();
    wpStart = SettingsManager::commuteStartLongitude() + "," + SettingsManager::commuteStartLatitude();
    wpEnd = SettingsManager::commuteEndLongitude() + "," + SettingsManager::commuteEndLatitude();

    //create update timer
    connect(&updateTimer, &QTimer::timeout, this, &CommuteWidgetService::update);
    updateTimer.setInterval(120000);
}

void CommuteWidgetService::init() {
    update();
    updateTimer.start();
}

void CommuteWidgetService::update() {
    getCommute();
}

void CommuteWidgetService::getCommute() {
    //make get request for commute data
    delete manager;
    manager = new QNetworkAccessManager();
    connect(manager, &QNetworkAccessManager::finished, this, &CommuteWidgetService::generateCommute);
    request.setUrl(QUrl("http://dev.virtualearth.net/REST/V1/Routes/Driving?wp.0=" + wpStart + "&wp.1=" + wpEnd + "&avoid=minimizeTolls&du=mi&key=" + apiKey));
    manager->get(request);
}

void CommuteWidgetService::generateCommute(QNetworkReply *reply) {
    //log any errors
    if (reply->error()) {
        qDebug() << reply->errorString();
        return;
    }

    //read network response and parse data
    QString answer = reply->readAll();
    QJsonDocument jsonResponse = QJsonDocument::fromJson(answer.toUtf8());
    QJsonArray resourceSets = jsonResponse.object()["resourceSets"].toArray();
    QJsonArray resources = resourceSets.at(0).toObject()["resources"].toArray();
    QJsonObject data = resources.at(0).toObject();

    commute.distance = QString::number(data["travelDistance"].toDouble(), 'f', 1);
    commute.totalTime = QString::number(data["travelDurationTraffic"].toInt() / 60);
    commute.arrivalTime = QTime::currentTime().addSecs(data["travelDurationTraffic"].toInt()).toString(SettingsManager::clockTimeFormat());
    commute.trafficVolume = data["trafficCongestion"].toString();

    emit updated();
}
