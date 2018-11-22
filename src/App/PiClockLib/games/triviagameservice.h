#ifndef TRIVIAGAMESERVICE_H
#define TRIVIAGAMESERVICE_H

#include "gameservice.h"
#include "models/game.h"
#include "QList"
#include "QNetworkAccessManager"
#include "QNetworkReply"
#include "QJsonDocument"
#include "QJsonObject"
#include "QJsonArray"
#include "QTextDocument"
#include "QEventLoop"

class TriviaGameService : public GameService
{
    friend class TestStub;

public:
    struct Answer {
        bool isCorrect;
        QString text;
    };

    struct Question {
        QString text;
        QList<Answer> options;
    };

    TriviaGameService();
    Question question;
    void reset(Game::Difficulty) Q_DECL_OVERRIDE;

private:
    struct ResponseObject{
        QString results;
        QString category;
        QString type;
        QString difficulty;
        QString question;
        QString correct_answer;
        QStringList incorrect_answers;
    };

    static const int numQuestions = 100;
    QNetworkAccessManager *manager;
    QNetworkRequest request;
    QEventLoop replyLoop;
    QList<Question> questions;
    void cycleQuestion();
    void getQuestions();
    QString toPlainString(QString);
    Question responseToQuestion(ResponseObject);
    bool isValidQuestion();


public slots:
    bool answer(int);

private slots:
    void generateQuestions(QNetworkReply *);
};

#endif // TRIVIAGAMESERVICE_H
