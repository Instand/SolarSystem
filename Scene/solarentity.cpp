#include "solarentity.h"
#include <SolarCore/cameracontroller.h>
#include <Scene/SceneObjects/solarskybox.h>

#ifdef QT3D_MATERIALS
    #include <SolarCore/SolarRender/solarforwardframegraph.h>
#else
    #include <SolarCore/SolarRender/solarframegraph.h>
    #include <SolarCore/SolarRender/solarlight.h>
#endif

SolarSystem::SolarEntity::SolarEntity(QNode* parent):
    Qt3DCore::QEntity(parent),
    solarAnimator(new SolarAnimator()),
    rootAction(new Qt3DLogic::QFrameAction()),
    planetsContainer(new PlanetsContainer(this))
{
    addComponent(rootAction);

    //scene camera setup
    mainCamera = new Qt3DRender::QCamera(this);
    mainCamera->setProjectionType(Qt3DRender::QCameraLens::PerspectiveProjection);
    mainCamera->setViewCenter(QVector3D(0.0f, 3.5f, 0.0f));

    mainCamera->setFieldOfView(CameraSettings::fieldOfView);
    mainCamera->setNearPlane(CameraSettings::nearPlane * 0.0001f);
    mainCamera->setFarPlane(CameraSettings::farPlane);
    mainCamera->setUpVector(CameraSettings::defaultUp);
    mainCamera->setPosition(CameraSettings::defaultCameraPosition);

    //orbit camera controller
    auto controller = new SolarSystem::CameraController(this);
    controller->setCamera(mainCamera);
    controller->setLookSpeed(controller->lookSpeed() * 1.2f);

    //skybox
    skybox = new SolarSkyBox(this);

#ifdef QT3D_MATERIALS
    frameGraph = new SolarForwardFrameGraph(this);
    frameGraph->setCamera(mainCamera);    
#else
    //light
    auto light = new SolarLight(this);
    lightCam = light->camera();

    frameGraph = new SolarFrameGraph(this);
    frameGraph->setViewCamera(mainCamera);
    frameGraph->setLightCamera(light->camera());
#endif

    input = new Qt3DInput::QInputSettings();

    addComponent(frameGraph);
    addComponent(input);

    //math core control
    solarAnimator->mathCore()->setPlanetsContainer(planetsContainer->planets());
    solarAnimator->mathCore()->setSolarView(mainCamera);
    solarAnimator->mathCore()->setCameraController(controller);
    solarAnimator->setDefaultValues();

#ifndef QT3D_MATERIALS
    planetsContainer->setLight(light);
    planetsContainer->setShadowTexture(frameGraph->shadowTexture());
    planetsContainer->initEffects();
#endif

    //animate scene on tick
    QObject::connect(rootAction, &Qt3DLogic::QFrameAction::triggered, solarAnimator, &SolarAnimator::animate);
}

SolarSystem::SolarEntity::~SolarEntity()
{
    delete planetsContainer;
    delete solarAnimator;
}

SolarSystem::SolarAnimator* SolarSystem::SolarEntity::animator() const
{
    return solarAnimator;
}

Qt3DRender::QCamera* SolarSystem::SolarEntity::camera() const
{
    return mainCamera;
}

Qt3DInput::QInputSettings* SolarSystem::SolarEntity::inputSettings() const
{
    return input;
}

#ifndef QT3D_MATERIALS
Qt3DRender::QTexture2D* SolarSystem::SolarEntity::shadowTexture() const
{
    return frameGraph->shadowTexture();
}

Qt3DRender::QCamera* SolarSystem::SolarEntity::lightCamera() const
{
    return lightCam;
}

void SolarSystem::SolarEntity::setSize(int width, int height)
{
    frameGraph->shadowTexture()->setWidth(width);
    frameGraph->shadowTexture()->setHeight(height);
    lightCam->setAspectRatio(width/height);
    mainCamera->setAspectRatio(width/height);
}
#endif
