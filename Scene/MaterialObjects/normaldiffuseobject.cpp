#include "normaldiffuseobject.h"
#include <QTextureWrapMode>
#include <QAbstractTexture>

SolarSystem::NormalDiffuseObject::NormalDiffuseObject(Qt3DCore::QNode* parent):
    Object3D(parent)
{
    m_materialType = SolarMaterials::NormalDiffuse;
    m_material = new Qt3DExtras::QNormalDiffuseMapMaterial();

    auto mat = qobject_cast<Qt3DExtras::QNormalDiffuseMapMaterial*>(m_material);
    Qt3DRender::QTextureWrapMode wrapMode;

    mat->diffuse()->setWrapMode(wrapMode);
    mat->diffuse()->setGenerateMipMaps(true);
    mat->diffuse()->setMagnificationFilter(Qt3DRender::QAbstractTexture::Linear);
    mat->diffuse()->setMinificationFilter(Qt3DRender::QAbstractTexture::LinearMipMapLinear);
    mat->diffuse()->setMaximumAnisotropy(16.0f);

    mat->normal()->setWrapMode(wrapMode);
    mat->normal()->setMagnificationFilter(Qt3DRender::QAbstractTexture::Linear);
    mat->normal()->setMinificationFilter(Qt3DRender::QAbstractTexture::Linear);
    mat->normal()->setMaximumAnisotropy(16.0f);

    addComponent(m_material);
}
