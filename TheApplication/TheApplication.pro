#-------------------------------------------------
#
# Project created by QtCreator 2017-11-05T12:00:00
#
#-------------------------------------------------

QT       += core gui webkitwidgets

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = TheApplication
TEMPLATE = app


SOURCES += \
    main.cpp \
    disease.cpp \
    person.cpp \
    daveywindow.cpp \
    mainwindow.cpp

HEADERS  += \
    person.h \
    disease.h \
    daveywindow.h \
    mainwindow.h

FORMS    += \
    daveywindow.ui \
    mainwindow.ui
