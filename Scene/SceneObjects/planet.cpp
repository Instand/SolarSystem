#include "planet.h"
#include <QMatrix4x4>
#include <QGeometryRenderer>
#include <QTransform>
#include <Qt3DExtras/QSphereGeometry>

SolarSystem::Planet::Planet(Qt3DCore::QNode *parent):
    NormalDiffuseObject(parent)
{
    m_Renderer = new Qt3DRender::QGeometryRenderer(this);
    addComponent(m_Renderer);

    auto sphereGeometry = new Qt3DExtras::QSphereGeometry(this);

    //setup geometry
    sphereGeometry->setRadius(PlanetSettings::radius);
    sphereGeometry->setGenerateTangents(PlanetSettings::generateTangents);
    sphereGeometry->setRings(PlanetSettings::rings);
    sphereGeometry->setSlices(PlanetSettings::slices);

    m_Renderer->setGeometry(sphereGeometry);
}

void SolarSystem::Planet::update(float deltaTime)
{
    Q_UNUSED(deltaTime)

    //create matrix
    auto matrix = QMatrix4x4();

    //set position
    matrix.translate(QVector3D(m_X, m_Y, m_Z));

    //rotate
    matrix.rotate(m_Tilt, SolarValues::tiltAxis);
    matrix.rotate(m_Roll, SolarValues::rollAxis);

    //planet scale
    matrix.scale(m_R);

    m_Transform->setMatrix(matrix);
}
