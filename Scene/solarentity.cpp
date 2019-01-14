#include "solarentity.h"
#include <SolarCore/cameracontroller.h>
#include <Scene/SceneObjects/solarskybox.h>
#include <solarsystemdbconnector.h>
#include <SolarCore/planetscontainer.h>
#include <SolarCore/SolarRender/solarforwardframegraph.h>
#include <SolarCore/SolarRender/solarstandardframegraph.h>

SolarSystem::SolarEntity::SolarEntity(QNode* parent):
    Qt3DCore::QEntity(parent),
    m_rootAction(new Qt3DLogic::QFrameAction()),
    m_planetsContainer(new PlanetsContainer(this)),
    m_fpsCounter(new FpsCounter(this))
{
    SolarSystemDBConnector::instance();

    addComponent(m_rootAction);

    //scene camera setup
    m_camera = new Qt3DRender::QCamera(this);
    m_camera->setProjectionType(Qt3DRender::QCameraLens::PerspectiveProjection);
    m_camera->setViewCenter(QVector3D(0.0f, 3.5f, 0.0f));

    m_camera->setFieldOfView(CameraSettings::fieldOfView);
    m_camera->setNearPlane(CameraSettings::nearPlane * 0.0001f);
    m_camera->setFarPlane(CameraSettings::farPlane);
    m_camera->setUpVector(CameraSettings::defaultUp);
    m_camera->setPosition(CameraSettings::defaultCameraPosition);

    //orbit camera controller
    auto controller = new SolarSystem::CameraController(this);
    controller->setCamera(m_camera);
    controller->setLookSpeed(controller->lookSpeed() * 1.2f);

    //skybox
    m_skybox = new SolarSkyBox(this);

    //frame graph
    m_frameGraph = new SolarForwardFrameGraph(this);
    m_frameGraph->setCamera(m_camera);    

    m_inputSettings = new Qt3DInput::QInputSettings();

    addComponent(m_frameGraph);
    addComponent(m_inputSettings);

    //math core control
    SolarMathCore::instance()->setPlanetsContainer(m_planetsContainer);
    SolarMathCore::instance()->setSolarView(m_camera);
    SolarMathCore::instance()->setCameraController(controller);
    SolarMathCore::instance()->setSolarSystemSpeed(SolarSystem::SolarValues::startSpeed);
    SolarMathCore::instance()->changeSolarSystemScale(SolarSystem::SolarValues::startSize);

    m_animator = new SolarAnimator(this);

    //animate scene on tick
    QObject::connect(m_rootAction, &Qt3DLogic::QFrameAction::triggered, m_animator, &SolarAnimator::animate);
}

SolarSystem::SolarEntity::~SolarEntity()
{
    delete m_planetsContainer;
}

SolarSystem::SolarAnimator* SolarSystem::SolarEntity::animator() const
{
    return m_animator;
}

Qt3DRender::QCamera* SolarSystem::SolarEntity::camera() const
{
    return m_camera;
}

Qt3DInput::QInputSettings* SolarSystem::SolarEntity::inputSettings() const
{
    return m_inputSettings;
}

SolarSystem::FpsCounter* SolarSystem::SolarEntity::counter() const
{
    return m_fpsCounter;
}

bool SolarSystem::SolarEntity::databaseStatus() const
{
    return SolarSystemDBConnector::instance().status() && SolarSystemDBConnector::instance().isOpen();
}
