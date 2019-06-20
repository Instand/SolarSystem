#include "sun.h"
#include <QSphereGeometry>
#include <QTextureImage>
#include <QTexture>
#include <QPointLight>
#include <QTransform>
#include <QGeometryRenderer>

SolarSystem::Sun::Sun(Qt3DCore::QNode* parent):
    UnlitObject(parent)
{
    m_renderer = new Qt3DRender::QGeometryRenderer(this);
    addComponent(m_renderer);

    auto sphereGeometry = new Qt3DExtras::QSphereGeometry(this);

    //setup geometry
    sphereGeometry->setRadius(PlanetSettings::radius);
    sphereGeometry->setGenerateTangents(PlanetSettings::generateTangents);
    sphereGeometry->setRings(PlanetSettings::rings);
    sphereGeometry->setSlices(PlanetSettings::slices);

    m_renderer->setGeometry(sphereGeometry);

    auto sunLight = new Qt3DRender::QPointLight();
    sunLight->setIntensity(1.35f);

    addComponent(sunLight);
    setObjectName(SolarObjectsValues::Sun::toString);

    auto mat = qobject_cast<Qt3DExtras::QTextureMaterial*>(m_material);

    // sun diffuse
    Qt3DRender::QTextureImage* sunDiffuse = new Qt3DRender::QTextureImage();
    sunDiffuse->setSource(QUrl::fromLocalFile(":/Resources/Images/sun_map.jpg"));
    mat->texture()->addTextureImage(sunDiffuse);

    setTilt(SolarObjectsValues::Sun::tilt);
}

void SolarSystem::Sun::update(float deltaTime)
{
    Q_UNUSED(deltaTime)
    Object3D::baseBehaviour();
}
