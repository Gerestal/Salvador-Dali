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

    connect(ui->show_statisticsfalse_but, &QAbstractButton::clicked, this, &StatisticsTrue::onShowStats);
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
    ui->textBrowser->setPlainText(stream.readAll());
    file.close();
}


void StatisticsTrue::exit_triggered()
{
    emit exit_signal();
    this->~StatisticsTrue();
}
