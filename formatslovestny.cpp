#include "formatslovestny.h"
#include "ui_formatslovestny.h"
#include <QDate>
#include <QRegularExpression>
#include <QFile>
#include <QTextStream>
#include <QDir>

FormatSlovestny::FormatSlovestny(QWidget *parent)
    : QMainWindow(parent),
    ui(new Ui::FormatSlovestny)
{
    ui->setupUi(this);
    setWindowIcon(QIcon(":/img/images/SalvadorDali.png"));

    resize(700, 500);
    setWindowTitle("Словесная запись");
    show();

}

FormatSlovestny::~FormatSlovestny()
{
    delete ui;
}



void FormatSlovestny:: writeData(){ //цифрами
    ui->label_3->setText(
        m_date.toString("dd.MM.yyyy") + " " +
        m_time.toString("hh:mm:ss")
        );
}




void FormatSlovestny::on_pushButtonParseVerbal_clicked()
{

    QString appDir = QCoreApplication::applicationDirPath();
    QString fileName = appDir
                       + QDir::separator()
                       + "Statistika_false.txt";


    QString in = ui->slova->toPlainText()
                     .toLower()
                     .trimmed();
    if (in.isEmpty()) {
        ui->slova->setText("Ошибка: пустая строка");

        QFile file(fileName);
       if (file.open(QIODevice::Append | QIODevice::Text)) {
            QTextStream out(&file);
            out << "Пустая строка" << '\n';
            file.close();
        }

        return;
    }


    QStringList dayNames = {
        "", "первое",   "второе",     "третье",    "четвёртое",
        "пятое",       "шестое",     "седьмое",   "восьмое",   "девятое",
        "десятое",     "одиннадцатое","двенадцатое","тринадцатое","четырнадцатое",
        "пятнадцатое", "шестнадцатое","семнадцатое","восемнадцатое","девятнадцатое",
        "двадцатое",   "двадцать первое","двадцать второе","двадцать третье",
        "двадцать четвёртое","двадцать пятое","двадцать шестое",
        "двадцать седьмое","двадцать восьмое","двадцать девятое",
        "тридцатое","тридцать первое"
    };
    QMap<QString,int> dayMap;
    for (int i = 1; i < dayNames.size(); ++i)
        dayMap[ dayNames[i] ] = i;


    QStringList monthNames = {
        "", "января", "февраля", "марта", "апреля", "мая",   "июня",
        "июля", "августа", "сентября", "октября", "ноября", "декабря"
    };
    QMap<QString,int> monthMap;
    for (int i = 1; i < monthNames.size(); ++i)
        monthMap[ monthNames[i] ] = i;


    QMap<QString,int> unitsCardRev = {
        {"один",1}, {"два",2}, {"две",2}, {"три",3}, {"четыре",4},
        {"пять",5},{"шесть",6},{"семь",7},{"восемь",8},{"девять",9}
    };
    QMap<QString,int> teensCardRev = {
        {"десять",10}, {"одиннадцать",11}, {"двенадцать",12},
        {"тринадцать",13}, {"четырнадцать",14}, {"пятнадцать",15},
        {"шестнадцать",16}, {"семнадцать",17}, {"восемнадцать",18},
        {"девятнадцать",19}
    };
    QMap<QString,int> tensCardRev = {
        {"двадцать",20}, {"тридцать",30}, {"сорок",40},
        {"пятьдесят",50}, {"шестьдесят",60},
        {"семьдесят",70}, {"восемьдесят",80}, {"девяносто",90}
    };
    QMap<QString,int> hundredsCardRev = {
        {"сто",100}, {"двести",200}, {"триста",300}, {"четыреста",400},
        {"пятьсот",500}, {"шестьсот",600}, {"семьсот",700},
        {"восемьсот",800}, {"девятьсот",900}
    };


    QMap<QString,int> unitsGenRev = {
        {"первого",1}, {"второго",2}, {"третьего",3}, {"четвёртого",4},
        {"пятого",5}, {"шестого",6}, {"седьмого",7}, {"восьмого",8},
        {"девятого",9}
    };
    QMap<QString,int> teensGenRev = {
        {"десятого",10}, {"одиннадцатого",11}, {"двенадцатого",12},
        {"тринадцатого",13}, {"четырнадцатого",14}, {"пятнадцатого",15},
        {"шестнадцатого",16}, {"семнадцатого",17}, {"восемнадцатого",18},
        {"девятнадцатого",19}
    };
    QMap<QString,int> tensGenRev = {
        {"двадцатого",20}, {"тридцатого",30}, {"сорокового",40},
        {"пятидесятого",50}, {"шестидесятого",60}, {"семидесятого",70},
        {"восьмидесятого",80}, {"девяностого",90}
    };
    QMap<QString,int> thouGenRev = {
        {"одна тысяча",1000}, {"две тысячи",2000}
        // {"три тысячи",3000},
        // {"четыре тысячи",4000},
        // {"пять тысяч",5000}, {"шесть тысяч",6000}, {"семь тысяч",7000},
        // {"восемь тысяч",8000}, {"девять тысяч",9000}
    };


    auto parseCardinal = [&](const QStringList& tk, int& val)->bool {
        val = 0;
        for (auto& w : tk) {
            if      (hundredsCardRev.contains(w)) val += hundredsCardRev[w];
            else if (teensCardRev.contains(w))    val += teensCardRev[w];
            else if (tensCardRev.contains(w))     val += tensCardRev[w];
            else if (unitsCardRev.contains(w))    val += unitsCardRev[w];
            else return false;
        }
        return true;
    };


    auto extractThousands = [&](QStringList& words, int& val) -> bool {
        val = 0;


        QMap<QString, int> thouNomRev = {
            {"одна тысяча", 1000}, {"две тысячи", 2000}, {"три тысячи", 3000},
            {"четыре тысячи", 4000}, {"пять тысяч", 5000}, {"шесть тысяч", 6000},
            {"семь тысяч", 7000}, {"восемь тысяч", 8000}, {"девять тысяч", 9000}
        };

        for (int len = qMin(3, words.size()); len >= 1; --len) {
            QString chunk = words.mid(0, len).join(' ');
            if (thouNomRev.contains(chunk)) {
                val += thouNomRev[chunk];
                words = words.mid(len);
                return true;
            }
        }
        return true;
    };

    auto parseOrdinalGen = [&](const QStringList& input, int& val) -> bool {
        val = 0;
        QStringList words = input;

        int thousands = 0;
        if (!extractThousands(words, thousands)) return false;

        int remainder = 0;
        for (auto& w : words) {
            if      (hundredsCardRev.contains(w)) remainder += hundredsCardRev[w];
            else if (teensGenRev.contains(w))     remainder += teensGenRev[w];
            else if (tensGenRev.contains(w))      remainder += tensGenRev[w];
            else if (unitsGenRev.contains(w))     remainder += unitsGenRev[w];
            else if (!w.isEmpty())                return false;
        }

        val = thousands + remainder;
        return (val > 0 && val <= 9999);
    };


    QStringList tk = in.split(QRegularExpression("\\s+"), Qt::SkipEmptyParts);

    int idxM = -1;
    for (int i = 0; i < tk.size(); ++i) {
        if (monthMap.contains(tk[i])) { idxM = i; break; }
    }
    if (idxM < 1) {
        ui->slova->setText("Ошибка: месяц не распознан");

        QFile file(fileName);
        if (file.open(QIODevice::Append | QIODevice::Text)) {
            QTextStream out(&file);
            out << in<< '\n';
            file.close();
        }
        return;
    }
    int idxG = tk.indexOf("года");
    if (idxG < idxM + 1) {
        ui->slova->setText("Ошибка: нет слова «года»");

        QFile file(fileName);
        if (file.open(QIODevice::Append | QIODevice::Text)) {
            QTextStream out(&file);
            out << in<< '\n';
            file.close();
        }
        return;
    }


    QStringList dayWords = tk.mid(0, idxM);
    QString dayStr = dayWords.join(' ');
    int d = dayMap.value(dayStr, -1);
    if (d < 1 || d > 31) {
        ui->slova->setText("Ошибка: день не распознан");

        QFile file(fileName);
        if (file.open(QIODevice::Append | QIODevice::Text)) {
            QTextStream out(&file);
            out << in<< '\n';
            file.close();
        }
        return;
    }


    int m = monthMap.value(tk[idxM], -1);


    QStringList yearWords = tk.mid(idxM + 1, idxG - idxM - 1);
    int y = 0;
    if (!parseOrdinalGen(yearWords, y) || y < 1 || y > 9999) {
        ui->slova->setText("Ошибка: год не распознан");

        QFile file(fileName);
        if (file.open(QIODevice::Append | QIODevice::Text)) {
            QTextStream out(&file);
            out << in<< '\n';
            file.close();
        }
        return;
    }


    int pos = idxG + 1;
    auto nextNum = [&](int& num, const QStringList& markers)->bool {
        QStringList buf;
        while (pos < tk.size()) {
            bool isMarker = false;
            for (auto& mk : markers) {
                if (tk[pos].startsWith(mk)) { isMarker = true; break; }
            }
            if (isMarker) break;
            buf << tk[pos++];
        }
        return !buf.isEmpty() && parseCardinal(buf, num);
    };

    int hh, mm, ss;
    if (!nextNum(hh, {"час", "часов", "часа"}) ||
        pos>=tk.size() || !tk[pos].startsWith("час")) {
        ui->slova->setText("Ошибка определения часов");

        QFile file(fileName);
        if (file.open(QIODevice::Append | QIODevice::Text)) {
            QTextStream out(&file);
            out << in<< '\n';
            file.close();
        }
        return;
    }
    ++pos;

    if (!nextNum(mm, {"минута","минуты","минут"}) ||
        pos>=tk.size() || !tk[pos].startsWith("минут")) {
        ui->slova->setText("Ошибка определения минут");

        QFile file(fileName);
        if (file.open(QIODevice::Append | QIODevice::Text)) {
            QTextStream out(&file);
            out << in<< '\n';
            file.close();
        }
        return;
    }
    ++pos;

    if (!nextNum(ss, {"секунда","секунды","секунд"}) ||
        pos>=tk.size() || !tk[pos].startsWith("секунд")) {
        ui->slova->setText("Ошибка определения секунд");

        QFile file(fileName);
        if (file.open(QIODevice::Append | QIODevice::Text)) {
            QTextStream out(&file);
            out << in<< '\n';
            file.close();
        }
        return;
    }

    QDate date(y, m, d);
    QTime time(hh, mm, ss);
    if (!date.isValid() || !time.isValid()) {
        ui->slova->setText("Ошибка: некорректная дата или время");

        QFile file(fileName);
        if (file.open(QIODevice::Append | QIODevice::Text)) {
            QTextStream out(&file);
            out << in<< '\n';
            file.close();
        }
        return;
    }

    m_date = date;
    m_time = time;
    writeData();
}

void FormatSlovestny::on_start_clocky_clicked()
{

        emit start_clock_signal (get_time());
        this ->hide();

}

