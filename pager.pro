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
    registrationpage.cpp \
    clientsocket.cpp \
    loginpage.cpp \
    sendthread.cpp

HEADERS += \
    homepage.h \
    registrationpage.h \
    clientsocket.h \
    loginpage.h \
    sendthread.h
