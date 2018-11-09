#ifndef TRIVIAGAME_H
#define TRIVIAGAME_H

#include <QObject>
#include "QNetworkAccessManager"
#include "QNetworkReply"
#include "QDebug"

/*
 * Enum for setting the difficulty of the game.
 */
enum Difficulty{
    Beginner,
    Intermediate,
    Advanced
};

/*
 * Struct that carries the values of the repsonse object.
 */
struct ResponseObject{

    QString results;
    QString category;
    QString type;
    QString difficulty;
    QString question;
    QString correct_answer;
    QStringList incorrect_answers;

};

/*
 * Struct that stores the answer and if it is correct or not.
 */
struct Answer{

    bool isCorrect;
    QString content;

};

/*
 * Struct that stores the question and a list of answers.
 */
struct Question{

    QString content;
    QList<Answer> answers;

};

/*
 * TriviaGame class that initializes every value.
 */
class TriviaGame : public QObject
{
    Q_OBJECT

public:

    QNetworkAccessManager *manager;
    QNetworkRequest request;
    explicit TriviaGame(Difficulty, QObject *parent = nullptr);
    int pointsThreshold;
    QList<Question> questions;
    void getQuestions();
    QString toPlainString(QString);
    Question responseToQuestion(ResponseObject);
    void playGame();

signals:

public slots:
};

#endif // TRIVIAGAME_H
