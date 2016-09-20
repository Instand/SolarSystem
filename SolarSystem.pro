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
    Parser/solarparser.cpp \
    Interface/isolarsystemobject.cpp \
    Interface/ivisualsolarobject.cpp \
    Scene/visualsolarobject.cpp \
    Scene/basevisualsolarobject.cpp \
    Scene/SceneObjects/emptysolarobject.cpp \
    Scene/SceneObjects/solarskybox.cpp

HEADERS += \
    solarsystemobject.h \
    solarsystemdbconnector.h \
    solarsystemcore.h \
    solar3dobject.h \
    viewportwidget.h \
    solar3dviewport.h \
    UI/solargui.h \
    Parser/solarparser.h \
    Interface/isolarsystemobject.h \
    Interface/ivisualsolarobject.h \
    Scene/visualsolarobject.h \
    Scene/basevisualsolarobject.h \
    Scene/SceneObjects/emptysolarobject.h \
    Scene/SceneObjects/solarskybox.h

RESOURCES += \
    res.qrc
