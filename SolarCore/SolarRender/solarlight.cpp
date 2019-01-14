#include "solarlight.h"
#include <Qt3DRender/QCamera>
#include <solarsystemcore.h>

SolarSystem::SolarLight::SolarLight(Qt3DCore::QNode* parent):
    Qt3DCore::QEntity(parent),
    m_lightCamera(new Qt3DRender::QCamera(this)),
    m_intensity(1.0f, 1.0f, 1.0f)
{
    //setup camera
    m_lightCamera->setObjectName("lightCameraLens");
    m_lightCamera->setProjectionType(Qt3DRender::QCameraLens::ProjectionType::PerspectiveProjection);
    m_lightCamera->setFieldOfView(30);
    m_lightCamera->setNearPlane(CameraSettings::nearPlane * 0.0001f);
    m_lightCamera->setFarPlane(10000000.0f);
    m_lightCamera->setPosition(QVector3D(0, 0, 0));
    m_lightCamera->setViewCenter(QVector3D(0, 0, 0));
    m_lightCamera->setUpVector(CameraSettings::defaultUp);
}

Qt3DRender::QCamera* SolarSystem::SolarLight::camera() const
{
    return m_lightCamera;
}

QMatrix4x4 SolarSystem::SolarLight::lightViewProjection() const
{
    return m_lightCamera->projectionMatrix() * m_lightCamera->viewMatrix();
}

QVector3D SolarSystem::SolarLight::intensity() const
{
    return m_intensity;
}

void SolarSystem::SolarLight::setIntensity(const QVector3D &intensity)
{
    m_intensity = intensity;
}
