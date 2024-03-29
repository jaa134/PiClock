#-------------------------------------------------
#
# Project created by QtCreator 2018-10-30T16:05:37
#
#-------------------------------------------------
QT += core sql multimedia network
QT -= gui

TARGET = PiClockLib
TEMPLATE = lib
CONFIG += staticlib gcov

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
        games/gameservice.cpp \
        games/mathgameservice.cpp \
        games/tictactoegameservice.cpp \
        games/memorygameservice.cpp \
        games/triviagameservice.cpp \
        widgets/worldclockwidgetservice.cpp \
        widgets/forecastwidgetservice.cpp \
        widgets/holidaycountdownwidgetservice.cpp \
        widgets/quoteswidgetservice.cpp \
        widgets/systemstatisticswidgetservice.cpp \
        widgets/weatherwidgetservice.cpp \
    widgets/commutewidgetservice.cpp \
    widgets/newswidgetservice.cpp

HEADERS += \
        piclocklib.h \
        managers/alarmmanager.h \
        managers/settingsmanager.h \
        managers/widgetmanager.h \
        managers/databasemanager.h \
        models/alarm.h \
        models/game.h \
        games/gameservice.h \
        games/mathgameservice.h \
        games/tictactoegameservice.h \
        teststub.h \
        games/memorygameservice.h \
        games/triviagameservice.h \
        widgets/worldclockwidgetservice.h \
        widgets/forecastwidgetservice.h \
        widgets/holidaycountdownwidgetservice.h \
        widgets/quoteswidgetservice.h \
        widgets/systemstatisticswidgetservice.h \
        widgets/weatherwidgetservice.h \
        widgets/widgetservice.h \
    widgets/commutewidgetservice.h \
    widgets/newswidgetservice.h

unix {
    target.path = /usr/lib
    INSTALLS += target
}
