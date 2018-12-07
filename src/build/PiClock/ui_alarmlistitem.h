/********************************************************************************
** Form generated from reading UI file 'alarmlistitem.ui'
**
** Created by: Qt User Interface Compiler version 5.12.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_ALARMLISTITEM_H
#define UI_ALARMLISTITEM_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QLabel>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_AlarmListItem
{
public:
    QPushButton *removeButton;
    QLabel *label;
    QLabel *styleLabel;

    void setupUi(QWidget *AlarmListItem)
    {
        if (AlarmListItem->objectName().isEmpty())
            AlarmListItem->setObjectName(QString::fromUtf8("AlarmListItem"));
        AlarmListItem->resize(350, 60);
        QSizePolicy sizePolicy(QSizePolicy::Preferred, QSizePolicy::Preferred);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(AlarmListItem->sizePolicy().hasHeightForWidth());
        AlarmListItem->setSizePolicy(sizePolicy);
        AlarmListItem->setStyleSheet(QString::fromUtf8("font-size: 15px;"));
        removeButton = new QPushButton(AlarmListItem);
        removeButton->setObjectName(QString::fromUtf8("removeButton"));
        removeButton->setGeometry(QRect(0, 0, 60, 60));
        QFont font;
        removeButton->setFont(font);
        removeButton->setStyleSheet(QString::fromUtf8("border: 0;"));
        label = new QLabel(AlarmListItem);
        label->setObjectName(QString::fromUtf8("label"));
        label->setGeometry(QRect(70, 0, 280, 60));
        label->setFont(font);
        label->setStyleSheet(QString::fromUtf8("font-size: 25px;"));
        styleLabel = new QLabel(AlarmListItem);
        styleLabel->setObjectName(QString::fromUtf8("styleLabel"));
        styleLabel->setGeometry(QRect(10, 10, 40, 40));
        QFont font1;
        font1.setBold(true);
        font1.setWeight(75);
        styleLabel->setFont(font1);
        styleLabel->setStyleSheet(QString::fromUtf8("border: 0;\n"
"background-color: rgb(240, 26, 26);\n"
"border-radius: 20px;\n"
"color: #fff;\n"
"font-size: 22px;\n"
"line-height: 10px;"));
        styleLabel->setAlignment(Qt::AlignCenter);
        label->raise();
        styleLabel->raise();
        removeButton->raise();

        retranslateUi(AlarmListItem);

        QMetaObject::connectSlotsByName(AlarmListItem);
    } // setupUi

    void retranslateUi(QWidget *AlarmListItem)
    {
        AlarmListItem->setWindowTitle(QApplication::translate("AlarmListItem", "Form", nullptr));
        removeButton->setText(QString());
        label->setText(QApplication::translate("AlarmListItem", "Alarm", nullptr));
        styleLabel->setText(QApplication::translate("AlarmListItem", "X", nullptr));
    } // retranslateUi

};

namespace Ui {
    class AlarmListItem: public Ui_AlarmListItem {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_ALARMLISTITEM_H
