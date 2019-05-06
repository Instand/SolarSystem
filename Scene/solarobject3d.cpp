#include "solarobject3d.h"
#include <Qt3DLogic/QFrameAction>
#include <Qt3DCore/QTransform>
#include <Qt3DRender/QGeometryRenderer>
#include <Qt3DRender/QObjectPicker>
#include <Qt3DRender/QMaterial>

SolarSystem::SolarObject3D::SolarObject3D(Qt3DCore::QNode* parent):
    QEntity(parent)
{
    m_frameAction = new Qt3DLogic::QFrameAction(this);
    m_transform = new Qt3DCore::QTransform(this);
    m_picker = new Qt3DRender::QObjectPicker(this);

    m_picker->setDragEnabled(false);
    m_picker->setEnabled(true);

    addComponent(m_frameAction);
    addComponent(m_transform);
    addComponent(m_picker);

    QObject::connect(m_frameAction, &Qt3DLogic::QFrameAction::triggered, this, [&](float deltaTime) {

        //additional actions
        for (auto elem : m_logic)
            elem(deltaTime);

        update(deltaTime);

    });
}

void SolarSystem::SolarObject3D::addLogic(SolarSystem::LogicPtr func)
{
    m_logic.push_back(func);
}

void SolarSystem::SolarObject3D::clearLogic()
{
    m_logic.clear();
}

Qt3DCore::QTransform* SolarSystem::SolarObject3D::transform() const
{
    return m_transform;
}

Qt3DRender::QGeometryRenderer* SolarSystem::SolarObject3D::renderer() const
{
    return m_renderer;
}

Qt3DRender::QObjectPicker* SolarSystem::SolarObject3D::picker() const
{
    return m_picker;
}

SolarSystem::SolarObjects SolarSystem::SolarObject3D::solarType() const
{
    return m_solarType;
}

void SolarSystem::SolarObject3D::setSolarType(SolarSystem::SolarObjects type)
{
    m_solarType = type;
}

SolarSystem::SolarMaterials SolarSystem::SolarObject3D::materialType() const
{
    return m_materialType;
}

Qt3DRender::QMaterial* SolarSystem::SolarObject3D::material() const
{
    return m_material;
}

double SolarSystem::SolarObject3D::r() const
{
    return m_r;
}

void SolarSystem::SolarObject3D::setR(double r)
{
    m_r = r;
}

double SolarSystem::SolarObject3D::x() const
{
    return m_x;
}

void SolarSystem::SolarObject3D::setX(double x)
{
    m_x = x;
}

double SolarSystem::SolarObject3D::y() const
{
    return m_y;
}

void SolarSystem::SolarObject3D::setY(double y)
{
    m_y = y;
}

double SolarSystem::SolarObject3D::z() const
{
    return m_z;
}

void SolarSystem::SolarObject3D::setZ(double z)
{
    m_z = z;
}

double SolarSystem::SolarObject3D::roll() const
{
    return m_roll;
}

void SolarSystem::SolarObject3D::setRoll(double roll)
{
    m_roll = roll;
}

double SolarSystem::SolarObject3D::tilt() const
{
    return m_tilt;
}

void SolarSystem::SolarObject3D::setTilt(double tilt)
{
    m_tilt = tilt;
}

QVector3D SolarSystem::SolarObject3D::position() const
{
    return QVector3D(static_cast<float>(m_x), static_cast<float>(m_y), static_cast<float>(m_z));
}
