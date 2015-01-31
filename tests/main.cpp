#include <QtQml>
#include <QScopedPointer>
//#include <QQuickView>
#include <QQmlEngine>
#include <QGuiApplication>
#include <sleepstore.h>
#include <QtQuickTest/quicktest.h>

// SailCalcTestSet is just a convenient name for reports - not linked to any of the main project entities
int main(int argc, char **argv)
{
    QGuiApplication app(argc, argv);

    qmlRegisterType<SleepStore>("fi.iki.jautero.sleepfollower",1,0,"SleepStore");

    return quick_test_main(argc, argv, "SleepFollowerTestSet", QUICK_TEST_SOURCE_DIR);
}
