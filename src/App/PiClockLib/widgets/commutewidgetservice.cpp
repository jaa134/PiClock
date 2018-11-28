#include "commutewidgetservice.h"

CommuteWidgetService::CommuteWidgetService()
{
    manager = nullptr;

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
    delete manager;
    manager = new QNetworkAccessManager();
    connect(manager, &QNetworkAccessManager::finished, this, &CommuteWidgetService::generateCommute);
    request.setUrl(QUrl("http://dev.virtualearth.net/REST/V1/Routes/Driving?wp.0=41.499803183159976,-81.59453630447389&wp.1=41.46306273702346,-81.9564950466156&avoid=minimizeTolls&du=mi&key=AoqKK9JbiMuCDMht8ZrRUajildqZDGNZlSe-omiay7n3x7k13Pnxz_WI_pucpASD"));
    manager->get(request);
}

void CommuteWidgetService::generateCommute(QNetworkReply *reply) {
    if (reply->error()) {
        qDebug() << reply->errorString();
        return;
    }

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
