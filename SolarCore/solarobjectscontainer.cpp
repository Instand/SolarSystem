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
    _solarObjects.push_back(SolarObjectsFactory::create<Stars::Sun>());

    //planets
    _solarObjects.push_back(SolarObjectsFactory::create<Planets::Mercury>());
    _solarObjects.push_back(SolarObjectsFactory::create<Planets::Venus>());
    _solarObjects.push_back(SolarObjectsFactory::create<Planets::Earth>());
    _solarObjects.push_back(SolarObjectsFactory::create<Planets::Mars>());
    _solarObjects.push_back(SolarObjectsFactory::create<Planets::Jupiter>());
    _solarObjects.push_back(SolarObjectsFactory::create<Planets::Saturn>());
    _solarObjects.push_back(SolarObjectsFactory::create<Planets::Neptune>());
    _solarObjects.push_back(SolarObjectsFactory::create<Planets::Uranus>());

    //moons
    _solarObjects.push_back(SolarObjectsFactory::create<Moons::Moon>());
}

SolarSystem::SolarObjectPtr SolarSystem::SolarObjectsContainer::solarObject(SolarSystem::SolarObjects object) const
{
    SolarObjectPtr solarObj;

    auto iter = std::find_if(_solarObjects.begin(), _solarObjects.end(),
                             [=](auto& elem){
                                 return elem->object() == object;
                             });

    if (iter != _solarObjects.end())
        solarObj = *iter;
    else
        qDebug() << "The object: " + SolarParser::parseSolarObjectToString(object) + " not in solar container";

    return solarObj;
}

const SolarSystem::SolarObjectsArray &SolarSystem::SolarObjectsContainer::allSolarObjects() const
{
    return _solarObjects;
}
