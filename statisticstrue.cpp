#include "statisticstrue.h"
#include "ui_statisticstrue.h"
#include <QTableWidget>
#include <QStringList>
#include <QShortcut>

StatisticsTrue::StatisticsTrue(int rows, QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::StatisticsTrue)
{
    ui->setupUi(this);
    setWindowIcon(QIcon(":/img/images/SalvadorDali.png"));
    setWindowTitle("Статистика");
    connect(ui->exit_but, &QAbstractButton::clicked, this, &StatisticsTrue::exit_triggered);
    QTableWidget *table = new QTableWidget(rows, 3);
    ui->scrollArea->setWidget(table);
    QStringList strl;
    strl.push_back("Время запуска");
    strl.push_back("Время завершения");
    strl.push_back("Продолжительность");
    table->setColumnWidth(0, ui->textBrowser->width()/3 - 13);
    table->setColumnWidth(1, ui->textBrowser->width()/3 - 13);
    table->setColumnWidth(2, ui->textBrowser->width()/3 - 13);
    table->setHorizontalHeaderLabels(strl);
    output();
}

StatisticsTrue::~StatisticsTrue()
{
    delete ui;
}

void StatisticsTrue::exit_triggered()
{
    emit exit_signal();
    this->~StatisticsTrue();
}

void StatisticsTrue::on_save_result_but_clicked()
{
    emit save_result_signal();
    //output();
}

void StatisticsTrue::setv(QVector<TimeDate> currv, TimeDate curr)
{
    VTimeDate = currv;
    startDate = curr.startDate;
    startTime = curr.startTime;
    endDate = curr.endDate;
    endTime = curr.endTime;
    output();
}

void StatisticsTrue::output()
{

    if (!VTimeDate.empty())
    {
        if (startTime != VTimeDate.back().startTime
            || startDate != VTimeDate.back().startDate
            || endTime != VTimeDate.back().endTime
            || endDate != VTimeDate.back().endDate)
        {
            QString str;
            str.push_back("Статистика:\nДата начала: ");
            str.push_back(startDate.toString());
            str.push_back("\nВремя начала: ");
            str.push_back(startTime.toString());
            str.push_back("\nДата конца: ");
            str.push_back(endDate.toString());
            str.push_back("\nВремя конца: ");
            str.push_back(endTime.toString());
            ui->textBrowser->setText(str);
        }
        else
        {
            ui->textBrowser->setText("Последнее тестирование уже было сохранено.");
        }
        for (int i = 0; i < VTimeDate.size(); i++)
        {
            QTableWidget *table = new QTableWidget(VTimeDate.size(), 3);
            QString timeString = VTimeDate[i].startTime.toString("hh:mm:ss");
            QTableWidgetItem *item = new QTableWidgetItem(timeString);
            table->setItem(i, 0, item);
            timeString = VTimeDate[i].endTime.toString("hh:mm:ss");
            delete item;
            item = new QTableWidgetItem(timeString);
            table->setItem(i, 1, item);
            int res;
            res = VTimeDate[i].startTime.secsTo(VTimeDate[i].endTime);
            res += VTimeDate[i].startDate.daysTo(VTimeDate[i].endDate)*24*60*60;
            delete item;
            item = new QTableWidgetItem(QString::number(res));
            table->setItem(i, 2, item);
            delete item;



            ui->scrollArea->setWidget(table);

        }
    }
    else
    {

            QString str;
            str.push_back("Статистика:\nДата начала: ");
            str.push_back(startDate.toString());
            str.push_back("\nВремя начала: ");
            str.push_back(startTime.toString());
            str.push_back("\nДата конца: ");
            str.push_back(endDate.toString());
            str.push_back("\nВремя конца: ");
            str.push_back(endTime.toString());
            ui->textBrowser->setText(str);
\
    }

}
