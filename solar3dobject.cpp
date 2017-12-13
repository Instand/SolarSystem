#include "solar3dobject.h"

SolarSystem::Solar3dObject::Solar3dObject(Qt3DCore::QNode* parent):
    BaseVisualSolarObject(parent),
    _picker(new Qt3DRender::QObjectPicker())
{
    _picker->setDragEnabled(false);
    _picker->setEnabled(true);

    addComponent(_picker);
}

Qt3DRender::QObjectPicker* SolarSystem::Solar3dObject::picker() const
{
    return _picker;
}

Qt3DRender::QMaterial* SolarSystem::Solar3dObject::material() const
{
    return _material;
}
