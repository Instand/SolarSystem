#include "solarobject3d.h"
#include <Qt3DLogic/QFrameAction>
#include <Qt3DCore/QTransform>
#include <Qt3DRender/QGeometryRenderer>
#include <Qt3DRender/QObjectPicker>
#include <Qt3DRender/QMaterial>

SolarSystem::SolarObject3D::SolarObject3D(Qt3DCore::QNode* parent):
    QEntity(parent)
{
    m_FrameAction = new Qt3DLogic::QFrameAction(this);
    m_Transform = new Qt3DCore::QTransform(this);
    m_Picker = new Qt3DRender::QObjectPicker(this);

    m_Picker->setDragEnabled(false);
    m_Picker->setEnabled(true);

    addComponent(m_FrameAction);
    addComponent(m_Transform);
    addComponent(m_Picker);

    QObject::connect(m_FrameAction, &Qt3DLogic::QFrameAction::triggered, this, [&](float deltaTime) {

        //additional actions
        for (auto elem : m_Logic)
            elem(deltaTime);

        update(deltaTime);

    });
}

void SolarSystem::SolarObject3D::addLogic(SolarSystem::LogicPtr func)
{
    m_Logic.push_back(func);
}

void SolarSystem::SolarObject3D::clearLogic()
{
    m_Logic.clear();
}

Qt3DCore::QTransform* SolarSystem::SolarObject3D::transform() const
{
    return m_Transform;
}

Qt3DRender::QGeometryRenderer* SolarSystem::SolarObject3D::renderer() const
{
    return m_Renderer;
}

Qt3DRender::QObjectPicker* SolarSystem::SolarObject3D::picker() const
{
    return m_Picker;
}

SolarSystem::SolarObjects SolarSystem::SolarObject3D::solarType() const
{
    return m_SolarType;
}

void SolarSystem::SolarObject3D::setSolarType(SolarSystem::SolarObjects type)
{
    m_SolarType = type;
}

SolarSystem::SolarMaterials SolarSystem::SolarObject3D::materialType() const
{
    return m_MaterialType;
}

Qt3DRender::QMaterial* SolarSystem::SolarObject3D::material() const
{
    return m_Material;
}

double SolarSystem::SolarObject3D::r() const
{
    return m_R;
}

void SolarSystem::SolarObject3D::setR(double r)
{
    m_R = r;
}

double SolarSystem::SolarObject3D::x() const
{
    return m_X;
}

void SolarSystem::SolarObject3D::setX(double x)
{
    m_X = x;
}

double SolarSystem::SolarObject3D::y() const
{
    return m_Y;
}

void SolarSystem::SolarObject3D::setY(double y)
{
    m_Y = y;
}

double SolarSystem::SolarObject3D::z() const
{
    return m_Z;
}

void SolarSystem::SolarObject3D::setZ(double z)
{
    m_Z = z;
}

double SolarSystem::SolarObject3D::roll() const
{
    return m_Roll;
}

void SolarSystem::SolarObject3D::setRoll(double roll)
{
    m_Roll = roll;
}

double SolarSystem::SolarObject3D::tilt() const
{
    return m_Tilt;
}

void SolarSystem::SolarObject3D::setTilt(double tilt)
{
    m_Tilt = tilt;
}
