#include "planet.h"
#include <Qt3DExtras/QSphereGeometry>

SolarSystem::Planet::Planet(Qt3DCore::QNode *parent):
    NormalDiffuseObject(parent)
{
    _renderer = new Qt3DRender::QGeometryRenderer(this);
    addComponent(_renderer);

    auto sphereGeometry = new Qt3DExtras::QSphereGeometry(this);

    //setup geometry
    sphereGeometry->setRadius(PlanetSettings::radius);
    sphereGeometry->setGenerateTangents(PlanetSettings::generateTangents);
    sphereGeometry->setRings(PlanetSettings::rings);
    sphereGeometry->setSlices(PlanetSettings::slices);

    _renderer->setGeometry(sphereGeometry);
}

void SolarSystem::Planet::update(float deltaTime)
{
    Q_UNUSED(deltaTime)

    //create matrix
    auto matrix = QMatrix4x4();

    //planet scale
    matrix.scale(_r);

    //set position
    matrix.translate(QVector3D(_x, _y, _z));

    //rotate
    matrix.rotate(_tilt, SolarValues::tiltAxis);
    matrix.rotate(_roll, SolarValues::rollAxis);

    _transform->setMatrix(matrix);
}
