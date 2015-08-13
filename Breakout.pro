#-------------------------------------------------
#
# Project created by QtCreator 2015-08-04T15:55:18
#
#-------------------------------------------------

QT       += core gui \
            multimedia

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = Breakout
TEMPLATE = app


SOURCES += main.cpp \
    bodygame.cpp \
    demond.cpp \
    health.cpp \
    player.cpp \
    score.cpp \
    ball.cpp \
    startmenu.cpp

HEADERS  += \
    bodygame.h \
    demond.h \
    health.h \
    player.h \
    score.h \
    ball.h \
    startmenu.h

FORMS    += mainwindow.ui

RESOURCES += \
    res.qrc

DISTFILES +=
