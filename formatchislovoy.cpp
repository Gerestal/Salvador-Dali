#include "formatchislovoy.h"
#include "ui_formatchislovoy.h"
#include <QDate>
#include <QTime>
#include <QStringList>
#include <QFile>
#include <QTextStream>
#include <QDir>

FormatChislovoy::FormatChislovoy(QWidget *parent)
    : QMainWindow(parent),
    ui(new Ui::FormatChislovoy)
{
    ui->setupUi(this);
    setWindowIcon(QIcon(":/img/images/SalvadorDali.png"));
    resize(700, 500);
    setWindowTitle("Числовая запись");
    show();



}

FormatChislovoy::~FormatChislovoy()
{
    delete ui;
}

void FormatChislovoy:: writeData(){ //словами


    int d  = m_date.day();
    int m  = m_date.month();
    int y  = m_date.year();
    int hh = m_time.hour();
    int mm = m_time.minute();
    int ss = m_time.second();


    static const QStringList dayNames = {
        "", "первое", "второе", "третье", "четвёртое", "пятое",
        "шестое", "седьмое", "восьмое", "девятое", "десятое",
        "одиннадцатое", "двенадцатое", "тринадцатое", "четырнадцатое",
        "пятнадцатое", "шестнадцатое", "семнадцатое", "восемнадцатое",
        "девятнадцатое", "двадцатое", "двадцать первое", "двадцать второе",
        "двадцать третье", "двадцать четвёртое", "двадцать пятое",
        "двадцать шестое", "двадцать седьмое", "двадцать восьмое",
        "двадцать девятое", "тридцатое", "тридцать первое"
    };
    static const QStringList monthNames = {
        "", "января", "февраля", "марта", "апреля", "мая", "июня",
        "июля", "августа", "сентября", "октября", "ноября", "декабря"
    };


    static const QString unitsCard[] = {
        "", "один", "два", "три", "четыре",
        "пять", "шесть", "семь", "восемь", "девять"
    };
    static const QString teensCard[] = {
        "десять","одиннадцать","двенадцать","тринадцать","четырнадцать",
        "пятнадцать","шестнадцать","семнадцать","восемнадцать","девятнадцать"
    };
    static const QString tensCard[] = {
        "", "", "двадцать", "тридцать", "сорок",
        "пятьдесят", "шестьдесят", "семьдесят",
        "восемьдесят", "девяносто"
    };
    static const QString hundredsCard[] = {
        "", "сто", "двести", "триста", "четыреста",
        "пятьсот", "шестьсот", "семьсот", "восемьсот", "девятьсот"
    };

    // порядковые единицы (для годов)
    static const QString unitsGen[] = {
        "", "первого", "второго", "третьего", "четвёртого", "пятого",
        "шестого", "седьмого", "восьмого", "девятого"
    };
    static const QString teensGen[] = {
        "десятого","одиннадцатого","двенадцатого","тринадцатого",
        "четырнадцатого","пятнадцатого","шестнадцатого",
        "семнадцатого","восемнадцатого","девятнадцатого"
    };
    static const QString tensGen[] = {
        "", "", "двадцатого", "тридцатого", "сорокового",
        "пятидесятого", "шестидесятого", "семидесятого",
        "восьмидесятого", "девяностого"
    };


    auto thousandsCard = [&](int num)->QString {
        switch (num) {
        case 1: return "одна тысяча";
        case 2: return "две тысячи";
        case 3: return "три тысячи";
        case 4: return "четыре тысячи";
        default:
            if (num > 4 && num < 10)
                return unitsCard[num] + " тысяч";
        }
        return "";
    };


    auto ordinalGen = [&](int num)->QString {
        if (num <= 0) return "";
        if (num < 10) return unitsGen[num];
        if (num < 20) return teensGen[num - 10];

        QStringList parts;
        int h   = num / 100;
        int rem = num % 100;
        if (h) parts << hundredsCard[h];

        if (rem < 10)
            parts << unitsGen[rem];
        else if (rem < 20)
            parts << teensGen[rem - 10];
        else {
            int t = rem / 10, u = rem % 10;
            if (u == 0)
                parts << tensGen[t];
            else
                parts << tensCard[t] + " " + unitsGen[u];
        }
        return parts.join(" ");
    };


    auto card = [&](int num)->QString {
        if (num == 0) return "ноль";
        QStringList parts;
        int h   = num / 100;
        int rem = num % 100;
        if (h) parts << hundredsCard[h];

        if (rem < 10)
            parts << unitsCard[rem];
        else if (rem < 20)
            parts << teensCard[rem - 10];
        else {
            int t = rem / 10, u = rem % 10;
            parts << tensCard[t];
            if (u) parts << unitsCard[u];
        }
        return parts.join(" ");
    };

    auto wordForm = [](int n, QString one, QString two, QString five){
        if (n % 10 == 1 && n % 100 != 11) return one;
        if (n % 10 >= 2 && n % 10 <= 4 && (n %100 < 10 || n %100 >= 20)) return two;
        return five;
    };


    QStringList out;
    out << dayNames[d]
        << monthNames[m];


    int th    = y / 1000;
    int remY  = y % 1000;
    if (th)   out << thousandsCard(th);
    if (remY) out << ordinalGen(remY);
    out << "года";


    out << card(hh) << wordForm(hh, "час", "часа", "часов")
        << card(mm) << wordForm(mm, "минута", "минуты", "минут")
        << card(ss) << wordForm(ss, "секунда", "секунды", "секунд");


    ui->textBrowser->setText(out.join(" "));
}



void FormatChislovoy::on_calendarWidget_clicked(const QDate &date)
{
    this->m_date = date;
    ui->lineEdit->setText(m_date.toString("dd.MM.yyyy") + " ");

}


void FormatChislovoy::on_pushButton_clicked()
{
    QString input = ui->lineEdit->text().trimmed();

    QString appDir = QCoreApplication::applicationDirPath();
    QString fileName = appDir
                       + QDir::separator()
                       + "Statistika_false.txt";


    QStringList parts = input.split(' ', Qt::SkipEmptyParts);
    if (parts.size() != 2) {
        ui->lineEdit->setText("Ошибка: формат ДД.MM.ГГГГ. ЧЧ:MM:СС");

        QFile file(fileName);
        if (file.open(QIODevice::Append | QIODevice::Text)) {
            QTextStream out(&file);
                out << input;
                file.close();
        }

        return;
    }


    QString dateStr = parts.at(0);
    if (dateStr.endsWith('.'))
        dateStr.chop(1);
    QDate date = QDate::fromString(dateStr, "dd.MM.yyyy");
    if (!date.isValid()) {
        ui->lineEdit->setText("Ошибка: неверная дата ДД.MM.ГГГГ.");


        QFile file(fileName);
        if (file.open(QIODevice::Append | QIODevice::Text)) {
            QTextStream out(&file);
            out << input;
            file.close();
        }

        return;
    }
    ui->calendarWidget->setSelectedDate(date);



    QString timeStr = parts.at(1);
    if (timeStr.endsWith('.'))
        timeStr.chop(1);
    QTime time = QTime::fromString(timeStr, "hh:mm:ss");
    if (!time.isValid()) {
        ui->lineEdit->setText("Ошибка: неверное время ЧЧ:MM:СС");

        QFile file(fileName);
        if (file.open(QIODevice::Append | QIODevice::Text)) {
            QTextStream out(&file);
            out << input;
            file.close();
        }
        return;
    }


    this->m_date = date;
    this->m_time = time;
    writeData();
}


void FormatChislovoy::on_start_clocky_clicked()
{
   emit start_clock_signal (get_time());
}

