#ifndef CLOCKY_H
#define CLOCKY_H

#include <QWidget>
#include <QTime>
#include <QTimer>

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

private:
    QTime currentTime;

    bool useRealTime;

    QTimer* updateTimer;

private slots:
    // void paintEvent(QPaintEvent* ev);
};

#endif // CLOCKY_H
