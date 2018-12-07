#include "triviagame.h"
#include "ui_triviagame.h"

TriviaGame::TriviaGame(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::TriviaGame)
{
    ui->setupUi(this);
    ui->questionLabel->setAlignment(Qt::AlignCenter);

    service = new TriviaGameService();

    //setup timer inbetween turns
    timer = new QTimer();
    timer->setSingleShot(true);
    timer->setInterval(1500);
    connect(timer, &QTimer::timeout, this, &TriviaGame::nextQuestion);

    isAcceptingInput = false;

    //setup game buttons
    connect(ui->answerButtonA, &QPushButton::released, this, &TriviaGame::onButtonA);
    connect(ui->answerButtonB, &QPushButton::released, this, &TriviaGame::onButtonB);
    connect(ui->answerButtonC, &QPushButton::released, this, &TriviaGame::onButtonC);
    connect(ui->answerButtonD, &QPushButton::released, this, &TriviaGame::onButtonD);
}

TriviaGame::~TriviaGame()
{
    delete ui;
}

void TriviaGame::init(Game::Difficulty difficulty) {
    service->reset(difficulty);
    emit pointsUpdated(service->numPointsNeeded());
    nextQuestion();
}

void TriviaGame::setInputEnabled(bool isEnabled) {
    isAcceptingInput = isEnabled;
}

void TriviaGame::onButtonA() {
    if (isAcceptingInput) {
        setInputEnabled(false);
        onAnswer(optionA);
    }
}

void TriviaGame::onButtonB() {
    if (isAcceptingInput) {
        setInputEnabled(false);
        onAnswer(optionB);
    }
}

void TriviaGame::onButtonC() {
    if (isAcceptingInput) {
        setInputEnabled(false);
        onAnswer(optionC);
    }
}

void TriviaGame::onButtonD() {
    if (isAcceptingInput) {
        setInputEnabled(false);
        onAnswer(optionD);
    }
}

void TriviaGame::onAnswer(int option) {
    //determine if answer is correct
    bool isCorrect = service->answer(option);
    //update points if correct
    if (isCorrect)
        emit pointsUpdated(service->numPointsNeeded());

    //update button styles
    setAnswerStyles(isCorrect, option);
    timer->start();
}

void TriviaGame::setAnswerStyles(bool isCorrect, int option) {
    QString buttonBackgroundColor;

    //set correct answers to green background
    if (isCorrect)
        buttonBackgroundColor = "background-color: #47d147;";
    //set incorrect answers to red background
    else
        buttonBackgroundColor = "background-color: #ff3333;";

    QString style = buttonBackgroundColor +
            "border: 0;"
            "padding: 10px;";

    //determine which button to apply the style to
    switch (option) {
        case optionA: {
            ui->contentA->setStyleSheet(style);
            break;
        }
        case optionB: {
            ui->contentB->setStyleSheet(style);
            break;
        }
        case optionC: {
            ui->contentC->setStyleSheet(style);
            break;
        }
        case optionD: {
            ui->contentD->setStyleSheet(style);
            break;
        }
    }
}

void TriviaGame::nextQuestion() {
    if (service->isWinner()) {
        emit gameOver();
        return;
    }

    setDefaultStyles();
    displayQuestion();
    setInputEnabled(true);
}

void TriviaGame::setDefaultStyles() {
    //add default grey color to buttons
    QString buttonBackgroundColor = "background-color: rgb(210, 210, 210);";
    QString style = buttonBackgroundColor +
            "border: 0;"
            "padding: 10px;";
    ui->contentA->setStyleSheet(style);
    ui->contentB->setStyleSheet(style);
    ui->contentC->setStyleSheet(style);
    ui->contentD->setStyleSheet(style);
}

void TriviaGame::displayQuestion() {
    //display the question
    ui->questionLabel->setText(service->question.text);

    //display the answers
    ui->contentA->setText(service->question.options[optionA].text);
    ui->contentB->setText(service->question.options[optionB].text);
    ui->contentC->setText(service->question.options[optionC].text);
    ui->contentD->setText(service->question.options[optionD].text);
}
