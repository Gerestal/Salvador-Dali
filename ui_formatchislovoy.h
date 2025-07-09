/********************************************************************************
** Form generated from reading UI file 'formatchislovoy.ui'
**
** Created by: Qt User Interface Compiler version 6.8.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_FORMATCHISLOVOY_H
#define UI_FORMATCHISLOVOY_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QCalendarWidget>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QTextBrowser>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_FormatChislovoy
{
public:
    QWidget *centralwidget;
    QLabel *label;
    QLabel *label_2;
    QLineEdit *lineEdit;
    QTextBrowser *textBrowser;
    QCalendarWidget *calendarWidget;
    QPushButton *pushButton;
    QPushButton *start_clocky;
    QMenuBar *menubar;
    QStatusBar *statusbar;

    void setupUi(QMainWindow *FormatChislovoy)
    {
        if (FormatChislovoy->objectName().isEmpty())
            FormatChislovoy->setObjectName("FormatChislovoy");
        FormatChislovoy->resize(800, 600);
        FormatChislovoy->setMinimumSize(QSize(800, 600));
        FormatChislovoy->setMaximumSize(QSize(800, 600));
        centralwidget = new QWidget(FormatChislovoy);
        centralwidget->setObjectName("centralwidget");
        label = new QLabel(centralwidget);
        label->setObjectName("label");
        label->setGeometry(QRect(30, 20, 191, 20));
        label_2 = new QLabel(centralwidget);
        label_2->setObjectName("label_2");
        label_2->setGeometry(QRect(440, 20, 291, 20));
        lineEdit = new QLineEdit(centralwidget);
        lineEdit->setObjectName("lineEdit");
        lineEdit->setGeometry(QRect(30, 50, 321, 26));
        textBrowser = new QTextBrowser(centralwidget);
        textBrowser->setObjectName("textBrowser");
        textBrowser->setGeometry(QRect(435, 50, 341, 192));
        calendarWidget = new QCalendarWidget(centralwidget);
        calendarWidget->setObjectName("calendarWidget");
        calendarWidget->setGeometry(QRect(30, 140, 371, 311));
        pushButton = new QPushButton(centralwidget);
        pushButton->setObjectName("pushButton");
        pushButton->setGeometry(QRect(260, 90, 93, 29));
        start_clocky = new QPushButton(centralwidget);
        start_clocky->setObjectName("start_clocky");
        start_clocky->setGeometry(QRect(600, 460, 171, 61));
        FormatChislovoy->setCentralWidget(centralwidget);
        menubar = new QMenuBar(FormatChislovoy);
        menubar->setObjectName("menubar");
        menubar->setGeometry(QRect(0, 0, 800, 26));
        FormatChislovoy->setMenuBar(menubar);
        statusbar = new QStatusBar(FormatChislovoy);
        statusbar->setObjectName("statusbar");
        FormatChislovoy->setStatusBar(statusbar);

        retranslateUi(FormatChislovoy);

        QMetaObject::connectSlotsByName(FormatChislovoy);
    } // setupUi

    void retranslateUi(QMainWindow *FormatChislovoy)
    {
        FormatChislovoy->setWindowTitle(QCoreApplication::translate("FormatChislovoy", "MainWindow", nullptr));
        label->setText(QCoreApplication::translate("FormatChislovoy", "\320\222\320\262\320\265\320\264\320\270\321\202\320\265 \320\264\320\260\321\202\321\203 \320\270 \320\262\321\200\320\265\320\274\321\217:", nullptr));
        label_2->setText(QCoreApplication::translate("FormatChislovoy", "\320\224\320\260\321\202\320\260 \320\270 \320\262\321\200\320\265\320\274\321\217 \320\262 \321\201\320\273\320\276\320\262\320\265\321\201\320\275\320\276\320\274 \321\204\320\276\321\200\320\274\320\260\321\202\320\265", nullptr));
        lineEdit->setPlaceholderText(QCoreApplication::translate("FormatChislovoy", "\320\224\320\224.\320\234\320\234.\320\223\320\223\320\223\320\223 \320\247\320\247:\320\234\320\234:\320\241\320\241", nullptr));
        pushButton->setText(QCoreApplication::translate("FormatChislovoy", "\320\222\320\262\320\265\321\201\321\202\320\270", nullptr));
        start_clocky->setText(QCoreApplication::translate("FormatChislovoy", "\320\227\320\260\320\277\321\203\321\201\321\202\320\270\321\202\321\214 \321\207\320\260\321\201\321\213", nullptr));
    } // retranslateUi

};

namespace Ui {
    class FormatChislovoy: public Ui_FormatChislovoy {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_FORMATCHISLOVOY_H
