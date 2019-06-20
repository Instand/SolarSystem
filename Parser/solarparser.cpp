#include "solarparser.h"

SolarSystem::ObjectType SolarSystem::SolarParser::parseString(const QString &str)
{
    ObjectType objectType = ObjectType::SolarSystemBody;

    if (str == SolarStrings::planet)
        objectType = ObjectType::Planet;

    if (str == SolarStrings::dwarfPlanet)
        objectType = ObjectType::DwarfPlanet;

    if (str == SolarStrings::star)
        objectType = ObjectType::Star;

    if (str == SolarStrings::moon)
        objectType = ObjectType::Moon;

    if (str == SolarStrings::asteroid)
        objectType = ObjectType::Asteroid;

    if (str == SolarStrings::galaxy)
        objectType = ObjectType::Galaxy;

    if (str == SolarStrings::ring)
        objectType = ObjectType::Ring;

    return objectType;
}

QString SolarSystem::SolarParser::parseSolarObjectToString(SolarSystem::SolarObjects object)
{
    QString str;

    switch (object)
    {
    case SolarObjects::SolarSystemView:
        str = SolarObjectsValues::SolarSystem::toString;
        break;

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
        break;

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
        str = SolarObjectsValues::Pluto::toString;
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
    double tilt = 0;

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

    case SolarObjects::Pluto:
        tilt = SolarObjectsValues::Pluto::tilt;
        break;

    case SolarObjects::Moon:
        tilt = SolarObjectsValues::Moon::tilt;
        break;

    default:
        break;
    }

    return static_cast<float>(tilt);
}

double SolarSystem::SolarParser::parseSolarObjectRadius(SolarSystem::SolarObjects object)
{
    double radius = 0;

    switch (object)
    {
    case SolarObjects::Sun:
        radius = SolarObjectsValues::Sun::radius;
        break;

    case SolarObjects::Mercury:
        radius = SolarObjectsValues::Mercury::radius;
        break;

    case SolarObjects::Venus:
        radius = SolarObjectsValues::Venus::radius;
        break;

    case SolarObjects::Earth:
        radius = SolarObjectsValues::Earth::radius;
        break;

    case SolarObjects::Mars:
        radius = SolarObjectsValues::Mars::radius;
        break;

    case SolarObjects::Jupiter:
        radius = SolarObjectsValues::Jupier::radius;
        break;

    case SolarObjects::Saturn:
        radius = SolarObjectsValues::Saturn::radius;
        break;

    case SolarObjects::Uranus:
        radius = SolarObjectsValues::Uranus::radius;
        break;

    case SolarObjects::Neptune:
        radius = SolarObjectsValues::Neptune::radius;
        break;

    case SolarObjects::Pluto:
        radius = SolarObjectsValues::Pluto::radius;
        break;

    case SolarObjects::Moon:
        radius = SolarObjectsValues::Moon::radius;
        break;

    default:
        break;
    }

    return radius;
}

SolarSystem::SolarObjects SolarSystem::SolarParser::parsePlanetListIndex(int index)
{
    SolarObjects object = SolarObjects::SolarSystemView;

    switch (index)
    {
    case 0:
        object = SolarObjects::SolarSystemView;
        break;

    case 1:
        object = SolarObjects::Sun;
        break;

    case 2:
        object = SolarObjects::Mercury;
        break;

    case 3:
        object = SolarObjects::Venus;
        break;

    case 4:
        object = SolarObjects::Earth;
        break;

    case 5:
        object = SolarObjects::Mars;
        break;

    case 6:
        object = SolarObjects::Jupiter;
        break;

    case 7:
        object = SolarObjects::Saturn;
        break;

    case 8:
        object = SolarObjects::Uranus;
        break;

    case 9:
        object = SolarObjects::Neptune;
        break;

    case 10:
        object = SolarObjects::Pluto;
        break;

    default:
        break;
    }

    return object;
}
