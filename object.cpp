#include "object.h"

struct SolarSystem::Object::ObjectData
{
    // base parameters
    QString stringType;            // solar object type: Planet, Sattelite (Moon), Ring, Dwarf Planet, Solar System Body, Star, Asteroid, Galaxy
    QString name;                  // base name
    float orbitalSpeed;            // base orbital speed, km/s
    double mass;                   // base mass, kg
    float meanRadius;              // base radius, km
    int surfaceTemp;               // base surface temperature, K
    float surfaceGRavity;          // base surface gravity, m/s^2
    double volume;                 // base volume, km^3

    // programming type
    SolarSystem::ObjectType solarType;

    // periods
    double siderealPeriod;         // sidereal rotation period (around of axis)
    double orbitalPeriod;          // orbital rotation period (around of sun)

    // solar system object description
    QString description;
};

SolarSystem::Object::Object(QObject* parent):
    QObject(parent), solarObjectData(new ObjectData)
{
    solarObjectData->solarType = ObjectType::SolarSystemBody;
}

SolarSystem::Object::~Object()
{
    delete solarObjectData;
}

SolarSystem::Object::Object(const SolarSystem::Object& obj):
    Object(obj.parent())
{
    solarObjectData = new SolarSystem::Object::ObjectData(*(obj.solarObjectData));
}

SolarSystem::Object& SolarSystem::Object::operator=(SolarSystem::Object obj)
{
    // temp object swap
    SolarSystem::swap(*this, obj);
    return *this;
}

// interface
void SolarSystem::Object::setDescription(const QString& description)
{
    solarObjectData->description = description;
}

QString &SolarSystem::Object::description() const
{
    return solarObjectData->description;
}

void SolarSystem::Object::setStringType(const QString& type)
{
    solarObjectData->stringType = type;
}

QString SolarSystem::Object::stringType() const
{
    return solarObjectData->stringType;
}

void SolarSystem::Object::setSolarObjectName(const QString& name)
{
    solarObjectData->name = name;
}

QString SolarSystem::Object::solarObjectName() const
{
    return solarObjectData->name;
}

void SolarSystem::Object::setOrbitalSpeed(float speed)
{
    solarObjectData->orbitalSpeed = speed;
}

float SolarSystem::Object::orbitalSpeed() const
{
    return solarObjectData->orbitalSpeed;
}

void SolarSystem::Object::setMass(double mass)
{
    solarObjectData->mass = mass;
}

double SolarSystem::Object::mass() const
{
    return solarObjectData->mass;
}

void SolarSystem::Object::setMeanRadius(float radius)
{
    solarObjectData->meanRadius = radius;
}

float SolarSystem::Object::meanRadius() const
{
    return solarObjectData->meanRadius;
}

void SolarSystem::Object::setSurfaceTemperature(int temperature)
{
    solarObjectData->surfaceTemp = temperature;
}

int SolarSystem::Object::surfaceTemperature() const
{
    return solarObjectData->surfaceTemp;
}

void SolarSystem::Object::setSurfaceGravity(float gravity)
{
    solarObjectData->surfaceGRavity = gravity;
}

float SolarSystem::Object::surfaceGravity() const
{
    return solarObjectData->surfaceGRavity;
}

void SolarSystem::Object::setVolume(double volume)
{
    solarObjectData->volume = volume;
}

double SolarSystem::Object::volume() const
{
    return solarObjectData->volume;
}

void SolarSystem::Object::setSolarType(ObjectType type)
{
    solarObjectData->solarType = type;
}

SolarSystem::ObjectType SolarSystem::Object::solarType() const
{
    return solarObjectData->solarType;
}

void SolarSystem::Object::setSiderealPeriod(double period)
{
    solarObjectData->siderealPeriod = period;
}

double SolarSystem::Object::siderealPeriod() const
{
    return solarObjectData->siderealPeriod;
}

void SolarSystem::Object::setOrbitalPeriod(double period)
{
    solarObjectData->orbitalPeriod = period;
}

double SolarSystem::Object::orbitalPeriod() const
{
    return solarObjectData->orbitalPeriod;
}

void SolarSystem::swap(SolarSystem::Object& lhs, SolarSystem::Object& rhs)
{
    std::swap(lhs.solarObjectData, rhs.solarObjectData);
}
