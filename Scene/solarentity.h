#ifndef SOLARENTITY_H
#define SOLARENTITY_H

#include <Qt3DRender/QCamera>
#include <Qt3DCore/QEntity>
#include <solarsystemcore.h>
#include <SolarCore/solaranimator.h>
#include <Qt3DInput/QInputSettings>
#include <Qt3DLogic/QFrameAction>

namespace SolarSystem {
    class PlanetsContainer;
}

namespace SolarSystem {

    //represents chain of solar objects (root entity)
    class SolarEntity : public Qt3DCore::QEntity
    {
        Q_OBJECT

        Q_PROPERTY(SolarAnimator* animator READ animator)
        Q_PROPERTY(Qt3DRender::QCamera* camera READ camera)
        Q_PROPERTY(Qt3DInput::QInputSettings* inputSettings READ inputSettings)

    public:

        //constructor
        SolarEntity(QNode* parent = nullptr);
        ~SolarEntity();

        //returns animator
        SolarAnimator* animator() const;

        //returns camera
        Qt3DRender::QCamera* camera() const;

        //returns input settings
        Qt3DInput::QInputSettings* inputSettings() const;

    private:

        //scene camera
        Qt3DRender::QCamera* mainCamera;

        //system animator
        SolarAnimator* solarAnimator;

        //tick
        Qt3DLogic::QFrameAction* rootAction;

        //planets container
        PlanetsContainer* planetsContainer;

        //input
        Qt3DInput::QInputSettings* input;
    };
}

#endif // SOLARENTITY_H
