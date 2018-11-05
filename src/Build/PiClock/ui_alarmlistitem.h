/********************************************************************************
** Form generated from reading UI file 'alarmlistitem.ui'
**
** Created by: Qt User Interface Compiler version 5.11.2
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

    void setupUi(QWidget *AlarmListItem)
    {
        if (AlarmListItem->objectName().isEmpty())
            AlarmListItem->setObjectName(QStringLiteral("AlarmListItem"));
        AlarmListItem->resize(350, 60);
        QSizePolicy sizePolicy(QSizePolicy::Preferred, QSizePolicy::Preferred);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(AlarmListItem->sizePolicy().hasHeightForWidth());
        AlarmListItem->setSizePolicy(sizePolicy);
        AlarmListItem->setStyleSheet(QStringLiteral("font-size: 15px;"));
        removeButton = new QPushButton(AlarmListItem);
        removeButton->setObjectName(QStringLiteral("removeButton"));
        removeButton->setGeometry(QRect(0, 0, 70, 60));
        label = new QLabel(AlarmListItem);
        label->setObjectName(QStringLiteral("label"));
        label->setGeometry(QRect(70, 0, 280, 60));
        QFont font;
        label->setFont(font);
        label->setStyleSheet(QStringLiteral("font-size: 25px;"));

        retranslateUi(AlarmListItem);

        QMetaObject::connectSlotsByName(AlarmListItem);
    } // setupUi

    void retranslateUi(QWidget *AlarmListItem)
    {
        AlarmListItem->setWindowTitle(QApplication::translate("AlarmListItem", "Form", nullptr));
        removeButton->setText(QApplication::translate("AlarmListItem", "x", nullptr));
        label->setText(QApplication::translate("AlarmListItem", "Alarm", nullptr));
    } // retranslateUi

};

namespace Ui {
    class AlarmListItem: public Ui_AlarmListItem {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_ALARMLISTITEM_H
