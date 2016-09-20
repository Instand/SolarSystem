#include "solar3dobject.h"

SolarSystem::Solar3dObject::Solar3dObject(Qt3DCore::QNode *parent) :
    BaseVisualSolarObject(parent),
    _picker(new Qt3DRender::QObjectPicker),
    _material(new Qt3DExtras::QNormalDiffuseSpecularMapMaterial),
    _diffuseImage(new Qt3DRender::QTextureImage),
    _normalImage(new Qt3DRender::QTextureImage)
{

    _material->diffuse()->addTextureImage(_diffuseImage);
    _material->normal()->addTextureImage(_normalImage);

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

Qt3DRender::QTextureImage &SolarSystem::Solar3dObject::diffuse() const
{
    return *_diffuseImage;
}

Qt3DRender::QTextureImage &SolarSystem::Solar3dObject::normal() const
{
    return *_normalImage;
}
