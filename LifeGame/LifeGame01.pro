#-------------------------------------------------
#
# Project created by QtCreator 2013-12-14T12:53:48
#
#-------------------------------------------------

QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = LifeGame01
TEMPLATE = app

INCLUDEPATH += include

SOURCES += main.cpp\
           mainwindow.cpp \
           lifegamewidget.cpp \
           src/LifeGame.cpp

HEADERS += mainwindow.h \
           lifegamewidget.h \
           include/LifeGame.h
