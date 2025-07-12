/********************************************************************************
** Form generated from reading UI file 'mainwindow.ui'
**
** Created by: Qt User Interface Compiler version 6.8.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MAINWINDOW_H
#define UI_MAINWINDOW_H

#include <QtCore/QVariant>
#include <QtGui/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenu>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QWidget>
#include "clocky.h"

QT_BEGIN_NAMESPACE

class Ui_MainWindow
{
public:
    QAction *about_action;
    QAction *help_action;
    QAction *wordf_action;
    QAction *from_device_action;
    QAction *manual_action;
    QAction *show_statistics_action;
    QAction *end_testing_action;
    QAction *fullscreen_action;
    QAction *exit_action;
    QWidget *centralwidget;
    QGridLayout *gridLayout;
    Clocky *widget;
    QMenuBar *menubar;
    QMenu *file_menu;
    QMenu *statistics_menu;
    QMenu *format_menu;
    QMenu *digf_menu;
    QMenu *help_menu;
    QStatusBar *statusbar;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName("MainWindow");
        MainWindow->resize(800, 600);
        about_action = new QAction(MainWindow);
        about_action->setObjectName("about_action");
        help_action = new QAction(MainWindow);
        help_action->setObjectName("help_action");
        wordf_action = new QAction(MainWindow);
        wordf_action->setObjectName("wordf_action");
        from_device_action = new QAction(MainWindow);
        from_device_action->setObjectName("from_device_action");
        manual_action = new QAction(MainWindow);
        manual_action->setObjectName("manual_action");
        show_statistics_action = new QAction(MainWindow);
        show_statistics_action->setObjectName("show_statistics_action");
        end_testing_action = new QAction(MainWindow);
        end_testing_action->setObjectName("end_testing_action");
        fullscreen_action = new QAction(MainWindow);
        fullscreen_action->setObjectName("fullscreen_action");
        exit_action = new QAction(MainWindow);
        exit_action->setObjectName("exit_action");
        centralwidget = new QWidget(MainWindow);
        centralwidget->setObjectName("centralwidget");
        gridLayout = new QGridLayout(centralwidget);
        gridLayout->setObjectName("gridLayout");
        widget = new Clocky(centralwidget);
        widget->setObjectName("widget");

        gridLayout->addWidget(widget, 0, 0, 1, 1);

        MainWindow->setCentralWidget(centralwidget);
        menubar = new QMenuBar(MainWindow);
        menubar->setObjectName("menubar");
        menubar->setGeometry(QRect(0, 0, 800, 25));
        file_menu = new QMenu(menubar);
        file_menu->setObjectName("file_menu");
        statistics_menu = new QMenu(menubar);
        statistics_menu->setObjectName("statistics_menu");
        format_menu = new QMenu(menubar);
        format_menu->setObjectName("format_menu");
        digf_menu = new QMenu(format_menu);
        digf_menu->setObjectName("digf_menu");
        help_menu = new QMenu(menubar);
        help_menu->setObjectName("help_menu");
        MainWindow->setMenuBar(menubar);
        statusbar = new QStatusBar(MainWindow);
        statusbar->setObjectName("statusbar");
        MainWindow->setStatusBar(statusbar);

        menubar->addAction(file_menu->menuAction());
        menubar->addAction(statistics_menu->menuAction());
        menubar->addAction(format_menu->menuAction());
        menubar->addAction(help_menu->menuAction());
        file_menu->addAction(about_action);
        file_menu->addAction(fullscreen_action);
        file_menu->addAction(exit_action);
        statistics_menu->addAction(show_statistics_action);
        statistics_menu->addAction(end_testing_action);
        format_menu->addAction(digf_menu->menuAction());
        format_menu->addAction(wordf_action);
        digf_menu->addAction(from_device_action);
        digf_menu->addAction(manual_action);
        help_menu->addAction(help_action);

        retranslateUi(MainWindow);

        QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindow)
    {
        MainWindow->setWindowTitle(QCoreApplication::translate("MainWindow", "MainWindow", nullptr));
        about_action->setText(QCoreApplication::translate("MainWindow", "\320\236 \320\277\321\200\320\276\320\263\321\200\320\260\320\274\320\274\320\265", nullptr));
        help_action->setText(QCoreApplication::translate("MainWindow", "\320\237\320\276\320\274\320\276\321\211\321\214", nullptr));
        wordf_action->setText(QCoreApplication::translate("MainWindow", "\320\241\320\273\320\276\320\262\320\265\321\201\320\275\321\213\320\271", nullptr));
        from_device_action->setText(QCoreApplication::translate("MainWindow", "\320\241 \321\203\321\201\321\202\321\200\320\276\320\271\321\201\321\202\320\262\320\260", nullptr));
        manual_action->setText(QCoreApplication::translate("MainWindow", "\320\222\321\200\321\203\321\207\320\275\321\203\321\216", nullptr));
        show_statistics_action->setText(QCoreApplication::translate("MainWindow", "\320\237\321\200\320\276\321\201\320\274\320\276\321\202\321\200\320\265\321\202\321\214 \321\201\321\202\320\260\321\202\320\270\321\201\321\202\320\270\320\272\321\203", nullptr));
        end_testing_action->setText(QCoreApplication::translate("MainWindow", "\320\227\320\260\320\272\320\276\320\275\321\207\320\270\321\202\321\214 \321\202\320\265\321\201\321\202\320\270\321\200\320\276\320\262\320\260\320\275\320\270\320\265", nullptr));
        fullscreen_action->setText(QCoreApplication::translate("MainWindow", "\320\237\320\276\320\273\320\275\320\276\321\215\320\272\321\200\320\260\320\275\320\275\321\213\320\271 \321\200\320\265\320\266\320\270\320\274 (F11)", nullptr));
        exit_action->setText(QCoreApplication::translate("MainWindow", "\320\222\321\213\320\271\321\202\320\270", nullptr));
        file_menu->setTitle(QCoreApplication::translate("MainWindow", "\320\244\320\260\320\271\320\273", nullptr));
        statistics_menu->setTitle(QCoreApplication::translate("MainWindow", "\320\241\321\202\320\260\321\202\320\270\321\201\321\202\320\270\320\272\320\260", nullptr));
        format_menu->setTitle(QCoreApplication::translate("MainWindow", "\320\244\320\276\321\200\320\274\320\260\321\202", nullptr));
        digf_menu->setTitle(QCoreApplication::translate("MainWindow", "\320\247\320\270\321\201\320\273\320\276\320\262\320\276\320\271", nullptr));
        help_menu->setTitle(QCoreApplication::translate("MainWindow", "\320\237\320\276\320\274\320\276\321\211\321\214", nullptr));
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
