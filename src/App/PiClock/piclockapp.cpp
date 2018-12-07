#include "piclockapp.h"
#include "ui_piclockapp.h"
#include "QTimer"
#include "QMenuBar"

#define LOADITEMS 1

PiClockApp::PiClockApp(QWidget *parent) : QMainWindow(parent), ui(new Ui::PiClockApp)
{
    ui->setupUi(this);
    this->menuBar()->hide();
    this->setWindowFlag(Qt::FramelessWindowHint);
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
    connect(this, &PiClockApp::loadFinished, this, &PiClockApp::transitionToMainPage);
    connect(mainPage, &MainPage::chunkLoaded, this, &PiClockApp::updateProgressBar);
    connect(settingsPage, &SettingsPage::chunkLoaded, this, &PiClockApp::updateProgressBar);
    connect(settingsPage, &SettingsPage::settingsSaved, alarmPage, &AlarmPage::onSettingsSaved);

    //add custom scroll bars
    ui->layout->setStyleSheet(QString(
        "QScrollBar:vertical { "
        "   background: #dddddd;"
        "   width: 15px; "
        "   margin: 0px 0px 0px 0px"
        "}"
        "QScrollBar::handle:vertical {"
        "    background: qlineargradient(x1:0, y1:0, x2:1, y2:0,"
        "    stop: 0 rgb(160, 160, 160), stop: 0.5 rgb(160, 160, 160), stop:1 rgb(160, 160, 160));"
        "    min-height: 0px;"
        "}"
        "QScrollBar::add-line:vertical {"
        "    background: qlineargradient(x1:0, y1:0, x2:1, y2:0,"
        "    stop: 0 rgb(160, 160, 160), stop: 0.5 rgb(160, 160, 160),  stop:1 rgb(160, 160, 160));"
        "    height: 0px;"
        "    subcontrol-position: bottom;"
        "    subcontrol-origin: margin;"
        "}"
        "QScrollBar::sub-line:vertical {"
        "    background: qlineargradient(x1:0, y1:0, x2:1, y2:0,"
        "    stop: 0  rgb(160, 160, 160), stop: 0.5 rgb(160, 160, 160),  stop:1 rgb(160, 160, 160));"
        "    height: 0 px;"
        "    subcontrol-position: top;"
        "    subcontrol-origin: margin;"
        "}"
    ));
}

void PiClockApp::transitionToMainPage() {
    QTimer::singleShot(2000, [this](){ ui->layout->setCurrentIndex(1); });
}

void PiClockApp::updateProgressBar() {
    //update load progrss bar. everytime method is called, update the value a set amount
    int current_value = ui->progressBar->value();
    int new_value = current_value + (100 / LOADITEMS);
    ui->progressBar->setValue(new_value);

    if (new_value == 100)
        emit loadFinished();
}

