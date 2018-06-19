#include "solarobjects.h"

SolarSystem::Stars::Sun::Sun(QObject *parent):
    AbstractSolarObject(parent)
{
    initialize();
}

void SolarSystem::Stars::Sun::initialize()
{
    m_Radius = SolarObjectsValues::Sun::radius;
    m_Tilt = SolarObjectsValues::Sun::tilt;
    m_N1 = SolarValues::zero;
    m_N2 = SolarValues::zero;
    m_I1 = SolarValues::zero;
    m_I2 = SolarValues::zero;
    m_W1 = SolarValues::zero;
    m_W2 = SolarValues::zero;
    m_A1 = SolarValues::zero;
    m_A2 = SolarValues::zero;
    m_E1 = SolarValues::zero;
    m_E2 = SolarValues::zero;
    m_M1 = SolarValues::zero;
    m_M2 = SolarValues::zero;
    m_Period = SolarObjectsValues::Sun::period;
    m_CenterOfOrbit = SolarObjects::Sun;
    m_ObjectType = SolarObjects::Sun;
}

SolarSystem::Planets::Mercury::Mercury(QObject *parent):
    AbstractSolarObject(parent)
{
    initialize();
}

void SolarSystem::Planets::Mercury::initialize()
{
    m_Radius = SolarObjectsValues::Mercury::radius;
    m_Tilt = SolarObjectsValues::Mercury::tilt;
    m_N1 = SolarObjectsValues::Mercury::N1;
    m_N2 = SolarObjectsValues::Mercury::N2;
    m_I1 = SolarObjectsValues::Mercury::i1;
    m_I2 = SolarObjectsValues::Mercury::i2;
    m_W1 = SolarObjectsValues::Mercury::w1;
    m_W2 = SolarObjectsValues::Mercury::w2;
    m_A1 = SolarObjectsValues::Mercury::a1;
    m_A2 = SolarObjectsValues::Mercury::a2;
    m_E1 = SolarObjectsValues::Mercury::e1;
    m_E2 = SolarObjectsValues::Mercury::e2;
    m_M1 = SolarObjectsValues::Mercury::M1;
    m_M2 = SolarObjectsValues::Mercury::M2;
    m_Period = SolarObjectsValues::Mercury::period;
    m_CenterOfOrbit = SolarObjectsValues::Mercury::centerOfOrbit;
    m_ObjectType = SolarObjects::Mercury;
}

SolarSystem::Planets::Venus::Venus(QObject *parent):
    AbstractSolarObject(parent)
{
    initialize();
}

void SolarSystem::Planets::Venus::initialize()
{
    m_Radius = SolarObjectsValues::Venus::radius;
    m_Tilt = SolarObjectsValues::Venus::tilt;
    m_N1 = SolarObjectsValues::Venus::N1;
    m_N2 = SolarObjectsValues::Venus::N2;
    m_I1 = SolarObjectsValues::Venus::i1;
    m_I2 = SolarObjectsValues::Venus::i2;
    m_W1 = SolarObjectsValues::Venus::w1;
    m_W2 = SolarObjectsValues::Venus::w2;
    m_A1 = SolarObjectsValues::Venus::a1;
    m_A2 = SolarObjectsValues::Venus::a2;
    m_E1 = SolarObjectsValues::Venus::e1;
    m_E2 = SolarObjectsValues::Venus::e2;
    m_M1 = SolarObjectsValues::Venus::M1;
    m_M2 = SolarObjectsValues::Venus::M2;
    m_Period = SolarObjectsValues::Venus::period;
    m_CenterOfOrbit = SolarObjectsValues::Venus::centerOfOrbit;
    m_ObjectType = SolarObjects::Venus;
}

SolarSystem::Planets::Earth::Earth(QObject *parent):
    AbstractSolarObject(parent)
{
    initialize();
}

void SolarSystem::Planets::Earth::initialize()
{
    m_Radius = SolarObjectsValues::Earth::radius;
    m_Tilt = SolarObjectsValues::Earth::tilt;
    m_N1 = SolarObjectsValues::Earth::N1;
    m_N2 = SolarObjectsValues::Earth::N2;
    m_I1 = SolarObjectsValues::Earth::i1;
    m_I2 = SolarObjectsValues::Earth::i2;
    m_W1 = SolarObjectsValues::Earth::w1;
    m_W2 = SolarObjectsValues::Earth::w2;
    m_A1 = SolarObjectsValues::Earth::a1;
    m_A2 = SolarObjectsValues::Earth::a2;
    m_E1 = SolarObjectsValues::Earth::e1;
    m_E2 = SolarObjectsValues::Earth::e2;
    m_M1 = SolarObjectsValues::Earth::M1;
    m_M2 = SolarObjectsValues::Earth::M2;
    m_Period = SolarObjectsValues::Earth::period;
    m_CenterOfOrbit = SolarObjectsValues::Earth::centerOfOrbit;
    m_ObjectType = SolarObjects::Earth;
}

