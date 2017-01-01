#include "solar3dviewport.h"
#include <Qt3DExtras/QForwardRenderer>
#include "Scene/SceneObjects/solarskybox.h"
#include <Qt3DExtras/QFirstPersonCameraController>
#include <SolarCore/planetscontainer.h>
#include <SolarCore/solarmathcore.h>

SolarSystem::Solar3dViewPort::Solar3dViewPort(QScreen* screen):
    Qt3DExtras::Qt3DWindow(screen),
    _camera(camera()),
    _root(new Qt3DCore::QEntity),
    mathCore(new SolarMathCore())
{
    //3d viewport setup
    defaultFramegraph()->setClearColor(Qt::black);

    //create root frame tick
    Qt3DLogic::QFrameAction* rootAction = new Qt3DLogic::QFrameAction(_root);
    _root->addComponent(rootAction);

    //scene camera setup
    _camera->setProjectionType(Qt3DRender::QCameraLens::PerspectiveProjection);
    _camera->setAspectRatio(width() / height());
    _camera->setUpVector(QVector3D(0.0f, 1.0f, 0.0f));
    _camera->setViewCenter(QVector3D(0.0f, 3.5f, 0.0f));
    _camera->setPosition(QVector3D(0.0f, 0.5f, 35.0f));
    _camera->setNearPlane(0.01f);
    _camera->setFarPlane(2000.0f);

    _camera->setFieldOfView(CameraSettings::fieldOfView);
    /*_camera->setNearPlane(CameraSettings::nearPlane);
    _camera->setFarPlane(CameraSettings::farPlane);
    _camera->setUpVector(CameraSettings::defaultUp);
    _camera->setPosition(CameraSettings::defaultCameraPosition);*/

    //solar rendering
    SolarSkyBox* skybox = new SolarSkyBox(_root);
    skybox->setCamera(_camera);

    //for test the scene
    Qt3DExtras::QFirstPersonCameraController* controller = new Qt3DExtras::QFirstPersonCameraController(_root);
    controller->setCamera(_camera);
    controller->setLookSpeed(controller->lookSpeed() * 2.0f);

    //create all planets
    PlanetsContainer::initialize(_root);
    mathCore->setPlanetsContainer(PlanetsContainer::planets());

    //set root
    setRootEntity(_root);

    //animate scene on tick
    QObject::connect(rootAction, &Qt3DLogic::QFrameAction::triggered, this, &Solar3dViewPort::animate);
}

void SolarSystem::Solar3dViewPort::animate()
{
    mathCore->advanceTime(SolarObjects::SolarSystemView);

    for (int i = 0; i < PlanetsContainer::planetsNumber(); ++i)
        mathCore->solarObjectPosition((SolarObjects)i);
}

