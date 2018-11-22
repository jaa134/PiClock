#include "triviagame.h"
#include "ui_triviagame.h"

TriviaGame::TriviaGame(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::TriviaGame)
{
    ui->setupUi(this);
    ui->questionLabel->setAlignment(Qt::AlignCenter);

    service = new TriviaGameService();

    timer = new QTimer();
    timer->setSingleShot(true);
    timer->setInterval(1500);
    connect(timer, &QTimer::timeout, this, &TriviaGame::nextQuestion);

    isAcceptingInput = false;

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
    bool isCorrect = service->answer(option);
    if (isCorrect)
        emit pointsUpdated(service->numPointsNeeded());

    setAnswerStyles(isCorrect, option);
    timer->start();
}

void TriviaGame::setAnswerStyles(bool isCorrect, int option) {
    QString buttonBackgroundColor;

    if (isCorrect) {
        buttonBackgroundColor = "background-color: #47d147;";
    }
    else {
        buttonBackgroundColor = "background-color: #ff3333;";
    }

    QString style = buttonBackgroundColor +
            "border: 0;"
            "padding: 10px;";

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
    ui->questionLabel->setText(service->question.text);

    ui->contentA->setText(service->question.options[optionA].text);
    ui->contentB->setText(service->question.options[optionB].text);
    ui->contentC->setText(service->question.options[optionC].text);
    ui->contentD->setText(service->question.options[optionD].text);
}
