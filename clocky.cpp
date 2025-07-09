#include "clocky.h"

Clocky::Clocky(QWidget* parent)
    : updateTimer(new QTimer(this))
{
    updateTimer->setInterval(50);
}

void Clocky::startClock(QTime time)
{
    currentTime = time;
    useRealTime = false;
    updateTimer->start();
}

void Clocky::startClock()
{
    currentTime = QTime::currentTime();
    useRealTime = true;
    updateTimer->start();
}

void Clocky::stopClock(){
    updateTimer->stop();
}

Clocky::~Clocky(){
    delete updateTimer;
}
