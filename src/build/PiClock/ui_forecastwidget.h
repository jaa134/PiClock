/********************************************************************************
** Form generated from reading UI file 'forecastwidget.ui'
**
** Created by: Qt User Interface Compiler version 5.12.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_FORECASTWIDGET_H
#define UI_FORECASTWIDGET_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QFrame>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_ForecastWidget
{
public:
    QFrame *day2;
    QFrame *day3;
    QFrame *day4;
    QFrame *day1;

    void setupUi(QWidget *ForecastWidget)
    {
        if (ForecastWidget->objectName().isEmpty())
            ForecastWidget->setObjectName(QString::fromUtf8("ForecastWidget"));
        ForecastWidget->resize(780, 310);
        day2 = new QFrame(ForecastWidget);
        day2->setObjectName(QString::fromUtf8("day2"));
        day2->setGeometry(QRect(197, 10, 189, 290));
        day2->setStyleSheet(QString::fromUtf8("border-radius: 10px;\n"
"background-color: #fff;"));
        day2->setFrameShape(QFrame::StyledPanel);
        day2->setFrameShadow(QFrame::Raised);
        day3 = new QFrame(ForecastWidget);
        day3->setObjectName(QString::fromUtf8("day3"));
        day3->setGeometry(QRect(394, 10, 189, 290));
        day3->setStyleSheet(QString::fromUtf8("border-radius: 10px;\n"
"background-color: #fff;"));
        day3->setFrameShape(QFrame::StyledPanel);
        day3->setFrameShadow(QFrame::Raised);
        day4 = new QFrame(ForecastWidget);
        day4->setObjectName(QString::fromUtf8("day4"));
        day4->setGeometry(QRect(591, 10, 189, 290));
        day4->setStyleSheet(QString::fromUtf8("border-radius: 10px;\n"
"background-color: #fff;"));
        day4->setFrameShape(QFrame::StyledPanel);
        day4->setFrameShadow(QFrame::Raised);
        day1 = new QFrame(ForecastWidget);
        day1->setObjectName(QString::fromUtf8("day1"));
        day1->setGeometry(QRect(0, 10, 189, 290));
        day1->setStyleSheet(QString::fromUtf8("border-radius: 10px;\n"
"background-color: #fff;"));
        day1->setFrameShape(QFrame::StyledPanel);
        day1->setFrameShadow(QFrame::Raised);

        retranslateUi(ForecastWidget);

        QMetaObject::connectSlotsByName(ForecastWidget);
    } // setupUi

    void retranslateUi(QWidget *ForecastWidget)
    {
        ForecastWidget->setWindowTitle(QApplication::translate("ForecastWidget", "Form", nullptr));
    } // retranslateUi

};

namespace Ui {
    class ForecastWidget: public Ui_ForecastWidget {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_FORECASTWIDGET_H
