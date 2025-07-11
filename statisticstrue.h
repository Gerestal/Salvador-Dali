#ifndef STATISTICSTRUE_H
#define STATISTICSTRUE_H

#include <QWidget>
#include <QDate>
#include <QTime>
#include <QVector>
#include "TimeDate.h"

namespace Ui {
class StatisticsTrue;
}

class StatisticsTrue : public QWidget
{
    Q_OBJECT



public:
    explicit StatisticsTrue(int rows = 0, QWidget *parent = nullptr);
    ~StatisticsTrue();
    void setv(QVector<TimeDate> currv, TimeDate curr);
    void output();

private:
    Ui::StatisticsTrue *ui;
    QVector<TimeDate> VTimeDate;
    QDate startDate;
    QTime startTime;
    QDate endDate;
    QTime endTime;

private slots:
    void exit_triggered();
    void on_save_result_but_clicked();

signals:
    void exit_signal();
    void save_result_signal();

};

#endif // STATISTICSTRUE_H
