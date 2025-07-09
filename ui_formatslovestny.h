/********************************************************************************
** Form generated from reading UI file 'formatslovestny.ui'
**
** Created by: Qt User Interface Compiler version 6.8.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_FORMATSLOVESTNY_H
#define UI_FORMATSLOVESTNY_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QLabel>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QTextEdit>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_FormatSlovestny
{
public:
    QWidget *centralwidget;
    QLabel *label;
    QLabel *label_2;
    QTextEdit *slova;
    QLabel *standart;
    QLabel *label_3;
    QPushButton *pushButtonParseVerbal;
    QPushButton *start_clocky;
    QMenuBar *menubar;
    QStatusBar *statusbar;

    void setupUi(QMainWindow *FormatSlovestny)
    {
        if (FormatSlovestny->objectName().isEmpty())
            FormatSlovestny->setObjectName("FormatSlovestny");
        FormatSlovestny->resize(800, 600);
        FormatSlovestny->setMinimumSize(QSize(800, 600));
        FormatSlovestny->setMaximumSize(QSize(800, 600));
        centralwidget = new QWidget(FormatSlovestny);
        centralwidget->setObjectName("centralwidget");
        label = new QLabel(centralwidget);
        label->setObjectName("label");
        label->setGeometry(QRect(10, 10, 451, 20));
        label_2 = new QLabel(centralwidget);
        label_2->setObjectName("label_2");
        label_2->setGeometry(QRect(10, 170, 191, 20));
        slova = new QTextEdit(centralwidget);
        slova->setObjectName("slova");
        slova->setGeometry(QRect(10, 40, 781, 111));
        standart = new QLabel(centralwidget);
        standart->setObjectName("standart");
        standart->setGeometry(QRect(10, 200, 331, 21));
        label_3 = new QLabel(centralwidget);
        label_3->setObjectName("label_3");
        label_3->setGeometry(QRect(10, 200, 331, 41));
        label_3->setFrameShape(QFrame::Shape::StyledPanel);
        pushButtonParseVerbal = new QPushButton(centralwidget);
        pushButtonParseVerbal->setObjectName("pushButtonParseVerbal");
        pushButtonParseVerbal->setGeometry(QRect(700, 160, 93, 29));
        start_clocky = new QPushButton(centralwidget);
        start_clocky->setObjectName("start_clocky");
        start_clocky->setGeometry(QRect(620, 470, 171, 61));
        FormatSlovestny->setCentralWidget(centralwidget);
        menubar = new QMenuBar(FormatSlovestny);
        menubar->setObjectName("menubar");
        menubar->setGeometry(QRect(0, 0, 800, 26));
        FormatSlovestny->setMenuBar(menubar);
        statusbar = new QStatusBar(FormatSlovestny);
        statusbar->setObjectName("statusbar");
        FormatSlovestny->setStatusBar(statusbar);

        retranslateUi(FormatSlovestny);

        QMetaObject::connectSlotsByName(FormatSlovestny);
    } // setupUi

    void retranslateUi(QMainWindow *FormatSlovestny)
    {
        FormatSlovestny->setWindowTitle(QCoreApplication::translate("FormatSlovestny", "MainWindow", nullptr));
        label->setText(QCoreApplication::translate("FormatSlovestny", "\320\241\320\273\320\276\320\262\320\265\321\201\320\275\321\213\320\271 \321\204\320\276\321\200\320\274\320\260\321\202 \320\264\320\260\321\202\321\213 (\320\262\320\262\320\265\320\264\320\270\321\202\320\265 \320\264\320\260\321\202\321\203 \320\270 \320\262\321\200\320\265\320\274\321\217 \321\201\320\273\320\276\320\262\320\260\320\274\320\270):", nullptr));
        label_2->setText(QCoreApplication::translate("FormatSlovestny", "\320\224\320\224.\320\234\320\234.\320\223\320\223.   \320\247\320\247.\320\234\320\234.\320\241\320\241. ", nullptr));
        standart->setText(QString());
        label_3->setText(QCoreApplication::translate("FormatSlovestny", "\320\236\320\266\320\270\320\264\320\260\320\275\320\270\320\265 \320\262\320\262\320\276\320\264\320\260...", nullptr));
        pushButtonParseVerbal->setText(QCoreApplication::translate("FormatSlovestny", "\320\222\320\262\320\265\321\201\321\202\320\270", nullptr));
        start_clocky->setText(QCoreApplication::translate("FormatSlovestny", "\320\227\320\260\320\277\321\203\321\201\321\202\320\270\321\202\321\214 \321\207\320\260\321\201\321\213", nullptr));
    } // retranslateUi

};

namespace Ui {
    class FormatSlovestny: public Ui_FormatSlovestny {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_FORMATSLOVESTNY_H
