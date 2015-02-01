#ifndef SLEEPSTORETEST_H
#define SLEEPSTORETEST_H
#include <QTest>
#include "sleepstore.h"

class SleepStoreTest: public QObject
{
    Q_OBJECT
private slots:
    void init() { testObject = new SleepStore(); }
    void testTestObjectSetup() { QVERIFY(testObject != 0); }
    void cleanup() { if (testObject) { delete testObject; testObject = 0; } }
private:
    SleepStore *testObject;
};

#endif // SLEEPSTORETEST_H
