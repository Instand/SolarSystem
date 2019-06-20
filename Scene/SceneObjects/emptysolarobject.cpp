#include "emptysolarobject.h"

SolarSystem::EmptySolarObject::EmptySolarObject(Qt3DCore::QNode* parent):
    Object3D(parent)
{
}

void SolarSystem::EmptySolarObject::update(float deltaTime)
{
    Q_UNUSED(deltaTime)

    //do anything we want
    //...
}
