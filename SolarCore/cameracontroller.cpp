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
    logicalDevice(new Qt3DInput::QLogicalDevice(this)),
    mouseDevice(new Qt3DInput::QMouseDevice(this)),
    mouseButtonAction(new Qt3DInput::QAction(this)),
    mouseButtonInput(new Qt3DInput::QActionInput(this)),
    mouseX_Axis(new Qt3DInput::QAxis(this)),
    mouseY_Axis(new Qt3DInput::QAxis(this)),
    mouseX_Input(new Qt3DInput::QAnalogAxisInput(this)),
    mouseY_Input(new Qt3DInput::QAnalogAxisInput(this)),
    mouseWheelX_Input(new Qt3DInput::QAnalogAxisInput(this)),
    mouseWheelY_Input(new Qt3DInput::QAnalogAxisInput(this)),
    mouseWheelX_Axis(new Qt3DInput::QAxis(this)),
    mouseWheelY_Axis(new Qt3DInput::QAxis(this))
{
#ifdef Q_OS_ANDROID
    mouseButtonInput->setButtons(QVector<int>({Qt::LeftButton}));
#else
    mouseButtonInput->setButtons(QVector<int>({Qt::RightButton}));
#endif

    mouseButtonInput->setSourceDevice(mouseDevice);
    mouseButtonAction->addInput(mouseButtonInput);

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
    logicalDevice->addAction(mouseButtonAction);
    logicalDevice->addAxis(mouseX_Axis);
    logicalDevice->addAxis(mouseY_Axis);
    logicalDevice->addAxis(mouseWheelX_Axis);
    logicalDevice->addAxis(mouseWheelY_Axis);

    //tick component
    Qt3DLogic::QFrameAction* frameAction = new Qt3DLogic::QFrameAction(this);

    QObject::connect(frameAction, &Qt3DLogic::QFrameAction::triggered, this, &CameraController::onFrameAction);
    QObject::connect(this, &CameraController::enabledChanged, logicalDevice, &Qt3DInput::QLogicalDevice::setEnabled);

    addComponent(logicalDevice);
    addComponent(frameAction);
}

void SolarSystem::CameraController::setCamera(Qt3DRender::QCamera* camera)
{
    viewCamera = camera;
}

Qt3DRender::QCamera* SolarSystem::CameraController::camera() const
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
        //right mouse button is pressed/ or touch on mobile
        if (mouseButtonAction->isActive())
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

void SolarSystem::CameraController::changeViewCenter(const QVector3D& center)
{
    viewCamera->setViewCenter(center);
}
