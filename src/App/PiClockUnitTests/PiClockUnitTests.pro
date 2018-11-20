QT += core testlib multimedia sql
QT -= gui
TARGET = PiClockUnitTests

CONFIG += c++11 console testcase gcov
CONFIG -= app_bundle
TEMPLATE = app

# The following define makes your compiler emit warnings if you use
# any feature of Qt which as been marked deprecated (the exact warnings
# depend on your compiler). Please consult the documentation of the
# deprecated API in order to know how to port your code away from it.
DEFINES += QT_DEPRECATED_WARNINGS

# You can also make your code fail to compile if you use deprecated APIs.
# In order to do so, uncomment the following line.
# You can also select to disable deprecated APIs only up to a certain version of Qt.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0

SOURCES += \
    main.cpp \
    managers/settingsmanagertests.cpp \
    managers/alarmmanagertests.cpp \
    managers/widgetmanagertests.cpp \
    managers/databasemanagertests.cpp \
    models/alarmtests.cpp \
    games/mathgameservicetests.cpp \
    games/tictactoegameservicetests.cpp

INCLUDEPATH += $$PWD/../PiClockLib
LIBS += -L$$OUT_PWD/../PiClockLib -lPiClockLib

# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target

HEADERS += \
    managers/settingsmanagertests.h \
    managers/alarmmanagertests.h \
    managers/widgetmanagertests.h \
    managers/databasemanagertests.h \
    models/alarmtests.h \
    games/mathgameservicetests.h \
    games/tictactoegameservicetests.h
