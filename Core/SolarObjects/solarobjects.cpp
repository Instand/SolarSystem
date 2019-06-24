#include "solarobjects.h"

SolarSystem::Stars::Sun::Sun(QObject* parent):
    AbstractSolarObject(parent)
{
    initialize();
}

void SolarSystem::Stars::Sun::initialize()
{
    m_radius = SolarObjectsValues::Sun::radius;
    m_tilt = SolarObjectsValues::Sun::tilt;
    m_n1 = SolarValues::zero;
    m_n2 = SolarValues::zero;
    m_i1 = SolarValues::zero;
    m_i2 = SolarValues::zero;
    m_w1 = SolarValues::zero;
    m_w2 = SolarValues::zero;
    m_a1 = SolarValues::zero;
    m_a2 = SolarValues::zero;
    m_e1 = SolarValues::zero;
    m_e2 = SolarValues::zero;
    m_m1 = SolarValues::zero;
    m_m2 = SolarValues::zero;
    m_period = SolarObjectsValues::Sun::period;
    m_centerOfOrbit = SolarObjects::Sun;
    m_objectType = SolarObjects::Sun;
}

SolarSystem::Planets::Mercury::Mercury(QObject* parent):
    AbstractSolarObject(parent)
{
    initialize();
}

void SolarSystem::Planets::Mercury::initialize()
{
    m_radius = SolarObjectsValues::Mercury::radius;
    m_tilt = SolarObjectsValues::Mercury::tilt;
    m_n1 = SolarObjectsValues::Mercury::N1;
    m_n2 = SolarObjectsValues::Mercury::N2;
    m_i1 = SolarObjectsValues::Mercury::i1;
    m_i2 = SolarObjectsValues::Mercury::i2;
    m_w1 = SolarObjectsValues::Mercury::w1;
    m_w2 = SolarObjectsValues::Mercury::w2;
    m_a1 = SolarObjectsValues::Mercury::a1;
    m_a2 = SolarObjectsValues::Mercury::a2;
    m_e1 = SolarObjectsValues::Mercury::e1;
    m_e2 = SolarObjectsValues::Mercury::e2;
    m_m1 = SolarObjectsValues::Mercury::M1;
    m_m2 = SolarObjectsValues::Mercury::M2;
    m_period = SolarObjectsValues::Mercury::period;
    m_centerOfOrbit = SolarObjectsValues::Mercury::centerOfOrbit;
    m_objectType = SolarObjects::Mercury;
}

SolarSystem::Planets::Venus::Venus(QObject* parent):
    AbstractSolarObject(parent)
{
    initialize();
}

void SolarSystem::Planets::Venus::initialize()
{
    m_radius = SolarObjectsValues::Venus::radius;
    m_tilt = SolarObjectsValues::Venus::tilt;
    m_n1 = SolarObjectsValues::Venus::N1;
    m_n2 = SolarObjectsValues::Venus::N2;
    m_i1 = SolarObjectsValues::Venus::i1;
    m_i2 = SolarObjectsValues::Venus::i2;
    m_w1 = SolarObjectsValues::Venus::w1;
    m_w2 = SolarObjectsValues::Venus::w2;
    m_a1 = SolarObjectsValues::Venus::a1;
    m_a2 = SolarObjectsValues::Venus::a2;
    m_e1 = SolarObjectsValues::Venus::e1;
    m_e2 = SolarObjectsValues::Venus::e2;
    m_m1 = SolarObjectsValues::Venus::M1;
    m_m2 = SolarObjectsValues::Venus::M2;
    m_period = SolarObjectsValues::Venus::period;
    m_centerOfOrbit = SolarObjectsValues::Venus::centerOfOrbit;
    m_objectType = SolarObjects::Venus;
}

SolarSystem::Planets::Earth::Earth(QObject* parent):
    AbstractSolarObject(parent)
{
    initialize();
}

void SolarSystem::Planets::Earth::initialize()
{
    m_radius = SolarObjectsValues::Earth::radius;
    m_tilt = SolarObjectsValues::Earth::tilt;
    m_n1 = SolarObjectsValues::Earth::N1;
    m_n2 = SolarObjectsValues::Earth::N2;
    m_i1 = SolarObjectsValues::Earth::i1;
    m_i2 = SolarObjectsValues::Earth::i2;
    m_w1 = SolarObjectsValues::Earth::w1;
    m_w2 = SolarObjectsValues::Earth::w2;
    m_a1 = SolarObjectsValues::Earth::a1;
    m_a2 = SolarObjectsValues::Earth::a2;
    m_e1 = SolarObjectsValues::Earth::e1;
    m_e2 = SolarObjectsValues::Earth::e2;
    m_m1 = SolarObjectsValues::Earth::M1;
    m_m2 = SolarObjectsValues::Earth::M2;
    m_period = SolarObjectsValues::Earth::period;
    m_centerOfOrbit = SolarObjectsValues::Earth::centerOfOrbit;
    m_objectType = SolarObjects::Earth;
}

