QT += core
QT += gui widgets sql concurrent
QT += 3dcore 3drender 3dextras

CONFIG += c++14

TARGET = SolarSystem

CONFIG -= app_bundle

TEMPLATE = app

SOURCES += main.cpp \
    solarsystemobject.cpp \
    solarsystemdbconnector.cpp \
    solarsystemcore.cpp \
    solar3dobject.cpp \
    viewportwidget.cpp \
    solar3dviewport.cpp \
    UI/solargui.cpp \
    Parser/solarparser.cpp

HEADERS += \
    solarsystemobject.h \
    solarsystemdbconnector.h \
    solarsystemcore.h \
    solar3dobject.h \
    viewportwidget.h \
    solar3dviewport.h \
    UI/solargui.h \
    Parser/solarparser.h
