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

QDateTime SolarSystem::SolarAnimator::solarTime() const
{
    return _mathCore->getTime();
}

void SolarSystem::SolarAnimator::setDefaultValues()
{
    _mathCore->changeSolarObjectsSpeed(SolarSystem::SolarValues::startSpeed);
    _mathCore->changeSolarSystemScale(SolarSystem::SolarValues::startSize);
}

void SolarSystem::SolarAnimator::animate(float deltaTime)
{
    //set delta time to math core
    _mathCore->setDeltaTime(deltaTime);

    //calculate time
    _mathCore->advanceTime(SolarObjects::SolarSystemView);

    //update solar objects position
    auto updateCount = static_cast<int>(SolarObjects::Pluto);

    for (int i = 0; i < updateCount; ++i)
        _mathCore->solarObjectPosition((SolarObjects)i);

    _mathCore->ringsCalculation();

    emit solarTimeChanged(_mathCore->getTime());
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
