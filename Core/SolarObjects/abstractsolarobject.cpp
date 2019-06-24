#include "abstractsolarobject.h"

SolarSystem::AbstractSolarObject::AbstractSolarObject(QObject* parent):
    QObject(parent)
{
}

SolarSystem::AbstractSolarObject::~AbstractSolarObject()
{
}

double SolarSystem::AbstractSolarObject::radius() const
{
    return m_radius;
}

void SolarSystem::AbstractSolarObject::setRadius(double radius)
{
    m_radius = radius;
}

double SolarSystem::AbstractSolarObject::tilt() const
{
    return m_tilt;
}

void SolarSystem::AbstractSolarObject::setTilt(double tilt)
{
    m_tilt = tilt;
}

double SolarSystem::AbstractSolarObject::roll() const
{
    return m_roll;
}

void SolarSystem::AbstractSolarObject::setRoll(double roll)
{
    m_roll = roll;
}

double SolarSystem::AbstractSolarObject::x() const
{
    return m_x;
}

void SolarSystem::AbstractSolarObject::setX(double x)
{
    m_x = x;
}

double SolarSystem::AbstractSolarObject::y() const
{
    return m_y;
}

void SolarSystem::AbstractSolarObject::setY(double y)
{
    m_y = y;
}

double SolarSystem::AbstractSolarObject::z() const
{
    return m_z;
}

void SolarSystem::AbstractSolarObject::setZ(double z)
{
    m_z = z;
}

double SolarSystem::AbstractSolarObject::N1() const
{
    return m_n1;
}

double SolarSystem::AbstractSolarObject::N2() const
{
    return m_n2;
}

double SolarSystem::AbstractSolarObject::i1() const
{
    return m_i1;
}

double SolarSystem::AbstractSolarObject::i2() const
{
    return m_i2;
}

double SolarSystem::AbstractSolarObject::w1() const
{
    return m_w1;
}

double SolarSystem::AbstractSolarObject::w2() const
{
    return m_w2;
}

double SolarSystem::AbstractSolarObject::a1() const
{
    return m_a1;
}

double SolarSystem::AbstractSolarObject::a2() const
{
    return m_a2;
}

double SolarSystem::AbstractSolarObject::e1() const
{
    return m_e1;
}

double SolarSystem::AbstractSolarObject::e2() const
{
    return m_e2;
}

double SolarSystem::AbstractSolarObject::M1() const
{
    return m_m1;
}

double SolarSystem::AbstractSolarObject::M2() const
{
    return m_m2;
}

double SolarSystem::AbstractSolarObject::period() const
{
    return m_period;
}

SolarSystem::SolarObjects SolarSystem::AbstractSolarObject::centerOfOrbit() const
{
    return m_centerOfOrbit;
}

SolarSystem::SolarObjects SolarSystem::AbstractSolarObject::object() const
{
    return m_objectType;
}
