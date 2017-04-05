QT += core gui sql
QT += 3dcore 3drender 3dextras 3dinput
QT += qml quick
QT += 3dquickextras

CONFIG += c++14
CONFIG += mobility

TARGET = SolarSystem

CONFIG += resources_big

TEMPLATE = app

SOURCES += main.cpp \
    solarsystemobject.cpp \
    solarsystemdbconnector.cpp \
    solarsystemcore.cpp \
    solar3dobject.cpp \
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
    Scene/solarentity.cpp \
    UI/solarquickui.cpp \
    Scene/SceneObjects/planetring.cpp \
    SolarCore/cameracontroller.cpp \
    solar3dalphaobject.cpp \
    Scene/SceneObjects/earthcloud.cpp \
    SolarCore/SolarRender/solarlight.cpp

HEADERS += \
    solarsystemobject.h \
    solarsystemdbconnector.h \
    solarsystemcore.h \
    solar3dobject.h \
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
    Scene/solarentity.h \
    UI/solarquickui.h \
    Scene/SceneObjects/planetring.h \
    SolarCore/cameracontroller.h \
    solar3dalphaobject.h \
    Scene/SceneObjects/earthcloud.h \
    SolarCore/SolarRender/solarlight.h

RESOURCES += \
    res.qrc

DISTFILES += \
    QML/SolarEntityMain.qml \
    QML/SolarSystemMain.qml \
    QML/DateText.qml \
    QML/TransparentButton.qml \
    QML/Controls.qml \
    QML/SolarFrame.qml \
    QML/PlanetList.qml \
    QML/PlanetButton.qml \
    QML/Info.qml \
    Resources/Shaders/shadowmap.vert


#for app icon
win32:RC_ICONS += Resources/Images/solarsystem_icon.ico

#ANDROID_PACKAGE_SOURCE_DIR = $$PWD/../SolarSystemAndroidBuild2/android-build





