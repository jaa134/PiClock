#ifndef NEWSWIDGETSERVICE_H
#define NEWSWIDGETSERVICE_H

#include "widgetservice.h"
#include "managers/settingsmanager.h"
#include "QTime"
#include "QString"
#include "QList"
#include "QDebug"
#include "QNetworkAccessManager"
#include "QNetworkReply"
#include "QJsonDocument"
#include "QJsonObject"
#include "QJsonArray"
#include "QTextDocument"

class NewsWidgetService : public WidgetService
{
    Q_OBJECT

public:
    struct NewsStory {
        QString title;
        QString source;
    };

    NewsStory newsStory;
    NewsWidgetService();
    void init() Q_DECL_OVERRIDE;

private:
    QNetworkAccessManager *manager;
    QNetworkRequest request;
    QList<NewsStory> newsStories;
    bool isValidNewsStory();
    void getNews();
    QString toPlainString(QString);

private slots:
    void update() Q_DECL_OVERRIDE;
    void generateNewsStories(QNetworkReply *);
};

#endif // NEWSWIDGETSERVICE_H
