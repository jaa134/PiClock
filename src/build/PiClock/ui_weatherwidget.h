/********************************************************************************
** Form generated from reading UI file 'weatherwidget.ui'
**
** Created by: Qt User Interface Compiler version 5.12.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_WEATHERWIDGET_H
#define UI_WEATHERWIDGET_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QGraphicsView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_WeatherWidget
{
public:
    QGraphicsView *weatherIcon;
    QLabel *degreeValue;
    QLabel *tempRangeLabel;
    QLabel *humidityLabel;
    QLabel *windLabel;
    QLabel *humidityValue;
    QLabel *windValue;
    QLabel *locationValue;
    QLabel *tempRangeValue;

    void setupUi(QWidget *WeatherWidget)
    {
        if (WeatherWidget->objectName().isEmpty())
            WeatherWidget->setObjectName(QString::fromUtf8("WeatherWidget"));
        WeatherWidget->resize(780, 310);
        weatherIcon = new QGraphicsView(WeatherWidget);
        weatherIcon->setObjectName(QString::fromUtf8("weatherIcon"));
        weatherIcon->setGeometry(QRect(10, 45, 220, 220));
        degreeValue = new QLabel(WeatherWidget);
        degreeValue->setObjectName(QString::fromUtf8("degreeValue"));
        degreeValue->setGeometry(QRect(275, 40, 220, 220));
        QFont font;
        font.setPointSize(200);
        degreeValue->setFont(font);
        degreeValue->setAlignment(Qt::AlignRight|Qt::AlignTrailing|Qt::AlignVCenter);
        tempRangeLabel = new QLabel(WeatherWidget);
        tempRangeLabel->setObjectName(QString::fromUtf8("tempRangeLabel"));
        tempRangeLabel->setGeometry(QRect(500, 117, 140, 30));
        QFont font1;
        font1.setPointSize(20);
        font1.setBold(false);
        font1.setWeight(50);
        tempRangeLabel->setFont(font1);
        humidityLabel = new QLabel(WeatherWidget);
        humidityLabel->setObjectName(QString::fromUtf8("humidityLabel"));
        humidityLabel->setGeometry(QRect(500, 168, 120, 30));
        humidityLabel->setFont(font1);
        windLabel = new QLabel(WeatherWidget);
        windLabel->setObjectName(QString::fromUtf8("windLabel"));
        windLabel->setGeometry(QRect(500, 218, 70, 30));
        windLabel->setFont(font1);
        humidityValue = new QLabel(WeatherWidget);
        humidityValue->setObjectName(QString::fromUtf8("humidityValue"));
        humidityValue->setGeometry(QRect(640, 168, 130, 30));
        QFont font2;
        font2.setPointSize(20);
        font2.setBold(true);
        font2.setWeight(75);
        humidityValue->setFont(font2);
        windValue = new QLabel(WeatherWidget);
        windValue->setObjectName(QString::fromUtf8("windValue"));
        windValue->setGeometry(QRect(590, 218, 170, 30));
        windValue->setFont(font2);
        locationValue = new QLabel(WeatherWidget);
        locationValue->setObjectName(QString::fromUtf8("locationValue"));
        locationValue->setGeometry(QRect(500, 70, 270, 30));
        locationValue->setFont(font2);
        tempRangeValue = new QLabel(WeatherWidget);
        tempRangeValue->setObjectName(QString::fromUtf8("tempRangeValue"));
        tempRangeValue->setGeometry(QRect(660, 117, 100, 30));
        tempRangeValue->setFont(font2);

        retranslateUi(WeatherWidget);

        QMetaObject::connectSlotsByName(WeatherWidget);
    } // setupUi

    void retranslateUi(QWidget *WeatherWidget)
    {
        WeatherWidget->setWindowTitle(QApplication::translate("WeatherWidget", "Form", nullptr));
        degreeValue->setText(QApplication::translate("WeatherWidget", "#", nullptr));
        tempRangeLabel->setText(QApplication::translate("WeatherWidget", "High / Low: ", nullptr));
        humidityLabel->setText(QApplication::translate("WeatherWidget", "Humidity:", nullptr));
        windLabel->setText(QApplication::translate("WeatherWidget", "Wind:", nullptr));
        humidityValue->setText(QApplication::translate("WeatherWidget", "x%", nullptr));
        windValue->setText(QApplication::translate("WeatherWidget", "0 mph dir", nullptr));
        locationValue->setText(QApplication::translate("WeatherWidget", "LOCATION", nullptr));
        tempRangeValue->setText(QApplication::translate("WeatherWidget", "00  00", nullptr));
    } // retranslateUi

};

namespace Ui {
    class WeatherWidget: public Ui_WeatherWidget {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_WEATHERWIDGET_H
