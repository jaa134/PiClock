/********************************************************************************
** Form generated from reading UI file 'piclockapp.ui'
**
** Created by: Qt User Interface Compiler version 5.12.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_PICLOCKAPP_H
#define UI_PICLOCKAPP_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QCheckBox>
#include <QtWidgets/QComboBox>
#include <QtWidgets/QFrame>
#include <QtWidgets/QLabel>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QProgressBar>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSlider>
#include <QtWidgets/QStackedWidget>
#include <QtWidgets/QTabWidget>
#include <QtWidgets/QWidget>
#include <settingsPage/draglistwidget.h>

QT_BEGIN_NAMESPACE

class Ui_PiClockApp
{
public:
    QWidget *centralWidget;
    QStackedWidget *layout;
    QWidget *start;
    QLabel *logo;
    QProgressBar *progressBar;
    QWidget *main;
    QWidget *clock;
    QLabel *time;
    QLabel *date;
    QStackedWidget *widgetSlideshow;
    QWidget *nw;
    QLabel *nw_title;
    QPushButton *settingsButton;
    QWidget *settings;
    QPushButton *mainButton;
    QTabWidget *options;
    QWidget *general;
    QComboBox *clockTimeFormatOptions;
    QSlider *slideDurationSlider;
    QLabel *clockTimeFormatLabel;
    QLabel *slideDurationLabel;
    QLabel *slideDurationValueLabel;
    QWidget *alarms;
    QComboBox *alarmGameEdit;
    QComboBox *alarmDifficultyEdit;
    QPushButton *alarmSetButton;
    DragListWidget *alarmList;
    DragListWidget *alarmTimeOptions;
    QLabel *alarmTimeLabel;
    QLabel *alarmGameLabel;
    QLabel *alarmDifficultyLabel;
    QWidget *widgets;
    QCheckBox *wclockCheckbox;
    QCheckBox *forecastCheckbox;
    QLabel *enabledLabel;
    QCheckBox *holidaysCheckbox;
    QCheckBox *sysstatsCheckbox;
    QCheckBox *weatherCheckbox;
    QCheckBox *quotesCheckbox;
    QFrame *line;
    QFrame *line_2;
    QFrame *line_3;
    QFrame *line_4;
    QFrame *line_5;
    QFrame *line_6;
    QFrame *line_7;
    QLabel *settingsHeader;
    QPushButton *settingsSaveButton;
    QPushButton *settingsCancelButton;
    QWidget *alarm;
    QStackedWidget *games;
    QLabel *pointsRequiredLabel;
    QLabel *currentPointsLabel;
    QLabel *timeRemainingLabel;
    QLabel *currentTimeLabel;

    void setupUi(QMainWindow *PiClockApp)
    {
        if (PiClockApp->objectName().isEmpty())
            PiClockApp->setObjectName(QString::fromUtf8("PiClockApp"));
        PiClockApp->resize(800, 480);
        PiClockApp->setStyleSheet(QString::fromUtf8(""));
        centralWidget = new QWidget(PiClockApp);
        centralWidget->setObjectName(QString::fromUtf8("centralWidget"));
        centralWidget->setStyleSheet(QString::fromUtf8(""));
        layout = new QStackedWidget(centralWidget);
        layout->setObjectName(QString::fromUtf8("layout"));
        layout->setGeometry(QRect(0, 0, 800, 480));
        start = new QWidget();
        start->setObjectName(QString::fromUtf8("start"));
        logo = new QLabel(start);
        logo->setObjectName(QString::fromUtf8("logo"));
        logo->setGeometry(QRect(0, 150, 800, 100));
        QFont font;
        font.setFamily(QString::fromUtf8("Tlwg Typist"));
        font.setPointSize(90);
        logo->setFont(font);
        logo->setAlignment(Qt::AlignCenter);
        progressBar = new QProgressBar(start);
        progressBar->setObjectName(QString::fromUtf8("progressBar"));
        progressBar->setGeometry(QRect(50, 270, 700, 25));
        progressBar->setValue(0);
        layout->addWidget(start);
        main = new QWidget();
        main->setObjectName(QString::fromUtf8("main"));
        clock = new QWidget(main);
        clock->setObjectName(QString::fromUtf8("clock"));
        clock->setGeometry(QRect(0, 0, 400, 150));
        clock->setStyleSheet(QString::fromUtf8(""));
        time = new QLabel(clock);
        time->setObjectName(QString::fromUtf8("time"));
        time->setGeometry(QRect(5, 10, 395, 80));
        QFont font1;
        font1.setFamily(QString::fromUtf8("Tlwg Typo"));
        font1.setPointSize(60);
        time->setFont(font1);
        time->setStyleSheet(QString::fromUtf8(""));
        date = new QLabel(clock);
        date->setObjectName(QString::fromUtf8("date"));
        date->setGeometry(QRect(10, 90, 390, 50));
        QFont font2;
        font2.setPointSize(40);
        date->setFont(font2);
        date->setStyleSheet(QString::fromUtf8(""));
        widgetSlideshow = new QStackedWidget(main);
        widgetSlideshow->setObjectName(QString::fromUtf8("widgetSlideshow"));
        widgetSlideshow->setGeometry(QRect(10, 160, 780, 310));
        widgetSlideshow->setStyleSheet(QString::fromUtf8("color: #fff;"));
        nw = new QWidget();
        nw->setObjectName(QString::fromUtf8("nw"));
        nw_title = new QLabel(nw);
        nw_title->setObjectName(QString::fromUtf8("nw_title"));
        nw_title->setGeometry(QRect(0, 0, 780, 310));
        QFont font3;
        font3.setPointSize(60);
        nw_title->setFont(font3);
        nw_title->setAlignment(Qt::AlignCenter);
        widgetSlideshow->addWidget(nw);
        settingsButton = new QPushButton(main);
        settingsButton->setObjectName(QString::fromUtf8("settingsButton"));
        settingsButton->setGeometry(QRect(726, 10, 64, 64));
        settingsButton->setStyleSheet(QString::fromUtf8(""));
        layout->addWidget(main);
        settings = new QWidget();
        settings->setObjectName(QString::fromUtf8("settings"));
        mainButton = new QPushButton(settings);
        mainButton->setObjectName(QString::fromUtf8("mainButton"));
        mainButton->setGeometry(QRect(726, 10, 64, 64));
        options = new QTabWidget(settings);
        options->setObjectName(QString::fromUtf8("options"));
        options->setEnabled(true);
        options->setGeometry(QRect(10, 70, 780, 350));
        QFont font4;
        font4.setPointSize(15);
        options->setFont(font4);
        options->setTabPosition(QTabWidget::North);
        options->setTabShape(QTabWidget::Rounded);
        options->setIconSize(QSize(16, 16));
        options->setElideMode(Qt::ElideNone);
        options->setDocumentMode(false);
        options->setTabsClosable(false);
        options->setMovable(false);
        options->setTabBarAutoHide(false);
        general = new QWidget();
        general->setObjectName(QString::fromUtf8("general"));
        clockTimeFormatOptions = new QComboBox(general);
        clockTimeFormatOptions->addItem(QString());
        clockTimeFormatOptions->addItem(QString());
        clockTimeFormatOptions->setObjectName(QString::fromUtf8("clockTimeFormatOptions"));
        clockTimeFormatOptions->setGeometry(QRect(15, 55, 300, 40));
        QFont font5;
        font5.setPointSize(20);
        clockTimeFormatOptions->setFont(font5);
        slideDurationSlider = new QSlider(general);
        slideDurationSlider->setObjectName(QString::fromUtf8("slideDurationSlider"));
        slideDurationSlider->setGeometry(QRect(340, 55, 420, 40));
        slideDurationSlider->setMinimum(0);
        slideDurationSlider->setMaximum(0);
        slideDurationSlider->setSingleStep(0);
        slideDurationSlider->setPageStep(0);
        slideDurationSlider->setValue(0);
        slideDurationSlider->setSliderPosition(0);
        slideDurationSlider->setOrientation(Qt::Horizontal);
        clockTimeFormatLabel = new QLabel(general);
        clockTimeFormatLabel->setObjectName(QString::fromUtf8("clockTimeFormatLabel"));
        clockTimeFormatLabel->setGeometry(QRect(15, 15, 300, 30));
        QFont font6;
        font6.setPointSize(18);
        clockTimeFormatLabel->setFont(font6);
        slideDurationLabel = new QLabel(general);
        slideDurationLabel->setObjectName(QString::fromUtf8("slideDurationLabel"));
        slideDurationLabel->setGeometry(QRect(340, 15, 250, 30));
        slideDurationLabel->setFont(font6);
        slideDurationValueLabel = new QLabel(general);
        slideDurationValueLabel->setObjectName(QString::fromUtf8("slideDurationValueLabel"));
        slideDurationValueLabel->setGeometry(QRect(590, 15, 170, 30));
        slideDurationValueLabel->setAlignment(Qt::AlignRight|Qt::AlignTrailing|Qt::AlignVCenter);
        options->addTab(general, QString());
        alarms = new QWidget();
        alarms->setObjectName(QString::fromUtf8("alarms"));
        alarmGameEdit = new QComboBox(alarms);
        alarmGameEdit->setObjectName(QString::fromUtf8("alarmGameEdit"));
        alarmGameEdit->setGeometry(QRect(210, 50, 200, 45));
        alarmGameEdit->setFont(font4);
        alarmDifficultyEdit = new QComboBox(alarms);
        alarmDifficultyEdit->setObjectName(QString::fromUtf8("alarmDifficultyEdit"));
        alarmDifficultyEdit->setGeometry(QRect(210, 150, 200, 45));
        alarmDifficultyEdit->setFont(font4);
        alarmSetButton = new QPushButton(alarms);
        alarmSetButton->setObjectName(QString::fromUtf8("alarmSetButton"));
        alarmSetButton->setGeometry(QRect(210, 245, 200, 45));
        alarmSetButton->setFont(font5);
        alarmList = new DragListWidget(alarms);
        alarmList->setObjectName(QString::fromUtf8("alarmList"));
        alarmList->setGeometry(QRect(421, 0, 355, 312));
        alarmList->setFont(font6);
        alarmList->setStyleSheet(QString::fromUtf8(""));
        alarmTimeOptions = new DragListWidget(alarms);
        alarmTimeOptions->setObjectName(QString::fromUtf8("alarmTimeOptions"));
        alarmTimeOptions->setGeometry(QRect(0, 50, 200, 262));
        alarmTimeOptions->setFont(font6);
        alarmTimeOptions->setStyleSheet(QString::fromUtf8(""));
        alarmTimeLabel = new QLabel(alarms);
        alarmTimeLabel->setObjectName(QString::fromUtf8("alarmTimeLabel"));
        alarmTimeLabel->setGeometry(QRect(0, 10, 200, 40));
        alarmTimeLabel->setFont(font5);
        alarmTimeLabel->setAlignment(Qt::AlignCenter);
        alarmGameLabel = new QLabel(alarms);
        alarmGameLabel->setObjectName(QString::fromUtf8("alarmGameLabel"));
        alarmGameLabel->setGeometry(QRect(210, 10, 200, 40));
        alarmGameLabel->setFont(font5);
        alarmGameLabel->setAlignment(Qt::AlignCenter);
        alarmDifficultyLabel = new QLabel(alarms);
        alarmDifficultyLabel->setObjectName(QString::fromUtf8("alarmDifficultyLabel"));
        alarmDifficultyLabel->setGeometry(QRect(210, 105, 200, 40));
        alarmDifficultyLabel->setFont(font5);
        alarmDifficultyLabel->setAlignment(Qt::AlignCenter);
        options->addTab(alarms, QString());
        widgets = new QWidget();
        widgets->setObjectName(QString::fromUtf8("widgets"));
        wclockCheckbox = new QCheckBox(widgets);
        wclockCheckbox->setObjectName(QString::fromUtf8("wclockCheckbox"));
        wclockCheckbox->setGeometry(QRect(50, 175, 200, 23));
        wclockCheckbox->setFont(font4);
        forecastCheckbox = new QCheckBox(widgets);
        forecastCheckbox->setObjectName(QString::fromUtf8("forecastCheckbox"));
        forecastCheckbox->setGeometry(QRect(50, 95, 200, 23));
        forecastCheckbox->setFont(font4);
        enabledLabel = new QLabel(widgets);
        enabledLabel->setObjectName(QString::fromUtf8("enabledLabel"));
        enabledLabel->setGeometry(QRect(15, 15, 125, 30));
        enabledLabel->setFont(font6);
        holidaysCheckbox = new QCheckBox(widgets);
        holidaysCheckbox->setObjectName(QString::fromUtf8("holidaysCheckbox"));
        holidaysCheckbox->setGeometry(QRect(50, 215, 200, 23));
        holidaysCheckbox->setFont(font4);
        sysstatsCheckbox = new QCheckBox(widgets);
        sysstatsCheckbox->setObjectName(QString::fromUtf8("sysstatsCheckbox"));
        sysstatsCheckbox->setGeometry(QRect(50, 255, 200, 23));
        sysstatsCheckbox->setFont(font4);
        weatherCheckbox = new QCheckBox(widgets);
        weatherCheckbox->setObjectName(QString::fromUtf8("weatherCheckbox"));
        weatherCheckbox->setGeometry(QRect(50, 55, 200, 23));
        weatherCheckbox->setFont(font4);
        weatherCheckbox->setCheckable(true);
        quotesCheckbox = new QCheckBox(widgets);
        quotesCheckbox->setObjectName(QString::fromUtf8("quotesCheckbox"));
        quotesCheckbox->setGeometry(QRect(50, 135, 200, 23));
        quotesCheckbox->setFont(font4);
        line = new QFrame(widgets);
        line->setObjectName(QString::fromUtf8("line"));
        line->setGeometry(QRect(15, 46, 20, 220));
        line->setFrameShape(QFrame::VLine);
        line->setFrameShadow(QFrame::Sunken);
        line_2 = new QFrame(widgets);
        line_2->setObjectName(QString::fromUtf8("line_2"));
        line_2->setGeometry(QRect(25, 65, 25, 3));
        line_2->setFrameShape(QFrame::HLine);
        line_2->setFrameShadow(QFrame::Sunken);
        line_3 = new QFrame(widgets);
        line_3->setObjectName(QString::fromUtf8("line_3"));
        line_3->setGeometry(QRect(25, 105, 25, 3));
        line_3->setFrameShape(QFrame::HLine);
        line_3->setFrameShadow(QFrame::Sunken);
        line_4 = new QFrame(widgets);
        line_4->setObjectName(QString::fromUtf8("line_4"));
        line_4->setGeometry(QRect(25, 145, 25, 3));
        line_4->setFrameShape(QFrame::HLine);
        line_4->setFrameShadow(QFrame::Sunken);
        line_5 = new QFrame(widgets);
        line_5->setObjectName(QString::fromUtf8("line_5"));
        line_5->setGeometry(QRect(25, 185, 25, 3));
        line_5->setFrameShape(QFrame::HLine);
        line_5->setFrameShadow(QFrame::Sunken);
        line_6 = new QFrame(widgets);
        line_6->setObjectName(QString::fromUtf8("line_6"));
        line_6->setGeometry(QRect(25, 225, 25, 3));
        line_6->setFrameShape(QFrame::HLine);
        line_6->setFrameShadow(QFrame::Sunken);
        line_7 = new QFrame(widgets);
        line_7->setObjectName(QString::fromUtf8("line_7"));
        line_7->setGeometry(QRect(25, 265, 25, 3));
        line_7->setFrameShape(QFrame::HLine);
        line_7->setFrameShadow(QFrame::Sunken);
        options->addTab(widgets, QString());
        settingsHeader = new QLabel(settings);
        settingsHeader->setObjectName(QString::fromUtf8("settingsHeader"));
        settingsHeader->setGeometry(QRect(10, 10, 250, 50));
        QFont font7;
        font7.setFamily(QString::fromUtf8("Tlwg Typo"));
        font7.setPointSize(40);
        settingsHeader->setFont(font7);
        settingsSaveButton = new QPushButton(settings);
        settingsSaveButton->setObjectName(QString::fromUtf8("settingsSaveButton"));
        settingsSaveButton->setGeometry(QRect(665, 430, 125, 40));
        QFont font8;
        font8.setFamily(QString::fromUtf8("Tlwg Typo"));
        font8.setPointSize(16);
        settingsSaveButton->setFont(font8);
        settingsCancelButton = new QPushButton(settings);
        settingsCancelButton->setObjectName(QString::fromUtf8("settingsCancelButton"));
        settingsCancelButton->setGeometry(QRect(520, 430, 125, 40));
        settingsCancelButton->setFont(font8);
        layout->addWidget(settings);
        alarm = new QWidget();
        alarm->setObjectName(QString::fromUtf8("alarm"));
        games = new QStackedWidget(alarm);
        games->setObjectName(QString::fromUtf8("games"));
        games->setGeometry(QRect(300, 70, 500, 410));
        pointsRequiredLabel = new QLabel(alarm);
        pointsRequiredLabel->setObjectName(QString::fromUtf8("pointsRequiredLabel"));
        pointsRequiredLabel->setGeometry(QRect(10, 250, 280, 70));
        QFont font9;
        font9.setPointSize(25);
        font9.setBold(true);
        font9.setWeight(75);
        pointsRequiredLabel->setFont(font9);
        pointsRequiredLabel->setStyleSheet(QString::fromUtf8("background-color: rgb(186, 189, 182);"));
        pointsRequiredLabel->setAlignment(Qt::AlignCenter);
        currentPointsLabel = new QLabel(alarm);
        currentPointsLabel->setObjectName(QString::fromUtf8("currentPointsLabel"));
        currentPointsLabel->setGeometry(QRect(10, 320, 280, 150));
        QFont font10;
        font10.setPointSize(90);
        font10.setBold(false);
        font10.setWeight(50);
        currentPointsLabel->setFont(font10);
        currentPointsLabel->setStyleSheet(QString::fromUtf8("background-color: rgb(225, 225, 225);"));
        currentPointsLabel->setAlignment(Qt::AlignCenter);
        timeRemainingLabel = new QLabel(alarm);
        timeRemainingLabel->setObjectName(QString::fromUtf8("timeRemainingLabel"));
        timeRemainingLabel->setGeometry(QRect(10, 10, 280, 70));
        timeRemainingLabel->setFont(font9);
        timeRemainingLabel->setStyleSheet(QString::fromUtf8("background-color: rgb(186, 189, 182);"));
        timeRemainingLabel->setAlignment(Qt::AlignCenter);
        currentTimeLabel = new QLabel(alarm);
        currentTimeLabel->setObjectName(QString::fromUtf8("currentTimeLabel"));
        currentTimeLabel->setGeometry(QRect(10, 80, 280, 150));
        currentTimeLabel->setFont(font10);
        currentTimeLabel->setStyleSheet(QString::fromUtf8("background-color: rgb(225, 225, 225);"));
        currentTimeLabel->setAlignment(Qt::AlignCenter);
        layout->addWidget(alarm);
        PiClockApp->setCentralWidget(centralWidget);

        retranslateUi(PiClockApp);

        layout->setCurrentIndex(3);
        widgetSlideshow->setCurrentIndex(0);
        options->setCurrentIndex(1);
        clockTimeFormatOptions->setCurrentIndex(-1);


        QMetaObject::connectSlotsByName(PiClockApp);
    } // setupUi

    void retranslateUi(QMainWindow *PiClockApp)
    {
        PiClockApp->setWindowTitle(QApplication::translate("PiClockApp", "PiClockApp", nullptr));
        logo->setText(QApplication::translate("PiClockApp", "PiClock", nullptr));
        time->setText(QApplication::translate("PiClockApp", "Time", nullptr));
        date->setText(QApplication::translate("PiClockApp", "Date", nullptr));
        nw_title->setText(QApplication::translate("PiClockApp", "no widgets enabled", nullptr));
        settingsButton->setText(QString());
        mainButton->setText(QString());
        clockTimeFormatOptions->setItemText(0, QApplication::translate("PiClockApp", "12 Hour (5:00pm)", nullptr));
        clockTimeFormatOptions->setItemText(1, QApplication::translate("PiClockApp", "24 Hour (17:00)", nullptr));

        clockTimeFormatLabel->setText(QApplication::translate("PiClockApp", "Clock Time Format", nullptr));
        slideDurationLabel->setText(QApplication::translate("PiClockApp", "Widget Slide Duration", nullptr));
        slideDurationValueLabel->setText(QApplication::translate("PiClockApp", "(seconds)", nullptr));
        options->setTabText(options->indexOf(general), QApplication::translate("PiClockApp", "General", nullptr));
        alarmSetButton->setText(QApplication::translate("PiClockApp", "Set", nullptr));
        alarmTimeLabel->setText(QApplication::translate("PiClockApp", "Time", nullptr));
        alarmGameLabel->setText(QApplication::translate("PiClockApp", "Game", nullptr));
        alarmDifficultyLabel->setText(QApplication::translate("PiClockApp", "Difficulty", nullptr));
        options->setTabText(options->indexOf(alarms), QApplication::translate("PiClockApp", "Alarms", nullptr));
        wclockCheckbox->setText(QApplication::translate("PiClockApp", " World Clocks", nullptr));
        forecastCheckbox->setText(QApplication::translate("PiClockApp", " Forecast", nullptr));
        enabledLabel->setText(QApplication::translate("PiClockApp", "Is Enabled?", nullptr));
        holidaysCheckbox->setText(QApplication::translate("PiClockApp", " Holiday Countdown", nullptr));
        sysstatsCheckbox->setText(QApplication::translate("PiClockApp", " System Usage", nullptr));
        weatherCheckbox->setText(QApplication::translate("PiClockApp", " Weather", nullptr));
        quotesCheckbox->setText(QApplication::translate("PiClockApp", " Quotes", nullptr));
        options->setTabText(options->indexOf(widgets), QApplication::translate("PiClockApp", "Widgets", nullptr));
        settingsHeader->setText(QApplication::translate("PiClockApp", "SETTINGS", nullptr));
        settingsSaveButton->setText(QApplication::translate("PiClockApp", "Save", nullptr));
        settingsCancelButton->setText(QApplication::translate("PiClockApp", "Cancel", nullptr));
        pointsRequiredLabel->setText(QApplication::translate("PiClockApp", "Points Required", nullptr));
        currentPointsLabel->setText(QApplication::translate("PiClockApp", "0", nullptr));
        timeRemainingLabel->setText(QApplication::translate("PiClockApp", "Time Remaining", nullptr));
        currentTimeLabel->setText(QApplication::translate("PiClockApp", "4:59", nullptr));
    } // retranslateUi

};

namespace Ui {
    class PiClockApp: public Ui_PiClockApp {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_PICLOCKAPP_H
