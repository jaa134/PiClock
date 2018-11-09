#include "triviagame.h"
#include "QJsonDocument"
#include "QJsonObject"
#include "QJsonArray"
#include "QTextDocument"
#include <iostream>

using namespace std;
/*
 * Trivia Game constructor.
 *
 * Sets the difficulty of the game.
 *
 * Retrieves a set of questions
 */
TriviaGame::TriviaGame(Difficulty difficulty, QObject *parent) : QObject(parent)
{
    srand(time(NULL));

    switch(difficulty){
        case Beginner:
            pointsThreshold = 3;
            break;

        case Intermediate:
            pointsThreshold = 4;
            break;

        case Advanced:
            pointsThreshold = 5;
            break;
    }
    manager = new QNetworkAccessManager();

    /*
     * Connects to the http and retrieves the information needed for the question.
     */
    connect(manager, &QNetworkAccessManager::finished,
            this, [=](QNetworkReply *reply) {
                if (reply->error()) {
                    qDebug() << reply->errorString();
                    return;
                }

                QString answer = reply->readAll();

                QJsonDocument jsonResponse = QJsonDocument::fromJson(answer.toUtf8());
                QJsonObject jsonObject = jsonResponse.object();
                QJsonArray jsonArray = jsonObject["results"].toArray();

                foreach (const QJsonValue & value, jsonArray) {
                    QJsonObject obj = value.toObject();
                    ResponseObject ro;
                    ro.category = toPlainString(obj["category"].toString());
                    ro.type = toPlainString(obj["type"].toString());
                    ro.difficulty = toPlainString(obj["difficulty"].toString());
                    ro.question = toPlainString(obj["question"].toString());
                    ro.correct_answer = toPlainString(obj["correct_answer"].toString());
                    QJsonArray a2 = obj["incorrect_answers"].toArray();
                    foreach (const QJsonValue v, a2) {
                        ro.incorrect_answers.append(toPlainString(v.toString()));
                    }

                    questions.append(responseToQuestion(ro));

                }

                this->playGame();
            }
        );
}

/*
 * Retrieves the question from the 3rd party API and stores it in a string and stores the correct and incorrect answers in variables.
 */
void TriviaGame::getQuestions(){

    cout << "Your questions are loading\n" << endl;
    request.setUrl(QUrl("https://opentdb.com/api.php?amount=100&type=multiple"));
    manager->get(request);

}

/*
 * Converts the text from its format to plain, normal text.
 */
QString TriviaGame::toPlainString(QString ques){

    QTextDocument text;
    text.setHtml(ques);
    return text.toPlainText();
}

/*
 * Retrieves the question and responses and randomizes the answers in a list.
 */
Question TriviaGame::responseToQuestion(ResponseObject response){

    Question q;
    q.content = response.question;

    Answer ca0;
    ca0.isCorrect = true;
    ca0.content = response.correct_answer;
    Answer ia0;
    ia0.isCorrect = false;
    ia0.content = response.incorrect_answers[0];
    Answer ia1;
    ia1.isCorrect = false;
    ia1.content = response.incorrect_answers[1];
    Answer ia2;
    ia2.isCorrect = false;
    ia2.content = response.incorrect_answers[2];

    QList<Answer> temp = QList<Answer>({ca0, ia0, ia1, ia2});
    q.answers.append(temp.takeAt(rand() % temp.length()));
    q.answers.append(temp.takeAt(rand() % temp.length()));
    q.answers.append(temp.takeAt(rand() % temp.length()));
    q.answers.append(temp.takeAt(rand() % temp.length()));

    return q;
}

/*
 * Initializes the game and outputs information based on if the user got the answer right or not.
 */
void TriviaGame::playGame(){
    int currentPoints = 0;
    while(currentPoints < pointsThreshold){

        if(questions.isEmpty()){
            cout << "You ran out of questions! You lost!" << endl;
            return;
        }
        Question q = questions.takeAt(0);
        cout << q.content.toStdString() << endl;
        for(int i = 0; i < q.answers.length(); i++){
            cout << i + 1 << ": " << q.answers[i].content.toStdString() << endl;
        }

        int choice = -1;
        while(choice <= 0 || choice > q.answers.length()) {
            cout << "Please enter a number: ";
            cin >> choice;
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
        }

        if(q.answers[choice - 1].isCorrect){
            currentPoints++;
            cout << "You were correct. A point has been added. Points left: " << (pointsThreshold - currentPoints) << endl;
        }
        else
            cout << "You were incorrect. Points left: " << (pointsThreshold - currentPoints) << endl;

        cout << "" << endl;

    }

    cout << "The alarm has been turned off." << endl;
}
