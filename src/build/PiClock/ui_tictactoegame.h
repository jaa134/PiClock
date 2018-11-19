/********************************************************************************
** Form generated from reading UI file 'tictactoegame.ui'
**
** Created by: Qt User Interface Compiler version 5.12.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_TICTACTOEGAME_H
#define UI_TICTACTOEGAME_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_TicTacToeGame
{
public:
    QPushButton *btn00;
    QPushButton *btn01;
    QPushButton *btn02;
    QPushButton *btn10;
    QPushButton *btn11;
    QPushButton *btn12;
    QPushButton *btn20;
    QPushButton *btn21;
    QPushButton *btn22;

    void setupUi(QWidget *TicTacToeGame)
    {
        if (TicTacToeGame->objectName().isEmpty())
            TicTacToeGame->setObjectName(QString::fromUtf8("TicTacToeGame"));
        TicTacToeGame->resize(500, 410);
        btn00 = new QPushButton(TicTacToeGame);
        btn00->setObjectName(QString::fromUtf8("btn00"));
        btn00->setGeometry(QRect(10, 1, 160, 136));
        QFont font;
        font.setPointSize(70);
        font.setBold(true);
        font.setWeight(75);
        btn00->setFont(font);
        btn00->setStyleSheet(QString::fromUtf8("outline: 0;\n"
"border: 2px solid black;\n"
"border-left: 0;\n"
"border-top: 0;\n"
"background-color: rgb(238, 238, 236);"));
        btn01 = new QPushButton(TicTacToeGame);
        btn01->setObjectName(QString::fromUtf8("btn01"));
        btn01->setGeometry(QRect(170, 1, 160, 136));
        btn01->setFont(font);
        btn01->setStyleSheet(QString::fromUtf8("outline: 0;\n"
"border: 2px solid black;\n"
"border-top: 0;\n"
"background-color: rgb(238, 238, 236);"));
        btn02 = new QPushButton(TicTacToeGame);
        btn02->setObjectName(QString::fromUtf8("btn02"));
        btn02->setGeometry(QRect(330, 1, 160, 136));
        btn02->setFont(font);
        btn02->setStyleSheet(QString::fromUtf8("outline: 0;\n"
"border: 2px solid black;\n"
"border-right: 0;\n"
"border-top: 0;\n"
"background-color: rgb(238, 238, 236);"));
        btn10 = new QPushButton(TicTacToeGame);
        btn10->setObjectName(QString::fromUtf8("btn10"));
        btn10->setGeometry(QRect(10, 137, 160, 136));
        btn10->setFont(font);
        btn10->setStyleSheet(QString::fromUtf8("outline: 0;\n"
"border: 2px solid black;\n"
"border-left: 0;\n"
"background-color: rgb(238, 238, 236);"));
        btn11 = new QPushButton(TicTacToeGame);
        btn11->setObjectName(QString::fromUtf8("btn11"));
        btn11->setGeometry(QRect(170, 137, 160, 136));
        btn11->setFont(font);
        btn11->setStyleSheet(QString::fromUtf8("outline: 0;\n"
"border: 2px solid black;\n"
"background-color: rgb(238, 238, 236);"));
        btn12 = new QPushButton(TicTacToeGame);
        btn12->setObjectName(QString::fromUtf8("btn12"));
        btn12->setGeometry(QRect(330, 137, 160, 136));
        btn12->setFont(font);
        btn12->setStyleSheet(QString::fromUtf8("outline: 0;\n"
"border: 2px solid black;\n"
"border-right: 0;\n"
"background-color: rgb(238, 238, 236);"));
        btn20 = new QPushButton(TicTacToeGame);
        btn20->setObjectName(QString::fromUtf8("btn20"));
        btn20->setGeometry(QRect(10, 273, 160, 136));
        btn20->setFont(font);
        btn20->setStyleSheet(QString::fromUtf8("outline: 0;\n"
"border: 2px solid black;\n"
"border-left: 0;\n"
"border-bottom: 0;\n"
"background-color: rgb(238, 238, 236);"));
        btn21 = new QPushButton(TicTacToeGame);
        btn21->setObjectName(QString::fromUtf8("btn21"));
        btn21->setGeometry(QRect(170, 273, 160, 136));
        btn21->setFont(font);
        btn21->setStyleSheet(QString::fromUtf8("outline: 0;\n"
"border: 2px solid black;\n"
"border-bottom: 0;\n"
"background-color: rgb(238, 238, 236);"));
        btn22 = new QPushButton(TicTacToeGame);
        btn22->setObjectName(QString::fromUtf8("btn22"));
        btn22->setGeometry(QRect(330, 273, 160, 136));
        btn22->setFont(font);
        btn22->setStyleSheet(QString::fromUtf8("outline: 0;\n"
"border: 2px solid black;\n"
"border-right: 0;\n"
"border-bottom: 0;\n"
"background-color: rgb(238, 238, 236);"));

        retranslateUi(TicTacToeGame);

        QMetaObject::connectSlotsByName(TicTacToeGame);
    } // setupUi

    void retranslateUi(QWidget *TicTacToeGame)
    {
        TicTacToeGame->setWindowTitle(QApplication::translate("TicTacToeGame", "Form", nullptr));
        btn00->setText(QString());
        btn01->setText(QString());
        btn02->setText(QString());
        btn10->setText(QString());
        btn11->setText(QString());
        btn12->setText(QString());
        btn20->setText(QString());
        btn21->setText(QString());
        btn22->setText(QString());
    } // retranslateUi

};

namespace Ui {
    class TicTacToeGame: public Ui_TicTacToeGame {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_TICTACTOEGAME_H
