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

float SolarSystem::SolarParser::parseSolarObjectTilt(SolarSystem::SolarObjects object)
{
    float tilt = 0;

    switch (object)
    {

    case SolarObjects::Sun:
        tilt = SolarObjectsValues::Sun::tilt;
        break;

    case SolarObjects::Mercury:
        tilt = SolarObjectsValues::Mercury::tilt;
        break;

    case SolarObjects::Venus:
        tilt = SolarObjectsValues::Venus::tilt;
        break;

    case SolarObjects::Earth:
        tilt = SolarObjectsValues::Earth::tilt;
        break;

    case SolarObjects::Mars:
        tilt = SolarObjectsValues::Mars::tilt;
        break;

    case SolarObjects::Jupiter:
        tilt = SolarObjectsValues::Jupier::tilt;
        break;

    case SolarObjects::Saturn:
        tilt = SolarObjectsValues::Saturn::tilt;
        break;

    case SolarObjects::Uranus:
        tilt = SolarObjectsValues::Uranus::tilt;
        break;

    case SolarObjects::Neptune:
        tilt = SolarObjectsValues::Neptune::tilt;
        break;

    default:
        break;
    }

    return tilt;
}
