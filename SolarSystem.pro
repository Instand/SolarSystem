QT += core
QT += gui widgets sql concurrent
QT += 3dcore 3drender 3dextras 3dinput
QT += qml quick
QT += 3dquickextras

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
    Scene/SceneObjects/solarskybox.cpp \
    SolarCore/isolarmathcore.cpp \
    SolarCore/solarmathcore.cpp \
    SolarCore/SolarObjects/solarobjects.cpp \
    SolarCore/SolarObjects/abstractsolarobject.cpp \
    SolarCore/solarobjectscontainer.cpp \
    Scene/SceneObjects/planet.cpp \
    SolarCore/planetscontainer.cpp \
    SolarCore/solaranimator.cpp \
    UI/solarcontrollerui.cpp \
    Scene/solarentity.cpp \
    UI/solarquickui.cpp \
    Scene/SceneObjects/planetring.cpp \
    SolarCore/cameracontroller.cpp

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
    Scene/SceneObjects/solarskybox.h \
    SolarCore/isolarmathcore.h \
    SolarCore/solarmathcore.h \
    SolarCore/SolarObjects/abstractsolarobject.h \
    SolarCore/SolarObjects/solarobjects.h \
    SolarCore/solarobjectsfactory.h \
    SolarCore/solarobjectscontainer.h \
    Scene/SceneObjects/planet.h \
    SolarCore/planetscontainer.h \
    SolarCore/solaranimator.h \
    UI/solarcontrollerui.h \
    Scene/solarentity.h \
    UI/solarquickui.h \
    Scene/SceneObjects/planetring.h \
    SolarCore/cameracontroller.h

RESOURCES += \
    res.qrc

DISTFILES += \
    QML/SolarEntityMain.qml \
    QML/SolarSystemMain.qml \
    QML/DateText.qml
