#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QDate>
#include <QTime>
#include <QVector>
#include "formatchislovoy.h"
#include "formatslovestny.h"
#include "clocky.h"

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private:
    Ui::MainWindow *ui;
    //Clocky* clock;
    //FormatChislovoy* formatchislovoy;
    //FormatSlovestny* formatslovestny;
    QDate endDate;
    QTime endTime;

private slots:
    void about_triggered();
    void help_triggered();
    void from_device_triggered();
    void chislovoy_input_triggered();
    void slovestny_input_triggered();
    void end_testing();

};

#endif // MAINWINDOW_H
