#include "alarmpage.h"
#include "mathgame.h"
#include "tictactoegame.h"
#include "QThread"

#define MATH 0
#define TICTACTOE 1

AlarmPage::AlarmPage(Ui::PiClockApp *ui) {
    this->ui = ui;
    timer_clock = new QTimer();
    alarm_manager = new AlarmManager();  
}

void AlarmPage::init() {
    timer_clock->setInterval(100);
    connect(timer_clock, &QTimer::timeout, this, &AlarmPage::updateRemainingTime);

    connect(alarm_manager, &AlarmManager::alarmStopped, this, &AlarmPage::navToMain);
    connect(alarm_manager, &AlarmManager::alarmStarted, this, &AlarmPage::navToAlarm);
    alarm_manager->init();
    emit chunkLoaded();

    MathGame *mathGame = new MathGame();
    ui->games->addWidget(mathGame);
    connect(mathGame, &MathGame::gameOver, this, &AlarmPage::onGameOver);
    connect(mathGame, &MathGame::pointsUpdated, this, &AlarmPage::updatePointsLabel);

    TicTacToeGame *tictactoeGame = new TicTacToeGame();
    ui->games->addWidget(tictactoeGame);
    connect(tictactoeGame, &TicTacToeGame::gameOver, this, &AlarmPage::onGameOver);
    connect(tictactoeGame, &TicTacToeGame::pointsUpdated, this, &AlarmPage::updatePointsLabel);
    emit chunkLoaded();
}

void AlarmPage::onSettingsSaved() {
    alarm_manager->init();
}

void AlarmPage::navToMain() {
    QThread::sleep(2);
    ui->layout->setCurrentIndex(1);
}

void AlarmPage::navToAlarm(Game::Type type, Game::Difficulty difficulty) {
    switch (type) {
        case Game::Type::Math: {
            ui->games->setCurrentIndex(MATH);
            MathGame *game = qobject_cast<MathGame *>(ui->games->currentWidget());
            game->init(difficulty);
            break;
        }
        case Game::Type::TicTacToe: {
            ui->games->setCurrentIndex(TICTACTOE);
            TicTacToeGame *game = qobject_cast<TicTacToeGame *>(ui->games->currentWidget());
            game->init(difficulty);
            break;
        }
    }
    ui->currentTimeLabel->setText("4:59");
    timer_clock->start();
    ui->layout->setCurrentIndex(3);
}

void AlarmPage::onGameOver() {
    timer_clock->stop();
    alarm_manager->stopAlarm();
}

void AlarmPage::updatePointsLabel(int newPoints) {
    ui->currentPointsLabel->setText(QString::number(newPoints));
}

void AlarmPage::updateRemainingTime() {
    ui->currentTimeLabel->setText(alarm_manager->timeRemaining());
}
