#include "solarobjects.h"

SolarSystem::Stars::Sun::Sun(QObject *parent):
    AbstractSolarObject(parent)
{
    initialize();
}

void SolarSystem::Stars::Sun::initialize()
{
    _radius = SolarObjectsValues::Sun::radius;
    _tilt = SolarObjectsValues::Sun::tilt;
    _N1 = SolarValues::zero;
    _N2 = SolarValues::zero;
    _i1 = SolarValues::zero;
    _i2 = SolarValues::zero;
    _w1 = SolarValues::zero;
    _w2 = SolarValues::zero;
    _a1 = SolarValues::zero;
    _a2 = SolarValues::zero;
    _e1 = SolarValues::zero;
    _e2 = SolarValues::zero;
    _M1 = SolarValues::zero;
    _M2 = SolarValues::zero;
    _period = SolarObjectsValues::Sun::period;
    _centerOfOrbit = SolarObjects::Sun;
    _objectType = SolarObjects::Sun;
}

SolarSystem::Planets::Mercury::Mercury(QObject *parent):
    AbstractSolarObject(parent)
{
    initialize();
}

void SolarSystem::Planets::Mercury::initialize()
{
    _radius = SolarObjectsValues::Mercury::radius;
    _tilt = SolarObjectsValues::Mercury::tilt;
    _N1 = SolarObjectsValues::Mercury::N1;
    _N2 = SolarObjectsValues::Mercury::N2;
    _i1 = SolarObjectsValues::Mercury::i1;
    _i2 = SolarObjectsValues::Mercury::i2;
    _w1 = SolarObjectsValues::Mercury::w1;
    _w2 = SolarObjectsValues::Mercury::w2;
    _a1 = SolarObjectsValues::Mercury::a1;
    _a2 = SolarObjectsValues::Mercury::a2;
    _e1 = SolarObjectsValues::Mercury::e1;
    _e2 = SolarObjectsValues::Mercury::e2;
    _M1 = SolarObjectsValues::Mercury::M1;
    _M2 = SolarObjectsValues::Mercury::M2;
    _period = SolarObjectsValues::Mercury::period;
    _centerOfOrbit = SolarObjectsValues::Mercury::centerOfOrbit;
    _objectType = SolarObjects::Mercury;
}

SolarSystem::Planets::Venus::Venus(QObject *parent):
    AbstractSolarObject(parent)
{
    initialize();
}

void SolarSystem::Planets::Venus::initialize()
{
    _radius = SolarObjectsValues::Venus::radius;
    _tilt = SolarObjectsValues::Venus::tilt;
    _N1 = SolarObjectsValues::Venus::N1;
    _N2 = SolarObjectsValues::Venus::N2;
    _i1 = SolarObjectsValues::Venus::i1;
    _i2 = SolarObjectsValues::Venus::i2;
    _w1 = SolarObjectsValues::Venus::w1;
    _w2 = SolarObjectsValues::Venus::w2;
    _a1 = SolarObjectsValues::Venus::a1;
    _a2 = SolarObjectsValues::Venus::a2;
    _e1 = SolarObjectsValues::Venus::e1;
    _e2 = SolarObjectsValues::Venus::e2;
    _M1 = SolarObjectsValues::Venus::M1;
    _M2 = SolarObjectsValues::Venus::M2;
    _period = SolarObjectsValues::Venus::period;
    _centerOfOrbit = SolarObjectsValues::Venus::centerOfOrbit;
    _objectType = SolarObjects::Venus;
}

SolarSystem::Planets::Earth::Earth(QObject *parent):
    AbstractSolarObject(parent)
{
    initialize();
}

void SolarSystem::Planets::Earth::initialize()
{
    _radius = SolarObjectsValues::Earth::radius;
    _tilt = SolarObjectsValues::Earth::tilt;
    _N1 = SolarObjectsValues::Earth::N1;
    _N2 = SolarObjectsValues::Earth::N2;
    _i1 = SolarObjectsValues::Earth::i1;
    _i2 = SolarObjectsValues::Earth::i2;
    _w1 = SolarObjectsValues::Earth::w1;
    _w2 = SolarObjectsValues::Earth::w2;
    _a1 = SolarObjectsValues::Earth::a1;
    _a2 = SolarObjectsValues::Earth::a2;
    _e1 = SolarObjectsValues::Earth::e1;
    _e2 = SolarObjectsValues::Earth::e2;
    _M1 = SolarObjectsValues::Earth::M1;
    _M2 = SolarObjectsValues::Earth::M2;
    _period = SolarObjectsValues::Earth::period;
    _centerOfOrbit = SolarObjectsValues::Earth::centerOfOrbit;
    _objectType = SolarObjects::Earth;
}

