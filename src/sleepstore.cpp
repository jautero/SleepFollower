#include "sleepstore.h"

SleepStore::SleepStore(QObject *parent) :
    QObject(parent),m_inBed(false),oldtimedelta(0),starttime(),endtime(),updaterTimer(0)
{
    updaterTimer=new QTimer(this);
    connect(updaterTimer,SIGNAL(timeout()),this,SLOT(updateSleepTime()));
    updaterTimer->start(60000);
}

void SleepStore::updateSleepTime()
{
    QString value=sleepTime();
}

QString SleepStore::sleepTime()
{
    int hour, minute;
    int timedelta;
    QString value;

    if (starttime.isNull()) {
        timedelta=0;
    } else if (endtime.isNull()) {
        timedelta=starttime.secsTo(QDateTime::currentDateTime());
    } else {
        timedelta=starttime.secsTo(endtime);
    }
    timedelta /= 60;
    minute=timedelta % 60;
    hour=timedelta/60;
    value=QString("%1:%2").arg(hour,1,10,QChar('0')).arg(minute,2,10,QChar('0'));
    if (timedelta!=oldtimedelta) {
        oldtimedelta=timedelta;
        emit sleepTimeChanged(value);
    }
    return value;
}

void SleepStore::setInBed(bool value)
{
    m_inBed=value;
    if (value) {
        starttime=QDateTime::currentDateTime();
        endtime=QDateTime();
    } else  {
        endtime=QDateTime::currentDateTime();
    }
    emit inBedChanged(value);
}