SolarSystem::Planets::Mars::Mars(QObject *parent):
    AbstractSolarObject(parent)
{
    initialize();
}

void SolarSystem::Planets::Mars::initialize()
{
    m_Radius = SolarObjectsValues::Mars::radius;
    m_Tilt = SolarObjectsValues::Mars::tilt;
    m_N1 = SolarObjectsValues::Mars::N1;
    m_N2 = SolarObjectsValues::Mars::N2;
    m_I1 = SolarObjectsValues::Mars::i1;
    m_I2 = SolarObjectsValues::Mars::i2;
    m_W1 = SolarObjectsValues::Mars::w1;
    m_W2 = SolarObjectsValues::Mars::w2;
    m_A1 = SolarObjectsValues::Mars::a1;
    m_A2 = SolarObjectsValues::Mars::a2;
    m_E1 = SolarObjectsValues::Mars::e1;
    m_E2 = SolarObjectsValues::Mars::e2;
    m_M1 = SolarObjectsValues::Mars::M1;
    m_M2 = SolarObjectsValues::Mars::M2;
    m_Period = SolarObjectsValues::Mars::period;
    m_CenterOfOrbit = SolarObjectsValues::Mars::centerOfOrbit;
    m_ObjectType = SolarObjects::Mars;
}

SolarSystem::Planets::Jupiter::Jupiter(QObject *parent):
    AbstractSolarObject(parent)
{
    initialize();
}

void SolarSystem::Planets::Jupiter::initialize()
{
    m_Radius = SolarObjectsValues::Jupier::radius;
    m_Tilt = SolarObjectsValues::Jupier::tilt;
    m_N1 = SolarObjectsValues::Jupier::N1;
    m_N2 = SolarObjectsValues::Jupier::N2;
    m_I1 = SolarObjectsValues::Jupier::i1;
    m_I2 = SolarObjectsValues::Jupier::i2;
    m_W1 = SolarObjectsValues::Jupier::w1;
    m_W2 = SolarObjectsValues::Jupier::w2;
    m_A1 = SolarObjectsValues::Jupier::a1;
    m_A2 = SolarObjectsValues::Jupier::a2;
    m_E1 = SolarObjectsValues::Jupier::e1;
    m_E2 = SolarObjectsValues::Jupier::e2;
    m_M1 = SolarObjectsValues::Jupier::M1;
    m_M2 = SolarObjectsValues::Jupier::M2;
    m_Period = SolarObjectsValues::Jupier::period;
    m_CenterOfOrbit = SolarObjectsValues::Jupier::centerOfOrbit;
    m_ObjectType = SolarObjects::Jupiter;
}

SolarSystem::Planets::Saturn::Saturn(QObject *parent):
    AbstractSolarObject(parent)
{
    initialize();
}

void SolarSystem::Planets::Saturn::initialize()
{
    m_Radius = SolarObjectsValues::Saturn::radius;
    m_Tilt = SolarObjectsValues::Saturn::tilt;
    m_N1 = SolarObjectsValues::Saturn::N1;
    m_N2 = SolarObjectsValues::Saturn::N2;
    m_I1 = SolarObjectsValues::Saturn::i1;
    m_I2 = SolarObjectsValues::Saturn::i2;
    m_W1 = SolarObjectsValues::Saturn::w1;
    m_W2 = SolarObjectsValues::Saturn::w2;
    m_A1 = SolarObjectsValues::Saturn::a1;
    m_A2 = SolarObjectsValues::Saturn::a2;
    m_E1 = SolarObjectsValues::Saturn::e1;
    m_E2 = SolarObjectsValues::Saturn::e2;
    m_M1 = SolarObjectsValues::Saturn::M1;
    m_M2 = SolarObjectsValues::Saturn::M2;
    m_Period = SolarObjectsValues::Saturn::period;
    m_CenterOfOrbit = SolarObjectsValues::Saturn::centerOfOrbit;
    m_ObjectType = SolarObjects::Saturn;
}

SolarSystem::Planets::Uranus::Uranus(QObject *parent):
    AbstractSolarObject(parent)
{
    initialize();
}