SolarSystem::Planets::Mars::Mars(QObject* parent):
    AbstractSolarObject(parent)
{
    initialize();
}

void SolarSystem::Planets::Mars::initialize()
{
    m_radius = SolarObjectsValues::Mars::radius;
    m_tilt = SolarObjectsValues::Mars::tilt;
    m_n1 = SolarObjectsValues::Mars::N1;
    m_n2 = SolarObjectsValues::Mars::N2;
    m_i1 = SolarObjectsValues::Mars::i1;
    m_i2 = SolarObjectsValues::Mars::i2;
    m_w1 = SolarObjectsValues::Mars::w1;
    m_w2 = SolarObjectsValues::Mars::w2;
    m_a1 = SolarObjectsValues::Mars::a1;
    m_a2 = SolarObjectsValues::Mars::a2;
    m_e1 = SolarObjectsValues::Mars::e1;
    m_e2 = SolarObjectsValues::Mars::e2;
    m_m1 = SolarObjectsValues::Mars::M1;
    m_m2 = SolarObjectsValues::Mars::M2;
    m_period = SolarObjectsValues::Mars::period;
    m_centerOfOrbit = SolarObjectsValues::Mars::centerOfOrbit;
    m_objectType = SolarObjects::Mars;
}

SolarSystem::Planets::Jupiter::Jupiter(QObject* parent):
    AbstractSolarObject(parent)
{
    initialize();
}

void SolarSystem::Planets::Jupiter::initialize()
{
    m_radius = SolarObjectsValues::Jupier::radius;
    m_tilt = SolarObjectsValues::Jupier::tilt;
    m_n1 = SolarObjectsValues::Jupier::N1;
    m_n2 = SolarObjectsValues::Jupier::N2;
    m_i1 = SolarObjectsValues::Jupier::i1;
    m_i2 = SolarObjectsValues::Jupier::i2;
    m_w1 = SolarObjectsValues::Jupier::w1;
    m_w2 = SolarObjectsValues::Jupier::w2;
    m_a1 = SolarObjectsValues::Jupier::a1;
    m_a2 = SolarObjectsValues::Jupier::a2;
    m_e1 = SolarObjectsValues::Jupier::e1;
    m_e2 = SolarObjectsValues::Jupier::e2;
    m_m1 = SolarObjectsValues::Jupier::M1;
    m_m2 = SolarObjectsValues::Jupier::M2;
    m_period = SolarObjectsValues::Jupier::period;
    m_centerOfOrbit = SolarObjectsValues::Jupier::centerOfOrbit;
    m_objectType = SolarObjects::Jupiter;
}

SolarSystem::Planets::Saturn::Saturn(QObject* parent):
    AbstractSolarObject(parent)
{
    initialize();
}

void SolarSystem::Planets::Saturn::initialize()
{
    m_radius = SolarObjectsValues::Saturn::radius;
    m_tilt = SolarObjectsValues::Saturn::tilt;
    m_n1 = SolarObjectsValues::Saturn::N1;
    m_n2 = SolarObjectsValues::Saturn::N2;
    m_i1 = SolarObjectsValues::Saturn::i1;
    m_i2 = SolarObjectsValues::Saturn::i2;
    m_w1 = SolarObjectsValues::Saturn::w1;
    m_w2 = SolarObjectsValues::Saturn::w2;
    m_a1 = SolarObjectsValues::Saturn::a1;
    m_a2 = SolarObjectsValues::Saturn::a2;
    m_e1 = SolarObjectsValues::Saturn::e1;
    m_e2 = SolarObjectsValues::Saturn::e2;
    m_m1 = SolarObjectsValues::Saturn::M1;
    m_m2 = SolarObjectsValues::Saturn::M2;
    m_period = SolarObjectsValues::Saturn::period;
    m_centerOfOrbit = SolarObjectsValues::Saturn::centerOfOrbit;
    m_objectType = SolarObjects::Saturn;
}

SolarSystem::Planets::Uranus::Uranus(QObject* parent):
    AbstractSolarObject(parent)
{
    initialize();
}

