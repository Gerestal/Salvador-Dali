
#include <QApplication>
#include "mainwindow.h"

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    MainWindow w;
    w.show();

    // Clocky c;
    // c.show();
    // c.startClock();
    return a.exec();
}
