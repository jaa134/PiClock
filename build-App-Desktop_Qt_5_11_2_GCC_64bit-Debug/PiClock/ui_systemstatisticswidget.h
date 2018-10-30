/********************************************************************************
** Form generated from reading UI file 'systemstatisticswidget.ui'
**
** Created by: Qt User Interface Compiler version 5.11.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_SYSTEMSTATISTICSWIDGET_H
#define UI_SYSTEMSTATISTICSWIDGET_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QLabel>
#include <QtWidgets/QProgressBar>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_SystemStatisticsWidget
{
public:
    QProgressBar *cpuBar;
    QProgressBar *ramBar;
    QProgressBar *discBar;
    QLabel *cpuLabel;
    QLabel *ramLabel;
    QLabel *discLabel;
    QProgressBar *ramBar_2;
    QLabel *cpuLabel_2;

    void setupUi(QWidget *SystemStatisticsWidget)
    {
        if (SystemStatisticsWidget->objectName().isEmpty())
            SystemStatisticsWidget->setObjectName(QStringLiteral("SystemStatisticsWidget"));
        SystemStatisticsWidget->resize(800, 310);
        cpuBar = new QProgressBar(SystemStatisticsWidget);
        cpuBar->setObjectName(QStringLiteral("cpuBar"));
        cpuBar->setGeometry(QRect(180, 40, 550, 35));
        cpuBar->setValue(0);
        cpuBar->setTextVisible(false);
        ramBar = new QProgressBar(SystemStatisticsWidget);
        ramBar->setObjectName(QStringLiteral("ramBar"));
        ramBar->setGeometry(QRect(180, 110, 550, 35));
        ramBar->setValue(0);
        ramBar->setTextVisible(false);
        discBar = new QProgressBar(SystemStatisticsWidget);
        discBar->setObjectName(QStringLiteral("discBar"));
        discBar->setGeometry(QRect(180, 245, 550, 35));
        discBar->setValue(0);
        discBar->setTextVisible(false);
        cpuLabel = new QLabel(SystemStatisticsWidget);
        cpuLabel->setObjectName(QStringLiteral("cpuLabel"));
        cpuLabel->setGeometry(QRect(10, 40, 150, 30));
        QFont font;
        font.setPointSize(20);
        cpuLabel->setFont(font);
        cpuLabel->setAlignment(Qt::AlignRight|Qt::AlignTrailing|Qt::AlignVCenter);
        ramLabel = new QLabel(SystemStatisticsWidget);
        ramLabel->setObjectName(QStringLiteral("ramLabel"));
        ramLabel->setGeometry(QRect(10, 175, 150, 30));
        ramLabel->setFont(font);
        ramLabel->setAlignment(Qt::AlignRight|Qt::AlignTrailing|Qt::AlignVCenter);
        discLabel = new QLabel(SystemStatisticsWidget);
        discLabel->setObjectName(QStringLiteral("discLabel"));
        discLabel->setGeometry(QRect(10, 245, 150, 30));
        discLabel->setFont(font);
        discLabel->setAlignment(Qt::AlignRight|Qt::AlignTrailing|Qt::AlignVCenter);
        ramBar_2 = new QProgressBar(SystemStatisticsWidget);
        ramBar_2->setObjectName(QStringLiteral("ramBar_2"));
        ramBar_2->setGeometry(QRect(180, 175, 550, 35));
        ramBar_2->setValue(0);
        ramBar_2->setTextVisible(false);
        cpuLabel_2 = new QLabel(SystemStatisticsWidget);
        cpuLabel_2->setObjectName(QStringLiteral("cpuLabel_2"));
        cpuLabel_2->setGeometry(QRect(10, 110, 150, 30));
        cpuLabel_2->setFont(font);
        cpuLabel_2->setAlignment(Qt::AlignRight|Qt::AlignTrailing|Qt::AlignVCenter);

        retranslateUi(SystemStatisticsWidget);

        QMetaObject::connectSlotsByName(SystemStatisticsWidget);
    } // setupUi

    void retranslateUi(QWidget *SystemStatisticsWidget)
    {
        SystemStatisticsWidget->setWindowTitle(QApplication::translate("SystemStatisticsWidget", "Form", nullptr));
        cpuLabel->setText(QApplication::translate("SystemStatisticsWidget", "CPU", nullptr));
        ramLabel->setText(QApplication::translate("SystemStatisticsWidget", "Disc", nullptr));
        discLabel->setText(QApplication::translate("SystemStatisticsWidget", "Network", nullptr));
        cpuLabel_2->setText(QApplication::translate("SystemStatisticsWidget", "Memory", nullptr));
    } // retranslateUi

};

namespace Ui {
    class SystemStatisticsWidget: public Ui_SystemStatisticsWidget {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_SYSTEMSTATISTICSWIDGET_H
