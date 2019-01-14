#include "planet.h"
#include <QMatrix4x4>
#include <QGeometryRenderer>
#include <QTransform>
#include <Qt3DExtras/QSphereGeometry>

SolarSystem::Planet::Planet(Qt3DCore::QNode *parent):
    NormalDiffuseObject(parent)
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
}

void SolarSystem::Planet::update(float deltaTime)
{
    Q_UNUSED(deltaTime)

    //create matrix
    auto matrix = QMatrix4x4();

    //set position
    matrix.translate(QVector3D(m_x, m_y, m_z));

    //rotate
    matrix.rotate(m_tilt, SolarValues::tiltAxis);
    matrix.rotate(m_roll, SolarValues::rollAxis);

    //planet scale
    matrix.scale(m_r);

    m_transform->setMatrix(matrix);
}
