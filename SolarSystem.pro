QT += core gui sql
QT += 3dcore 3drender 3dextras 3dinput
QT += qml quick
QT += 3dquickextras

CONFIG += c++14

TARGET = SolarSystem

CONFIG += resources_big

TEMPLATE = app

SOURCES += main.cpp \
    solarsystemobject.cpp \
    solarsystemdbconnector.cpp \
    solarsystemcore.cpp \
    Parser/solarparser.cpp \
    Scene/SceneObjects/emptysolarobject.cpp \
    Scene/SceneObjects/solarskybox.cpp \
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
    Scene/SceneObjects/earthcloud.cpp \
    SolarCore/SolarRender/solarlight.cpp \
    SolarCore/SolarRender/solarshadoweffect.cpp \
    SolarCore/SolarRender/solarobjecteffect.cpp \
    SolarCore/SolarRender/solarmaterial.cpp \
    SolarCore/SolarRender/solarframegraph.cpp \
    SolarCore/SolarRender/solarforwardframegraph.cpp \
    SolarCore/SolarRender/solardiffuseeffect.cpp \
    Additional/solarinfoloader.cpp \
    Scene/SceneObjects/sun.cpp \
    Scene/MaterialObjects/normaldiffuseobject.cpp \
    Scene/MaterialObjects/normaldiffusealphaobject.cpp \
    Scene/MaterialObjects/diffuseobject.cpp \
    Scene/MaterialObjects/unlitobject.cpp \
    Scene/fpscounter.cpp \
    SolarCore/SolarRender/solarstandardframegraph.cpp \
    Scene/solarobject3d.cpp

HEADERS += \
    solarsystemobject.h \
    solarsystemdbconnector.h \
    solarsystemcore.h \
    Parser/solarparser.h \
    Scene/SceneObjects/emptysolarobject.h \
    Scene/SceneObjects/solarskybox.h \
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
    Scene/SceneObjects/earthcloud.h \
    SolarCore/SolarRender/solarlight.h \
    SolarCore/SolarRender/solarshadoweffect.h \
    SolarCore/SolarRender/solarobjecteffect.h \
    SolarCore/SolarRender/solarmaterial.h \
    SolarCore/SolarRender/solarframegraph.h \
    SolarCore/SolarRender/solarforwardframegraph.h \
    SolarCore/SolarRender/solardiffuseeffect.h \
    Additional/solarinfoloader.h \
    Scene/SceneObjects/sun.h \
    Scene/MaterialObjects/normaldiffuseobject.h \
    Scene/MaterialObjects/normaldiffusealphaobject.h \
    Scene/MaterialObjects/diffuseobject.h \
    Scene/MaterialObjects/unlitobject.h \
    Scene/fpscounter.h \
    SolarCore/SolarRender/solarstandardframegraph.h \
    Interface/iframegraph.h \
    Scene/solarobject3d.h

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


#for win app icon
win32 {
    RC_ICONS += Resources/Images/solarsystem_icon.ico
}

#android setup
android {
    QT += androidextras
    deployment.files += Resources/Database/SolarDB.db
    deployment.path = /assets
    INSTALLS += deployment
    CONFIG += mobility
}

ANDROID_PACKAGE_SOURCE_DIR = $$PWD/android