void SolarSystem::Planets::Uranus::initialize()
{
    m_Radius = SolarObjectsValues::Uranus::radius;
    m_Tilt = SolarObjectsValues::Uranus::tilt;
    m_N1 = SolarObjectsValues::Uranus::N1;
    m_N2 = SolarObjectsValues::Uranus::N2;
    m_I1 = SolarObjectsValues::Uranus::i1;
    m_I2 = SolarObjectsValues::Uranus::i2;
    m_W1 = SolarObjectsValues::Uranus::w1;
    m_W2 = SolarObjectsValues::Uranus::w2;
    m_A1 = SolarObjectsValues::Uranus::a1;
    m_A2 = SolarObjectsValues::Uranus::a2;
    m_E1 = SolarObjectsValues::Uranus::e1;
    m_E2 = SolarObjectsValues::Uranus::e2;
    m_M1 = SolarObjectsValues::Uranus::M1;
    m_M2 = SolarObjectsValues::Uranus::M2;
    m_Period = SolarObjectsValues::Uranus::period;
    m_CenterOfOrbit = SolarObjectsValues::Uranus::centerOfOrbit;
    m_ObjectType = SolarObjects::Uranus;
}

SolarSystem::Planets::Neptune::Neptune(QObject *parent):
    AbstractSolarObject(parent)
{
    initialize();
}

void SolarSystem::Planets::Neptune::initialize()
{
    m_Radius = SolarObjectsValues::Neptune::radius;
    m_Tilt = SolarObjectsValues::Neptune::tilt;
    m_N1 = SolarObjectsValues::Neptune::N1;
    m_N2 = SolarObjectsValues::Neptune::N2;
    m_I1 = SolarObjectsValues::Neptune::i1;
    m_I2 = SolarObjectsValues::Neptune::i2;
    m_W1 = SolarObjectsValues::Neptune::w1;
    m_W2 = SolarObjectsValues::Neptune::w2;
    m_A1 = SolarObjectsValues::Neptune::a1;
    m_A2 = SolarObjectsValues::Neptune::a2;
    m_E1 = SolarObjectsValues::Neptune::e1;
    m_E2 = SolarObjectsValues::Neptune::e2;
    m_M1 = SolarObjectsValues::Neptune::M1;
    m_M2 = SolarObjectsValues::Neptune::M2;
    m_Period = SolarObjectsValues::Neptune::period;
    m_CenterOfOrbit = SolarObjectsValues::Neptune::centerOfOrbit;
    m_ObjectType = SolarObjects::Neptune;
}

SolarSystem::Moons::Moon::Moon(QObject *parent):
    AbstractSolarObject(parent)
{
    initialize();
}

void SolarSystem::Moons::Moon::initialize()
{
    m_Radius = SolarObjectsValues::Moon::radius;
    m_Tilt = SolarObjectsValues::Moon::tilt;
    m_N1 = SolarObjectsValues::Moon::N1;
    m_N2 = SolarObjectsValues::Moon::N2;
    m_I1 = SolarObjectsValues::Moon::i1;
    m_I2 = SolarObjectsValues::Moon::i2;
    m_W1 = SolarObjectsValues::Moon::w1;
    m_W2 = SolarObjectsValues::Moon::w2;
    m_A1 = SolarObjectsValues::Moon::a1;
    m_A2 = SolarObjectsValues::Moon::a2;
    m_E1 = SolarObjectsValues::Moon::e1;
    m_E2 = SolarObjectsValues::Moon::e2;
    m_M1 = SolarObjectsValues::Moon::M1;
    m_M2 = SolarObjectsValues::Moon::M2;
    m_Period = SolarObjectsValues::Moon::period;
    m_CenterOfOrbit = SolarObjectsValues::Moon::centerOfOrbit;
    m_ObjectType = SolarObjects::Moon;
}

SolarSystem::Planets::Pluto::Pluto(QObject *parent):
    AbstractSolarObject(parent)
{
    initialize();
}

void SolarSystem::Planets::Pluto::initialize()
{
    m_Radius = SolarObjectsValues::Pluto::radius;
    m_Tilt = SolarObjectsValues::Pluto::tilt;
    m_N1 = SolarObjectsValues::Pluto::N1;
    m_N2 = SolarObjectsValues::Pluto::N2;
    m_I1 = SolarObjectsValues::Pluto::i1;
    m_I2 = SolarObjectsValues::Pluto::i2;
    m_W1 = SolarObjectsValues::Pluto::w1;
    m_W2 = SolarObjectsValues::Pluto::w2;
    m_A1 = SolarObjectsValues::Pluto::a1;
    m_A2 = SolarObjectsValues::Pluto::a2;
    m_E1 = SolarObjectsValues::Pluto::e1;
    m_E2 = SolarObjectsValues::Pluto::e2;
    m_M1 = SolarObjectsValues::Pluto::M1;
    m_M2 = SolarObjectsValues::Pluto::M2;
    m_Period = SolarObjectsValues::Pluto::period;
    m_CenterOfOrbit = SolarObjectsValues::Pluto::centerOfOrbit;
    m_ObjectType = SolarObjects::Pluto;
}
