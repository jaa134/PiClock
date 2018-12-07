#include "mathgameservice.h"
#include "QSet"

#define ADD "+"
#define SUBTRACT "-"
#define MULTIPLY "*"
#define DIVIDE "/"

MathGameService::MathGameService()
{ }

QString MathGameService::operators[] = { ADD, SUBTRACT, MULTIPLY, DIVIDE };

bool MathGameService::generateQuestion() {
    std::srand(time(nullptr));
    //chose two random numbers and a random operator
    int num1 = (rand() % (maxNum-minNum + 1)) + minNum;
    int num2 = (rand() % (maxNum-minNum + 1)) + minNum;
    QString op = operators[rand() % numOperators];

    //dont use zero
    if (num1 == 0 || num2 == 0)
        return false;

    //set the question text
    question.text = QString::number(num1) + "  " + op + "  " + QString::number(num2);

    Answer a0;
    Answer a1;
    Answer a2;
    Answer a3;

    a0.isCorrect = op == ADD;
    a1.isCorrect = op == SUBTRACT;
    a2.isCorrect = op == MULTIPLY;
    a3.isCorrect = op == DIVIDE;

    //set the answer text
    a0.text = QString::number(num1 + num2);
    a1.text = QString::number(num1 - num2);
    a2.text = QString::number(num1 * num2);
    a3.text = QString::number(double(num1) / double(num2), 'g', 3);

    int numExpectedAnswers = 4;
    int numDistinctAnswers = QSet<QString>::fromList({ a0.text, a1.text, a2.text, a3.text }).count();
    if (numDistinctAnswers < numExpectedAnswers)
        return false;

    QList<Answer> answers = QList<Answer>({ a0, a1, a2, a3 });
    question.options.clear();
    question.options.append(answers.takeAt(rand() % answers.length()));
    question.options.append(answers.takeAt(rand() % answers.length()));
    question.options.append(answers.takeAt(rand() % answers.length()));
    question.options.append(answers.takeAt(rand() % answers.length()));

    return true;
}

bool MathGameService::answer(int choice) {
    //test if the choice is correct
    bool isCorrect = question.options[choice].isCorrect;
    //add points if it is correct
    if (isCorrect)
        currentPoints++;
    //generate the next quetion
    while (!generateQuestion());
    return isCorrect;
}

void MathGameService::reset(Game::Difficulty difficulty) {
    currentPoints = 0;

    if (difficulty == Game::Difficulty::Easy)
        pointsToWin = 3;
    if (difficulty == Game::Difficulty::Medium)
        pointsToWin = 5;
    if (difficulty == Game::Difficulty::Hard)
        pointsToWin = 7;

    while (!generateQuestion());
}
