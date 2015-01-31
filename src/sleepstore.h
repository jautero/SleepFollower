#ifndef SLEEPSTORE_H
#define SLEEPSTORE_H

#include <QObject>

class SleepStore : public QObject
{
    Q_OBJECT
public:
    explicit SleepStore(QObject *parent = 0);
    Q_PROPERTY(bool inBed MEMBER m_inBed NOTIFY inBedChanged);

signals:
    void inBedChanged(bool value);

public slots:

private:
    bool m_inBed;

};

#endif // SLEEPSTORE_H
