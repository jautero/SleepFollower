TEMPLATE = app

# The name of your app
TARGET = tst-harbour-sleepfollower-pro-sailfish

include(../src/src.pri)
CONFIG += qmltestcase

QT += testlib

TARGETPATH = /usr/bin
target.path = $$TARGETPATH

DEPLOYMENT_PATH = /usr/share/$$TARGET
qml.path = $$DEPLOYMENT_PATH

extra.path = $$DEPLOYMENT_PATH
extra.files = runTestsOnDevice.sh

# defining QUICK_TEST_SOURCE_DIR here doesn't work QtCreator keeps injecting another definition to command line (from CONFIG += qmltestcase ?)
#DEFINES += QUICK_TEST_SOURCE_DIR=\"\\\"\"$${DEPLOYMENT_PATH}/\"\\\"\"
DEFINES += DEPLOYMENT_PATH=\"\\\"\"$${DEPLOYMENT_PATH}/\"\\\"\"

# C++ sources
SOURCES += main.cpp \
    sleepstoretest.cpp

# C++ headers

INSTALLS += target qml extra

# QML files and folders
qml.files = *.qml

OTHER_FILES += \
    tst_RealUiTest.qml \
    tst_NonUiTests.qml

HEADERS += \
    sleepstoretest.h


