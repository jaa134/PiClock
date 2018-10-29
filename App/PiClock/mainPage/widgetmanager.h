#ifndef WIDGETMANAGER_H
#define WIDGETMANAGER_H

#include "QObject"
#include "QQueue"
#include "QTimer"

class WidgetManager : public QObject
{
    Q_OBJECT

public:
    WidgetManager();
    ~WidgetManager();

private:
    QQueue<int> enabled_widget_indexes;
    QTimer *update_timer;

signals:
    void changeWidgetSlide(int);

public slots:
    void start();
    void stop();

private slots:
    void nextSlide();

};

#endif // WIDGETMANAGER_H
