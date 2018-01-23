#ifndef SOLARENTITY_H
#define SOLARENTITY_H

#include <Qt3DRender/QCamera>
#include <Qt3DCore/QEntity>
#include <solarsystemcore.h>
#include <SolarCore/solaranimator.h>
#include <Scene/fpscounter.h>
#include <Qt3DLogic/QFrameAction>
#include <Qt3DRender/QTexture>
#include <Qt3DInput/QInputSettings>

namespace SolarSystem
{
    class SolarSkyBox;
    class PlanetsContainer;
    class SolarAnimator;
    class IFrameGraph;

    //Represents chain of solar objects (root entity)
    class SolarEntity : public Qt3DCore::QEntity
    {
        Q_OBJECT

        Q_PROPERTY(SolarAnimator* animator READ animator)
        Q_PROPERTY(FpsCounter* counter READ counter)
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

        //returns fps counter
        FpsCounter* counter() const;

    private:

        //scene camera
        Qt3DRender::QCamera* mainCamera;

        //light camera
        Qt3DRender::QCamera* lightCam;

        //system animator
        SolarAnimator* solarAnimator;

        //tick
        Qt3DLogic::QFrameAction* rootAction;

        //planets container
        PlanetsContainer* planetsContainer;

        //input
        Qt3DInput::QInputSettings* input;

        //fps
        FpsCounter* fpsCounter;

        //main graph
        IFrameGraph* frameGraph;

        //box
        SolarSkyBox* skybox;
    };
}

#endif // SOLARENTITY_H
