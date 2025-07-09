/********************************************************************************
** Form generated from reading UI file 'statisticstrue.ui'
**
** Created by: Qt User Interface Compiler version 6.8.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_STATISTICSTRUE_H
#define UI_STATISTICSTRUE_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QScrollArea>
#include <QtWidgets/QTextBrowser>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_StatisticsTrue
{
public:
    QGridLayout *gridLayout;
    QPushButton *exit_but;
    QPushButton *show_statisticsfalse_but;
    QPushButton *save_result_but;
    QTextBrowser *textBrowser;
    QScrollArea *scrollArea;
    QWidget *scrollAreaWidgetContents;

    void setupUi(QWidget *StatisticsTrue)
    {
        if (StatisticsTrue->objectName().isEmpty())
            StatisticsTrue->setObjectName("StatisticsTrue");
        StatisticsTrue->resize(479, 549);
        StatisticsTrue->setMinimumSize(QSize(479, 549));
        StatisticsTrue->setMaximumSize(QSize(479, 549));
        gridLayout = new QGridLayout(StatisticsTrue);
        gridLayout->setObjectName("gridLayout");
        exit_but = new QPushButton(StatisticsTrue);
        exit_but->setObjectName("exit_but");

        gridLayout->addWidget(exit_but, 1, 2, 1, 1);

        show_statisticsfalse_but = new QPushButton(StatisticsTrue);
        show_statisticsfalse_but->setObjectName("show_statisticsfalse_but");

        gridLayout->addWidget(show_statisticsfalse_but, 1, 0, 1, 1);

        save_result_but = new QPushButton(StatisticsTrue);
        save_result_but->setObjectName("save_result_but");

        gridLayout->addWidget(save_result_but, 1, 1, 1, 1);

        textBrowser = new QTextBrowser(StatisticsTrue);
        textBrowser->setObjectName("textBrowser");
        textBrowser->setMinimumSize(QSize(457, 192));
        textBrowser->setMaximumSize(QSize(457, 192));

        gridLayout->addWidget(textBrowser, 0, 0, 1, 3);

        scrollArea = new QScrollArea(StatisticsTrue);
        scrollArea->setObjectName("scrollArea");
        scrollArea->setWidgetResizable(true);
        scrollAreaWidgetContents = new QWidget();
        scrollAreaWidgetContents->setObjectName("scrollAreaWidgetContents");
        scrollAreaWidgetContents->setGeometry(QRect(0, 0, 455, 290));
        scrollArea->setWidget(scrollAreaWidgetContents);

        gridLayout->addWidget(scrollArea, 2, 0, 1, 3);


        retranslateUi(StatisticsTrue);

        QMetaObject::connectSlotsByName(StatisticsTrue);
    } // setupUi

    void retranslateUi(QWidget *StatisticsTrue)
    {
        StatisticsTrue->setWindowTitle(QCoreApplication::translate("StatisticsTrue", "Form", nullptr));
        exit_but->setText(QCoreApplication::translate("StatisticsTrue", "\320\222\321\213\320\271\321\202\320\270", nullptr));
        show_statisticsfalse_but->setText(QCoreApplication::translate("StatisticsTrue", "\320\237\320\276\320\272\320\260\320\267\320\260\321\202\321\214 \320\276\321\210\320\270\320\261\320\276\321\207\320\275\321\213\320\265 \320\262\320\262\320\276\320\264\321\213", nullptr));
        save_result_but->setText(QCoreApplication::translate("StatisticsTrue", "\320\241\320\276\321\205\321\200\320\260\320\275\320\270\321\202\321\214 \321\200\320\265\320\267\321\203\320\273\321\214\321\202\320\260\321\202", nullptr));
    } // retranslateUi

};

namespace Ui {
    class StatisticsTrue: public Ui_StatisticsTrue {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_STATISTICSTRUE_H
