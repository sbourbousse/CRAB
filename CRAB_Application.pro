#-------------------------------------------------
#
# Project created by QtCreator 2019-11-13T11:11:14
#
#-------------------------------------------------

QT       += core gui sql
CONFIG   += c++11

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = CRAB_Application
TEMPLATE = app

# The following define makes your compiler emit warnings if you use
# any feature of Qt which as been marked as deprecated (the exact warnings
# depend on your compiler). Please consult the documentation of the
# deprecated API in order to know how to port your code away from it.
DEFINES += QT_DEPRECATED_WARNINGS

# You can also make your code fail to compile if you use deprecated APIs.
# In order to do so, uncomment the following line.
# You can also select to disable deprecated APIs only up to a certain version of Qt.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0


SOURCES += main.cpp\
        mainwindow.cpp \
    typeborne.cpp \
    borne.cpp \
    station.cpp \
    visite.cpp \
    technicien.cpp \
    maintenance.cpp \
    date.cpp \
    passerelle.cpp

HEADERS  += mainwindow.h \
    typeborne.h \
    borne.h \
    station.h \
    visite.h \
    technicien.h \
    maintenance.h \
    date.h \
    passerelle.h

FORMS    += mainwindow.ui
