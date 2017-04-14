#include "solarentity.h"
#include <SolarCore/cameracontroller.h>
#include <SolarCore/SolarRender/solarframegraph.h>
#include <SolarCore/SolarRender/solarlight.h>
#include <Scene/SceneObjects/solarskybox.h>

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
    SolarSystem::CameraController* controller = new SolarSystem::CameraController(this);
    controller->setCamera(mainCamera);
    controller->setLookSpeed(controller->lookSpeed() * 1.2f);

    //skybox
    skybox = new SolarSkyBox(this);

    //light
    auto* light = new SolarLight(this);
    lightCam = light->camera();

    frameGraph = new SolarFrameGraph(this);
    frameGraph->setViewCamera(mainCamera);
    frameGraph->setLightCamera(light->camera());

    input = new Qt3DInput::QInputSettings();

    addComponent(frameGraph);
    addComponent(input);

    //math core control
    solarAnimator->mathCore()->setPlanetsContainer(planetsContainer->planets());
    solarAnimator->mathCore()->setSolarView(mainCamera);
    solarAnimator->mathCore()->setCameraController(controller);
    solarAnimator->setDefaultValues();

    planetsContainer->setLight(light);
    planetsContainer->setShadowTexture(frameGraph->shadowTexture());
    planetsContainer->initEffects();

    //animate scene on tick
    QObject::connect(rootAction, &Qt3DLogic::QFrameAction::triggered, solarAnimator, &SolarAnimator::animate);
    QObject::connect(planetsContainer, &PlanetsContainer::coordClicked, controller, &CameraController::changeViewCenter);
}

SolarSystem::SolarEntity::~SolarEntity()
{
    delete planetsContainer;
    delete solarAnimator;
}

SolarSystem::SolarAnimator *SolarSystem::SolarEntity::animator() const
{
    return solarAnimator;
}

Qt3DRender::QCamera *SolarSystem::SolarEntity::camera() const
{
    return mainCamera;
}

Qt3DInput::QInputSettings *SolarSystem::SolarEntity::inputSettings() const
{
    return input;
}

Qt3DRender::QTexture2D *SolarSystem::SolarEntity::shadowTexture() const
{
    return frameGraph->shadowTexture();
}

Qt3DRender::QCamera *SolarSystem::SolarEntity::lightCamera() const
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
