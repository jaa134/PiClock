#ifndef WEATHERWIDGETSERVICE_H
#define WEATHERWIDGETSERVICE_H

#include "widgetservice.h"
#include "managers/settingsmanager.h"
#include "QTime"
#include "QString"
#include "QNetworkAccessManager"
#include "QNetworkReply"
#include "QJsonDocument"
#include "QJsonObject"
#include "QJsonArray"

class WeatherWidgetService : public WidgetService
{
    Q_OBJECT

    struct Weather {
        QString type;
        QString currentTemp;
        QString location;
        QString region;
        QString windSpeed;
        QString windDirection;
        QString humidity;
        QString precipitation;
        QString cloudCoverage;
        QString visibility;
    };

public:
    Weather weather;
    WeatherWidgetService();
    void init() Q_DECL_OVERRIDE;

private:
    QNetworkAccessManager *manager;
    QNetworkRequest request;
    void getWeather();

private slots:
    void update() Q_DECL_OVERRIDE;
    void generateWeather(QNetworkReply *);

};

#endif // WEATHERWIDGETSERVICE_H
