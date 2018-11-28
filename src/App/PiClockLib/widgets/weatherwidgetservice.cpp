#include "weatherwidgetservice.h"

WeatherWidgetService::WeatherWidgetService() {
    manager = nullptr;

    connect(&updateTimer, &QTimer::timeout, this, &WeatherWidgetService::update);
    updateTimer.setInterval(600000);
}

void WeatherWidgetService::init() {
    update();
    updateTimer.start();
}

void WeatherWidgetService::update() {
    getWeather();
}

void WeatherWidgetService::getWeather() {
    delete manager;
    manager = new QNetworkAccessManager();
    connect(manager, &QNetworkAccessManager::finished, this, &WeatherWidgetService::generateWeather);
    request.setUrl(QUrl("http://api.apixu.com/v1/current.json?key=c7e7a336a66244cd81641549180911&q=44101"));
    manager->get(request);
}

void WeatherWidgetService::generateWeather(QNetworkReply *reply) {
    if (reply->error()) {
        qDebug() << reply->errorString();
        return;
    }

    QString answer = reply->readAll();
    QJsonDocument jsonResponse = QJsonDocument::fromJson(answer.toUtf8());
    QJsonObject jsonObject = jsonResponse.object();
    QJsonObject locationData = jsonObject["location"].toObject();
    QJsonObject currentData = jsonObject["current"].toObject();

    weather.location = locationData["name"].toString();
    weather.region = locationData["region"].toString();
    weather.currentTemp = QString::number((int)currentData["temp_f"].toDouble());
    weather.windSpeed = QString::number(currentData["wind_mph"].toDouble());
    weather.windDirection = currentData["wind_dir"].toString();
    weather.humidity = QString::number(currentData["humidity"].toDouble());
    weather.precipitation = QString::number(currentData["precip_in"].toDouble());
    weather.cloudCoverage = QString::number(currentData["cloud"].toDouble());
    weather.visibility = QString::number(currentData["vis_miles"].toDouble());

    int code = currentData["condition"].toObject()["code"].toInt();
    QFile f(":/json/weather_conditions.json");
    f.open(QIODevice::ReadOnly);
    QJsonDocument contents = QJsonDocument::fromJson(f.readAll());
    QJsonArray conditions = contents.array();
    foreach (const QJsonValue & value, conditions) {
        if (code == value["code"].toInt()) {
            weather.type = value["icon"].toString();
            break;
        }
    }
    f.close();

    emit updated();
}
