#include "solar3dobject.h"

SolarSystem::Solar3dObject::Solar3dObject(Qt3DCore::QNode* parent):
    BaseVisualSolarObject(parent),
    _picker(new Qt3DRender::QObjectPicker()),
#ifdef QT3D_MATERIALS
    _material(new Qt3DExtras::QNormalDiffuseSpecularMapMaterial()),
    _diffuse(new Qt3DRender::QTextureImage())
#else
    _material(new SolarMaterial())
#endif
{
    _picker->setDragEnabled(false);
    _picker->setHoverEnabled(false);
    _picker->setEnabled(true);

#ifdef QT3D_MATERIALS
    _material->diffuse()->addTextureImage(_diffuse);
#endif

    addComponent(_material);
    addComponent(_picker);
}

Qt3DRender::QObjectPicker& SolarSystem::Solar3dObject::picker() const
{
    return *_picker;
}

#ifndef QT3D_MATERIALS
SolarSystem::SolarMaterial& SolarSystem::Solar3dObject::material() const
{
    return *_material;
}
#else
Qt3DExtras::QNormalDiffuseSpecularMapMaterial& SolarSystem::Solar3dObject::material() const
{
    return *_material;
}

Qt3DRender::QTextureImage& SolarSystem::Solar3dObject::diffuse() const
{
    return *_diffuse;
}
#endif
