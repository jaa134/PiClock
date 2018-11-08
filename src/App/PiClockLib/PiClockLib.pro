#-------------------------------------------------
#
# Project created by QtCreator 2018-10-30T16:05:37
#
#-------------------------------------------------
QT += core sql
QT -= gui

TARGET = PiClockLib
TEMPLATE = lib
CONFIG += staticlib

# The following define makes your compiler emit warnings if you use
# any feature of Qt which has been marked as deprecated (the exact warnings
# depend on your compiler). Please consult the documentation of the
# deprecated API in order to know how to port your code away from it.
DEFINES += QT_DEPRECATED_WARNINGS

# You can also make your code fail to compile if you use deprecated APIs.
# In order to do so, uncomment the following line.
# You can also select to disable deprecated APIs only up to a certain version of Qt.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0

SOURCES += \
        piclocklib.cpp \
        managers/alarmmanager.cpp \
        managers/settingsmanager.cpp \
        managers/widgetmanager.cpp \
        managers/databasemanager.cpp \
        models/alarm.cpp \
        games/mathgameservice.cpp \
    games/gameservice.cpp

HEADERS += \
        piclocklib.h \
        managers/alarmmanager.h \
        managers/settingsmanager.h \
        managers/widgetmanager.h \
        managers/databasemanager.h \
        models/alarm.h \
        models/game.h \
        games/mathgameservice.h \
    games/gameservice.h

unix {
    target.path = /usr/lib
    INSTALLS += target
}
