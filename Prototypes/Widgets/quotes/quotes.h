#ifndef QUOTES_H
#define QUOTES_H

#include <QObject>
#include "QNetworkAccessManager"
#include "QNetworkReply"
#include "QDebug"

/*
 * API returns quotes as JSON array with quote itself, speaker of quote, and quote category
 * quoteStruct holds these 3 values
 */
struct quoteStruct{
    QString quote;
    QString author;
    QString category;
};

/*
 * PiClock quotes widget.
 * Prints a quote and its author to the screen
 * Updates quote every time widget cycles through slideshow
 */
class Quotes : public QObject
{
    Q_OBJECT

public:
	//manages API request
    QNetworkAccessManager *manager;

	//Holds API request
    QNetworkRequest request;

	//constructor
    explicit Quotes(QObject *parent = nullptr);

    QString toPlainString(QString);
    QList<quoteStruct> quoteList;
    bool quoteListIsEmpty();
    void printQuotes();
    void getQuotes();


signals:

public slots:
};

#endif // QUOTES_H
