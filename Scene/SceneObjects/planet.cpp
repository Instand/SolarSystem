#include "planet.h"
#include <Qt3DExtras/QSphereGeometry>
#include <solarsystemcore.h>
#include <Parser/solarparser.h>

SolarSystem::Planet::Planet(Qt3DCore::QNode *parent):
    Solar3dObject(parent)
{
    Qt3DExtras::QSphereGeometry* sphereGeometry = new Qt3DExtras::QSphereGeometry();

    //setup geometry
    sphereGeometry->setRadius(PlanetSettings::radius);
    sphereGeometry->setGenerateTangents(PlanetSettings::generateTangents);
    sphereGeometry->setRings(PlanetSettings::rings);
    sphereGeometry->setSlices(PlanetSettings::slices);

    mesh().setGeometry(sphereGeometry);
}

void SolarSystem::Planet::update(float deltaTime)
{
    Q_UNUSED(deltaTime)

    //position
    transform().setTranslation(QVector3D(_x, _y, _z));

    //rotation
    transform().setRotationY(_roll);
    transform().setRotationZ(_tilt);

    //scale
    transform().setScale(_r);
}
