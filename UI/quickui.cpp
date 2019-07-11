#include "quickui.h"

#include <QGuiApplication>

#include <Core/utils.h>
#include <Scene/solarentity.h>
#include <Additional/solarinfoloader.h>

SolarSystem::QuickUi::QuickUi(QObject* parent):
    QObject(parent)
{
    qmlRegisterType<SolarSystem::SolarEntity>("SolarSystem", 1, 0, "SolarEntity");

    qmlRegisterSingletonType<SolarSystem::Utils>("SolarSystem.Utils", 1, 0, "Utils", SolarSystem::utilsProvider);
    qmlRegisterSingletonType<SolarSystem::SolarInfoLoader>("SolarSystem.InfoLoader", 1, 0, "InfoLoader", SolarSystem::infoLoaderProvider);

    if (QOpenGLContext::openGLModuleType() == QOpenGLContext::LibGL)
    {
        m_format.setVersion(4, 0);
        m_format.setProfile(QSurfaceFormat::CoreProfile);
    }

    m_format.setDepthBufferSize(24);
    m_format.setStencilBufferSize(8);
    m_format.setSamples(4);

    m_view.setFormat(m_format);
    m_view.setResizeMode(QQuickView::SizeRootObjectToView);
    m_view.setSource(QUrl("qrc:/QML/SolarSystemMain.qml"));
    m_view.setColor("#000000");

    m_view.setMinimumWidth(1280);
    m_view.setMinimumHeight(700);

    m_view.setIcon(QIcon(QStringLiteral(":/Resources/Images/solarsystem_icon.png")));

    QObject::connect(m_view.engine(), SIGNAL(quit()), this, SLOT(quit()));
}

void SolarSystem::QuickUi::show()
{
#ifdef QT_NO_DEBUG
    m_view.showFullScreen();
#else
    m_view.show();
#endif
}

void SolarSystem::QuickUi::quit()
{
    qApp->exit();
}
