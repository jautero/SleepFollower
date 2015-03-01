#include <sleepstoretest.h>


#define TESTTIMESTAMP 93221700
const QDateTime teststarttime = QDateTime::fromTime_t(TESTTIMESTAMP);
#define TESTDIFFERENCE 60*(40+60*5)
const QDateTime testendtime = QDateTime::fromTime_t(TESTTIMESTAMP+TESTDIFFERENCE);

void SleepStoreTest::testNotify()
{

}

void SleepStoreTest::testPropertySet()
{
    testObject->setProperty("inBed",true);
    QVERIFY(testObject->m_inBed == true);
    testObject->setProperty("inBed",false);
    QVERIFY(testObject->m_inBed == false);
}

void SleepStoreTest::testPropertyGet()
{
    testObject->m_inBed=true;
    QVERIFY(testObject->property("inBed")==true);
    testObject->m_inBed=false;
    QVERIFY(testObject->property("inBed")==false);
}

void SleepStoreTest::testSleeptime()
{
    testObject->starttime=teststarttime;
    testObject->endtime=teststarttime;
    QVERIFY(testObject->sleepTime()=="0:00");
    testObject->starttime=teststarttime;
    testObject->endtime=testendtime;
    QVERIFY(testObject->sleepTime()=="5:40");
}

