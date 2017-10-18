#include "unlitobject.h"
#include <QTextureWrapMode>
#include <QAbstractTexture>

SolarSystem::UnlitObject::UnlitObject(Qt3DCore::QNode* parent):
    Solar3dObject(parent)
{
    _materialType = SolarMaterials::Unlit;
    _material = new Qt3DExtras::QTextureMaterial();

    auto mat = qobject_cast<Qt3DExtras::QTextureMaterial*>(_material);
    Qt3DRender::QTextureWrapMode wrapMode;

    wrapMode.setX(Qt3DRender::QTextureWrapMode::WrapMode::Repeat);
    wrapMode.setY(Qt3DRender::QTextureWrapMode::WrapMode::Repeat);
    wrapMode.setZ(Qt3DRender::QTextureWrapMode::WrapMode::Repeat);

    mat->texture()->setWrapMode(wrapMode);
    mat->texture()->setGenerateMipMaps(true);
    mat->texture()->setMagnificationFilter(Qt3DRender::QAbstractTexture::Linear);
    mat->texture()->setMinificationFilter(Qt3DRender::QAbstractTexture::LinearMipMapLinear);
    mat->texture()->setMaximumAnisotropy(16.0f);

    _picker->setEnabled(false);

    addComponent(_material);
}