SolarSystem::Planets::Mars::Mars(QObject *parent):
    AbstractSolarObject(parent)
{
    initialize();
}

void SolarSystem::Planets::Mars::initialize()
{
    _radius = SolarObjectsValues::Mars::radius;
    _tilt = SolarObjectsValues::Mars::tilt;
    _N1 = SolarObjectsValues::Mars::N1;
    _N2 = SolarObjectsValues::Mars::N2;
    _i1 = SolarObjectsValues::Mars::i1;
    _i2 = SolarObjectsValues::Mars::i2;
    _w1 = SolarObjectsValues::Mars::w1;
    _w2 = SolarObjectsValues::Mars::w2;
    _a1 = SolarObjectsValues::Mars::a1;
    _a2 = SolarObjectsValues::Mars::a2;
    _e1 = SolarObjectsValues::Mars::e1;
    _e2 = SolarObjectsValues::Mars::e2;
    _M1 = SolarObjectsValues::Mars::M1;
    _M2 = SolarObjectsValues::Mars::M2;
    _period = SolarObjectsValues::Mars::period;
    _centerOfOrbit = SolarObjectsValues::Mars::centerOfOrbit;
    _objectType = SolarObjects::Mars;
}

SolarSystem::Planets::Jupiter::Jupiter(QObject *parent):
    AbstractSolarObject(parent)
{
    initialize();
}

void SolarSystem::Planets::Jupiter::initialize()
{
    _radius = SolarObjectsValues::Jupier::radius;
    _tilt = SolarObjectsValues::Jupier::tilt;
    _N1 = SolarObjectsValues::Jupier::N1;
    _N2 = SolarObjectsValues::Jupier::N2;
    _i1 = SolarObjectsValues::Jupier::i1;
    _i2 = SolarObjectsValues::Jupier::i2;
    _w1 = SolarObjectsValues::Jupier::w1;
    _w2 = SolarObjectsValues::Jupier::w2;
    _a1 = SolarObjectsValues::Jupier::a1;
    _a2 = SolarObjectsValues::Jupier::a2;
    _e1 = SolarObjectsValues::Jupier::e1;
    _e2 = SolarObjectsValues::Jupier::e2;
    _M1 = SolarObjectsValues::Jupier::M1;
    _M2 = SolarObjectsValues::Jupier::M2;
    _period = SolarObjectsValues::Jupier::period;
    _centerOfOrbit = SolarObjectsValues::Jupier::centerOfOrbit;
    _objectType = SolarObjects::Jupiter;
}

SolarSystem::Planets::Saturn::Saturn(QObject *parent):
    AbstractSolarObject(parent)
{
    initialize();
}

void SolarSystem::Planets::Saturn::initialize()
{
    _radius = SolarObjectsValues::Saturn::radius;
    _tilt = SolarObjectsValues::Saturn::tilt;
    _N1 = SolarObjectsValues::Saturn::N1;
    _N2 = SolarObjectsValues::Saturn::N2;
    _i1 = SolarObjectsValues::Saturn::i1;
    _i2 = SolarObjectsValues::Saturn::i2;
    _w1 = SolarObjectsValues::Saturn::w1;
    _w2 = SolarObjectsValues::Saturn::w2;
    _a1 = SolarObjectsValues::Saturn::a1;
    _a2 = SolarObjectsValues::Saturn::a2;
    _e1 = SolarObjectsValues::Saturn::e1;
    _e2 = SolarObjectsValues::Saturn::e2;
    _M1 = SolarObjectsValues::Saturn::M1;
    _M2 = SolarObjectsValues::Saturn::M2;
    _period = SolarObjectsValues::Saturn::period;
    _centerOfOrbit = SolarObjectsValues::Saturn::centerOfOrbit;
    _objectType = SolarObjects::Saturn;
}

SolarSystem::Planets::Uranus::Uranus(QObject *parent):
    AbstractSolarObject(parent)
{
    initialize();
}

