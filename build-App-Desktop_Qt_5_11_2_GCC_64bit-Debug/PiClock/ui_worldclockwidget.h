/********************************************************************************
** Form generated from reading UI file 'worldclockwidget.ui'
**
** Created by: Qt User Interface Compiler version 5.11.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_WORLDCLOCKWIDGET_H
#define UI_WORLDCLOCKWIDGET_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QLabel>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_WorldClockWidget
{
public:
    QLabel *city1;
    QLabel *city2;
    QLabel *city3;
    QLabel *city4;
    QLabel *city5;
    QLabel *city6;
    QLabel *val2;
    QLabel *val3;
    QLabel *val5;
    QLabel *val6;
    QLabel *val4;
    QLabel *val1;

    void setupUi(QWidget *WorldClockWidget)
    {
        if (WorldClockWidget->objectName().isEmpty())
            WorldClockWidget->setObjectName(QStringLiteral("WorldClockWidget"));
        WorldClockWidget->resize(780, 310);
        city1 = new QLabel(WorldClockWidget);
        city1->setObjectName(QStringLiteral("city1"));
        city1->setGeometry(QRect(35, 30, 150, 30));
        QFont font;
        font.setPointSize(20);
        font.setBold(true);
        font.setWeight(75);
        city1->setFont(font);
        city1->setAlignment(Qt::AlignCenter);
        city2 = new QLabel(WorldClockWidget);
        city2->setObjectName(QStringLiteral("city2"));
        city2->setGeometry(QRect(325, 30, 150, 30));
        city2->setFont(font);
        city2->setAlignment(Qt::AlignCenter);
        city3 = new QLabel(WorldClockWidget);
        city3->setObjectName(QStringLiteral("city3"));
        city3->setGeometry(QRect(595, 30, 150, 30));
        city3->setFont(font);
        city3->setAlignment(Qt::AlignCenter);
        city4 = new QLabel(WorldClockWidget);
        city4->setObjectName(QStringLiteral("city4"));
        city4->setGeometry(QRect(35, 170, 150, 30));
        city4->setFont(font);
        city4->setAlignment(Qt::AlignCenter);
        city5 = new QLabel(WorldClockWidget);
        city5->setObjectName(QStringLiteral("city5"));
        city5->setGeometry(QRect(325, 170, 150, 30));
        city5->setFont(font);
        city5->setAlignment(Qt::AlignCenter);
        city6 = new QLabel(WorldClockWidget);
        city6->setObjectName(QStringLiteral("city6"));
        city6->setGeometry(QRect(595, 170, 150, 30));
        city6->setFont(font);
        city6->setAlignment(Qt::AlignCenter);
        val2 = new QLabel(WorldClockWidget);
        val2->setObjectName(QStringLiteral("val2"));
        val2->setGeometry(QRect(300, 70, 200, 60));
        QFont font1;
        font1.setFamily(QStringLiteral("FreeMono"));
        font1.setPointSize(40);
        val2->setFont(font1);
        val2->setStyleSheet(QLatin1String("background-color: rgb(255, 255, 255);\n"
"color: black;\n"
"border-radius: 6px;"));
        val2->setAlignment(Qt::AlignCenter);
        val3 = new QLabel(WorldClockWidget);
        val3->setObjectName(QStringLiteral("val3"));
        val3->setGeometry(QRect(570, 70, 200, 60));
        val3->setFont(font1);
        val3->setStyleSheet(QLatin1String("background-color: rgb(255, 255, 255);\n"
"color: black;\n"
"border-radius: 6px;"));
        val3->setAlignment(Qt::AlignCenter);
        val5 = new QLabel(WorldClockWidget);
        val5->setObjectName(QStringLiteral("val5"));
        val5->setGeometry(QRect(300, 210, 200, 60));
        val5->setFont(font1);
        val5->setStyleSheet(QLatin1String("background-color: rgb(255, 255, 255);\n"
"color: black;\n"
"border-radius: 6px;"));
        val5->setAlignment(Qt::AlignCenter);
        val6 = new QLabel(WorldClockWidget);
        val6->setObjectName(QStringLiteral("val6"));
        val6->setGeometry(QRect(570, 210, 200, 60));
        val6->setFont(font1);
        val6->setStyleSheet(QLatin1String("background-color: rgb(255, 255, 255);\n"
"color: black;\n"
"border-radius: 6px;"));
        val6->setAlignment(Qt::AlignCenter);
        val4 = new QLabel(WorldClockWidget);
        val4->setObjectName(QStringLiteral("val4"));
        val4->setGeometry(QRect(10, 210, 200, 60));
        val4->setFont(font1);
        val4->setStyleSheet(QLatin1String("background-color: rgb(255, 255, 255);\n"
"color: black;\n"
"border-radius: 6px;"));
        val4->setAlignment(Qt::AlignCenter);
        val1 = new QLabel(WorldClockWidget);
        val1->setObjectName(QStringLiteral("val1"));
        val1->setGeometry(QRect(10, 70, 200, 60));
        val1->setFont(font1);
        val1->setStyleSheet(QLatin1String("background-color: rgb(255, 255, 255);\n"
"color: black;\n"
"border-radius: 6px;"));
        val1->setAlignment(Qt::AlignCenter);

        retranslateUi(WorldClockWidget);

        QMetaObject::connectSlotsByName(WorldClockWidget);
    } // setupUi

    void retranslateUi(QWidget *WorldClockWidget)
    {
        WorldClockWidget->setWindowTitle(QApplication::translate("WorldClockWidget", "Form", nullptr));
        city1->setText(QApplication::translate("WorldClockWidget", "City 1", nullptr));
        city2->setText(QApplication::translate("WorldClockWidget", "City 2", nullptr));
        city3->setText(QApplication::translate("WorldClockWidget", "City 3", nullptr));
        city4->setText(QApplication::translate("WorldClockWidget", "City 4", nullptr));
        city5->setText(QApplication::translate("WorldClockWidget", "City 5", nullptr));
        city6->setText(QApplication::translate("WorldClockWidget", "City 6", nullptr));
        val2->setText(QApplication::translate("WorldClockWidget", "12:00", nullptr));
        val3->setText(QApplication::translate("WorldClockWidget", "12:00", nullptr));
        val5->setText(QApplication::translate("WorldClockWidget", "12:00", nullptr));
        val6->setText(QApplication::translate("WorldClockWidget", "12:00", nullptr));
        val4->setText(QApplication::translate("WorldClockWidget", "12:00", nullptr));
        val1->setText(QApplication::translate("WorldClockWidget", "12:00", nullptr));
    } // retranslateUi

};

namespace Ui {
    class WorldClockWidget: public Ui_WorldClockWidget {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_WORLDCLOCKWIDGET_H
