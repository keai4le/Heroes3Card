#-------------------------------------------------
#
# Project created by QtCreator 2015-09-09T14:32:13
#
#-------------------------------------------------

QT       += core gui
QT       += network
QT       += widgets

TARGET = Heroes3CardEdition


TEMPLATE = app


SOURCES += main.cpp \
    card.cpp \
    monster.cpp \
    realmonstercard.cpp \
    skeletons.cpp \
    bonedragon.cpp \
    player.cpp \
    desk.cpp \
    messagesender.cpp \
    messagereceiver.cpp \
    mainwindow.cpp \
    nomonster.cpp

HEADERS += \
    card.h \
    monster.h \
    realmonstercard.h \
    skeletons.h \
    bonedragon.h \
    player.h \
    desk.h \
    messagesender.h \
    messagereceiver.h \
    mainwindow.h \
    nomonster.h

FORMS += \
    mainwindow.ui
