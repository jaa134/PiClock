#ifndef WEATHER_H
#define WEATHER_H

#include <QObject>
#include "QNetworkAccessManager"
#include "QNetworkReply"
#include "QDebug"
#include "QTimer"

struct ResponseObject{
     QString name;
     QString region;
     QString temp_f;
     QString temp_c;
     QString wind_mph;
     QString humidity;
     QString feelslike_c;
     QString feelslike_f;
};

struct WeatherContents {
    QString content;
};

class Weather : public QObject
{
    Q_OBJECT

public:
    explicit Weather(QObject *parent = nullptr);
    QTimer *updateTimer;
    QNetworkAccessManager *manager;
    QNetworkRequest request;
    QString toPlainString(QString);
    void displayWeather(ResponseObject);

public slots:
    void getWeather();
};

#endif // WEATHER_H
