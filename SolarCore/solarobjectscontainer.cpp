#include "solarobjectscontainer.h"
#include "Parser/solarparser.h"
#include "SolarCore/solarobjectsfactory.h"
#include "SolarCore/SolarObjects/solarobjects.h"
#include <QDebug>

SolarSystem::SolarObjectsContainer::SolarObjectsContainer(QObject *parent):
    QObject(parent)
{
    //create all maths solar system objects

    //stars
    m_solarObjects.push_back(SolarObjectsFactory::create<Stars::Sun>());

    //planets
    m_solarObjects.push_back(SolarObjectsFactory::create<Planets::Mercury>());
    m_solarObjects.push_back(SolarObjectsFactory::create<Planets::Venus>());
    m_solarObjects.push_back(SolarObjectsFactory::create<Planets::Earth>());
    m_solarObjects.push_back(SolarObjectsFactory::create<Planets::Mars>());
    m_solarObjects.push_back(SolarObjectsFactory::create<Planets::Jupiter>());
    m_solarObjects.push_back(SolarObjectsFactory::create<Planets::Saturn>());
    m_solarObjects.push_back(SolarObjectsFactory::create<Planets::Neptune>());
    m_solarObjects.push_back(SolarObjectsFactory::create<Planets::Uranus>());
    m_solarObjects.push_back(SolarObjectsFactory::create<Planets::Pluto>());

    //moons
    m_solarObjects.push_back(SolarObjectsFactory::create<Moons::Moon>());
}

SolarSystem::SolarObjectPtr SolarSystem::SolarObjectsContainer::solarObject(SolarSystem::SolarObjects object) const
{
    SolarObjectPtr solarObj;

    auto iter = std::find_if(m_solarObjects.begin(), m_solarObjects.end(), [=](auto& elem){
                                 return elem->object() == object;
                             });

    if (iter != m_solarObjects.end())
        solarObj = *iter;
    else
        qDebug() << "The object: " + SolarParser::parseSolarObjectToString(object) + " not in solar container";

    return solarObj;
}

const SolarSystem::SolarObjectsArray& SolarSystem::SolarObjectsContainer::allSolarObjects() const
{
    return m_solarObjects;
}
