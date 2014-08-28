#-------------------------------------------------
#
# Project created by QtCreator 2014-08-19T20:04:03
#
#-------------------------------------------------

QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = Stundenplan
TEMPLATE = app


SOURCES += main.cpp\
        mainwindow.cpp \
    timeClass.cpp \
    fileparser.cpp

HEADERS  += mainwindow.h \
    timeClass.h \
    fileparser.h

FORMS    += mainwindow.ui
