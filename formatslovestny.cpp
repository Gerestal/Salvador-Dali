#include "formatslovestny.h"
#include "ui_formatslovestny.h"
#include <QDate>
#include <QRegularExpression>
#include <QFile>
#include <QTextStream>

FormatSlovestny::FormatSlovestny(QWidget *parent)
    : QMainWindow(parent),
    ui(new Ui::FormatSlovestny)
{
    ui->setupUi(this);


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

    QString in = ui->slova->toPlainText()
                     .toLower()
                     .trimmed();
    if (in.isEmpty()) {
        ui->slova->setText("Ошибка: пустая строка");

        QString fileName = ":/new/prefix_statistika_neverno/Statistika_false.txt";
        QFile file(fileName);

        if (file.open(QIODevice::WriteOnly | QIODevice::Text)) {
            QTextStream out(&file);
            out << "Пустая строка";
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
        {"один",1}, {"два",2}, {"три",3}, {"четыре",4},
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
    auto parseOrdinalGen = [&](const QStringList& tk, int& val)->bool {
        val = 0;

        if (tk.size()>=2) {
            QString two = tk[0] + " " + tk[1];
            if (thouGenRev.contains(two)) {
                val += thouGenRev[two];
            }
        }

        for (auto& w : tk) {
            if      (hundredsCardRev.contains(w)) val += hundredsCardRev[w];
            else if (teensGenRev.contains(w))     val += teensGenRev[w];
            else if (tensGenRev.contains(w))      val += tensGenRev[w];
            else if (unitsGenRev.contains(w))     val += unitsGenRev[w];
        }
        return val>0;
    };


    QStringList tk = in.split(QRegularExpression("\\s+"), Qt::SkipEmptyParts);
    if (tk.size() < 6) {
        ui->slova->setText("Ошибка: слишком короткая строка");

        QString fileName = ":/new/prefix_statistika_neverno/Statistika_false.txt";
        QFile file(fileName);

        if (file.open(QIODevice::WriteOnly | QIODevice::Text)) {
            QTextStream out(&file);
            out << in;
            file.close();
        }

        return;
    }


    int d = dayMap.value(tk[0], -1);
    int m = monthMap.value(tk[1], -1);
    if (d < 1 || m < 1) {
        ui->slova->setText("Ошибка: неверный день или месяц");

        QString fileName = ":/new/prefix_statistika_neverno/Statistika_false.txt";
        QFile file(fileName);

        if (file.open(QIODevice::WriteOnly | QIODevice::Text)) {
            QTextStream out(&file);
            out << in;
            file.close();
        }

        return;
    }

    // 6. Год — найти индекс слова "года"
    int idxG = tk.indexOf("года");
    if (idxG < 2) {
        ui->slova->setText("Ошибка: нет слова «года»");

        QString fileName = ":/new/prefix_statistika_neverno/Statistika_false.txt";
        QFile file(fileName);

        if (file.open(QIODevice::WriteOnly | QIODevice::Text)) {
            QTextStream out(&file);
            out << in;
            file.close();
        }

        return;
    }

    QStringList yearWords = tk.mid(2, idxG - 2);
    int y = 0;
    if (!parseOrdinalGen(yearWords, y) || y < 1 || y > 9999) {
        ui->slova->setText("Ошибка: не удалось определить год");

        QString fileName = ":/new/prefix_statistika_neverno/Statistika_false.txt";
        QFile file(fileName);

        if (file.open(QIODevice::WriteOnly | QIODevice::Text)) {
            QTextStream out(&file);
            out << in;
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
        return;
    }
    ++pos;

    if (!nextNum(mm, {"минута","минуты","минут"}) ||
        pos>=tk.size() || !tk[pos].startsWith("минут")) {
        ui->slova->setText("Ошибка определения минут");
        return;
    }
    ++pos;

    if (!nextNum(ss, {"секунда","секунды","секунд"}) ||
        pos>=tk.size() || !tk[pos].startsWith("секунд")) {
        ui->slova->setText("Ошибка определения секунд");
        return;
    }


    QDate date(d, m, y);
    QTime time(hh, mm, ss);
    if (!date.isValid() || !time.isValid()) {
        ui->slova->setText("Ошибка: некорректная дата или время");

        QString fileName = ":/new/prefix_statistika_neverno/Statistika_false.txt";
        QFile file(fileName);

        if (file.open(QIODevice::WriteOnly | QIODevice::Text)) {
            QTextStream out(&file);
            out << in;
            file.close();
        }

        return;
    }

    m_date = date;
    m_time = time;
    writeData();

}


