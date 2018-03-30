#include "solarobject3d.h"
#include <Qt3DLogic/QFrameAction>
#include <Qt3DCore/QTransform>
#include <Qt3DRender/QGeometryRenderer>
#include <Qt3DRender/QObjectPicker>
#include <Qt3DRender/QMaterial>

SolarSystem::SolarObject3D::SolarObject3D(Qt3DCore::QNode* parent):
    QEntity(parent)
{
    frameAction_ = new Qt3DLogic::QFrameAction(this);
    transform_ = new Qt3DCore::QTransform(this);
    picker_ = new Qt3DRender::QObjectPicker(this);

    picker_->setDragEnabled(false);
    picker_->setEnabled(true);

    addComponent(frameAction_);
    addComponent(transform_);
    addComponent(picker_);

    QObject::connect(frameAction_, &Qt3DLogic::QFrameAction::triggered, this, [&](float deltaTime) {

        //additional actions
        for (auto elem : logic_)
            elem(deltaTime);

        update(deltaTime);

    });
}

void SolarSystem::SolarObject3D::addLogic(SolarSystem::LogicPtr func)
{
    logic_.push_back(func);
}

void SolarSystem::SolarObject3D::clearLogic()
{
    logic_.clear();
}

Qt3DCore::QTransform* SolarSystem::SolarObject3D::transform() const
{
    return transform_;
}

Qt3DRender::QGeometryRenderer* SolarSystem::SolarObject3D::renderer() const
{
    return renderer_;
}

Qt3DRender::QObjectPicker* SolarSystem::SolarObject3D::picker() const
{
    return picker_;
}

SolarSystem::SolarObjects SolarSystem::SolarObject3D::solarType() const
{
    return solarType_;
}

void SolarSystem::SolarObject3D::setSolarType(SolarSystem::SolarObjects type)
{
    solarType_ = type;
}

SolarSystem::SolarMaterials SolarSystem::SolarObject3D::materialType() const
{
    return materialType_;
}

Qt3DRender::QMaterial* SolarSystem::SolarObject3D::material() const
{
    return material_;
}

double SolarSystem::SolarObject3D::r() const
{
    return r_;
}

void SolarSystem::SolarObject3D::setR(double r)
{
    r_ = r;
}

double SolarSystem::SolarObject3D::x() const
{
    return x_;
}

void SolarSystem::SolarObject3D::setX(double x)
{
    x_ = x;
}

double SolarSystem::SolarObject3D::y() const
{
    return y_;
}

void SolarSystem::SolarObject3D::setY(double y)
{
    y_ = y;
}

double SolarSystem::SolarObject3D::z() const
{
    return z_;
}

void SolarSystem::SolarObject3D::setZ(double z)
{
    z_ = z;
}

double SolarSystem::SolarObject3D::roll() const
{
    return roll_;
}

void SolarSystem::SolarObject3D::setRoll(double roll)
{
    roll_ = roll;
}

double SolarSystem::SolarObject3D::tilt() const
{
    return tilt_;
}

void SolarSystem::SolarObject3D::setTilt(double tilt)
{
    tilt_ = tilt;
}
