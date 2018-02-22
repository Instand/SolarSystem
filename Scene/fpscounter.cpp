#include "fpscounter.h"
#include <Qt3DLogic/QFrameAction>

struct SolarSystem::FpsCounter::FpsData
{
    //tick element
    Qt3DLogic::QFrameAction* action = nullptr;

    //fps data
    int frameCount = 0;
    float dt = 0;
    float fps = 0;
    float updateRate = 1.0f;
};

SolarSystem::FpsCounter::FpsCounter(Qt3DCore::QNode* parent):
    QEntity(parent),
    fpsData(new FpsData())
{
    fpsData->action = new Qt3DLogic::QFrameAction(this);
    addComponent(fpsData->action);

    QObject::connect(fpsData->action, &Qt3DLogic::QFrameAction::triggered, [&](float dt){

        ++fpsData->frameCount;
        fpsData->dt += dt;

        if (fpsData->dt > (1.0f / fpsData->updateRate))
        {
            fpsData->fps = fpsData->frameCount / fpsData->dt;
            fpsData->frameCount = 0;
            fpsData->dt -= 1.0f/ fpsData->updateRate;

            emit fpsChanged(fpsData->fps);
        }
    });
}

SolarSystem::FpsCounter::~FpsCounter()
{
    delete fpsData;
}

int SolarSystem::FpsCounter::fps() const
{
    return fpsData->fps;
}
