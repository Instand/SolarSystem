#include "solarentity.h"

#include <dbconnector.h>

#include <Scene/SceneObjects/solarskybox.h>

#include <Core/cameracontroller.h>
#include <Core/object3dcontainer.h>
#include <Core/Render/solarforwardframegraph.h>
#include <Core/Render/solarstandardframegraph.h>

#include <Parser/solarparser.h>

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
    MathCore::instance()->setCamera(m_camera);
    MathCore::instance()->setCameraController(controller);
    MathCore::instance()->setSolarSystemSpeed(SolarSystem::SolarValues::startSpeed);
    MathCore::instance()->changeSolarSystemScale(SolarSystem::SolarValues::startSize);

    m_animator = new Animator(this);

    QObject::connect(m_rootAction, &Qt3DLogic::QFrameAction::triggered, m_animator, &Animator::animate);
    QObject::connect(MathCore::instance(), &MathCore::solarTimeChanged, this, &SolarEntity::timeChanged);
    QObject::connect(m_animator, &Animator::currentObjectChanged, this, &SolarEntity::onAnimatedObjectChanged);
}

Qt3DRender::QCamera* SolarSystem::SolarEntity::camera() const
{
    return m_camera;
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

QString SolarSystem::SolarEntity::currentObjectString() const
{
    return SolarParser::parseSolarObjectToString(m_animator->currentObject());
}

QString SolarSystem::SolarEntity::info() const
{
    auto columnNames = DBConnector::instance().columnNames();
    auto objParameters = DBConnector::instance().info(m_animator->currentObject());
    auto dbFieldsParamsCount = DbParams::paramList.size();
    auto str = QString();

    if (columnNames.size() != objParameters.size() || columnNames.size() != dbFieldsParamsCount
            || dbFieldsParamsCount != objParameters.size())
    {
        qDebug() << "Something wrong in DB connector";
        qDebug() << columnNames.size() << " != " << objParameters.size();

        return str;
    }

    // fill info sheet
    for (int i = 0; i < columnNames.size(); ++i)
        str.append(columnNames[i] + ":  " + objParameters[i] + " " + DbParams::paramList[i] + "\n\n");

    return str;
}

double SolarSystem::SolarEntity::extraSpeed() const
{
    return MathCore::instance()->extraSpeed();
}

void SolarSystem::SolarEntity::setSolarSpeed(int value)
{
    auto coeff = 0.02f * value;
    MathCore::instance()->setSolarSystemSpeed(SolarValues::startSpeed * coeff);
}

void SolarSystem::SolarEntity::setSolarSize(int value)
{
    float coeff = value/50.0f;
    MathCore::instance()->changeSolarSystemScale(SolarValues::startSize * coeff);
}

void SolarSystem::SolarEntity::setViewCenter(int index)
{
    auto object = SolarParser::parsePlanetListIndex(index);
    m_animator->animateCamera(object);
}

void SolarSystem::SolarEntity::setEventSource(QObject* object)
{
    m_inputSettings->setEventSource(object);
}

void SolarSystem::SolarEntity::changeExtraSpeed()
{
    MathCore::instance()->changeExtraSpeed();
    emit extraSpeedChanged(MathCore::instance()->extraSpeed());
}

void SolarSystem::SolarEntity::resetExtraSpeed()
{
    MathCore::instance()->resetExtraSpeed();
    emit extraSpeedChanged(MathCore::instance()->extraSpeed());
}

void SolarSystem::SolarEntity::onAnimatedObjectChanged(SolarSystem::SolarObjects object)
{
    emit currentObjectStringChanged(SolarParser::parseSolarObjectToString(object));
}
