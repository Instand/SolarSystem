#include "basevisualsolarobject.h"

SolarSystem::BaseVisualSolarObject::BaseVisualSolarObject(Qt3DCore::QNode* parent):
    VisualSolarObject(parent),
    _transform(new Qt3DCore::QTransform(this)),
    _mesh(new Qt3DRender::QMesh(this))
{
    addComponent(_transform);
    addComponent(_mesh);
}

Qt3DCore::QTransform &SolarSystem::BaseVisualSolarObject::transform() const
{
    return *_transform;
}

Qt3DRender::QMesh &SolarSystem::BaseVisualSolarObject::mesh() const
{
    return *_mesh;
}
