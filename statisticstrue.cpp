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

    // Убрано создание таблицы здесь - она будет создана в output()

    connect(ui->show_statisticsfalse_but, &QAbstractButton::clicked, this, &StatisticsTrue::onShowStats);
    // output();
}

StatisticsTrue::~StatisticsTrue()
{
    delete ui;
}

void StatisticsTrue::onShowStats()
{
    QString appDir = QCoreApplication::applicationDirPath();
    QString fileName = appDir + QDir::separator() + "Statistika_false.txt";
    QFile file(fileName);
    file.open(QIODevice::ReadOnly | QIODevice::Text);
    QTextStream stream(&file);
    ui->textBrowser->clear();
    ui->textBrowser->setPlainText(stream.readAll());
    file.close();
}


void StatisticsTrue::exit_triggered()
{
    emit exit_signal();
    this->~StatisticsTrue();
}

void StatisticsTrue::on_save_result_but_clicked()
{
    emit save_result_signal();
    output();
}

void StatisticsTrue::setv(QVector<TimeDate> currv, TimeDate curr)
{
    VTimeDate = currv;
    startDate = new QDate;
    startTime = new QTime;
    endDate = new QDate;
    endTime = new QTime;
    *startDate = curr.startDate;
    *startTime = curr.startTime;
    *endDate = curr.endDate;
    *endTime = curr.endTime;
    output();
}

void StatisticsTrue::output()
{
    QTableWidget *table = qobject_cast<QTableWidget*>(ui->scrollArea->widget());
    // if (!table) {
    table = new QTableWidget(0, 3, this);
    table->setColumnWidth(0, ui->scrollArea->width()/3 - 13);
    table->setColumnWidth(1, ui->scrollArea->width()/3 - 13);
    table->setColumnWidth(2, ui->scrollArea->width()/3 - 13);
    QStringList headers;
    headers << "Время запуска" << "Время завершения" << "Продолжительность";
    table->setHorizontalHeaderLabels(headers);

    ui->scrollArea->setWidget(table);
    // }

    table->setRowCount(VTimeDate.size());

    for (int i = 0; i < VTimeDate.size(); i++)
    {
        QString timeString = VTimeDate[i].startDate.toString("dd.MM.yyyy") + " " +
                             VTimeDate[i].startTime.toString("hh:mm:ss");
        QTableWidgetItem *item = new QTableWidgetItem(timeString);
        table->setItem(i, 0, item);

        timeString = VTimeDate[i].endDate.toString("dd.MM.yyyy") + " " +
                     VTimeDate[i].endTime.toString("hh:mm:ss");
        item = new QTableWidgetItem(timeString);
        table->setItem(i, 1, item);

        int seconds = VTimeDate[i].startDate.daysTo(VTimeDate[i].endDate)*24*60*60 +
                      VTimeDate[i].startTime.secsTo(VTimeDate[i].endTime);
        item = new QTableWidgetItem(QString::number(seconds));
        table->setItem(i, 2, item);
    }

    if (startTime != nullptr && !VTimeDate.empty())
    {
        if (*startTime == VTimeDate.last().startTime)
        {
            startTime = nullptr;
            startDate = nullptr;
            endTime = nullptr;
            endDate = nullptr;
        }
    }


    if (startTime == nullptr)
    {
        ui->textBrowser->setText("Последнее тестирование уже было записано");
    }
    else
    {
        // const TimeDate& last = VTimeDate.last();
        QString str = "Статистика:\nДата начала: " + (*startDate).toString() +
                      "\nВремя начала: " + (*startTime).toString() +
                      "\nДата конца: " + (*endDate).toString() +
                      "\nВремя конца: " + (*endTime).toString();
        ui->textBrowser->setText(str);
    }
}
