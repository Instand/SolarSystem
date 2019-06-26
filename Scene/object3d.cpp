#include "object3d.h"

#include <Qt3DLogic/QFrameAction>
#include <Qt3DCore/QTransform>
#include <Qt3DRender/QGeometryRenderer>
#include <Qt3DRender/QObjectPicker>
#include <Qt3DRender/QMaterial>

SolarSystem::Object3D::Object3D(Qt3DCore::QNode* parent):
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

    QObject::connect(m_frameAction, &Qt3DLogic::QFrameAction::triggered, this, [this](float deltaTime) {

        //additional actions
        for (const auto& elem : m_logic)
            elem(deltaTime);

        update(deltaTime);

    });
}

void SolarSystem::Object3D::addLogic(SolarSystem::LogicPtr func)
{
    m_logic.push_back(func);
}

void SolarSystem::Object3D::clearLogic()
{
    m_logic.clear();
}

Qt3DCore::QTransform* SolarSystem::Object3D::transform() const
{
    return m_transform;
}

Qt3DRender::QGeometryRenderer* SolarSystem::Object3D::renderer() const
{
    return m_renderer;
}

Qt3DRender::QObjectPicker* SolarSystem::Object3D::picker() const
{
    return m_picker;
}

Qt3DRender::QMaterial* SolarSystem::Object3D::material() const
{
    return m_material;
}

SolarSystem::SolarObjects SolarSystem::Object3D::solarType() const
{
    return m_solarType;
}

void SolarSystem::Object3D::setSolarType(SolarSystem::SolarObjects type)
{
    m_solarType = type;
}

SolarSystem::SolarMaterials SolarSystem::Object3D::materialType() const
{
    return m_materialType;
}

double SolarSystem::Object3D::r() const
{
    return m_r;
}

void SolarSystem::Object3D::setR(double r)
{
    m_r = r;
}

double SolarSystem::Object3D::x() const
{
    return m_x;
}

void SolarSystem::Object3D::setX(double x)
{
    m_x = x;
}

double SolarSystem::Object3D::y() const
{
    return m_y;
}

void SolarSystem::Object3D::setY(double y)
{
    m_y = y;
}

double SolarSystem::Object3D::z() const
{
    return m_z;
}

void SolarSystem::Object3D::setZ(double z)
{
    m_z = z;
}

double SolarSystem::Object3D::roll() const
{
    return m_roll;
}

void SolarSystem::Object3D::setRoll(double roll)
{
    m_roll = roll;
}

double SolarSystem::Object3D::tilt() const
{
    return m_tilt;
}

void SolarSystem::Object3D::setTilt(double tilt)
{
    m_tilt = tilt;
}

QVector3D SolarSystem::Object3D::position() const
{
    return QVector3D(static_cast<float>(m_x), static_cast<float>(m_y), static_cast<float>(m_z));
}

void SolarSystem::Object3D::baseBehaviour()
{
    auto matrix = QMatrix4x4();

    matrix.translate(position());

    matrix.rotate(static_cast<float>(m_tilt), SolarValues::tiltAxis);
    matrix.rotate(static_cast<float>(m_roll), SolarValues::rollAxis);

    matrix.scale(static_cast<float>(m_r));

    m_transform->setMatrix(matrix);
}
