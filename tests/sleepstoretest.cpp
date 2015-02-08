#include <sleepstoretest.h>

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
