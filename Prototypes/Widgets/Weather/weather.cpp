#include "weather.h"
#include "QJsonDocument"
#include "QJsonObject"
#include "QJsonArray"
#include "QTextDocument"
#include <iostream>

using namespace std;

Weather::Weather(QObject *parent) : QObject(parent)
{
    manager = new QNetworkAccessManager();

    updateTimer = new QTimer();
    updateTimer->setInterval(5000);
    updateTimer->setSingleShot(true);
    connect(updateTimer, &QTimer::timeout, this, &Weather::getWeather);

    /*
     * Connects to the http and retrieves the information needed for the question.
     */
    connect(manager, &QNetworkAccessManager::finished, this, [=](QNetworkReply *reply) {
        if (reply->error()) {
            qDebug() << reply->errorString();
            return;
        }

        QString answer = reply->readAll();
        QJsonDocument jsonResponse = QJsonDocument::fromJson(answer.toUtf8());
        QJsonObject jsonObject = jsonResponse.object();
        QJsonObject locationData = jsonObject["location"].toObject();
        QJsonObject weatherData = jsonObject["current"].toObject();

        ResponseObject ro;
        ro.name = toPlainString(locationData["name"].toString());
        ro.region = toPlainString(locationData["region"].toString());
        ro.temp_c = QString::number(weatherData["temp_c"].toDouble());
        ro.temp_f = QString::number(weatherData["temp_f"].toDouble());
        ro.wind_mph = QString::number(weatherData["wind_mph"].toDouble());
        ro.humidity = QString::number(weatherData["humidity"].toDouble());
        ro.feelslike_c = QString::number(weatherData["feelslike_c"].toDouble());
        ro.feelslike_f = QString::number(weatherData["feelslike_f"].toDouble());

        displayWeather(ro);

        updateTimer->start();
    });
}

/*
 * Converts the text from its format to plain, normal text.
 */
 QString Weather::toPlainString(QString weather){
     QTextDocument text;
     text.setHtml(weather);
     return text.toPlainText();
 }

/*
 * Retrieves the weather from the 3rd party API and stores it in a string
 */
void Weather::getWeather(){
    cout << "Weather is loading...\n" << endl;
    request.setUrl(QUrl("http://api.apixu.com/v1/current.json?key=c7e7a336a66244cd81641549180911&q=44101"));
    manager->get(request);
}

void Weather::displayWeather(ResponseObject ro) {
    cout << "Weather in " << ro.name.toStdString() << endl;
    cout << "REGION: " << ro.region.toStdString() << endl;
    cout << "TEMP C: " << ro.temp_c.toStdString() << endl;
    cout << "TEMP F: " << ro.temp_f.toStdString() << endl;
    cout << "WIND MPH: " << ro.wind_mph.toStdString() << endl;
    cout << "HUMIDITY: " << ro.humidity.toStdString() << endl;
    cout << "FEELS LIKE C: " << ro.feelslike_c.toStdString() << endl;
    cout << "FEELS LIKE F: " << ro.feelslike_f.toStdString() << endl;
    cout << endl << endl;
}
