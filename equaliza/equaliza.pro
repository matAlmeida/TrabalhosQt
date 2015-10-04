#-------------------------------------------------
#
# Project created by QtCreator 2015-10-02T15:58:33
#
#-------------------------------------------------

QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets printsupport

TARGET = equaliza
TEMPLATE = app


SOURCES += main.cpp\
        mainwindow.cpp \
    qcustomplot.cpp \
    carregar.cpp \
    processar.cpp \
    grafico.cpp

HEADERS  += mainwindow.h \
    qcustomplot.h \
    carregar.h \
    processar.h \
    grafico.h

FORMS    += mainwindow.ui
