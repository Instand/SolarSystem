cmake_minimum_required(VERSION 3.16)
project(SolarSystem VERSION 1.0 LANGUAGES CXX)

set(CMAKE_INCLUDE_CURRENT_DIR ON)

if (MSVC)
    set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} /std:c++17")
else()
    set(CMAKE_CXX_STANDARD 17)
endif()

find_package(QT NAMES Qt6 REQUIRED COMPONENTS Core)
find_package(Qt${QT_VERSION_MAJOR} REQUIRED COMPONENTS 3DCore 3DExtras 3DInput 3DQuickExtras 3DRender Gui Qml Quick Sql)

qt_standard_project_setup()

qt_add_executable(SolarSystem WIN32 MACOSX_BUNDLE
    Additional/solarinfoloader.cpp Additional/solarinfoloader.h
    Core/Render/solardiffuseeffect.cpp Core/Render/solardiffuseeffect.h
    Core/Render/solarforwardframegraph.cpp Core/Render/solarforwardframegraph.h
    Core/Render/solarframegraph.cpp Core/Render/solarframegraph.h
    Core/Render/solarlight.cpp Core/Render/solarlight.h
    Core/Render/solarmaterial.cpp Core/Render/solarmaterial.h
    Core/Render/solarobjecteffect.cpp Core/Render/solarobjecteffect.h
    Core/Render/solarshadoweffect.cpp Core/Render/solarshadoweffect.h
    Core/Render/solarstandardframegraph.cpp Core/Render/solarstandardframegraph.h
    Core/SolarObjects/abstractsolarobject.cpp Core/SolarObjects/abstractsolarobject.h
    Core/SolarObjects/solarobjects.cpp Core/SolarObjects/solarobjects.h
    Core/animator.cpp Core/animator.h
    Core/cameracontroller.cpp Core/cameracontroller.h
    Core/mathcore.cpp Core/mathcore.h
    Core/object3dbuilder.h
    Core/object3dcontainer.cpp Core/object3dcontainer.h
    Core/solarobjectscontainer.cpp Core/solarobjectscontainer.h
    Core/solarobjectsfactory.h
    Core/utils.cpp Core/utils.h
    Interface/iframegraph.h
    Parser/solarparser.cpp Parser/solarparser.h
    Scene/MaterialObjects/diffuseobject.cpp Scene/MaterialObjects/diffuseobject.h
    Scene/MaterialObjects/normaldiffusealphaobject.cpp Scene/MaterialObjects/normaldiffusealphaobject.h
    Scene/MaterialObjects/normaldiffuseobject.cpp Scene/MaterialObjects/normaldiffuseobject.h
    Scene/MaterialObjects/unlitobject.cpp Scene/MaterialObjects/unlitobject.h
    Scene/SceneObjects/earthcloud.cpp Scene/SceneObjects/earthcloud.h
    Scene/SceneObjects/emptysolarobject.cpp Scene/SceneObjects/emptysolarobject.h
    Scene/SceneObjects/planet.cpp Scene/SceneObjects/planet.h
    Scene/SceneObjects/planetring.cpp Scene/SceneObjects/planetring.h
    Scene/SceneObjects/solarskybox.cpp Scene/SceneObjects/solarskybox.h
    Scene/SceneObjects/sun.cpp Scene/SceneObjects/sun.h
    Scene/fpscounter.cpp Scene/fpscounter.h
    Scene/object3d.cpp Scene/object3d.h
    Scene/solarentity.cpp Scene/solarentity.h
    UI/quickui.cpp UI/quickui.h
    dbconnector.cpp dbconnector.h
    main.cpp
    object.cpp object.h
    solarsystemcore.cpp solarsystemcore.h
    android/AndroidManifest.xml
)

