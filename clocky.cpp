#include "clocky.h"

Clocky::Clocky(QWidget* parent)
    : QWidget(parent)
    , updateTimer(new QTimer(this))
{
    background = new QPixmap(":/background/background.jpg");
    for(int i = 0; i < 12; i++){
        hours[i] = new QPixmap(tr(":/hourHands/hours/%1.png").arg(i + 1));
        hoursShadows[i] = new QPixmap(tr(":/hourHands/hours/%1s.png").arg(i + 1));
    }

    for(int i = 0; i < 60; i++){
        minutes[i] = new QPixmap(tr(":/minuteHands/minutes/%1.png").arg(i + 1));
        minutesShadows[i] = new QPixmap(tr(":/minuteHands/minutes/%1s.png").arg(i + 1));
    }

    updateTimer->setInterval(1000);

    connect(updateTimer, &QTimer::timeout, this, &Clocky::updateTime);
}

void Clocky::startClock(QTime time)
{
    deltaSec = QTime::currentTime().secsTo(time);
    useRealTime = false;
    updateTimer->start();
}

void Clocky::startClock()
{
    currentTime = QTime::currentTime();
    useRealTime = true;
    updateTimer->start();
}

void Clocky::stopClock()
{
    updateTimer->stop();
}

void Clocky::paintEvent(QPaintEvent* ev)
{
    QPainter painter(this);
    double width = this->width();
    double height = this->height();

    int hour = currentTime.hour() % 12 - 1;
    int minute = currentTime.minute();

    double offset;

    if(width > height)
    {
        if(width / height > 1.2415)
        {
            offset = height * (width / height - 1.2415);
            painter.drawPixmap(0, 0, background->scaledToWidth(width - offset, Qt::SmoothTransformation));
            if(updateTimer->isActive()){
                painter.drawPixmap(0, 0, hoursShadows[hour]->scaledToWidth(width - offset, Qt::SmoothTransformation));
                painter.drawPixmap(0, 0, minutesShadows[minute]->scaledToWidth(width - offset, Qt::SmoothTransformation));
                painter.drawPixmap(0, 0, hours[hour]->scaledToWidth(width - offset, Qt::SmoothTransformation));
                painter.drawPixmap(0, 0, minutes[minute]->scaledToWidth(width - offset, Qt::SmoothTransformation));
            }
        }
        else
        {
            painter.drawPixmap(0, 0, background->scaledToWidth(width, Qt::SmoothTransformation));
            if(updateTimer->isActive()){
                painter.drawPixmap(0, 0, hoursShadows[hour]->scaledToWidth(width, Qt::SmoothTransformation));
                painter.drawPixmap(0, 0, minutesShadows[minute]->scaledToWidth(width, Qt::SmoothTransformation));
                painter.drawPixmap(0, 0, hours[hour]->scaledToWidth(width, Qt::SmoothTransformation));
                painter.drawPixmap(0, 0, minutes[minute]->scaledToWidth(width, Qt::SmoothTransformation));
            }
        }
    }
    else
    {
        painter.drawPixmap(0, 0, background->scaledToWidth(width, Qt::SmoothTransformation));
        if(updateTimer->isActive()){
            painter.drawPixmap(0, 0, hoursShadows[hour]->scaledToWidth(width, Qt::SmoothTransformation));
            painter.drawPixmap(0, 0, minutesShadows[minute]->scaledToWidth(width, Qt::SmoothTransformation));
            painter.drawPixmap(0, 0, hours[hour]->scaledToWidth(width, Qt::SmoothTransformation));
            painter.drawPixmap(0, 0, minutes[minute]->scaledToWidth(width, Qt::SmoothTransformation));
        }
    }
}

void Clocky::updateTime(){
    currentTime = QTime::currentTime();
    if(!useRealTime)
    {
        currentTime = currentTime.addSecs(deltaSec);
    }
    update();
}

QTime Clocky::getClockTime()
{
    if(useRealTime) return currentTime;
    else return currentTime.addSecs(deltaSec);
}

void Clocky::setClockTime()
{
    useRealTime = true;
    currentTime = QTime::currentTime();
    update();
}

void Clocky::setClockTime(QTime time)
{
    deltaSec = QTime::currentTime().secsTo(time);
    useRealTime = false;
    currentTime = time;
    update();
}

Clocky::~Clocky(){
    delete updateTimer;
    delete background;
    for(int i = 0; i < 12; i++){
        delete hours[i];
        delete hoursShadows[i];
    }

    for(int i = 0; i < 60; i++){
        delete minutes[i];
        delete minutesShadows[i];
    }
}
