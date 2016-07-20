#include "solar3dobject.h"

SolarSystem::Solar3dObject::Solar3dObject(Qt3DCore::QNode *parent) :
    Qt3DCore::QEntity(parent),
    _transform(new Qt3DCore::QTransform),
    _mesh(new Qt3DRender::QMesh),
    _frame(new Qt3DLogic::QFrameAction),
    _picker(new Qt3DRender::QObjectPicker),
    _material(new Qt3DExtras::QNormalDiffuseSpecularMapMaterial),
    _diffuseImage(new Qt3DRender::QTextureImage),
    _normalImage(new Qt3DRender::QTextureImage)
{

    _material.get()->diffuse()->addTextureImage(_diffuseImage.get());
    _material.get()->normal()->addTextureImage(_normalImage.get());

    addComponent(_transform.get());
    addComponent(_mesh.get());
    addComponent(_frame.get());
    addComponent(_material.get());

    //frame update
    QObject::connect(_frame.get(), SIGNAL(triggered(float)), SLOT(frameTick(float)));
}

Qt3DCore::QTransform &SolarSystem::Solar3dObject::transform() const
{
    return *_transform;
}

Qt3DRender::QMesh &SolarSystem::Solar3dObject::mesh() const
{
    return *_mesh;
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

void SolarSystem::Solar3dObject::frameTick(float deltaTime)
{
    //polymorphic call
    update(deltaTime);

    //tick signal
    emit tick(deltaTime);
}
