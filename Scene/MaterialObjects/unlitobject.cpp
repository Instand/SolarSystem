#include "unlitobject.h"
#include <QTextureWrapMode>
#include <QAbstractTexture>
#include <QObjectPicker>

SolarSystem::UnlitObject::UnlitObject(Qt3DCore::QNode* parent):
    SolarObject3D(parent)
{
    m_MaterialType = SolarMaterials::Unlit;
    m_Material = new Qt3DExtras::QTextureMaterial();

    auto mat = qobject_cast<Qt3DExtras::QTextureMaterial*>(m_Material);
    Qt3DRender::QTextureWrapMode wrapMode;

    wrapMode.setX(Qt3DRender::QTextureWrapMode::WrapMode::Repeat);
    wrapMode.setY(Qt3DRender::QTextureWrapMode::WrapMode::Repeat);
    wrapMode.setZ(Qt3DRender::QTextureWrapMode::WrapMode::Repeat);

    mat->texture()->setWrapMode(wrapMode);
    mat->texture()->setGenerateMipMaps(true);
    mat->texture()->setMagnificationFilter(Qt3DRender::QAbstractTexture::Linear);
    mat->texture()->setMinificationFilter(Qt3DRender::QAbstractTexture::LinearMipMapLinear);
    mat->texture()->setMaximumAnisotropy(16.0f);

    m_Picker->setEnabled(false);

    addComponent(m_Material);
}
