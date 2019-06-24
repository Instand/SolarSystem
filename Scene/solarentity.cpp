#include "solarentity.h"

#include <dbconnector.h>

#include <Scene/SceneObjects/solarskybox.h>

#include <Core/cameracontroller.h>
#include <Core/object3dcontainer.h>
#include <Core/Render/solarforwardframegraph.h>
#include <Core/Render/solarstandardframegraph.h>

SolarSystem::SolarEntity::SolarEntity(QNode* parent):
    Qt3DCore::QEntity(parent),
    m_rootAction(new Qt3DLogic::QFrameAction()),
    m_object3DContainer(new Object3DContainer(this)),
    m_fpsCounter(new FpsCounter(this))
{
    DBConnector::instance();

    addComponent(m_rootAction);

    // scene camera setup
    m_camera = new Qt3DRender::QCamera(this);
    m_camera->setProjectionType(Qt3DRender::QCameraLens::PerspectiveProjection);
    m_camera->setViewCenter(QVector3D(0.0f, 3.5f, 0.0f));

    m_camera->setFieldOfView(CameraSettings::fieldOfView);
    m_camera->setNearPlane(CameraSettings::nearPlane * 0.0001f);
    m_camera->setFarPlane(CameraSettings::farPlane);
    m_camera->setUpVector(CameraSettings::defaultUp);
    m_camera->setPosition(CameraSettings::defaultCameraPosition);

    // orbit camera controller
    auto controller = new SolarSystem::CameraController(this);
    controller->setCamera(m_camera);
    controller->setLookSpeed(controller->lookSpeed() * 1.2f);

    m_skybox = new SolarSkyBox(this);

    // frame graph
    m_frameGraph = new SolarStandardFrameGraph(this);
    m_frameGraph->setCamera(m_camera);

    m_inputSettings = new Qt3DInput::QInputSettings();

    addComponent(m_frameGraph);
    addComponent(m_inputSettings);

    // math core control
    MathCore::instance()->setObject3DContainer(m_object3DContainer);
    MathCore::instance()->setSolarView(m_camera);
    MathCore::instance()->setCameraController(controller);
    MathCore::instance()->setSolarSystemSpeed(SolarSystem::SolarValues::startSpeed);
    MathCore::instance()->changeSolarSystemScale(SolarSystem::SolarValues::startSize);

    m_animator = new SolarAnimator(this);

    QObject::connect(m_rootAction, &Qt3DLogic::QFrameAction::triggered, m_animator, &SolarAnimator::animate);
    QObject::connect(m_animator, &SolarAnimator::solarTimeChanged, this, &SolarEntity::timeChanged);
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
    return DBConnector::instance().status() && DBConnector::instance().isOpen();
}

QDateTime SolarSystem::SolarEntity::time() const
{
    return MathCore::instance()->getTime();
}
