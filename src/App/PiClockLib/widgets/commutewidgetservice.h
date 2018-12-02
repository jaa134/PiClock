#ifndef COMMUTEWIDGETSERVICE_H
#define COMMUTEWIDGETSERVICE_H

#include "widgetservice.h"
#include "managers/settingsmanager.h"
#include "QTime"
#include "QString"
#include "QNetworkAccessManager"
#include "QNetworkReply"
#include "QJsonDocument"
#include "QJsonObject"
#include "QJsonArray"

class CommuteWidgetService : public WidgetService
{
    Q_OBJECT

    struct Commute {
        QString distance;
        QString totalTime;
        QString arrivalTime;
        QString trafficVolume;
    };

public:
    Commute commute;
    CommuteWidgetService();
    void init() Q_DECL_OVERRIDE;

private:
    QString apiKey;
    QString wpStart;
    QString wpEnd;
    QNetworkAccessManager *manager;
    QNetworkRequest request;
    void getCommute();

private slots:
    void update() Q_DECL_OVERRIDE;
    void generateCommute(QNetworkReply *);
};

#endif // COMMUTEWIDGETSERVICE_H
