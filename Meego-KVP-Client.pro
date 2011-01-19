#-------------------------------------------------
#
# Project created by QtCreator 2010-12-01T13:04:39
#
#-------------------------------------------------

QT       += core gui
QT       += network

TARGET = Meego-KVP-Client
CONFIG += meegotouch
TEMPLATE = app
target.path=/usr/bin
INSTALLS=target


SOURCES += main.cpp \
    settingpage.cpp \
    sendthread.cpp \
    registrationpage.cpp \
    recvclass.cpp \
    message.cpp \
    mainwindow.cpp \
    loginpage.cpp \
    list_model.cpp \
    infopage.cpp \
    homepage.cpp \
    contactlistpage.cpp \
    clientsocket.cpp \
    dialogpage.cpp \
    ThumbnailListControl.cpp

HEADERS += \
    settingpage.h \
    sendthread.h \
    registrationpage.h \
    recvclass.h \
    message.h \
    MContentItemCreator.h \
    mainwindow.h \
    loginpage.h \
    list_model.h \
    infopage.h \
    homepage.h \
    contactlistpage.h \
    contact_data.h \
    clientsocket.h \
    dialogpage.h \
    config.h \
    ThumbnailListControl.h

OTHER_FILES += \
    style/Meego-KVP-Client.css \
    style/logo.gif \
    svg/my-meegotouch-list.svg \
    svg/my-icon-incoming-message.svg \
    svg/icon-user-online.svg \
    svg/icon-user-offline.svg \
    svg/button.svg \
    svg/background.svg
