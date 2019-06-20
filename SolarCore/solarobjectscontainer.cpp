#include "solarobjectscontainer.h"

#include <Parser/solarparser.h>

#include <SolarCore/solarobjectsfactory.h>
#include <SolarCore/SolarObjects/solarobjects.h>

#include <QDebug>

SolarSystem::SolarObjectsContainer::SolarObjectsContainer(QObject* parent):
    QObject(parent)
{
    // create all maths solar system objects

    // stars
    m_solarObjects.emplace(std::make_pair(SolarObjects::Sun, SolarObjectsFactory::create<Stars::Sun>()));

    // planets
    m_solarObjects.emplace(std::make_pair(SolarObjects::Mercury, SolarObjectsFactory::create<Planets::Mercury>()));
    m_solarObjects.emplace(std::make_pair(SolarObjects::Venus, SolarObjectsFactory::create<Planets::Venus>()));
    m_solarObjects.emplace(std::make_pair(SolarObjects::Earth, SolarObjectsFactory::create<Planets::Earth>()));
    m_solarObjects.emplace(std::make_pair(SolarObjects::Mars, SolarObjectsFactory::create<Planets::Mars>()));
    m_solarObjects.emplace(std::make_pair(SolarObjects::Jupiter, SolarObjectsFactory::create<Planets::Jupiter>()));
    m_solarObjects.emplace(std::make_pair(SolarObjects::Saturn, SolarObjectsFactory::create<Planets::Saturn>()));
    m_solarObjects.emplace(std::make_pair(SolarObjects::Neptune, SolarObjectsFactory::create<Planets::Neptune>()));
    m_solarObjects.emplace(std::make_pair(SolarObjects::Uranus, SolarObjectsFactory::create<Planets::Uranus>()));
    m_solarObjects.emplace(std::make_pair(SolarObjects::Pluto, SolarObjectsFactory::create<Planets::Pluto>()));

    // moons
    m_solarObjects.emplace(std::make_pair(SolarObjects::Moon, SolarObjectsFactory::create<Moons::Moon>()));
}

SolarSystem::SolarObjectPtr SolarSystem::SolarObjectsContainer::solarObject(SolarSystem::SolarObjects object) const
{
    auto iter = m_solarObjects.find(object);

    if (iter != m_solarObjects.end())
        return iter->second;
    else
        qDebug() << "The object: " + SolarParser::parseSolarObjectToString(object) + " not in solar container";

    return SolarObjectPtr();
}
