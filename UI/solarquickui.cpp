#include "solarquickui.h"
#include <QGuiApplication>
#include <Scene/solarentity.h>
#include <Additional/solarinfoloader.h>

SolarSystem::SolarQuickUI::SolarQuickUI(QObject* parent):
    QObject(parent)
{
    qmlRegisterType<SolarSystem::SolarEntity>("SolarSystem", 1, 0, "SolarEntity");
    qmlRegisterSingletonType<SolarSystem::SolarInfoLoader>("SolarSystem.InfoLoader", 1, 0, "InfoLoader", SolarSystem::infoLoaderProvider);

    if (QOpenGLContext::openGLModuleType() == QOpenGLContext::LibGL)
    {
        format.setVersion(4, 0);
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
