#-------------------------------------------------
#
# Project created by QtCreator 2017-11-04T12:25:02
#
#-------------------------------------------------

QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = GenomeData
TEMPLATE = app


SOURCES += main.cpp\
        mainwindow.cpp \
    person.cpp \
    disease.cpp

HEADERS  += mainwindow.h \
    person.h \
    disease.h

FORMS    += mainwindow.ui
