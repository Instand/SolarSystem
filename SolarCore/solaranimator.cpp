#include "solaranimator.h"
#include <SolarCore/solarmathcore.h>

SolarSystem::SolarAnimator::SolarAnimator(QObject *parent):
    QObject(parent)
{
    _mathCore = new SolarMathCore();
    _mathCore->changeSolarObjectsSpeed(0.05f);
}

SolarSystem::SolarAnimator::~SolarAnimator()
{
    delete _mathCore;
}

SolarSystem::ISolarMathCore *SolarSystem::SolarAnimator::mathCore() const
{
    return _mathCore;
}

void SolarSystem::SolarAnimator::animate()
{
    _mathCore->advanceTime(SolarObjects::SolarSystemView);

    for (int i = 0; i < PlanetsContainer::planetsNumber(); ++i)
        _mathCore->solarObjectPosition((SolarObjects)i);
}
