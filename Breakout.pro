#-------------------------------------------------
#
# Project created by QtCreator 2015-08-04T15:55:18
#
#-------------------------------------------------

QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = Breakout
TEMPLATE = app


SOURCES += main.cpp \
    MyRect.cpp \
    bodygame.cpp \
    demond.cpp \
    health.cpp \
    player.cpp \
    score.cpp \
    ball.cpp

HEADERS  += \
    MyRect.h \
    bodygame.h \
    demond.h \
    health.h \
    player.h \
    score.h \
    ball.h

FORMS    += mainwindow.ui
