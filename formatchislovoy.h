#ifndef FORMATCHISLOVOY_H
#define FORMATCHISLOVOY_H

#include <QMainWindow>
#include <QDate>
#include <QTime>

QT_BEGIN_NAMESPACE
namespace Ui { class FormatChislovoy; }
QT_END_NAMESPACE



class FormatChislovoy: public QMainWindow {
    Q_OBJECT
private:
    QDate m_date;
   QTime m_time;
public:
   FormatChislovoy(QWidget *parent = nullptr);
    ~FormatChislovoy();

   QTime get_time (){
       return m_time;
   }

   signals:
   void start_clock_signal(const QTime &time);

private slots:

void writeData(); //словами

void on_calendarWidget_clicked(const QDate &date);

void on_pushButton_clicked();

void on_start_clocky_clicked();

private:
Ui::FormatChislovoy *ui;
};

#endif // FORMATCHISLOVOY_H

