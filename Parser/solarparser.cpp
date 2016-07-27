#include "solarparser.h"

SolarSystem::SolarSystemObject::SolarSystemObjectType SolarSystem::SolarParser::parseString(const QString &str)
{
    SolarSystemObject::SolarSystemObjectType objectType = SolarSystemObject::SolarSystemObjectType::SolarSystemBody;

    if (str == SolarStrings::planet)
        objectType = SolarSystemObject::SolarSystemObjectType::Planet;

    if (str == SolarStrings::dwarfPlanet)
        objectType = SolarSystemObject::SolarSystemObjectType::DwarfPlanet;

    if (str == SolarStrings::star)
        objectType = SolarSystemObject::SolarSystemObjectType::Star;

    if (str == SolarStrings::moon)
        objectType = SolarSystemObject::SolarSystemObjectType::Moon;

    if (str == SolarStrings::asteroid)
        objectType = SolarSystemObject::SolarSystemObjectType::Asteroid;

    if (str == SolarStrings::galaxy)
        objectType = SolarSystemObject::SolarSystemObjectType::Galaxy;

    if (str == SolarStrings::ring)
        objectType = SolarSystemObject::SolarSystemObjectType::Ring;

    return objectType;
}
