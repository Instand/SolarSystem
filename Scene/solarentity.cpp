#include "solarentity.h"
#include <SolarCore/cameracontroller.h>
#include <SolarCore/SolarRender/solarforwardframegraph.h>

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

    auto* frameGraph = new SolarForwardFrameGraph(this);
    frameGraph->setCamera(mainCamera);

    input = new Qt3DInput::QInputSettings();

    addComponent(frameGraph);
    addComponent(input);

    //math core control
    solarAnimator->mathCore()->setPlanetsContainer(planetsContainer->planets());
    solarAnimator->mathCore()->setSolarView(mainCamera);
    solarAnimator->mathCore()->setCameraController(controller);
    solarAnimator->setDefaultValues();

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