void SolarSystem::Planets::Uranus::initialize()
{
    m_radius = SolarObjectsValues::Uranus::radius;
    m_tilt = SolarObjectsValues::Uranus::tilt;
    m_n1 = SolarObjectsValues::Uranus::N1;
    m_n2 = SolarObjectsValues::Uranus::N2;
    m_i1 = SolarObjectsValues::Uranus::i1;
    m_i2 = SolarObjectsValues::Uranus::i2;
    m_w1 = SolarObjectsValues::Uranus::w1;
    m_w2 = SolarObjectsValues::Uranus::w2;
    m_a1 = SolarObjectsValues::Uranus::a1;
    m_a2 = SolarObjectsValues::Uranus::a2;
    m_e1 = SolarObjectsValues::Uranus::e1;
    m_e2 = SolarObjectsValues::Uranus::e2;
    m_m1 = SolarObjectsValues::Uranus::M1;
    m_m2 = SolarObjectsValues::Uranus::M2;
    m_period = SolarObjectsValues::Uranus::period;
    m_centerOfOrbit = SolarObjectsValues::Uranus::centerOfOrbit;
    m_objectType = SolarObjects::Uranus;
}

SolarSystem::Planets::Neptune::Neptune(QObject* parent):
    AbstractSolarObject(parent)
{
    initialize();
}

void SolarSystem::Planets::Neptune::initialize()
{
    m_radius = SolarObjectsValues::Neptune::radius;
    m_tilt = SolarObjectsValues::Neptune::tilt;
    m_n1 = SolarObjectsValues::Neptune::N1;
    m_n2 = SolarObjectsValues::Neptune::N2;
    m_i1 = SolarObjectsValues::Neptune::i1;
    m_i2 = SolarObjectsValues::Neptune::i2;
    m_w1 = SolarObjectsValues::Neptune::w1;
    m_w2 = SolarObjectsValues::Neptune::w2;
    m_a1 = SolarObjectsValues::Neptune::a1;
    m_a2 = SolarObjectsValues::Neptune::a2;
    m_e1 = SolarObjectsValues::Neptune::e1;
    m_e2 = SolarObjectsValues::Neptune::e2;
    m_m1 = SolarObjectsValues::Neptune::M1;
    m_m2 = SolarObjectsValues::Neptune::M2;
    m_period = SolarObjectsValues::Neptune::period;
    m_centerOfOrbit = SolarObjectsValues::Neptune::centerOfOrbit;
    m_objectType = SolarObjects::Neptune;
}

SolarSystem::Moons::Moon::Moon(QObject* parent):
    AbstractSolarObject(parent)
{
    initialize();
}

void SolarSystem::Moons::Moon::initialize()
{
    m_radius = SolarObjectsValues::Moon::radius;
    m_tilt = SolarObjectsValues::Moon::tilt;
    m_n1 = SolarObjectsValues::Moon::N1;
    m_n2 = SolarObjectsValues::Moon::N2;
    m_i1 = SolarObjectsValues::Moon::i1;
    m_i2 = SolarObjectsValues::Moon::i2;
    m_w1 = SolarObjectsValues::Moon::w1;
    m_w2 = SolarObjectsValues::Moon::w2;
    m_a1 = SolarObjectsValues::Moon::a1;
    m_a2 = SolarObjectsValues::Moon::a2;
    m_e1 = SolarObjectsValues::Moon::e1;
    m_e2 = SolarObjectsValues::Moon::e2;
    m_m1 = SolarObjectsValues::Moon::M1;
    m_m2 = SolarObjectsValues::Moon::M2;
    m_period = SolarObjectsValues::Moon::period;
    m_centerOfOrbit = SolarObjectsValues::Moon::centerOfOrbit;
    m_objectType = SolarObjects::Moon;
}

SolarSystem::Planets::Pluto::Pluto(QObject* parent):
    AbstractSolarObject(parent)
{
    initialize();
}

void SolarSystem::Planets::Pluto::initialize()
{
    m_radius = SolarObjectsValues::Pluto::radius;
    m_tilt = SolarObjectsValues::Pluto::tilt;
    m_n1 = SolarObjectsValues::Pluto::N1;
    m_n2 = SolarObjectsValues::Pluto::N2;
    m_i1 = SolarObjectsValues::Pluto::i1;
    m_i2 = SolarObjectsValues::Pluto::i2;
    m_w1 = SolarObjectsValues::Pluto::w1;
    m_w2 = SolarObjectsValues::Pluto::w2;
    m_a1 = SolarObjectsValues::Pluto::a1;
    m_a2 = SolarObjectsValues::Pluto::a2;
    m_e1 = SolarObjectsValues::Pluto::e1;
    m_e2 = SolarObjectsValues::Pluto::e2;
    m_m1 = SolarObjectsValues::Pluto::M1;
    m_m2 = SolarObjectsValues::Pluto::M2;
    m_period = SolarObjectsValues::Pluto::period;
    m_centerOfOrbit = SolarObjectsValues::Pluto::centerOfOrbit;
    m_objectType = SolarObjects::Pluto;
}
