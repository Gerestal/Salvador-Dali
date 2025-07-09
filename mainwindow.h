#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QDate>
#include <QTime>
#include <QVector>
#include "formatchislovoy.h"
#include "formatslovestny.h"
#include "clocky.h"
#include "statisticstrue.h"

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
    Clocky* clock;
    FormatChislovoy* formatchislovoy;
    FormatSlovestny* formatslovestny;
    StatisticsTrue* statisticstrue;
    QDate startDate;
    QTime startTime;
    QDate endDate;
    QTime endTime;
    struct TimeDate
    {
        QDate startDate;
        QTime startTime;
        QDate endDate;
        QTime endTime;
    };
    QVector<TimeDate> VTimeDate;

private slots:
    void about_triggered();
    void help_triggered();
    void from_device_triggered();
    void chislovoy_input_triggered();
    void slovestny_input_triggered();
    void end_testing_triggered();
    void fullscreen_triggered();
    void show_statistics_triggered();
    void exit_triggered();
    void push_start_time_date(const QTime &time);

};

#endif // MAINWINDOW_H
