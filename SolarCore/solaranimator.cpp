#include "solaranimator.h"
#include <SolarCore/solarmathcore.h>

SolarSystem::SolarAnimator::SolarAnimator(QObject *parent):
    QObject(parent)
{
    _mathCore = new SolarMathCore();
}

SolarSystem::SolarAnimator::~SolarAnimator()
{
    delete _mathCore;
}

SolarSystem::ISolarMathCore *SolarSystem::SolarAnimator::mathCore() const
{
    return _mathCore;
}

void SolarSystem::SolarAnimator::setDefaultValues()
{
    _mathCore->changeSolarObjectsSpeed(SolarSystem::SolarValues::startSpeed);
    _mathCore->changeSolarSystemScale(SolarSystem::SolarValues::startSize);
}

void SolarSystem::SolarAnimator::animate()
{
    _mathCore->advanceTime(SolarObjects::SolarSystemView);

    for (int i = 0; i < PlanetsContainer::planetsNumber(); ++i)
        _mathCore->solarObjectPosition((SolarObjects)i);
}

void SolarSystem::SolarAnimator::setSolarSpeed(int value)
{
    float coeff = value/50.0f;
    _mathCore->changeSolarObjectsSpeed(SolarValues::startSpeed * coeff);
}

void SolarSystem::SolarAnimator::setSolarSize(int value)
{
    float coeff = value/50.0f;
    _mathCore->changeSolarSystemScale(SolarValues::startSize * coeff);
}
