#include "visualsolarobject.h"

SolarSystem::VisualSolarObject::VisualSolarObject(Qt3DCore::QNode* parent):
    SolarSystem::IVisualSolarObject(parent), _frameAction(new Qt3DLogic::QFrameAction(this))
{
    addComponent(_frameAction);

    QObject::connect(_frameAction, &Qt3DLogic::QFrameAction::triggered, this, &VisualSolarObject::frameTick);
}

void SolarSystem::VisualSolarObject::addLogic(SolarSystem::LogicPtr func)
{
    logic.push_back(func);
}

void SolarSystem::VisualSolarObject::clearLogic()
{
    logic.clear();
}

void SolarSystem::VisualSolarObject::frameTick(float deltaTime)
{
    //additional actions
    for (auto elem : logic)
        elem(deltaTime);

    update(deltaTime);
}
