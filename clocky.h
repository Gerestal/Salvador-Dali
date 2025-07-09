#ifndef CLOCKY_H
#define CLOCKY_H

#include <QWidget>
#include <QTime>
#include <QTimer>
#include <QPainter>

QT_BEGIN_NAMESPACE
namespace Ui { class Clocky; }
QT_END_NAMESPACE

class Clocky : public QWidget {

    Q_OBJECT

public:
    Clocky(QWidget* parent = nullptr);

    void startClock(QTime time);
    void startClock();
    void stopClock();

    ~Clocky();

private:
    QTime currentTime;

    bool useRealTime;

    int deltaSec;

    QTimer* updateTimer;

    QPixmap* background;
    QPixmap* hours[12];
    QPixmap* hoursShadows[12];
    //QPixmap* minutes[60];
    //QPixmap* minutesShadows[60];

private slots:
    void paintEvent(QPaintEvent* ev);
    void updateTime();
};

#endif // CLOCKY_H
