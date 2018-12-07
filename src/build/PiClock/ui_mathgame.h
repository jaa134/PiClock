/********************************************************************************
** Form generated from reading UI file 'mathgame.ui'
**
** Created by: Qt User Interface Compiler version 5.12.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MATHGAME_H
#define UI_MATHGAME_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QLabel>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_MathGame
{
public:
    QPushButton *answerButtonA;
    QPushButton *answerButtonB;
    QPushButton *answerButtonC;
    QPushButton *answerButtonD;
    QLabel *labelA;
    QLabel *labelB;
    QLabel *labelC;
    QLabel *labelD;
    QLabel *questionLabel;

    void setupUi(QWidget *MathGame)
    {
        if (MathGame->objectName().isEmpty())
            MathGame->setObjectName(QString::fromUtf8("MathGame"));
        MathGame->resize(500, 410);
        answerButtonA = new QPushButton(MathGame);
        answerButtonA->setObjectName(QString::fromUtf8("answerButtonA"));
        answerButtonA->setGeometry(QRect(10, 90, 480, 70));
        QFont font;
        font.setPointSize(20);
        answerButtonA->setFont(font);
        answerButtonA->setStyleSheet(QString::fromUtf8("background-color: rgb(210, 210, 210);\n"
"text-align: left;\n"
"padding-left: 80px;"));
        answerButtonB = new QPushButton(MathGame);
        answerButtonB->setObjectName(QString::fromUtf8("answerButtonB"));
        answerButtonB->setGeometry(QRect(10, 170, 480, 70));
        answerButtonB->setFont(font);
        answerButtonB->setStyleSheet(QString::fromUtf8("background-color: rgb(210, 210, 210);\n"
"text-align: left;\n"
"padding-left: 80px;"));
        answerButtonC = new QPushButton(MathGame);
        answerButtonC->setObjectName(QString::fromUtf8("answerButtonC"));
        answerButtonC->setGeometry(QRect(10, 250, 480, 70));
        answerButtonC->setFont(font);
        answerButtonC->setStyleSheet(QString::fromUtf8("background-color: rgb(210, 210, 210);\n"
"text-align: left;\n"
"padding-left: 80px;"));
        answerButtonD = new QPushButton(MathGame);
        answerButtonD->setObjectName(QString::fromUtf8("answerButtonD"));
        answerButtonD->setGeometry(QRect(10, 330, 480, 70));
        answerButtonD->setFont(font);
        answerButtonD->setStyleSheet(QString::fromUtf8("background-color: rgb(210, 210, 210);\n"
"text-align: left;\n"
"padding-left: 80px;"));
        labelA = new QLabel(MathGame);
        labelA->setObjectName(QString::fromUtf8("labelA"));
        labelA->setGeometry(QRect(10, 90, 60, 70));
        QFont font1;
        font1.setPointSize(25);
        labelA->setFont(font1);
        labelA->setStyleSheet(QString::fromUtf8("background-color: rgb(85, 87, 83);\n"
"color: #eee;\n"
""));
        labelA->setAlignment(Qt::AlignCenter);
        labelB = new QLabel(MathGame);
        labelB->setObjectName(QString::fromUtf8("labelB"));
        labelB->setGeometry(QRect(10, 170, 60, 70));
        labelB->setFont(font1);
        labelB->setStyleSheet(QString::fromUtf8("background-color: rgb(85, 87, 83);\n"
"color: #eee;\n"
""));
        labelB->setAlignment(Qt::AlignCenter);
        labelC = new QLabel(MathGame);
        labelC->setObjectName(QString::fromUtf8("labelC"));
        labelC->setGeometry(QRect(10, 250, 60, 70));
        labelC->setFont(font1);
        labelC->setStyleSheet(QString::fromUtf8("background-color: rgb(85, 87, 83);\n"
"color: #eee;\n"
""));
        labelC->setAlignment(Qt::AlignCenter);
        labelD = new QLabel(MathGame);
        labelD->setObjectName(QString::fromUtf8("labelD"));
        labelD->setGeometry(QRect(10, 330, 60, 70));
        labelD->setFont(font1);
        labelD->setStyleSheet(QString::fromUtf8("background-color: rgb(85, 87, 83);\n"
"color: #eee;\n"
""));
        labelD->setAlignment(Qt::AlignCenter);
        questionLabel = new QLabel(MathGame);
        questionLabel->setObjectName(QString::fromUtf8("questionLabel"));
        questionLabel->setGeometry(QRect(10, 0, 480, 80));
        QFont font2;
        font2.setPointSize(30);
        questionLabel->setFont(font2);
        questionLabel->setStyleSheet(QString::fromUtf8("\n"
"background-color: rgb(210, 210, 210);"));
        questionLabel->setAlignment(Qt::AlignCenter);

        retranslateUi(MathGame);

        QMetaObject::connectSlotsByName(MathGame);
    } // setupUi

    void retranslateUi(QWidget *MathGame)
    {
        MathGame->setWindowTitle(QApplication::translate("MathGame", "Form", nullptr));
        answerButtonA->setText(QApplication::translate("MathGame", "Button A", nullptr));
        answerButtonB->setText(QApplication::translate("MathGame", "Button B", nullptr));
        answerButtonC->setText(QApplication::translate("MathGame", "Button C", nullptr));
        answerButtonD->setText(QApplication::translate("MathGame", "Button D", nullptr));
        labelA->setText(QApplication::translate("MathGame", "A", nullptr));
        labelB->setText(QApplication::translate("MathGame", "B", nullptr));
        labelC->setText(QApplication::translate("MathGame", "C", nullptr));
        labelD->setText(QApplication::translate("MathGame", "D", nullptr));
        questionLabel->setText(QString());
    } // retranslateUi

};

namespace Ui {
    class MathGame: public Ui_MathGame {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MATHGAME_H
