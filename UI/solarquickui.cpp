#include "solarquickui.h"
#include <Scene/solarentity.h>

SolarSystem::SolarQuickUI::SolarQuickUI(QObject* parent):
    QObject(parent)
{
    qmlRegisterType<SolarSystem::SolarEntity>("SolarSystem", 1, 0, "SolarEntity");

    if (QOpenGLContext::openGLModuleType() == QOpenGLContext::LibGL)
    {
        format.setVersion(3, 2);
        format.setProfile(QSurfaceFormat::CoreProfile);
    }

    format.setDepthBufferSize(24);
    format.setStencilBufferSize(8);
    format.setSamples(4);

    view.setFormat(format);
    view.setResizeMode(QQuickView::SizeRootObjectToView);
    view.setSource(QUrl("qrc:/QML/SolarSystemMain.qml"));
    view.setColor("#000000");

    view.setMinimumWidth(1280);
    view.setMinimumHeight(700);
}

void SolarSystem::SolarQuickUI::show()
{
    view.show();
}
