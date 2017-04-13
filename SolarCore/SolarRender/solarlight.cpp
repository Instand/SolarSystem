#include "solarlight.h"
#include <Qt3DRender/QCamera>
#include <solarsystemcore.h>

SolarSystem::SolarLight::SolarLight(Qt3DCore::QNode* parent):
    Qt3DCore::QEntity(parent),
    lightCamera(new Qt3DRender::QCamera(this)),
    _intensity(1.0f, 1.0f, 1.0f)
{
    //setup camera
    lightCamera->setObjectName("lightCameraLens");
    lightCamera->setProjectionType(Qt3DRender::QCameraLens::ProjectionType::PerspectiveProjection);
    lightCamera->setFieldOfView(45);
    lightCamera->setNearPlane(CameraSettings::nearPlane * 0.0001f);
    lightCamera->setFarPlane(10000000.0f);
    lightCamera->setPosition(QVector3D(0, 0, 0));
    lightCamera->setViewCenter(QVector3D(0, 0, 0));
    lightCamera->setUpVector(CameraSettings::defaultUp);
}

Qt3DRender::QCamera* SolarSystem::SolarLight::camera() const
{
    return lightCamera;
}

QMatrix4x4 SolarSystem::SolarLight::lightViewProjection() const
{
    return lightCamera->projectionMatrix() * lightCamera->viewMatrix();
}

QVector3D SolarSystem::SolarLight::intensity() const
{
    return _intensity;
}

void SolarSystem::SolarLight::setIntensity(const QVector3D &intensity)
{
    _intensity = intensity;
}
