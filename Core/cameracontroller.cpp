#include "cameracontroller.h"
#include <Qt3DRender/QCamera>
#include <Qt3DLogic/QFrameAction>
#include <Qt3DInput/QLogicalDevice>
#include <Qt3DInput/QMouseDevice>
#include <Qt3DInput/QAction>
#include <Qt3DInput/QActionInput>
#include <Qt3DInput/QAxis>
#include <Qt3DInput/QAnalogAxisInput>
#include <QDebug>

SolarSystem::CameraController::CameraController(Qt3DCore::QNode* parent):
    Qt3DCore::QEntity(parent),
    m_logicalDevice(new Qt3DInput::QLogicalDevice(this)),
    m_mouseDevice(new Qt3DInput::QMouseDevice(this)),
    m_mouseButtonAction(new Qt3DInput::QAction(this)),
    m_mouseButtonInput(new Qt3DInput::QActionInput(this)),
    m_mouseXAxis(new Qt3DInput::QAxis(this)),
    m_mouseYAxis(new Qt3DInput::QAxis(this)),
    m_mouseXInput(new Qt3DInput::QAnalogAxisInput(this)),
    m_mouseYInput(new Qt3DInput::QAnalogAxisInput(this)),
    m_mouseWheelXInput(new Qt3DInput::QAnalogAxisInput(this)),
    mouseWheelYInput(new Qt3DInput::QAnalogAxisInput(this)),
    m_mouseWheelXAxis(new Qt3DInput::QAxis(this)),
    m_mouseWheelYAxis(new Qt3DInput::QAxis(this))
{
#ifdef Q_OS_ANDROID
    m_mouseButtonInput->setButtons(QVector<int>({Qt::LeftButton}));
#else
    m_mouseButtonInput->setButtons(QVector<int>({Qt::RightButton}));
#endif

    m_mouseButtonInput->setSourceDevice(m_mouseDevice);
    m_mouseButtonAction->addInput(m_mouseButtonInput);

    // axes

    // mouse X
    m_mouseXInput->setAxis(Qt3DInput::QMouseDevice::X);
    m_mouseXInput->setSourceDevice(m_mouseDevice);
    m_mouseXAxis->addInput(m_mouseXInput);

    // mouse Y
    m_mouseYInput->setAxis(Qt3DInput::QMouseDevice::Y);
    m_mouseYInput->setSourceDevice(m_mouseDevice);
    m_mouseYAxis->addInput(m_mouseYInput);

    // mouse wheel X
    m_mouseWheelXInput->setAxis(Qt3DInput::QMouseDevice::WheelX);
    m_mouseWheelXInput->setSourceDevice(m_mouseDevice);
    m_mouseWheelXAxis->addInput(m_mouseWheelXInput);

    // mouse wheel Y
    mouseWheelYInput->setAxis(Qt3DInput::QMouseDevice::WheelY);
    mouseWheelYInput->setSourceDevice(m_mouseDevice);
    m_mouseWheelYAxis->addInput(mouseWheelYInput);

    // logical device init
    m_logicalDevice->addAction(m_mouseButtonAction);
    m_logicalDevice->addAxis(m_mouseXAxis);
    m_logicalDevice->addAxis(m_mouseYAxis);
    m_logicalDevice->addAxis(m_mouseWheelXAxis);
    m_logicalDevice->addAxis(m_mouseWheelYAxis);

    // tick component
    Qt3DLogic::QFrameAction* frameAction = new Qt3DLogic::QFrameAction(this);

    QObject::connect(frameAction, &Qt3DLogic::QFrameAction::triggered, this, &CameraController::onFrameAction);
    QObject::connect(this, &CameraController::enabledChanged, m_logicalDevice, &Qt3DInput::QLogicalDevice::setEnabled);

    addComponent(m_logicalDevice);
    addComponent(frameAction);
}

void SolarSystem::CameraController::setCamera(Qt3DRender::QCamera* camera)
{
    m_viewCamera = camera;
}

Qt3DRender::QCamera* SolarSystem::CameraController::camera() const
{
    return m_viewCamera;
}

void SolarSystem::CameraController::setLookSpeed(float lookSpeed)
{
    m_lookSpeedValue = lookSpeed;
}

float SolarSystem::CameraController::lookSpeed() const
{
    return m_lookSpeedValue;
}

void SolarSystem::CameraController::setZoomLimit(float limit)
{
    m_zoomLimitValue = limit;
}

float SolarSystem::CameraController::zoomLimit() const
{
    return m_zoomLimitValue;
}

void SolarSystem::CameraController::setZoomSpeed(float zoomSpeed)
{
    m_zoomSpeedValue = zoomSpeed;
}

float SolarSystem::CameraController::zoomSpeed() const
{
    return m_zoomSpeedValue;
}

void SolarSystem::CameraController::setDefaultZoomLimit()
{
    m_zoomLimitValue = m_defaultZoomLimitValue;
}

float SolarSystem::CameraController::defaultZoomLimit() const
{
    return m_defaultZoomLimitValue;
}

void SolarSystem::CameraController::setDefaultZoomSpeed()
{
    m_zoomSpeedValue = m_defaultZoomSpeedValue;
}

float SolarSystem::CameraController::defaultZoomSpeed() const
{
    return m_defaultZoomSpeedValue;
}

void SolarSystem::CameraController::onFrameAction(float deltaTime)
{
    if (m_viewCamera != nullptr)
    {
        // right mouse button is pressed/ or touch on mobile
        if (m_mouseButtonAction->isActive())
        {
            m_viewCamera->panAboutViewCenter(m_mouseXAxis->value() * m_lookSpeedValue * deltaTime, m_cameraUp);
            m_viewCamera->tiltAboutViewCenter(m_mouseYAxis->value() * m_lookSpeedValue * deltaTime);
        }

        // zoom check in
        if ((m_viewCamera->viewCenter() - m_viewCamera->position()).lengthSquared() > (m_zoomLimitValue * m_zoomLimitValue))
        {
            if (m_mouseWheelYAxis->value() > 0)
            {
                m_viewCamera->translate(QVector3D(0, 0, m_mouseWheelYAxis->value() * deltaTime * m_zoomSpeedValue),
                                      Qt3DRender::QCamera::CameraTranslationOption::DontTranslateViewCenter);
            }
        }

        // zoom check out
        if ((m_viewCamera->viewCenter() - m_viewCamera->position()).lengthSquared() < (m_zoomOutLimitValue * m_zoomOutLimitValue * 1000.0f))
        {
            if (m_mouseWheelYAxis->value() < 0)
            {
                m_viewCamera->translate(QVector3D(0, 0, m_mouseWheelYAxis->value() * deltaTime * m_zoomSpeedValue),
                                      Qt3DRender::QCamera::CameraTranslationOption::DontTranslateViewCenter);
            }
        }
    }
}

void SolarSystem::CameraController::changeViewCenter(const QVector3D& center)
{
    m_viewCamera->setViewCenter(center);
}
