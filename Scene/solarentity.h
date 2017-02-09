#ifndef SOLARENTITY_H
#define SOLARENTITY_H

#include <Qt3DRender/QCamera>
#include <Qt3DCore/QEntity>
#include <solarsystemcore.h>
#include <Scene/SceneObjects/solarskybox.h>
#include <SolarCore/solaranimator.h>
#include <Qt3DRender/QSortPolicy>
#include <Qt3DRender/QClearBuffers>
#include <Qt3DRender/QCameraSelector>
#include <Qt3DRender/QViewport>
#include <Qt3DRender/QRenderSurfaceSelector>
#include <Qt3DRender/QTechniqueFilter>
#include <Qt3DRender/QRenderSettings>
#include <Qt3DInput/QInputSettings>

namespace SolarSystem {

    //represents chain of solar objects (root entity)
    class SolarEntity : public Qt3DCore::QEntity {

        Q_OBJECT

    public:

        //constructor
        SolarEntity(QNode* parent = nullptr);
        ~SolarEntity();

        //returns animator
        SolarAnimator* animator() const;

    private:

        //scene camera
        Qt3DRender::QCamera* mainCamera;

        //system animator
        SolarAnimator* solarAnimator;

        //tick
        Qt3DLogic::QFrameAction* rootAction;

        //stars
        SolarSkyBox* skybox;

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
