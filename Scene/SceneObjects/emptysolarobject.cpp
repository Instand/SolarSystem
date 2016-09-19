#include "emptysolarobject.h"

SolarSystem::EmptySolarObject::EmptySolarObject(Qt3DCore::QNode* parent):
    BaseVisualSolarObject(parent)
{

}

void SolarSystem::EmptySolarObject::update(float deltaTime)
{
    Q_UNUSED(deltaTime)

    //do anything we want
    //...
}
