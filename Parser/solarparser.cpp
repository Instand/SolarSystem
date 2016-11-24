#include "solarparser.h"

SolarSystem::SolarSystemObjectType SolarSystem::SolarParser::parseString(const QString &str)
{
    SolarSystemObjectType objectType = SolarSystemObjectType::SolarSystemBody;

    if (str == SolarStrings::planet)
        objectType = SolarSystemObjectType::Planet;

    if (str == SolarStrings::dwarfPlanet)
        objectType = SolarSystemObjectType::DwarfPlanet;

    if (str == SolarStrings::star)
        objectType = SolarSystemObjectType::Star;

    if (str == SolarStrings::moon)
        objectType = SolarSystemObjectType::Moon;

    if (str == SolarStrings::asteroid)
        objectType = SolarSystemObjectType::Asteroid;

    if (str == SolarStrings::galaxy)
        objectType = SolarSystemObjectType::Galaxy;

    if (str == SolarStrings::ring)
        objectType = SolarSystemObjectType::Ring;

    return objectType;
}

QString SolarSystem::SolarParser::parseSolarObjectToString(SolarSystem::SolarObjects object)
{
    QString str;

    switch (object)
    {
    case SolarObjects::Sun:
        str = SolarObjectsValues::Sun::toString;
        break;

    case SolarObjects::Mercury:
        str = SolarObjectsValues::Mercury::toString;
        break;

    case SolarObjects::Venus:
        str = SolarObjectsValues::Venus::toString;
        break;

    case SolarObjects::Earth:
        str = SolarObjectsValues::Earth::toString;

    case SolarObjects::Mars:
        str = SolarObjectsValues::Mars::toString;
        break;

    case SolarObjects::Jupiter:
        str = SolarObjectsValues::Jupier::toString;
        break;

    case SolarObjects::Saturn:
        str = SolarObjectsValues::Saturn::toString;
        break;

    case SolarObjects::Neptune:
        str = SolarObjectsValues::Neptune::toString;
        break;

    case SolarObjects::Uranus:
        str = SolarObjectsValues::Uranus::toString;
        break;

    case SolarObjects::Pluto:
        str = "Not realized";
        break;

    case SolarObjects::Moon:
        str = SolarObjectsValues::Moon::toString;
        break;

    default:
        str = "None";
        break;
    }

    return str;
}
