#include "forecastwidgetservice.h"

ForecastWidgetService::ForecastWidgetService() {
    manager = nullptr;

    apiKey = SettingsManager::weatherApiKey();
    apiLocation = SettingsManager::weatherLocation();

    connect(&updateTimer, &QTimer::timeout, this, &ForecastWidgetService::update);
    updateTimer.setInterval(600000);
}

void ForecastWidgetService::init() {
    update();
    updateTimer.start();
}

void ForecastWidgetService::update() {
    getForecast();
}

void ForecastWidgetService::getForecast() {
    delete manager;
    manager = new QNetworkAccessManager();
    connect(manager, &QNetworkAccessManager::finished, this, &ForecastWidgetService::generateForecast);
    request.setUrl(QUrl("http://api.apixu.com/v1/forecast.json?key=" + apiKey + "&q=" + apiLocation + "&days=" + QString::number(numDays)));
    manager->get(request);
}

void ForecastWidgetService::generateForecast(QNetworkReply *reply) {
    if (reply->error()) {
        qDebug() << reply->errorString();
        return;
    }

    QString answer = reply->readAll();
    QJsonObject replyObject = QJsonDocument::fromJson(answer.toUtf8()).object();

    QJsonObject locationData = replyObject["location"].toObject();
    location = locationData["name"].toString();
    region = locationData["region"].toString();

    QJsonArray forecastData = replyObject["forecast"].toObject()["forecastday"].toArray();
    QFile f(":/json/weather_conditions.json");
    f.open(QIODevice::ReadOnly);
    QJsonArray conditions = QJsonDocument::fromJson(f.readAll()).array();
    for (int i = 0; i < numDays; i++) {
            QJsonObject forecastDayData = forecastData[i].toObject();
            forecast[i].date = QDate::fromString(forecastDayData["date"].toString(), "yyyy-MM-dd").toString("ddd");
            QJsonObject day = forecastDayData["day"].toObject();
            forecast[i].high = QString::number((int)forecastDayData["day"].toObject()["maxtemp_f"].toDouble());
            forecast[i].low = QString::number((int)forecastDayData["day"].toObject()["mintemp_f"].toDouble());

            int code = forecastDayData["day"].toObject()["condition"].toObject()["code"].toInt();
            foreach (const QJsonValue & value, conditions) {
                if (code == value["code"].toInt()) {
                    forecast[i].type = value["icon"].toString();
                    break;
                }
            }
    }
    f.close();

    emit updated();
}
