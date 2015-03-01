#ifndef SLEEPSTORE_H
#define SLEEPSTORE_H

#include <QObject>
#include <QString>
#include <QDateTime>
#include <QTimer>
class SleepStoreTest;

class SleepStore : public QObject
{
    Q_OBJECT
public:
    explicit SleepStore(QObject *parent = 0);
    Q_PROPERTY(bool inBed MEMBER m_inBed WRITE setInBed NOTIFY inBedChanged);
    Q_PROPERTY(QString sleepTime READ sleepTime NOTIFY sleepTimeChanged);
    QString sleepTime();
    void setInBed(bool value);

signals:
    void inBedChanged(bool value);
    void sleepTimeChanged(QString value);

public slots:
    void updateSleepTime();

private:
    bool m_inBed;
    int oldtimedelta;
    QDateTime starttime;
    QDateTime endtime;
    QTimer *updaterTimer;

    friend class SleepStoreTest;
};


#endif // SLEEPSTORE_H
