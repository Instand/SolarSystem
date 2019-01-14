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
    m_data(new FpsData())
{
    m_data->action = new Qt3DLogic::QFrameAction(this);
    addComponent(m_data->action);

    QObject::connect(m_data->action, &Qt3DLogic::QFrameAction::triggered, [&](float dt){

        ++m_data->frameCount;
        m_data->dt += dt;

        if (m_data->dt > (1.0f / m_data->updateRate))
        {
            m_data->fps = m_data->frameCount / m_data->dt;
            m_data->frameCount = 0;
            m_data->dt -= 1.0f/ m_data->updateRate;

            emit fpsChanged(m_data->fps);
        }
    });
}

SolarSystem::FpsCounter::~FpsCounter()
{
    delete m_data;
}

int SolarSystem::FpsCounter::fps() const
{
    return m_data->fps;
}
