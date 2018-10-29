/********************************************************************************
** Form generated from reading UI file 'piclockapp.ui'
**
** Created by: Qt User Interface Compiler version 5.11.2
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
    QPushButton *settingsRestoreButton;
    QPushButton *settingsCancelButton;

    void setupUi(QMainWindow *PiClockApp)
    {
        if (PiClockApp->objectName().isEmpty())
            PiClockApp->setObjectName(QStringLiteral("PiClockApp"));
        PiClockApp->resize(800, 480);
        PiClockApp->setStyleSheet(QStringLiteral(""));
        centralWidget = new QWidget(PiClockApp);
        centralWidget->setObjectName(QStringLiteral("centralWidget"));
        centralWidget->setStyleSheet(QStringLiteral(""));
        layout = new QStackedWidget(centralWidget);
        layout->setObjectName(QStringLiteral("layout"));
        layout->setGeometry(QRect(0, 0, 800, 480));
        start = new QWidget();
        start->setObjectName(QStringLiteral("start"));
        logo = new QLabel(start);
        logo->setObjectName(QStringLiteral("logo"));
        logo->setGeometry(QRect(0, 150, 800, 100));
        QFont font;
        font.setFamily(QStringLiteral("Tlwg Typist"));
        font.setPointSize(90);
        logo->setFont(font);
        logo->setAlignment(Qt::AlignCenter);
        progressBar = new QProgressBar(start);
        progressBar->setObjectName(QStringLiteral("progressBar"));
        progressBar->setGeometry(QRect(50, 270, 700, 25));
        progressBar->setValue(0);
        layout->addWidget(start);
        main = new QWidget();
        main->setObjectName(QStringLiteral("main"));
        clock = new QWidget(main);
        clock->setObjectName(QStringLiteral("clock"));
        clock->setGeometry(QRect(0, 0, 400, 150));
        clock->setStyleSheet(QStringLiteral(""));
        time = new QLabel(clock);
        time->setObjectName(QStringLiteral("time"));
        time->setGeometry(QRect(5, 10, 395, 80));
        QFont font1;
        font1.setFamily(QStringLiteral("Tlwg Typo"));
        font1.setPointSize(60);
        time->setFont(font1);
        time->setStyleSheet(QStringLiteral(""));
        date = new QLabel(clock);
        date->setObjectName(QStringLiteral("date"));
        date->setGeometry(QRect(10, 90, 390, 50));
        QFont font2;
        font2.setPointSize(40);
        date->setFont(font2);
        date->setStyleSheet(QStringLiteral(""));
        widgetSlideshow = new QStackedWidget(main);
        widgetSlideshow->setObjectName(QStringLiteral("widgetSlideshow"));
        widgetSlideshow->setGeometry(QRect(10, 160, 780, 310));
        widgetSlideshow->setStyleSheet(QStringLiteral("color: #fff;"));
        nw = new QWidget();
        nw->setObjectName(QStringLiteral("nw"));
        nw_title = new QLabel(nw);
        nw_title->setObjectName(QStringLiteral("nw_title"));
        nw_title->setGeometry(QRect(0, 0, 780, 310));
        QFont font3;
        font3.setPointSize(60);
        nw_title->setFont(font3);
        nw_title->setAlignment(Qt::AlignCenter);
        widgetSlideshow->addWidget(nw);
        settingsButton = new QPushButton(main);
        settingsButton->setObjectName(QStringLiteral("settingsButton"));
        settingsButton->setGeometry(QRect(726, 10, 64, 64));
        settingsButton->setStyleSheet(QStringLiteral(""));
        layout->addWidget(main);
        settings = new QWidget();
        settings->setObjectName(QStringLiteral("settings"));
        mainButton = new QPushButton(settings);
        mainButton->setObjectName(QStringLiteral("mainButton"));
        mainButton->setGeometry(QRect(726, 10, 64, 64));
        options = new QTabWidget(settings);
        options->setObjectName(QStringLiteral("options"));
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
        general->setObjectName(QStringLiteral("general"));
        clockTimeFormatOptions = new QComboBox(general);
        clockTimeFormatOptions->addItem(QString());
        clockTimeFormatOptions->addItem(QString());
        clockTimeFormatOptions->setObjectName(QStringLiteral("clockTimeFormatOptions"));
        clockTimeFormatOptions->setGeometry(QRect(15, 55, 300, 40));
        QFont font5;
        font5.setPointSize(20);
        clockTimeFormatOptions->setFont(font5);
        slideDurationSlider = new QSlider(general);
        slideDurationSlider->setObjectName(QStringLiteral("slideDurationSlider"));
        slideDurationSlider->setGeometry(QRect(340, 55, 420, 40));
        slideDurationSlider->setMinimum(0);
        slideDurationSlider->setMaximum(0);
        slideDurationSlider->setSingleStep(0);
        slideDurationSlider->setPageStep(0);
        slideDurationSlider->setValue(0);
        slideDurationSlider->setSliderPosition(0);
        slideDurationSlider->setOrientation(Qt::Horizontal);
        clockTimeFormatLabel = new QLabel(general);
        clockTimeFormatLabel->setObjectName(QStringLiteral("clockTimeFormatLabel"));
        clockTimeFormatLabel->setGeometry(QRect(15, 15, 300, 30));
        QFont font6;
        font6.setPointSize(18);
        clockTimeFormatLabel->setFont(font6);
        slideDurationLabel = new QLabel(general);
        slideDurationLabel->setObjectName(QStringLiteral("slideDurationLabel"));
        slideDurationLabel->setGeometry(QRect(340, 15, 250, 30));
        slideDurationLabel->setFont(font6);
        slideDurationValueLabel = new QLabel(general);
        slideDurationValueLabel->setObjectName(QStringLiteral("slideDurationValueLabel"));
        slideDurationValueLabel->setGeometry(QRect(590, 15, 170, 30));
        slideDurationValueLabel->setAlignment(Qt::AlignRight|Qt::AlignTrailing|Qt::AlignVCenter);
        options->addTab(general, QString());
        alarms = new QWidget();
        alarms->setObjectName(QStringLiteral("alarms"));
        options->addTab(alarms, QString());
        widgets = new QWidget();
        widgets->setObjectName(QStringLiteral("widgets"));
        wclockCheckbox = new QCheckBox(widgets);
        wclockCheckbox->setObjectName(QStringLiteral("wclockCheckbox"));
        wclockCheckbox->setGeometry(QRect(50, 175, 200, 23));
        wclockCheckbox->setFont(font4);
        forecastCheckbox = new QCheckBox(widgets);
        forecastCheckbox->setObjectName(QStringLiteral("forecastCheckbox"));
        forecastCheckbox->setGeometry(QRect(50, 95, 200, 23));
        forecastCheckbox->setFont(font4);
        enabledLabel = new QLabel(widgets);
        enabledLabel->setObjectName(QStringLiteral("enabledLabel"));
        enabledLabel->setGeometry(QRect(15, 15, 125, 30));
        enabledLabel->setFont(font6);
        holidaysCheckbox = new QCheckBox(widgets);
        holidaysCheckbox->setObjectName(QStringLiteral("holidaysCheckbox"));
        holidaysCheckbox->setGeometry(QRect(50, 215, 200, 23));
        holidaysCheckbox->setFont(font4);
        sysstatsCheckbox = new QCheckBox(widgets);
        sysstatsCheckbox->setObjectName(QStringLiteral("sysstatsCheckbox"));
        sysstatsCheckbox->setGeometry(QRect(50, 255, 200, 23));
        sysstatsCheckbox->setFont(font4);
        weatherCheckbox = new QCheckBox(widgets);
        weatherCheckbox->setObjectName(QStringLiteral("weatherCheckbox"));
        weatherCheckbox->setGeometry(QRect(50, 55, 200, 23));
        weatherCheckbox->setFont(font4);
        weatherCheckbox->setCheckable(true);
        quotesCheckbox = new QCheckBox(widgets);
        quotesCheckbox->setObjectName(QStringLiteral("quotesCheckbox"));
        quotesCheckbox->setGeometry(QRect(50, 135, 200, 23));
        quotesCheckbox->setFont(font4);
        line = new QFrame(widgets);
        line->setObjectName(QStringLiteral("line"));
        line->setGeometry(QRect(15, 46, 20, 220));
        line->setFrameShape(QFrame::VLine);
        line->setFrameShadow(QFrame::Sunken);
        line_2 = new QFrame(widgets);
        line_2->setObjectName(QStringLiteral("line_2"));
        line_2->setGeometry(QRect(25, 65, 25, 3));
        line_2->setFrameShape(QFrame::HLine);
        line_2->setFrameShadow(QFrame::Sunken);
        line_3 = new QFrame(widgets);
        line_3->setObjectName(QStringLiteral("line_3"));
        line_3->setGeometry(QRect(25, 105, 25, 3));
        line_3->setFrameShape(QFrame::HLine);
        line_3->setFrameShadow(QFrame::Sunken);
        line_4 = new QFrame(widgets);
        line_4->setObjectName(QStringLiteral("line_4"));
        line_4->setGeometry(QRect(25, 145, 25, 3));
        line_4->setFrameShape(QFrame::HLine);
        line_4->setFrameShadow(QFrame::Sunken);
        line_5 = new QFrame(widgets);
        line_5->setObjectName(QStringLiteral("line_5"));
        line_5->setGeometry(QRect(25, 185, 25, 3));
        line_5->setFrameShape(QFrame::HLine);
        line_5->setFrameShadow(QFrame::Sunken);
        line_6 = new QFrame(widgets);
        line_6->setObjectName(QStringLiteral("line_6"));
        line_6->setGeometry(QRect(25, 225, 25, 3));
        line_6->setFrameShape(QFrame::HLine);
        line_6->setFrameShadow(QFrame::Sunken);
        line_7 = new QFrame(widgets);
        line_7->setObjectName(QStringLiteral("line_7"));
        line_7->setGeometry(QRect(25, 265, 25, 3));
        line_7->setFrameShape(QFrame::HLine);
        line_7->setFrameShadow(QFrame::Sunken);
        options->addTab(widgets, QString());
        settingsHeader = new QLabel(settings);
        settingsHeader->setObjectName(QStringLiteral("settingsHeader"));
        settingsHeader->setGeometry(QRect(10, 10, 250, 50));
        QFont font7;
        font7.setFamily(QStringLiteral("Tlwg Typo"));
        font7.setPointSize(40);
        settingsHeader->setFont(font7);
        settingsSaveButton = new QPushButton(settings);
        settingsSaveButton->setObjectName(QStringLiteral("settingsSaveButton"));
        settingsSaveButton->setGeometry(QRect(665, 430, 125, 40));
        QFont font8;
        font8.setFamily(QStringLiteral("Tlwg Typo"));
        font8.setPointSize(16);
        settingsSaveButton->setFont(font8);
        settingsRestoreButton = new QPushButton(settings);
        settingsRestoreButton->setObjectName(QStringLiteral("settingsRestoreButton"));
        settingsRestoreButton->setGeometry(QRect(390, 430, 260, 40));
        settingsRestoreButton->setFont(font8);
        settingsCancelButton = new QPushButton(settings);
        settingsCancelButton->setObjectName(QStringLiteral("settingsCancelButton"));
        settingsCancelButton->setGeometry(QRect(250, 430, 125, 40));
        settingsCancelButton->setFont(font8);
        layout->addWidget(settings);
        PiClockApp->setCentralWidget(centralWidget);

        retranslateUi(PiClockApp);

        layout->setCurrentIndex(2);
        widgetSlideshow->setCurrentIndex(0);
        options->setCurrentIndex(0);
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
        settingsRestoreButton->setText(QApplication::translate("PiClockApp", "Restore Defaults", nullptr));
        settingsCancelButton->setText(QApplication::translate("PiClockApp", "Cancel", nullptr));
    } // retranslateUi

};

namespace Ui {
    class PiClockApp: public Ui_PiClockApp {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_PICLOCKAPP_H
