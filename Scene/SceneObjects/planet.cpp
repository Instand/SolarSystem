#include "planet.h"
#include <Qt3DExtras/QSphereGeometry>

SolarSystem::Planet::Planet(Qt3DCore::QNode *parent):
    NormalDiffuseObject(parent)
{
    Qt3DExtras::QSphereGeometry* sphereGeometry = new Qt3DExtras::QSphereGeometry(this);

    //setup geometry
    sphereGeometry->setRadius(PlanetSettings::radius);
    sphereGeometry->setGenerateTangents(PlanetSettings::generateTangents);
    sphereGeometry->setRings(PlanetSettings::rings);
    sphereGeometry->setSlices(PlanetSettings::slices);

    _mesh->setGeometry(sphereGeometry);
}

void SolarSystem::Planet::update(float deltaTime)
{
    Q_UNUSED(deltaTime)

    //create matrix
    auto matrix = QMatrix4x4();

    //set position
    matrix.translate(QVector3D(_x, _y, _z));

    //rotate
    matrix.rotate(_tilt, SolarValues::tiltAxis);
    matrix.rotate(_roll, SolarValues::rollAxis);

    //planet scale
    matrix.scale(_r);

    _transform->setMatrix(matrix);
}