void SolarSystem::Planets::Uranus::initialize()
{
    _radius = SolarObjectsValues::Uranus::radius;
    _tilt = SolarObjectsValues::Uranus::tilt;
    _N1 = SolarObjectsValues::Uranus::N1;
    _N2 = SolarObjectsValues::Uranus::N2;
    _i1 = SolarObjectsValues::Uranus::i1;
    _i2 = SolarObjectsValues::Uranus::i2;
    _w1 = SolarObjectsValues::Uranus::w1;
    _w2 = SolarObjectsValues::Uranus::w2;
    _a1 = SolarObjectsValues::Uranus::a1;
    _a2 = SolarObjectsValues::Uranus::a2;
    _e1 = SolarObjectsValues::Uranus::e1;
    _e2 = SolarObjectsValues::Uranus::e2;
    _M1 = SolarObjectsValues::Uranus::M1;
    _M2 = SolarObjectsValues::Uranus::M2;
    _period = SolarObjectsValues::Uranus::period;
    _centerOfOrbit = SolarObjectsValues::Uranus::centerOfOrbit;
    _objectType = SolarObjects::Uranus;
}

SolarSystem::Planets::Neptune::Neptune(QObject *parent):
    AbstractSolarObject(parent)
{
    initialize();
}

void SolarSystem::Planets::Neptune::initialize()
{
    _radius = SolarObjectsValues::Neptune::radius;
    _tilt = SolarObjectsValues::Neptune::tilt;
    _N1 = SolarObjectsValues::Neptune::N1;
    _N2 = SolarObjectsValues::Neptune::N2;
    _i1 = SolarObjectsValues::Neptune::i1;
    _i2 = SolarObjectsValues::Neptune::i2;
    _w1 = SolarObjectsValues::Neptune::w1;
    _w2 = SolarObjectsValues::Neptune::w2;
    _a1 = SolarObjectsValues::Neptune::a1;
    _a2 = SolarObjectsValues::Neptune::a2;
    _e1 = SolarObjectsValues::Neptune::e1;
    _e2 = SolarObjectsValues::Neptune::e2;
    _M1 = SolarObjectsValues::Neptune::M1;
    _M2 = SolarObjectsValues::Neptune::M2;
    _period = SolarObjectsValues::Neptune::period;
    _centerOfOrbit = SolarObjectsValues::Neptune::centerOfOrbit;
    _objectType = SolarObjects::Neptune;
}

SolarSystem::Moons::Moon::Moon(QObject *parent):
    AbstractSolarObject(parent)
{
    initialize();
}

void SolarSystem::Moons::Moon::initialize()
{
    _radius = SolarObjectsValues::Moon::radius;
    _tilt = SolarObjectsValues::Moon::tilt;
    _N1 = SolarObjectsValues::Moon::N1;
    _N2 = SolarObjectsValues::Moon::N2;
    _i1 = SolarObjectsValues::Moon::i1;
    _i2 = SolarObjectsValues::Moon::i2;
    _w1 = SolarObjectsValues::Moon::w1;
    _w2 = SolarObjectsValues::Moon::w2;
    _a1 = SolarObjectsValues::Moon::a1;
    _a2 = SolarObjectsValues::Moon::a2;
    _e1 = SolarObjectsValues::Moon::e1;
    _e2 = SolarObjectsValues::Moon::e2;
    _M1 = SolarObjectsValues::Moon::M1;
    _M2 = SolarObjectsValues::Moon::M2;
    _period = SolarObjectsValues::Moon::period;
    _centerOfOrbit = SolarObjectsValues::Moon::centerOfOrbit;
    _objectType = SolarObjects::Moon;
}

SolarSystem::Planets::Pluto::Pluto(QObject *parent):
    AbstractSolarObject(parent)
{
    initialize();
}

void SolarSystem::Planets::Pluto::initialize()
{
    _radius = SolarObjectsValues::Pluto::radius;
    _tilt = SolarObjectsValues::Pluto::tilt;
    _N1 = SolarObjectsValues::Pluto::N1;
    _N2 = SolarObjectsValues::Pluto::N2;
    _i1 = SolarObjectsValues::Pluto::i1;
    _i2 = SolarObjectsValues::Pluto::i2;
    _w1 = SolarObjectsValues::Pluto::w1;
    _w2 = SolarObjectsValues::Pluto::w2;
    _a1 = SolarObjectsValues::Pluto::a1;
    _a2 = SolarObjectsValues::Pluto::a2;
    _e1 = SolarObjectsValues::Pluto::e1;
    _e2 = SolarObjectsValues::Pluto::e2;
    _M1 = SolarObjectsValues::Pluto::M1;
    _M2 = SolarObjectsValues::Pluto::M2;
    _period = SolarObjectsValues::Pluto::period;
    _centerOfOrbit = SolarObjectsValues::Pluto::centerOfOrbit;
    _objectType = SolarObjects::Pluto;
}
