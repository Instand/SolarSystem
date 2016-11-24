#include "abstractsolarobject.h"

SolarSystem::AbstractSolarObject::AbstractSolarObject(QObject *parent):
    QObject(parent)
{

}

SolarSystem::AbstractSolarObject::~AbstractSolarObject()
{

}

double SolarSystem::AbstractSolarObject::radius() const
{
    return _radius;
}

void SolarSystem::AbstractSolarObject::setRadius(double radius)
{
    _radius = radius;
}

double SolarSystem::AbstractSolarObject::tilt() const
{
    return _tilt;
}

void SolarSystem::AbstractSolarObject::setTilt(double tilt)
{
    _tilt = tilt;
}

double SolarSystem::AbstractSolarObject::roll() const
{
    return _roll;
}

void SolarSystem::AbstractSolarObject::setRoll(double roll)
{
    _roll = roll;
}

double SolarSystem::AbstractSolarObject::x() const
{
    return _x;
}

void SolarSystem::AbstractSolarObject::setX(double x)
{
    _x = x;
}

double SolarSystem::AbstractSolarObject::y() const
{
    return _y;
}

void SolarSystem::AbstractSolarObject::setY(double y)
{
    _y = y;
}

double SolarSystem::AbstractSolarObject::z() const
{
    return _z;
}

void SolarSystem::AbstractSolarObject::setZ(double z)
{
    _z = z;
}

double SolarSystem::AbstractSolarObject::N1() const
{
    return _N1;
}

double SolarSystem::AbstractSolarObject::N2() const
{
    return _N2;
}

double SolarSystem::AbstractSolarObject::i1() const
{
    return _i1;
}

double SolarSystem::AbstractSolarObject::i2() const
{
    return _i2;
}

double SolarSystem::AbstractSolarObject::w1() const
{
    return _w1;
}

double SolarSystem::AbstractSolarObject::w2() const
{
    return _w2;
}

double SolarSystem::AbstractSolarObject::a1() const
{
    return _a1;
}

double SolarSystem::AbstractSolarObject::a2() const
{
    return _a2;
}

double SolarSystem::AbstractSolarObject::e1() const
{
    return _e1;
}

double SolarSystem::AbstractSolarObject::e2() const
{
    return _e2;
}

double SolarSystem::AbstractSolarObject::M1() const
{
    return _M1;
}

double SolarSystem::AbstractSolarObject::M2() const
{
    return _M2;
}

double SolarSystem::AbstractSolarObject::period() const
{
    return _period;
}

SolarSystem::SolarObjects SolarSystem::AbstractSolarObject::centerOfOrbit() const
{
    return _centerOfOrbit;
}

SolarSystem::SolarObjects SolarSystem::AbstractSolarObject::object() const
{
    return _objectType;
}
