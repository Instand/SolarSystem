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
    return m_Radius;
}

void SolarSystem::AbstractSolarObject::setRadius(double radius)
{
    m_Radius = radius;
}

double SolarSystem::AbstractSolarObject::tilt() const
{
    return m_Tilt;
}

void SolarSystem::AbstractSolarObject::setTilt(double tilt)
{
    m_Tilt = tilt;
}

double SolarSystem::AbstractSolarObject::roll() const
{
    return m_Roll;
}

void SolarSystem::AbstractSolarObject::setRoll(double roll)
{
    m_Roll = roll;
}

double SolarSystem::AbstractSolarObject::x() const
{
    return m_X;
}

void SolarSystem::AbstractSolarObject::setX(double x)
{
    m_X = x;
}

double SolarSystem::AbstractSolarObject::y() const
{
    return m_Y;
}

void SolarSystem::AbstractSolarObject::setY(double y)
{
    m_Y = y;
}

double SolarSystem::AbstractSolarObject::z() const
{
    return m_Z;
}

void SolarSystem::AbstractSolarObject::setZ(double z)
{
    m_Z = z;
}

double SolarSystem::AbstractSolarObject::N1() const
{
    return m_N1;
}

double SolarSystem::AbstractSolarObject::N2() const
{
    return m_N2;
}

double SolarSystem::AbstractSolarObject::i1() const
{
    return m_I1;
}

double SolarSystem::AbstractSolarObject::i2() const
{
    return m_I2;
}

double SolarSystem::AbstractSolarObject::w1() const
{
    return m_W1;
}

double SolarSystem::AbstractSolarObject::w2() const
{
    return m_W2;
}

double SolarSystem::AbstractSolarObject::a1() const
{
    return m_A1;
}

double SolarSystem::AbstractSolarObject::a2() const
{
    return m_A2;
}

double SolarSystem::AbstractSolarObject::e1() const
{
    return m_E1;
}

double SolarSystem::AbstractSolarObject::e2() const
{
    return m_E2;
}

double SolarSystem::AbstractSolarObject::M1() const
{
    return m_M1;
}

double SolarSystem::AbstractSolarObject::M2() const
{
    return m_M2;
}

double SolarSystem::AbstractSolarObject::period() const
{
    return m_Period;
}

SolarSystem::SolarObjects SolarSystem::AbstractSolarObject::centerOfOrbit() const
{
    return m_CenterOfOrbit;
}

SolarSystem::SolarObjects SolarSystem::AbstractSolarObject::object() const
{
    return m_ObjectType;
}
