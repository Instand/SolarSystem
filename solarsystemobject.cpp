#include "solarsystemobject.h"

enum class SolarSystem::SolarSystemObject::SolarSystemObjectType {
    SolarSystemBody,
    Planet,
    DwarfPlanet,
    Moon,
    Ring,
    Star
};

struct SolarSystem::SolarSystemObject::SolarObjectData {

    //base parameters
    QString _stringType;            //solar object type: Planet, Sattelite (Moon), Ring, Dwarf Planet, Solar System Body, Star
    QString _name;                  //base name
    float _orbitalSpeed;            //base orbital speed, km/s
    double _mass;                   //base mass, kg
    float _meanRadius;              //base radius, km
    int _surfaceTemp;               //base surface temperature, K
    float _surfaceGRavity;          //base surface gravity, m/s^2
    double _volume;                 //base volume, km^3

    //programming type
    SolarSystemObject::SolarSystemObjectType _solarType;

    //periods
    double _siderealPeriod;         //sidereal rotation period (around of axis)
    double _orbitalPeriod;          //orbital rotation period (around of sun)

    //solar system object description
    QString _description;
};

SolarSystem::SolarSystemObject::SolarSystemObject(QObject *parent):
    QObject(parent), solarObjectData(new SolarObjectData)
{
    solarObjectData->_solarType = SolarSystemObjectType::SolarSystemBody;
}

SolarSystem::SolarSystemObject::~SolarSystemObject()
{
    delete solarObjectData;
}

SolarSystem::SolarSystemObject::SolarSystemObject(const SolarSystem::SolarSystemObject &obj):
    QObject(nullptr)
{
    solarObjectData = new SolarSystem::SolarSystemObject::SolarObjectData();

    //just copying fields
    solarObjectData = obj.solarObjectData;
}

SolarSystem::SolarSystemObject& SolarSystem::SolarSystemObject::operator=(SolarSystem::SolarSystemObject obj)
{
    SolarSystem::swap(*this, obj);
    return *this;
}

//interface realization
void SolarSystem::SolarSystemObject::setDescription(const QString &description)
{
    solarObjectData->_description = description;
}

QString &SolarSystem::SolarSystemObject::description() const
{
    return solarObjectData->_description;
}

void SolarSystem::SolarSystemObject::setStringType(const QString &type)
{
    solarObjectData->_stringType = type;
}

QString SolarSystem::SolarSystemObject::stringType() const
{
    return solarObjectData->_stringType;
}

void SolarSystem::SolarSystemObject::setSolarObjectName(const QString &name)
{
    solarObjectData->_name = name;
}

QString SolarSystem::SolarSystemObject::solarObjectName() const
{
    return solarObjectData->_name;
}

void SolarSystem::SolarSystemObject::setOrbitalSpeed(float speed)
{
    solarObjectData->_orbitalSpeed = speed;
}

float SolarSystem::SolarSystemObject::orbitalSpeed() const
{
    return solarObjectData->_orbitalSpeed;
}

void SolarSystem::SolarSystemObject::setMass(double mass)
{
    solarObjectData->_mass = mass;
}

double SolarSystem::SolarSystemObject::mass() const
{
    return solarObjectData->_mass;
}

void SolarSystem::SolarSystemObject::setMeanRadius(float radius)
{
    solarObjectData->_meanRadius = radius;
}

float SolarSystem::SolarSystemObject::meanRadius() const
{
    return solarObjectData->_meanRadius;
}

void SolarSystem::SolarSystemObject::setSurfaceTemperature(int temperature)
{
    solarObjectData->_surfaceTemp = temperature;
}

int SolarSystem::SolarSystemObject::surfaceTemperature() const
{
    return solarObjectData->_surfaceTemp;
}

void SolarSystem::SolarSystemObject::setSurfaceGravity(float gravity)
{
    solarObjectData->_surfaceGRavity = gravity;
}

float SolarSystem::SolarSystemObject::surfaceGravity() const
{
    return solarObjectData->_surfaceGRavity;
}

void SolarSystem::SolarSystemObject::setVolume(double volume)
{
    solarObjectData->_volume = volume;
}

double SolarSystem::SolarSystemObject::volume() const
{
    return solarObjectData->_volume;
}

void SolarSystem::SolarSystemObject::setSolarType(SolarSystemObject::SolarSystemObjectType type)
{
    solarObjectData->_solarType = type;
}

SolarSystem::SolarSystemObject::SolarSystemObjectType SolarSystem::SolarSystemObject::solarType() const
{
    return solarObjectData->_solarType;
}

void SolarSystem::SolarSystemObject::setSiderealPeriod(double period)
{
    solarObjectData->_siderealPeriod = period;
}

double SolarSystem::SolarSystemObject::siderealPeriod() const
{
    return solarObjectData->_siderealPeriod;
}

void SolarSystem::SolarSystemObject::setOrbitalPeriod(double period)
{
    solarObjectData->_orbitalPeriod = period;
}

double SolarSystem::SolarSystemObject::orbitalPeriod() const
{
    return solarObjectData->_orbitalPeriod;
}

//friend
void SolarSystem::swap(SolarSystem::SolarSystemObject &ls, SolarSystem::SolarSystemObject &rs)
{
    std::swap(ls.solarObjectData, rs.solarObjectData);
}
