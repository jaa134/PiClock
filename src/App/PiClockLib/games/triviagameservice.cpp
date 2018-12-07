#include "triviagameservice.h"

TriviaGameService::TriviaGameService() {
    std::srand(time(nullptr));
    manager = new QNetworkAccessManager();
    connect(manager, &QNetworkAccessManager::finished, &replyLoop, &QEventLoop::quit);
    connect(manager, &QNetworkAccessManager::finished, this, &TriviaGameService::generateQuestions);
}

void TriviaGameService::getQuestions() {
    //make a network request for questions
    request.setUrl(QUrl("https://opentdb.com/api.php?amount=100&type=multiple"));
    manager->get(request);
    replyLoop.exec();
}

void TriviaGameService::generateQuestions(QNetworkReply *reply) {
    //if there is an answer, send it to debug
    if (reply->error()) {
        qDebug() << reply->errorString();
        return;
    }

    //read contents and parse json
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

    cycleQuestion();
}

QString TriviaGameService::toPlainString(QString ques) {
    //remove special chars
    QTextDocument text;
    text.setHtml(ques);
    return text.toPlainText();
}

TriviaGameService::Question TriviaGameService::responseToQuestion(ResponseObject response) {
    //make a question from response object
    Question q;
    q.text = response.question;

    Answer ca0;
    ca0.isCorrect = true;
    ca0.text = response.correct_answer;
    Answer ia0;
    ia0.isCorrect = false;
    ia0.text = response.incorrect_answers[0];
    Answer ia1;
    ia1.isCorrect = false;
    ia1.text = response.incorrect_answers[1];
    Answer ia2;
    ia2.isCorrect = false;
    ia2.text = response.incorrect_answers[2];

    QList<Answer> temp = QList<Answer>({ca0, ia0, ia1, ia2});
    q.options.append(temp.takeAt(rand() % temp.length()));
    q.options.append(temp.takeAt(rand() % temp.length()));
    q.options.append(temp.takeAt(rand() % temp.length()));
    q.options.append(temp.takeAt(rand() % temp.length()));

    return q;
}

bool TriviaGameService::answer(int choice) {
    //answer the question
    bool isCorrect = question.options[choice].isCorrect;
    //award points if its correct
    if (isCorrect)
        currentPoints++;
    //change question
    cycleQuestion();
    return isCorrect;
}

void TriviaGameService::reset(Game::Difficulty difficulty) {
    currentPoints = 0;

    //update number of points required to win
    if (difficulty == Game::Difficulty::Easy)
        pointsToWin = 3;
    if (difficulty == Game::Difficulty::Medium)
        pointsToWin = 5;
    if (difficulty == Game::Difficulty::Hard)
        pointsToWin = 7;

    getQuestions();
}

void TriviaGameService::cycleQuestion() {
    do {
        if (questions.length() > 0) {
            question = questions.takeFirst();
        }
        else {
            currentPoints = pointsToWin;
            return;
        }
    } while (!isValidQuestion());
}

bool TriviaGameService::isValidQuestion() {
    //valid questions must be of a certain length to show in full in the ui
    int maxQuestionLength = 60;
    int maxAnswerLength = 22;
    return question.text.length() <= maxQuestionLength &&
            question.options.at(0).text.length() <= maxAnswerLength &&
            question.options.at(1).text.length() <= maxAnswerLength &&
            question.options.at(2).text.length() <= maxAnswerLength &&
            question.options.at(3).text.length() <= maxAnswerLength;
}
