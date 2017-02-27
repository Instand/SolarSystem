#include "solar3dviewport.h"
#include <Qt3DExtras/QForwardRenderer>
#include <Scene/SceneObjects/solarskybox.h>
#include <Qt3DLogic/QFrameAction>
#include <Qt3DExtras/QOrbitCameraController>
#include <SolarCore/planetscontainer.h>
#include <Qt3DExtras/QFirstPersonCameraController>

SolarSystem::Solar3dViewPort::Solar3dViewPort(QScreen* screen):
    Qt3DExtras::Qt3DWindow(screen),
    _camera(camera()),
    root(new Qt3DCore::QEntity()),
    solarAnimator(new SolarAnimator())
{
    //create root frame tick
    Qt3DLogic::QFrameAction* rootAction = new Qt3DLogic::QFrameAction();
    root->addComponent(rootAction);

    //scene camera setup
    _camera = new Qt3DRender::QCamera(root);
    _camera->setProjectionType(Qt3DRender::QCameraLens::PerspectiveProjection);
    _camera->setAspectRatio(width() / height());
    _camera->setViewCenter(QVector3D(0.0f, 3.5f, 0.0f));

    _camera->setFieldOfView(CameraSettings::fieldOfView);
    _camera->setNearPlane(CameraSettings::nearPlane * 0.0001f);
    _camera->setFarPlane(CameraSettings::farPlane);
    _camera->setUpVector(CameraSettings::defaultUp);
    _camera->setPosition(CameraSettings::defaultCameraPosition);

    //solar rendering
    SolarSkyBox* skybox = new SolarSkyBox(root);
    Q_UNUSED(skybox)

    Qt3DExtras::QFirstPersonCameraController* controller = new Qt3DExtras::QFirstPersonCameraController(root);
    controller->setCamera(_camera);
    controller->setLookSpeed(controller->lookSpeed() * 1.5f);
    controller->setLinearSpeed(controller->linearSpeed() * 150000.0f);

    //create all planets
    PlanetsContainer::initialize(root);

    //math core control
    solarAnimator->mathCore()->setPlanetsContainer(PlanetsContainer::planets());
    solarAnimator->setDefaultValues();

    //set root
    setRootEntity(root);

    //animate scene on tick
    QObject::connect(rootAction, &Qt3DLogic::QFrameAction::triggered, solarAnimator, &SolarAnimator::animate);
}

SolarSystem::Solar3dViewPort::~Solar3dViewPort()
{
    PlanetsContainer::destruct();
}

SolarSystem::SolarAnimator *SolarSystem::Solar3dViewPort::animator() const
{
    return solarAnimator;
}





