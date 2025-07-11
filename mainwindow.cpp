#include "mainwindow.h"
#include "ui_mainwindow1.h"
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
    about->setText("Это приложение служит для создания часов.");
    about->exec();
}

void MainWindow::help_triggered()
{
    QMessageBox *help = new QMessageBox;
    help->setWindowTitle("Помощь");
    help->setIcon(QMessageBox::Information);
    help->setWindowIcon(QIcon(":/img/images/SalvadorDali.png"));
    help->setText("Вкладка помощь.\n Добро пожаловать в Мягкие часы! Если у вас возникли проблемы, обращайтесь к @stsniskhan в Telegram. \nДля того, чтобы запустить часы, необходимо сперва указать дату и время запуска. Для этого перейдите в Формат в строке меню. Выберите желаемый формат ввода данных. \n"
                  "В появившемся окне ввода данных введите дату и время в указанном формате. Дату и время в словесном формате необходимо указывать словами со сточной буквы через пробел (без иных разделителей). \n Нажмите кнопку Ввести и, если всё введено корректно, нажмите Запустить часы. \n"
                  "В строке меню Вы так же найдёте опцию Статистика, где можно посмотреть все запуски часов. По нажатию на кнопку Показать ошибочные вводы Вы увидите только неверные вводы даты и времени, когда запуск часов не состоялся. В строке меню при нажатии на опцию Статистика можно завершить сохранение и запись вводов, если они не нужны, выбрав пункт Завершить тестирование.");
    help->exec();
}

void MainWindow::from_device_triggered()
{
    ui->widget->startClock();
    startDate = QDate::currentDate();
    startTime = QTime::currentTime();
}

void MainWindow::chislovoy_input_triggered()
{
    formatchislovoy = new FormatChislovoy(this);
    connect (formatchislovoy, &FormatChislovoy::start_clock_signal, this, &MainWindow::push_start_time_date);
}

void MainWindow::slovestny_input_triggered()
{
    formatslovestny = new FormatSlovestny;
    connect (formatslovestny, &FormatSlovestny::start_clock_signal, this, &MainWindow::push_start_time_date);
}

void MainWindow::end_testing_triggered()
{
    ui->widget->stopClock();
    endDate = QDate::currentDate();
    endTime = QTime::currentTime();
    isSaved = false;
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
    statisticstrue = new StatisticsTrue(VTimeDate.size());
    connect(statisticstrue, &StatisticsTrue::exit_signal, this, &MainWindow::exit_triggered);
    connect(statisticstrue, &StatisticsTrue::save_result_signal, this, &MainWindow::save_result_triggered);
    TimeDate curr;
    curr.startTime = startTime;
    curr.startDate = startDate;
    curr.endTime = endTime;
    curr.endDate = endDate;
    statisticstrue->setv(VTimeDate, curr);
    statisticstrue->output();
    statisticstrue->show();
}

void MainWindow::exit_triggered()
{
    this->~MainWindow();
}

void MainWindow::push_start_time_date(const QTime &time)
{
    ui->widget->startClock(time);
    startDate = QDate::currentDate();
    startTime = QTime::currentTime();
}

void MainWindow::save_result_triggered()
{
    if (!isSaved)
    {
        TimeDate curr;
        curr.startTime = startTime;
        curr.startDate = startDate;
        curr.endTime = endTime;
        curr.endDate = endDate;
        VTimeDate.push_back(curr);
        isSaved = true;
        statisticstrue->setv(VTimeDate, curr);

    }

}


bool MainWindow::getIsSaved()
{
    return isSaved;
}

bool MainWindow::setIsSaved(bool isSaved_)
{
    isSaved = isSaved_;
}
