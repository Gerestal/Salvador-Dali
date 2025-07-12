#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QDate>
#include <QTime>
#include <QVector>
#include "formatchislovoy.h"
#include "formatslovestny.h"
#include "statisticstrue.h"

QT_BEGIN_NAMESPACE
namespace Ui {
class MainWindow;
}
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = nullptr);
    ~MainWindow();
    bool getIsSaved();
    bool setIsSaved(bool isSaved_);

private:
    Ui::MainWindow *ui;
    FormatChislovoy* formatchislovoy;
    FormatSlovestny* formatslovestny;
    StatisticsTrue* statisticstrue;
    QDate* startDate = nullptr;
    QTime* startTime = nullptr;
    QDate* endDate = nullptr;
    QTime* endTime = nullptr;
    QVector<TimeDate> VTimeDate;
    bool isSaved = true;

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
    void save_result_triggered();

};

#endif // MAINWINDOW_H
