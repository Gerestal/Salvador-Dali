#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QMessageBox>

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    setWindowTitle("Главное меню");
    // setWindowIcon(QIcon("qrc:/img/images/background.jpg"));
    connect(ui->about_action, &QAction::triggered, this, &MainWindow::about_triggered);
    connect(ui->help_action, &QAction::triggered, this, &MainWindow::help_triggered);
    connect(ui->from_device_action, &QAction::triggered, this, &MainWindow::from_device_triggered);
    connect(ui->manual_action, &QAction::triggered, this, &MainWindow::chislovoy_input_triggered);
    connect(ui->wordf_action, &QAction::triggered, this, &MainWindow::slovestny_input_triggered);
    connect(ui->end_testing_action, &QAction::triggered, this, &MainWindow::end_testing);

    // clock = new Clocky(this);
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::about_triggered()
{
    QMessageBox *about = new QMessageBox;
    about->setWindowTitle("О программе");
    about->setIcon(QMessageBox::Information);
    about->setText("Вкладка о программе");
    about->exec();
}

void MainWindow::help_triggered()
{
    QMessageBox *help = new QMessageBox;
    help->setWindowTitle("Помощь");
    help->setIcon(QMessageBox::Information);
    help->setText("Вкладка помощь");
    help->exec();
}

void MainWindow::from_device_triggered()
{
    // clock->startClock();
}

void MainWindow::chislovoy_input_triggered()
{
    // formatchislovoy = new FormatChislovoy;
}

void MainWindow::slovestny_input_triggered()
{
    // formatslovestny = new formatslovestny;
}

void MainWindow::end_testing()
{
    // clock->stopClock();
    //
}
