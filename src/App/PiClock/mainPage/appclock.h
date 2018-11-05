#ifndef APPCLOCK_H
#define APPCLOCK_H

#include "QObject"
#include "QTimer"
#include "QString"

class AppClock : public QObject
{
    Q_OBJECT

public:
    AppClock();
    ~AppClock();

private:
    QString *time_format;
    QTimer *update_timer;

signals:
    void changeDateTime(QString, QString);

public slots:
    void start();
    void stop();

private slots:
    void updateDateTime();
};

#endif // APPCLOCK_H
