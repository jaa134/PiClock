#ifndef APPLICATIONTEST_H
#define APPLICATIONTEST_H

#include <QObject>

class ApplicationTest : public QObject
{
    Q_OBJECT
public:
    explicit ApplicationTest(QObject *parent = nullptr);

signals:

public slots:
};

#endif // APPLICATIONTEST_H