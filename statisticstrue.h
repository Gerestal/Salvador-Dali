#ifndef STATISTICSTRUE_H
#define STATISTICSTRUE_H

#include <QWidget>
#include <QFile>
#include <QDir>

namespace Ui {
class StatisticsTrue;
}

class StatisticsTrue : public QWidget
{
    Q_OBJECT

public:
    explicit StatisticsTrue(int rows = 0, QWidget *parent = nullptr);
    ~StatisticsTrue();

private:
    Ui::StatisticsTrue *ui;

private slots:
    void exit_triggered();
    void onShowStats();

signals:
    void exit_signal();

};

#endif // STATISTICSTRUE_H
