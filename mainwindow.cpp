#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QMessageBox>
#include <QShortcut>

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    setWindowIcon(QIcon(":/img/images/SalvadorDali.png"));
    setWindowTitle("Часы");

    QShortcut *shortcut = new QShortcut(QKeySequence(Qt::Key_F11), this);
    connect(shortcut, &QShortcut::activated, this, &MainWindow::fullscreen_triggered);
    connect(ui->about_action, &QAction::triggered, this, &MainWindow::about_triggered);
    connect(ui->help_action, &QAction::triggered, this, &MainWindow::help_triggered);
    connect(ui->from_device_action, &QAction::triggered, this, &MainWindow::from_device_triggered);
    connect(ui->manual_action, &QAction::triggered, this, &MainWindow::chislovoy_input_triggered);
    connect(ui->wordf_action, &QAction::triggered, this, &MainWindow::slovestny_input_triggered);
    connect(ui->end_testing_action, &QAction::triggered, this, &MainWindow::end_testing_triggered);
    connect(ui->fullscreen_action, &QAction::triggered, this, &MainWindow::fullscreen_triggered);
    connect(ui->show_statistics_action, &QAction::triggered, this, &MainWindow::show_statistics_triggered);
    connect(ui->exit_action, &QAction::triggered, this, &MainWindow::exit_triggered);

    clock = new Clocky(ui->widget);
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
    about->setWindowIcon(QIcon(":/img/images/SalvadorDali.png"));
    about->setText("Вкладка о программе");
    about->exec();
}

void MainWindow::help_triggered()
{
    QMessageBox *help = new QMessageBox;
    help->setWindowTitle("Помощь");
    help->setIcon(QMessageBox::Information);
    help->setWindowIcon(QIcon(":/img/images/SalvadorDali.png"));
    help->setText("Вкладка помощь");
    help->exec();
}

void MainWindow::from_device_triggered()
{
    clock->startClock();
}

void MainWindow::chislovoy_input_triggered()
{
    formatchislovoy = new FormatChislovoy;
    // connect (formatchislovoy, &FormatChislovoy::start_clock_signal, this, &MainWindow::push_start_time_date);
}

void MainWindow::slovestny_input_triggered()
{
    formatslovestny = new FormatSlovestny;
}

void MainWindow::end_testing_triggered()
{
    clock->stopClock();
}

void MainWindow::fullscreen_triggered()
{
    if (!isFullScreen())
    {
        showFullScreen();
        ui->fullscreen_action->setChecked(true);
    }
    else
    {
        showNormal();
        ui->fullscreen_action->setChecked(false);
    }
}

void MainWindow::show_statistics_triggered()
{
    statisticstrue = new StatisticsTrue(15);
    connect(statisticstrue, &StatisticsTrue::exit_signal, this, &MainWindow::exit_triggered);
    statisticstrue->show();
}

void MainWindow::exit_triggered()
{
    this->~MainWindow();
}

void MainWindow::push_start_time_date()
{
    // startDate = formatchislovoy->returnDate();
    // startTime = formatchislovoy->returnTime();
}
