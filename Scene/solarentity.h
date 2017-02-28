#ifndef SOLARENTITY_H
#define SOLARENTITY_H

#include <Qt3DRender/QCamera>
#include <Qt3DCore/QEntity>
#include <solarsystemcore.h>
#include <SolarCore/solaranimator.h>
#include <Qt3DRender/QSortPolicy>
#include <Qt3DRender/QClearBuffers>
#include <Qt3DRender/QCameraSelector>
#include <Qt3DRender/QViewport>
#include <Qt3DRender/QRenderSurfaceSelector>
#include <Qt3DRender/QTechniqueFilter>
#include <Qt3DRender/QRenderSettings>
#include <Qt3DInput/QInputSettings>
#include <Qt3DLogic/QFrameAction>

namespace SolarSystem {
    class PlanetsContainer;
}

namespace SolarSystem {

    //represents chain of solar objects (root entity)
    class SolarEntity : public Qt3DCore::QEntity {

        Q_OBJECT

        Q_PROPERTY(SolarAnimator* animator READ animator)
        Q_PROPERTY(Qt3DRender::QCamera* camera READ camera)

    public:

        //constructor
        SolarEntity(QNode* parent = nullptr);
        ~SolarEntity();

        //returns animator
        SolarAnimator* animator() const;

        //returns camera
        Qt3DRender::QCamera* camera() const;

    private:

        //scene camera
        Qt3DRender::QCamera* mainCamera;

        //system animator
        SolarAnimator* solarAnimator;

        //tick
        Qt3DLogic::QFrameAction* rootAction;

        //planets container
        PlanetsContainer* planetsContainer;

        //render frame graph elements
        Qt3DRender::QSortPolicy* sortPolicy;
        Qt3DRender::QClearBuffers* clearBuffers;
        Qt3DRender::QCameraSelector* cameraSelector;
        Qt3DRender::QViewport* viewPort;
        Qt3DRender::QRenderSurfaceSelector* surfaceSelector;
        Qt3DRender::QTechniqueFilter* filter;
        Qt3DRender::QRenderSettings* settings;
        Qt3DInput::QInputSettings* input;
    };
}

#endif // SOLARENTITY_H
