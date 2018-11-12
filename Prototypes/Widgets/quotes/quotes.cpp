#include "quotes.h"
#include "QJsonDocument"
#include "QJsonObject"
#include "QJsonArray"
#include "QTextDocument"
#include <iostream>

using namespace std;

/*
 * Constructor
 * Connects to API, gets JSON array with quotes
 * Converts JSON array into array of quoteStruct objects, then calls printQuotes() method
 */
Quotes::Quotes(QObject *parent) : QObject(parent){

    manager = new QNetworkAccessManager();

	//connects to API
    connect(manager, &QNetworkAccessManager::finished,
            this, [=](QNetworkReply *reply) {
                if (reply->error()) {
                    qDebug() << reply->errorString();
                    return;
                }

				//answer holds text directly obtained from API call
                QString answer = reply->readAll();

				//converts answer to Utf8 format
                QJsonDocument jsonResponse = QJsonDocument::fromJson(answer.toUtf8());

				//This API stores all quotes structures in a single array, so convert directly to jsonArray type
                QJsonArray jsonArray = jsonResponse.array();

				//for each quote structure (containing quote, author, and category) in the array
                foreach (const QJsonValue & value, jsonArray) {

					//converts to QJsonObject
                    QJsonObject obj = value.toObject();
                    quoteStruct qu;

					//converts API's JsonObject to a new quoteStruct object by matching fields
                    qu.quote = toPlainString(obj["quote"].toString());
                    qu.author = toPlainString(obj["author"].toString());
                    qu.category = toPlainString(obj["cat"].toString());

					//appends qu to list quoteStructs
                    quoteList.append(qu);
                }

                this -> printQuotes();
            }

        );

}

/*
 * Converts the text from its format to plain, normal text.
 */
QString Quotes::toPlainString(QString ques){

    QTextDocument text;
    text.setHtml(ques);
    return text.toPlainText();
}

/*
 * Specifies url of API request
 */
void Quotes::getQuotes(){
    cout << "Quotes are loading\n" << endl;
    request.setUrl(QUrl("https://talaikis.com/api/quotes/"));
    manager->get(request);
}

/*
 * Prints each quote and author in quoteList to screen
 */
void Quotes::printQuotes(){

	//print quotes until list is empty
   while(!quoteList.isEmpty()){
        quoteStruct testquote = quoteList.takeFirst();

		//prints quote in this format:
		//"quote....................."
		//		- Author
        cout << "\"" << testquote.quote.toStdString() << "\"" << endl;
        cout << "\t- " << testquote.author.toStdString() << endl << endl;
   }
}

