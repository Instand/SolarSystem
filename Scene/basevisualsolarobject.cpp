#include "basevisualsolarobject.h"

SolarSystem::BaseVisualSolarObject::BaseVisualSolarObject(Qt3DCore::QNode* parent):
    VisualSolarObject(parent),
    _transform(new Qt3DCore::QTransform(this))
{
    addComponent(_transform);
}

Qt3DCore::QTransform* SolarSystem::BaseVisualSolarObject::transform() const
{
    return _transform;
}

Qt3DRender::QGeometryRenderer* SolarSystem::BaseVisualSolarObject::renderer() const
{
    return _renderer;
}

SolarSystem::SolarMaterials SolarSystem::BaseVisualSolarObject::materialType() const
{
    return _materialType;
}

SolarSystem::SolarObjects SolarSystem::BaseVisualSolarObject::solarType() const
{
    return _solarType;
}

void SolarSystem::BaseVisualSolarObject::setSolarType(SolarSystem::SolarObjects type)
{
    _solarType = type;
}

double SolarSystem::BaseVisualSolarObject::tilt() const
{
    return _tilt;
}

void SolarSystem::BaseVisualSolarObject::setTilt(double tilt)
{
    _tilt = tilt;
}

double SolarSystem::BaseVisualSolarObject::roll() const
{
    return _roll;
}

void SolarSystem::BaseVisualSolarObject::setRoll(double roll)
{
    _roll = roll;
}

double SolarSystem::BaseVisualSolarObject::z() const
{
    return _z;
}

void SolarSystem::BaseVisualSolarObject::setZ(double z)
{
    _z = z;
}

double SolarSystem::BaseVisualSolarObject::y() const
{
    return _y;
}

void SolarSystem::BaseVisualSolarObject::setY(double y)
{
    _y = y;
}

double SolarSystem::BaseVisualSolarObject::x() const
{
    return _x;
}

void SolarSystem::BaseVisualSolarObject::setX(double x)
{
    _x = x;
}

double SolarSystem::BaseVisualSolarObject::r() const
{
    return _r;
}

void SolarSystem::BaseVisualSolarObject::setR(double r)
{
    _r = r;
}
