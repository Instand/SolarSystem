QT += core gui sql
QT += 3dcore 3drender 3dextras 3dinput
QT += qml quick
QT += 3dquickextras

if (MSVC) {
    QMAKE_CXXFLAGS += -std=c++17 /std:c++17
} else {
    CONFIG += c++17
}

TARGET = SolarSystem

CONFIG += resources_big

TEMPLATE = app

SOURCES += main.cpp \
    Core/utils.cpp \
    object.cpp \
    dbconnector.cpp \
    solarsystemcore.cpp \
    Parser/solarparser.cpp \
    Scene/SceneObjects/emptysolarobject.cpp \
    Scene/SceneObjects/solarskybox.cpp \
    Core/mathcore.cpp \
    Core/SolarObjects/solarobjects.cpp \
    Core/SolarObjects/abstractsolarobject.cpp \
    Core/solarobjectscontainer.cpp \
    Scene/SceneObjects/planet.cpp \
    Core/object3dcontainer.cpp \
    Core/animator.cpp \
    Scene/solarentity.cpp \
    UI/quickui.cpp \
    Scene/SceneObjects/planetring.cpp \
    Core/cameracontroller.cpp \
    Scene/SceneObjects/earthcloud.cpp \
    Core/Render/solarlight.cpp \
    Core/Render/solarshadoweffect.cpp \
    Core/Render/solarobjecteffect.cpp \
    Core/Render/solarmaterial.cpp \
    Core/Render/solarframegraph.cpp \
    Core/Render/solarforwardframegraph.cpp \
    Core/Render/solardiffuseeffect.cpp \
    Additional/solarinfoloader.cpp \
    Scene/SceneObjects/sun.cpp \
    Scene/MaterialObjects/normaldiffuseobject.cpp \
    Scene/MaterialObjects/normaldiffusealphaobject.cpp \
    Scene/MaterialObjects/diffuseobject.cpp \
    Scene/MaterialObjects/unlitobject.cpp \
    Scene/fpscounter.cpp \
    Core/Render/solarstandardframegraph.cpp \
    Scene/object3d.cpp

HEADERS += \
    Core/object3dbuilder.h \
    object.h \
    dbconnector.h \
    solarsystemcore.h \
    Parser/solarparser.h \
    Scene/SceneObjects/emptysolarobject.h \
    Scene/SceneObjects/solarskybox.h \
    Core/mathcore.h \
    Core/SolarObjects/abstractsolarobject.h \
    Core/SolarObjects/solarobjects.h \
    Core/solarobjectsfactory.h \
    Core/solarobjectscontainer.h \
    Scene/SceneObjects/planet.h \
    Core/object3dcontainer.h \
    Core/animator.h \
    Scene/solarentity.h \
    UI/quickui.h \
    Scene/SceneObjects/planetring.h \
    Core/cameracontroller.h \
    Scene/SceneObjects/earthcloud.h \
    Core/Render/solarlight.h \
    Core/Render/solarshadoweffect.h \
    Core/Render/solarobjecteffect.h \
    Core/Render/solarmaterial.h \
    Core/Render/solarframegraph.h \
    Core/Render/solarforwardframegraph.h \
    Core/Render/solardiffuseeffect.h \
    Additional/solarinfoloader.h \
    Scene/SceneObjects/sun.h \
    Scene/MaterialObjects/normaldiffuseobject.h \
    Scene/MaterialObjects/normaldiffusealphaobject.h \
    Scene/MaterialObjects/diffuseobject.h \
    Scene/MaterialObjects/unlitobject.h \
    Scene/fpscounter.h \
    Core/Render/solarstandardframegraph.h \
    Interface/iframegraph.h \
    Scene/object3d.h \
    Core/utils.h

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
    Resources/Shaders/shadowmap.vert \
    Resources/Shaders/shadowmap.frag \
    Resources/Shaders/diffusenormal.vert \
    Resources/Shaders/diffusenormal.frag \
    Resources/Shaders/diffuseshadow.vert \
    Resources/Shaders/diffuseshadow.frag \
    Resources/Shaders/diffuse.vert \
    Resources/Shaders/diffuse.frag \
    Resources/Shaders/skybox.vert \
    Resources/Shaders/skybox.frag \
    QML/FpsLabel.qml \
    QML/SpeedSlider.qml \
    android/AndroidManifest.xml \
    QML/DatabaseLabel.qml \
    QML/UserOptions.qml

# for win app icon
win32 {
    RC_ICONS += Resources/Images/solarsystem_icon.ico
}

# android setup
android {
    QT += androidextras
    deployment.files += Resources/Database/SolarDB.db
    deployment.path = /assets
    INSTALLS += deployment
    CONFIG += mobility
}

ANDROID_PACKAGE_SOURCE_DIR = $$PWD/android
