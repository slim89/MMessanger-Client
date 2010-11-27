#-------------------------------------------------
#
# Project created by QtCreator 2010-11-24T15:04:44
#
#-------------------------------------------------

QT       += core gui

TARGET = pager
CONFIG += meegotouch
TEMPLATE = app
target.path=/usr/local/bin
INSTALLS=target


SOURCES += main.cpp \
    homepage.cpp \
    loginpage.cpp \
    sendthread.cpp \
    clientsocket.cpp \
    registrationpage.cpp \
    mainwindow.cpp \
    settingpage.cpp \
    recvclass.cpp \
    infopage.cpp

HEADERS += \
    homepage.h \
    registrationpage.h \
    loginpage.h \
    sendthread.h \
    clientsocket.h \
    mainwindow.h \
    settingpage.h \
    recvclass.h \
    infopage.h
