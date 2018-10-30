/********************************************************************************
** Form generated from reading UI file 'holidaycountdownwidget.ui'
**
** Created by: Qt User Interface Compiler version 5.11.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_HOLIDAYCOUNTDOWNWIDGET_H
#define UI_HOLIDAYCOUNTDOWNWIDGET_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QLabel>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_HolidayCountdownWidget
{
public:
    QLabel *label;
    QLabel *label_2;

    void setupUi(QWidget *HolidayCountdownWidget)
    {
        if (HolidayCountdownWidget->objectName().isEmpty())
            HolidayCountdownWidget->setObjectName(QStringLiteral("HolidayCountdownWidget"));
        HolidayCountdownWidget->resize(780, 310);
        label = new QLabel(HolidayCountdownWidget);
        label->setObjectName(QStringLiteral("label"));
        label->setGeometry(QRect(50, 40, 200, 200));
        QFont font;
        font.setPointSize(200);
        label->setFont(font);
        label->setStyleSheet(QStringLiteral("color: #fff"));
        label->setAlignment(Qt::AlignRight|Qt::AlignTrailing|Qt::AlignVCenter);
        label_2 = new QLabel(HolidayCountdownWidget);
        label_2->setObjectName(QStringLiteral("label_2"));
        label_2->setGeometry(QRect(270, 40, 471, 200));
        QFont font1;
        font1.setPointSize(100);
        label_2->setFont(font1);
        label_2->setStyleSheet(QStringLiteral("color: #fff"));

        retranslateUi(HolidayCountdownWidget);

        QMetaObject::connectSlotsByName(HolidayCountdownWidget);
    } // setupUi

    void retranslateUi(QWidget *HolidayCountdownWidget)
    {
        HolidayCountdownWidget->setWindowTitle(QApplication::translate("HolidayCountdownWidget", "Form", nullptr));
        label->setText(QApplication::translate("HolidayCountdownWidget", "#", nullptr));
        label_2->setText(QApplication::translate("HolidayCountdownWidget", "Holiday", nullptr));
    } // retranslateUi

};

namespace Ui {
    class HolidayCountdownWidget: public Ui_HolidayCountdownWidget {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_HOLIDAYCOUNTDOWNWIDGET_H
