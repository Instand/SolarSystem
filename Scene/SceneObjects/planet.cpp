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

SolarSystem::SolarObjects SolarSystem::Planet::solarType() const
{
    return _solarType;
}

void SolarSystem::Planet::setSolarType(SolarSystem::SolarObjects type)
{
    _solarType = type;
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

float SolarSystem::Planet::tilt() const
{
    return _tilt;
}

void SolarSystem::Planet::setTilt(float tilt)
{
    _tilt = tilt;
}

float SolarSystem::Planet::roll() const
{
    return _roll;
}

void SolarSystem::Planet::setRoll(float roll)
{
    _roll = roll;
}

float SolarSystem::Planet::z() const
{
    return _z;
}

void SolarSystem::Planet::setZ(float z)
{
    _z = z;
}

float SolarSystem::Planet::y() const
{
    return _y;
}

void SolarSystem::Planet::setY(float y)
{
    _y = y;
}

float SolarSystem::Planet::x() const
{
    return _x;
}

void SolarSystem::Planet::setX(float x)
{
    _x = x;
}

float SolarSystem::Planet::r() const
{
    return _r;
}

void SolarSystem::Planet::setR(float r)
{
    _r = r;
}
