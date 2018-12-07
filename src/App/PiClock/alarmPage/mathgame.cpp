#include "mathgame.h"
#include "ui_mathgame.h"

MathGame::MathGame(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::MathGame)
{
    ui->setupUi(this);

    service = new MathGameService();

    //setup pause timer between questions
    timer = new QTimer();
    timer->setSingleShot(true);
    timer->setInterval(1500);
    connect(timer, &QTimer::timeout, this, &MathGame::nextQuestion);

    isAcceptingInput = false;

    //setup game buttons
    connect(ui->answerButtonA, &QPushButton::released, this, &MathGame::onButtonA);
    connect(ui->answerButtonB, &QPushButton::released, this, &MathGame::onButtonB);
    connect(ui->answerButtonC, &QPushButton::released, this, &MathGame::onButtonC);
    connect(ui->answerButtonD, &QPushButton::released, this, &MathGame::onButtonD);
}

MathGame::~MathGame()
{
    delete ui;
}

void MathGame::init(Game::Difficulty difficulty) {
    service->reset(difficulty);
    emit pointsUpdated(service->numPointsNeeded());
    nextQuestion();
}

void MathGame::setInputEnabled(bool isEnabled) {
    isAcceptingInput = isEnabled;
}

void MathGame::onButtonA() {
    if (isAcceptingInput) {
        setInputEnabled(false);
        onAnswer(optionA);
    }
}

void MathGame::onButtonB() {
    if (isAcceptingInput) {
        setInputEnabled(false);
        onAnswer(optionB);
    }
}

void MathGame::onButtonC() {
    if (isAcceptingInput) {
        setInputEnabled(false);
        onAnswer(optionC);
    }
}

void MathGame::onButtonD() {
    if (isAcceptingInput) {
        setInputEnabled(false);
        onAnswer(optionD);
    }
}

void MathGame::onAnswer(int option) {
    bool isCorrect = service->answer(option);
    if (isCorrect)
        emit pointsUpdated(service->numPointsNeeded());

    setAnswerStyles(isCorrect, option);
    timer->start();
}

void MathGame::setAnswerStyles(bool isCorrect, int option) {
    QString buttonBackgroundColor;

    if (isCorrect) {
        //color it green
        buttonBackgroundColor = "background-color: #47d147";
    }
    else {
        //color it red
        buttonBackgroundColor = "background-color: #ff3333";
    }

    //add the style to the button pressed
    switch (option) {
        case optionA: {
            ui->answerButtonA->setStyleSheet(buttonBackgroundColor);
            break;
        }
        case optionB: {
            ui->answerButtonB->setStyleSheet(buttonBackgroundColor);
            break;
        }
        case optionC: {
            ui->answerButtonC->setStyleSheet(buttonBackgroundColor);
            break;
        }
        case optionD: {
            ui->answerButtonD->setStyleSheet(buttonBackgroundColor);
            break;
        }
    }
}

void MathGame::nextQuestion() {
    if (service->isWinner()) {
        emit gameOver();
        return;
    }

    setDefaultStyles();
    displayQuestion();
    setInputEnabled(true);
}

void MathGame::setDefaultStyles() {
    //add back in the default grey button color
    QString buttonBackgroundColor = "background-color: rgb(210, 210, 210)";
    ui->answerButtonA->setStyleSheet(buttonBackgroundColor);
    ui->answerButtonB->setStyleSheet(buttonBackgroundColor);
    ui->answerButtonC->setStyleSheet(buttonBackgroundColor);
    ui->answerButtonD->setStyleSheet(buttonBackgroundColor);
}

void MathGame::displayQuestion() {
    //show the question
    ui->questionLabel->setText(service->question.text);

    //show the answers
    ui->answerButtonA->setText(service->question.options[optionA].text);
    ui->answerButtonB->setText(service->question.options[optionB].text);
    ui->answerButtonC->setText(service->question.options[optionC].text);
    ui->answerButtonD->setText(service->question.options[optionD].text);
}
