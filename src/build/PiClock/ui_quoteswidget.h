/********************************************************************************
** Form generated from reading UI file 'quoteswidget.ui'
**
** Created by: Qt User Interface Compiler version 5.12.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_QUOTESWIDGET_H
#define UI_QUOTESWIDGET_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QTextBrowser>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_QuotesWidget
{
public:
    QTextBrowser *textBrowser;

    void setupUi(QWidget *QuotesWidget)
    {
        if (QuotesWidget->objectName().isEmpty())
            QuotesWidget->setObjectName(QString::fromUtf8("QuotesWidget"));
        QuotesWidget->resize(780, 310);
        textBrowser = new QTextBrowser(QuotesWidget);
        textBrowser->setObjectName(QString::fromUtf8("textBrowser"));
        textBrowser->setGeometry(QRect(10, 80, 760, 131));
        textBrowser->setStyleSheet(QString::fromUtf8("background-color: rgba(0, 0, 0, 0);"));
        textBrowser->setFrameShape(QFrame::NoFrame);
        textBrowser->setFrameShadow(QFrame::Plain);
        textBrowser->setLineWidth(0);
        textBrowser->setVerticalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
        textBrowser->setHorizontalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
        textBrowser->setSizeAdjustPolicy(QAbstractScrollArea::AdjustToContents);
        textBrowser->setTextInteractionFlags(Qt::NoTextInteraction);

        retranslateUi(QuotesWidget);

        QMetaObject::connectSlotsByName(QuotesWidget);
    } // setupUi

    void retranslateUi(QWidget *QuotesWidget)
    {
        QuotesWidget->setWindowTitle(QApplication::translate("QuotesWidget", "Form", nullptr));
        textBrowser->setHtml(QApplication::translate("QuotesWidget", "<!DOCTYPE HTML PUBLIC \"-//W3C//DTD HTML 4.0//EN\" \"http://www.w3.org/TR/REC-html40/strict.dtd\">\n"
"<html><head><meta name=\"qrichtext\" content=\"1\" /><style type=\"text/css\">\n"
"p, li { white-space: pre-wrap; }\n"
"</style></head><body style=\" font-family:'Ubuntu'; font-size:11pt; font-weight:400; font-style:normal;\">\n"
"<p align=\"center\" style=\" margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\"><span style=\" font-size:24pt;\">&quot;The quote will be placed here!&quot;</span></p>\n"
"<p align=\"center\" style=\" margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\"><span style=\" font-size:24pt;\">-Author</span></p></body></html>", nullptr));
    } // retranslateUi

};

namespace Ui {
    class QuotesWidget: public Ui_QuotesWidget {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_QUOTESWIDGET_H
