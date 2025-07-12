#ifndef FORMATSLOVESTNY_H
#define FORMATSLOVESTNY_H


#include <QMainWindow>
#include <QDate>
#include <QTime>


QT_BEGIN_NAMESPACE
namespace Ui { class FormatSlovestny; }
QT_END_NAMESPACE

class FormatSlovestny: public QMainWindow {
    Q_OBJECT
private:
    QDate m_date;
    QTime m_time;
public:
    FormatSlovestny(QWidget *parent = nullptr);
    ~FormatSlovestny();
    QTime get_time (){
        return m_time;
    }

signals:
    void start_clock_signal(const QTime &time);

private slots:

void writeData();
    void on_pushButtonParseVerbal_clicked();

void on_start_clocky_clicked();

private:
Ui::FormatSlovestny *ui;
};

#endif // FORMATSLOVESTNY_H
