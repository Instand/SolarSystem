#include "solarquickui.h"
#include <QApplication>
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

    view.setIcon(QIcon(QStringLiteral(":/Resources/Images/solarsystem_icon.png")));

    QObject::connect(view.engine(), SIGNAL(quit()), this, SLOT(quit()));
}

void SolarSystem::SolarQuickUI::show()
{
    view.show();
}

void SolarSystem::SolarQuickUI::showFullScreen()
{
    view.showFullScreen();
}

void SolarSystem::SolarQuickUI::quit()
{
    qApp->exit();
}
