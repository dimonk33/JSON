#-------------------------------------------------
#
# Project created by QtCreator 2014-07-29T10:34:42
#
#-------------------------------------------------

QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = JSON
TEMPLATE = app


SOURCES += main.cpp\
        widget.cpp \
    frozen.c \
    cjsonconverter.cpp

HEADERS  += widget.h \
    frozen.h \
    datatypes.h \
    cjsonconverter.h

FORMS    += widget.ui
