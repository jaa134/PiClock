#include "alarmpage.h"
#include "mathgame.h"
#include "QThread"

#define MATH 0

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

    ui->games->addWidget(new MathGame());
    MathGame *mathGame = qobject_cast<MathGame *>(ui->games->widget(MATH));
    connect(mathGame, &MathGame::gameOver, this, &AlarmPage::onGameOver);
    connect(mathGame, &MathGame::pointsUpdated, this, &AlarmPage::updatePointsLabel);
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
        case Game::Type::Concentration: {
            break;
        }
        case Game::Type::TicTacToe: {
            break;
        }
        case Game::Type::Trivia: {
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
