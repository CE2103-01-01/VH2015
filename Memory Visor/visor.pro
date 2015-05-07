#-------------------------------------------------
#
# Project created by QtCreator 2015-04-20T02:12:12
#
#-------------------------------------------------

QT       += core gui network

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets printsupport

TARGET = visor
TEMPLATE = app


SOURCES += main.cpp\
        mainwindow.cpp \
    qcustomplot.cpp \
    mytcpsocket.cpp

HEADERS  += mainwindow.h \
    qcustomplot.h \
    mytcpsocket.h

FORMS    += mainwindow.ui
