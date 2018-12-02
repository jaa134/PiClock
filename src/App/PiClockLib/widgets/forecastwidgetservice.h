#ifndef FORECASTWIDGETSERVICE_H
#define FORECASTWIDGETSERVICE_H

#include "widgetservice.h"
#include "managers/settingsmanager.h"
#include "QTime"
#include "QString"
#include "QNetworkAccessManager"
#include "QNetworkReply"
#include "QJsonDocument"
#include "QJsonObject"
#include "QJsonArray"

class ForecastWidgetService : public WidgetService
{
    Q_OBJECT

    struct Weather {
        QString date;
        QString type;
        QString high;
        QString low;
    };

    const static int numDays = 7;

public:
    QString location;
    QString region;
    Weather forecast[numDays];
    ForecastWidgetService();
    void init() Q_DECL_OVERRIDE;

private:
    QString apiKey;
    QString apiLocation;
    QNetworkAccessManager *manager;
    QNetworkRequest request;
    void getForecast();

private slots:
    void update() Q_DECL_OVERRIDE;
    void generateForecast(QNetworkReply *);
};

#endif // FORECASTWIDGETSERVICE_H
