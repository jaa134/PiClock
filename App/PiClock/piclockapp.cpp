#include "piclockapp.h"
#include "ui_piclockapp.h"
#include "QTimer"

#define LOADITEMS 1

PiClockApp::PiClockApp(QWidget *parent) : QMainWindow(parent), ui(new Ui::PiClockApp)
{
    ui->setupUi(this);
    mainPage = new MainPage(ui);
    settingsPage = new SettingsPage(ui);
    alarmPage = new AlarmPage(ui);
}

PiClockApp::~PiClockApp()
{
    delete mainPage;
    delete ui;
}

void PiClockApp::init() {
    initWindow();
    mainPage->init();
    settingsPage->init();
    alarmPage->init();
}

void PiClockApp::initWindow() {
    setFixedSize(QSize(800, 480));
    setStyleSheet("QMainWindow{ background-image: url(:/images/background.png); }");
    ui->layout->setCurrentIndex(0);

    //label
    ui->logo->setStyleSheet("color: #fff");

    //progress bar
    connect(this, SIGNAL(loadFinished()), this, SLOT(transitionToMainPage()));
    connect(mainPage, SIGNAL(chunkLoaded()), this, SLOT(updateProgressBar()));
    connect(settingsPage, SIGNAL(chunkLoaded()), this, SLOT(updateProgressBar()));
}

void PiClockApp::transitionToMainPage() {
    QTimer::singleShot(2000, [this](){ ui->layout->setCurrentIndex(1); });
}

void PiClockApp::updateProgressBar() {
    int current_value = ui->progressBar->value();
    int new_value = current_value + (100 / LOADITEMS);
    ui->progressBar->setValue(new_value);

    if (new_value == 100)
        emit loadFinished();
}

