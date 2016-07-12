QT += core
QT += gui widgets sql concurrent

CONFIG += c++14

TARGET = SolarSystem
CONFIG -= app_bundle

TEMPLATE = app

SOURCES += main.cpp \
    solarsystemobject.cpp \
    solarsystemdbconnector.cpp \
    solarsystemcore.cpp

HEADERS += \
    solarsystemobject.h \
    solarsystemdbconnector.h \
    solarsystemcore.h
