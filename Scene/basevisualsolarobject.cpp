#include "basevisualsolarobject.h"

SolarSystem::BaseVisualSolarObject::BaseVisualSolarObject(Qt3DCore::QNode* parent):
    VisualSolarObject(parent),
    _transform(new Qt3DCore::QTransform(this)),
    _mesh(new Qt3DRender::QMesh(this))
{
    addComponent(_transform);
    addComponent(_mesh);
}

Qt3DCore::QTransform &SolarSystem::BaseVisualSolarObject::transform() const
{
    return *_transform;
}

Qt3DRender::QMesh &SolarSystem::BaseVisualSolarObject::mesh() const
{
    return *_mesh;
}

SolarSystem::SolarObjects SolarSystem::BaseVisualSolarObject::solarType() const
{
    return _solarType;
}

void SolarSystem::BaseVisualSolarObject::setSolarType(SolarSystem::SolarObjects type)
{
    _solarType = type;
}

float SolarSystem::BaseVisualSolarObject::tilt() const
{
    return _tilt;
}

void SolarSystem::BaseVisualSolarObject::setTilt(float tilt)
{
    _tilt = tilt;
}

float SolarSystem::BaseVisualSolarObject::roll() const
{
    return _roll;
}

void SolarSystem::BaseVisualSolarObject::setRoll(float roll)
{
    _roll = roll;
}

float SolarSystem::BaseVisualSolarObject::z() const
{
    return _z;
}

void SolarSystem::BaseVisualSolarObject::setZ(float z)
{
    _z = z;
}

float SolarSystem::BaseVisualSolarObject::y() const
{
    return _y;
}

void SolarSystem::BaseVisualSolarObject::setY(float y)
{
    _y = y;
}

float SolarSystem::BaseVisualSolarObject::x() const
{
    return _x;
}

void SolarSystem::BaseVisualSolarObject::setX(float x)
{
    _x = x;
}

float SolarSystem::BaseVisualSolarObject::r() const
{
    return _r;
}

void SolarSystem::BaseVisualSolarObject::setR(float r)
{
    _r = r;
}