qt_add_qml_module(SolarSystem
    URI SolarSystemQml
    VERSION ${PROJECT_VERSION}
    QML_FILES
        QML/SolarEntityMain.qml
        QML/SolarSystemMain.qml
        QML/DateText.qml
        QML/TransparentButton.qml
        QML/Controls.qml
        QML/SolarFrame.qml
        QML/PlanetList.qml
        QML/PlanetButton.qml
        QML/Info.qml
        QML/FpsLabel.qml
        QML/SpeedSlider.qml
        QML/DatabaseLabel.qml
        QML/UserOptions.qml
    RESOURCES
        Resources/Skybox/stars_negx.webp
        Resources/Skybox/stars_negy.webp
        Resources/Skybox/stars_negz.webp
        Resources/Skybox/stars_posx.webp
        Resources/Skybox/stars_posy.webp
        Resources/Skybox/stars_posz.webp
        Resources/Images/earth.png
        Resources/Images/earthcloudmapcolortrans.png
        Resources/Images/earthcloudmapspec.jpg
        Resources/Images/earthmap1k.jpg
        Resources/Images/earthnormal1k.jpg
        Resources/Images/earthspec1k.jpg
        Resources/Images/jupiter.png
        Resources/Images/jupitermap.jpg
        Resources/Images/mars.png
        Resources/Images/marsmap1k.jpg
        Resources/Images/marsnormal1k.jpg
        Resources/Images/mercury.png
        Resources/Images/mercurymap.jpg
        Resources/Images/mercurynormal.jpg
        Resources/Images/moonmap1k.jpg
        Resources/Images/moonnormal1k.jpg
        Resources/Images/neptune.png
        Resources/Images/neptunemap.jpg
        Resources/Images/saturn.png
        Resources/Images/saturnmap.jpg
        Resources/Images/saturnringcolortrans.png
        Resources/Images/sun.png
        Resources/Images/sunmap.jpg
        Resources/Images/uranus.png
        Resources/Images/uranusmap.jpg
        Resources/Images/uranusringcolortrans.png
        Resources/Images/venus.png
        Resources/Meshes/ring.obj
        Resources/Images/sun_map.jpg
        Resources/Images/jupiternormal.jpg
        Resources/Images/saturnnormal.jpg
        Resources/Images/uranusnormal.jpg
        Resources/Images/neptunenormal.jpg
        Resources/Images/saturnringcolortransnormal.png
        Resources/Images/uranusringcolortransnormal.png
        Resources/Images/planet_icon.png
        Resources/Images/options_icon.png
        Resources/Images/calendar_icon.png
        Resources/Images/info_icon.png
        Resources/Images/venus_atmo.jpg
        Resources/Images/venus_atmonormal.jpg
        Resources/Images/earthcloudmapcolortransnormal.png
        Resources/Images/solarsystem.png
        Resources/Images/solarsystem_icon.png
        Resources/Images/exit_icon.png
        Resources/Images/solarsystem_icon.ico
        Resources/Images/pluto.png
        Resources/Images/plutomap.jpg
        Resources/Images/plutonormal.jpg
        Resources/Images/saturn_rings.png
        Resources/Images/screen_icon.png
        Resources/Meshes/planetRing.obj
        Resources/Shaders/shadowmap.vert
        Resources/Shaders/diffusenormal.frag
        Resources/Shaders/diffusenormal.vert
        Resources/Shaders/diffuseshadow.vert
        Resources/Shaders/shadowmap.frag
        Resources/Shaders/diffuseshadow.frag
        Resources/Images/sun_normal.jpg
        Resources/Shaders/diffuse.frag
        Resources/Shaders/diffuse.vert
        Resources/Shaders/skybox.frag
        Resources/Shaders/skybox.vert
        Resources/Database/SolarDB.db
        Resources/Info.txt
    NO_RESOURCE_TARGET_PATH
)

set(ANDROID_PACKAGE_SOURCE_DIR ${PROJECT_SOURCE_DIR}/android CACHE INTERNAL "")

target_link_libraries(SolarSystem PRIVATE
    Qt::3DCore
    Qt::3DExtras
    Qt::3DInput
    Qt::3DQuickExtras
    Qt::3DRender
    Qt::Core
    Qt::Gui
    Qt::Qml
    Qt::Quick
    Qt::Sql
)

install(TARGETS SolarSystem
    BUNDLE DESTINATION .
    LIBRARY DESTINATION ${CMAKE_INSTALL_BINDIR}
    RUNTIME DESTINATION ${CMAKE_INSTALL_BINDIR}
)

qt_generate_deploy_qml_app_script(
    TARGET SolarSystem
    FILENAME_VARIABLE deploy_script
    NO_UNSUPPORTED_PLATFORM_ERROR
    DEPLOY_USER_QML_MODULES_ON_UNSUPPORTED_PLATFORM
    MACOS_BUNDLE_POST_BUILD
)

install(SCRIPT ${deploy_script})
