#include "solarsystemobject.h"

struct SolarSystem::SolarSystemObject::SolarObjectData
{
    //base parameters
    QString stringType;            //solar object type: Planet, Sattelite (Moon), Ring, Dwarf Planet, Solar System Body, Star, Asteroid, Galaxy
    QString name;                  //base name
    float orbitalSpeed;            //base orbital speed, km/s
    double mass;                   //base mass, kg
    float meanRadius;              //base radius, km
    int surfaceTemp;               //base surface temperature, K
    float surfaceGRavity;          //base surface gravity, m/s^2
    double volume;                 //base volume, km^3

    //programming type
    SolarSystem::SolarSystemObjectType solarType;

    //periods
    double siderealPeriod;         //sidereal rotation period (around of axis)
    double orbitalPeriod;          //orbital rotation period (around of sun)

    //solar system object description
    QString description;
};

SolarSystem::SolarSystemObject::SolarSystemObject(QObject* parent):
    QObject(parent), solarObjectData(new SolarObjectData)
{
    solarObjectData->solarType = SolarSystemObjectType::SolarSystemBody;
}

SolarSystem::SolarSystemObject::~SolarSystemObject()
{
    delete solarObjectData;
}

SolarSystem::SolarSystemObject::SolarSystemObject(const SolarSystem::SolarSystemObject& obj):
    SolarSystemObject(obj.parent())
{
    solarObjectData = new SolarSystem::SolarSystemObject::SolarObjectData();

    //just copying fields
    solarObjectData = obj.solarObjectData;
}

SolarSystem::SolarSystemObject& SolarSystem::SolarSystemObject::operator=(SolarSystem::SolarSystemObject obj)
{
    //temp object swap
    SolarSystem::swap(*this, obj);
    return *this;
}

//interface realization
void SolarSystem::SolarSystemObject::setDescription(const QString& description)
{
    solarObjectData->description = description;
}

QString &SolarSystem::SolarSystemObject::description() const
{
    return solarObjectData->description;
}

void SolarSystem::SolarSystemObject::setStringType(const QString& type)
{
    solarObjectData->stringType = type;
}

QString SolarSystem::SolarSystemObject::stringType() const
{
    return solarObjectData->stringType;
}

void SolarSystem::SolarSystemObject::setSolarObjectName(const QString& name)
{
    solarObjectData->name = name;
}

QString SolarSystem::SolarSystemObject::solarObjectName() const
{
    return solarObjectData->name;
}

void SolarSystem::SolarSystemObject::setOrbitalSpeed(float speed)
{
    solarObjectData->orbitalSpeed = speed;
}

float SolarSystem::SolarSystemObject::orbitalSpeed() const
{
    return solarObjectData->orbitalSpeed;
}

void SolarSystem::SolarSystemObject::setMass(double mass)
{
    solarObjectData->mass = mass;
}

double SolarSystem::SolarSystemObject::mass() const
{
    return solarObjectData->mass;
}

void SolarSystem::SolarSystemObject::setMeanRadius(float radius)
{
    solarObjectData->meanRadius = radius;
}

float SolarSystem::SolarSystemObject::meanRadius() const
{
    return solarObjectData->meanRadius;
}

void SolarSystem::SolarSystemObject::setSurfaceTemperature(int temperature)
{
    solarObjectData->surfaceTemp = temperature;
}

int SolarSystem::SolarSystemObject::surfaceTemperature() const
{
    return solarObjectData->surfaceTemp;
}

void SolarSystem::SolarSystemObject::setSurfaceGravity(float gravity)
{
    solarObjectData->surfaceGRavity = gravity;
}

float SolarSystem::SolarSystemObject::surfaceGravity() const
{
    return solarObjectData->surfaceGRavity;
}

void SolarSystem::SolarSystemObject::setVolume(double volume)
{
    solarObjectData->volume = volume;
}

double SolarSystem::SolarSystemObject::volume() const
{
    return solarObjectData->volume;
}

void SolarSystem::SolarSystemObject::setSolarType(SolarSystemObjectType type)
{
    solarObjectData->solarType = type;
}

SolarSystem::SolarSystemObjectType SolarSystem::SolarSystemObject::solarType() const
{
    return solarObjectData->solarType;
}

void SolarSystem::SolarSystemObject::setSiderealPeriod(double period)
{
    solarObjectData->siderealPeriod = period;
}

double SolarSystem::SolarSystemObject::siderealPeriod() const
{
    return solarObjectData->siderealPeriod;
}

void SolarSystem::SolarSystemObject::setOrbitalPeriod(double period)
{
    solarObjectData->orbitalPeriod = period;
}

double SolarSystem::SolarSystemObject::orbitalPeriod() const
{
    return solarObjectData->orbitalPeriod;
}

//friend
void SolarSystem::swap(SolarSystem::SolarSystemObject& ls, SolarSystem::SolarSystemObject& rs)
{
    std::swap(ls.solarObjectData, rs.solarObjectData);
}
