#include "statisticstrue.h"
#include "ui_statisticstrue.h"
#include <QTableWidget>
#include <QStringList>

StatisticsTrue::StatisticsTrue(int rows, QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::StatisticsTrue)
{
    ui->setupUi(this);
    setWindowIcon(QIcon(":/img/images/SalvadorDali.png"));
    setWindowTitle("Статистика");
    connect(ui->exit_but, &QAbstractButton::clicked, this, &StatisticsTrue::exit);
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
    // table->set
}

StatisticsTrue::~StatisticsTrue()
{
    delete ui;
}

void StatisticsTrue::exit()
{
    this->~StatisticsTrue();
}
