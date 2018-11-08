#-------------------------------------------------
#
# Project created by QtCreator 2018-10-18T13:57:20
#
#-------------------------------------------------

QT       += core gui sql

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = PiClock
TEMPLATE = app

# The following define makes your compiler emit warnings if you use
# any feature of Qt which has been marked as deprecated (the exact warnings
# depend on your compiler). Please consult the documentation of the
# deprecated API in order to know how to port your code away from it.
DEFINES += QT_DEPRECATED_WARNINGS

# You can also make your code fail to compile if you use deprecated APIs.
# In order to do so, uncomment the following line.
# You can also select to disable deprecated APIs only up to a certain version of Qt.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0

CONFIG += c++11

SOURCES += \
    main.cpp \
    piclockapp.cpp \
    mainPage/appclock.cpp \
    mainPage/forecastwidget.cpp \
    mainPage/holidaycountdownwidget.cpp \
    mainPage/mainpage.cpp \
    mainPage/quoteswidget.cpp \
    mainPage/systemstatisticswidget.cpp \
    mainPage/weatherwidget.cpp \
    mainPage/worldclockwidget.cpp \
    settingsPage/settingspage.cpp \
    settingsPage/alarmlistitem.cpp \
    settingsPage/draglistwidget.cpp \
    alarmPage/alarmpage.cpp \
    alarmPage/mathgame.cpp

HEADERS += \
    piclockapp.h \
    mainPage/appclock.h \
    mainPage/forecastwidget.h \
    mainPage/holidaycountdownwidget.h \
    mainPage/mainpage.h \
    mainPage/quoteswidget.h \
    mainPage/systemstatisticswidget.h \
    mainPage/weatherwidget.h \
    mainPage/worldclockwidget.h \
    settingsPage/settingspage.h \
    settingsPage/alarmlistitem.h \
    settingsPage/draglistwidget.h \
    alarmPage/alarmpage.h \
    alarmPage/mathgame.h

FORMS += \
    piclockapp.ui \
    mainPage/weatherwidget.ui \
    mainPage/forecastwidget.ui \
    mainPage/quoteswidget.ui \
    mainPage/worldclockwidget.ui \
    mainPage/holidaycountdownwidget.ui \
    mainPage/systemstatisticswidget.ui \
    settingsPage/alarmlistitem.ui \
    alarmPage/mathgame.ui

RESOURCES += \
    resources.qrc

INCLUDEPATH += $$PWD/../PiClockLib
LIBS += -L$$OUT_PWD/../PiClockLib -lPiClockLib

# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target
