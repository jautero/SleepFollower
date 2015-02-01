#include <QtQml>
#include <QScopedPointer>
#include <QQmlEngine>
#include <QGuiApplication>
#include <QtQuickTest/quicktest.h>

#include <QTest>
#include <sleepstoretest.h>

// SailCalcTestSet is just a convenient name for reports - not linked to any of the main project entities
int main(int argc, char **argv)
{
    QGuiApplication app(argc, argv);

    qmlRegisterType<SleepStore>("fi.iki.jautero.sleepfollower",1,0,"SleepStore");

    SleepStoreTest sleepstoretest;
    QTest::qExec(&sleepstoretest);

    return quick_test_main(argc, argv, "SleepFollowerTestSet", QUICK_TEST_SOURCE_DIR);
}
