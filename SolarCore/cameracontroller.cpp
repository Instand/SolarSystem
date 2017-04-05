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

SolarSystem::CameraController::CameraController(Qt3DCore::QNode *parent):
    Qt3DCore::QEntity(parent),
    frameAction(new Qt3DLogic::QFrameAction()),
    logicalDevice(new Qt3DInput::QLogicalDevice()),
    mouseDevice(new Qt3DInput::QMouseDevice()),
    rightMouseButtonAction(new Qt3DInput::QAction()),
    rightMouseButtonInput(new Qt3DInput::QActionInput()),
    mouseX_Axis(new Qt3DInput::QAxis()),
    mouseY_Axis(new Qt3DInput::QAxis()),
    mouseX_Input(new Qt3DInput::QAnalogAxisInput()),
    mouseY_Input(new Qt3DInput::QAnalogAxisInput()),
    mouseWheelX_Input(new Qt3DInput::QAnalogAxisInput()),
    mouseWheelY_Input(new Qt3DInput::QAnalogAxisInput()),
    mouseWheelX_Axis(new Qt3DInput::QAxis()),
    mouseWheelY_Axis(new Qt3DInput::QAxis())
{
    //right mouse button action
    rightMouseButtonInput->setButtons(QVector<int>({Qt::RightButton}));
    rightMouseButtonInput->setSourceDevice(mouseDevice);
    rightMouseButtonAction->addInput(rightMouseButtonInput);

    //axes

    //mouse X
    mouseX_Input->setAxis(Qt3DInput::QMouseDevice::X);
    mouseX_Input->setSourceDevice(mouseDevice);
    mouseX_Axis->addInput(mouseX_Input);

    //mouse Y
    mouseY_Input->setAxis(Qt3DInput::QMouseDevice::Y);
    mouseY_Input->setSourceDevice(mouseDevice);
    mouseY_Axis->addInput(mouseY_Input);

    //mouse wheel X
    mouseWheelX_Input->setAxis(Qt3DInput::QMouseDevice::WheelX);
    mouseWheelX_Input->setSourceDevice(mouseDevice);
    mouseWheelX_Axis->addInput(mouseWheelX_Input);

    //mouse wheel Y
    mouseWheelY_Input->setAxis(Qt3DInput::QMouseDevice::WheelY);
    mouseWheelY_Input->setSourceDevice(mouseDevice);
    mouseWheelY_Axis->addInput(mouseWheelY_Input);

    //logical device init
    logicalDevice->addAction(rightMouseButtonAction);
    logicalDevice->addAxis(mouseX_Axis);
    logicalDevice->addAxis(mouseY_Axis);
    logicalDevice->addAxis(mouseWheelX_Axis);
    logicalDevice->addAxis(mouseWheelY_Axis);

    QObject::connect(frameAction, &Qt3DLogic::QFrameAction::triggered, this, &CameraController::onFrameAction);
    QObject::connect(this, &CameraController::enabledChanged, logicalDevice, &Qt3DInput::QLogicalDevice::setEnabled);

    //add action and device to components
    addComponent(frameAction);
    addComponent(logicalDevice);
}

SolarSystem::CameraController::~CameraController()
{
    //delete mouseDevice;
}

void SolarSystem::CameraController::setCamera(Qt3DRender::QCamera *camera)
{
    viewCamera = camera;
}

Qt3DRender::QCamera *SolarSystem::CameraController::camera() const
{
    return viewCamera;
}

void SolarSystem::CameraController::setLookSpeed(float lookSpeed)
{
    lookSpeedValue = lookSpeed;
}

float SolarSystem::CameraController::lookSpeed() const
{
    return lookSpeedValue;
}

void SolarSystem::CameraController::setZoomLimit(float limit)
{
    zoomLimitValue = limit;
}

float SolarSystem::CameraController::zoomLimit() const
{
    return zoomLimitValue;
}

void SolarSystem::CameraController::setZoomSpeed(float zoomSpeed)
{
    zoomSpeedValue = zoomSpeed;
}

float SolarSystem::CameraController::zoomSpeed() const
{
    return zoomSpeedValue;
}

void SolarSystem::CameraController::setDefaultZoomLimit()
{
    zoomLimitValue = defaultZoomLimitValue;
}

float SolarSystem::CameraController::defaultZoomLimit() const
{
    return defaultZoomLimitValue;
}

void SolarSystem::CameraController::setDefaultZoomSpeed()
{
    zoomSpeedValue = defaultZoomSpeedValue;
}

float SolarSystem::CameraController::defaultZoomSpeed() const
{
    return defaultZoomSpeedValue;
}

void SolarSystem::CameraController::onFrameAction(float deltaTime)
{
    if (viewCamera != nullptr)
    {
        //right mouse button is pressed
        if (rightMouseButtonAction->isActive())
        {
            viewCamera->panAboutViewCenter(mouseX_Axis->value() * lookSpeedValue * deltaTime, cameraUp);
            viewCamera->tiltAboutViewCenter(mouseY_Axis->value() * lookSpeedValue * deltaTime);
        }

        //zoom check in
        if ((viewCamera->viewCenter() - viewCamera->position()).lengthSquared() > (zoomLimitValue * zoomLimitValue))
        {
            if (mouseWheelY_Axis->value() > 0)
            {
                viewCamera->translate(QVector3D(0, 0, mouseWheelY_Axis->value() * deltaTime * zoomSpeedValue),
                                      Qt3DRender::QCamera::CameraTranslationOption::DontTranslateViewCenter);
            }
        }

        //zoom check out
        if ((viewCamera->viewCenter() - viewCamera->position()).lengthSquared() < (zoomOutLimitValue * zoomOutLimitValue * 1000.0f))
        {
            if (mouseWheelY_Axis->value() < 0)
            {
                viewCamera->translate(QVector3D(0, 0, mouseWheelY_Axis->value() * deltaTime * zoomSpeedValue),
                                      Qt3DRender::QCamera::CameraTranslationOption::DontTranslateViewCenter);
            }
        }
    }
}

void SolarSystem::CameraController::changeViewCenter(QVector3D center)
{
    if (viewCamera != nullptr)
        viewCamera->setViewCenter(center);
    else
        qDebug() << "Camera is null";
}
