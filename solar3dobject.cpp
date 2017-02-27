#include "solar3dobject.h"

SolarSystem::Solar3dObject::Solar3dObject(Qt3DCore::QNode *parent):
    BaseVisualSolarObject(parent),
    _picker(new Qt3DRender::QObjectPicker),
    _material(new Qt3DExtras::QNormalDiffuseSpecularMapMaterial),
    _diffuse(new Qt3DRender::QTextureImage())
{
    _material->diffuse()->addTextureImage(_diffuse);

    _picker->setDragEnabled(false);
    _picker->setHoverEnabled(false);
    _picker->setEnabled(true);

    addComponent(_material);
    addComponent(_picker);
}

Qt3DRender::QObjectPicker &SolarSystem::Solar3dObject::picker() const
{
    return *_picker;
}

Qt3DExtras::QNormalDiffuseSpecularMapMaterial &SolarSystem::Solar3dObject::material() const
{
    return *_material;
}

Qt3DRender::QTextureImage& SolarSystem::Solar3dObject::diffuse() const
{
    return *_diffuse;
}
