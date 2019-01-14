#include "solarmaterial.h"

SolarSystem::SolarMaterial::SolarMaterial(Qt3DCore::QNode* parent):
    QMaterial(parent)
{
    //main params
    m_ambientColorParam = new Qt3DRender::QParameter(this);
    m_ambientColorParam->setName("ambient");
    m_ambientColorParam->setValue(QVector3D(m_ambientColor.redF(), m_ambientColor.blueF(), m_ambientColor.greenF()));

    m_specularColorParam = new Qt3DRender::QParameter(this);
    m_specularColorParam->setName("specular");
    m_specularColorParam->setValue(QVector3D(m_specularColor.redF(), m_specularColor.blueF(), m_specularColor.greenF()));

    m_shininessParam = new Qt3DRender::QParameter(this);
    m_shininessParam->setName("shininess");
    m_shininessParam->setValue(m_shininess);

    m_textureScaleParam = new Qt3DRender::QParameter(this);
    m_textureScaleParam->setName("texCoordScale");
    m_textureScaleParam->setValue(m_textureScale);

    m_opacityParam = new Qt3DRender::QParameter(this);
    m_opacityParam->setName("opacity");
    m_opacityParam->setValue(m_opacity);

    //create diffuse texture
    m_diffuseTexture2D = new Qt3DRender::QTexture2D();
    m_diffuseTexture2D->setMinificationFilter(Qt3DRender::QAbstractTexture::LinearMipMapLinear);
    m_diffuseTexture2D->setMagnificationFilter(Qt3DRender::QAbstractTexture::Linear);
    m_diffuseTexture2D->wrapMode()->setX(Qt3DRender::QTextureWrapMode::Repeat);
    m_diffuseTexture2D->wrapMode()->setY(Qt3DRender::QTextureWrapMode::Repeat);
    m_diffuseTexture2D->setGenerateMipMaps(true);
    m_diffuseTexture2D->setMaximumAnisotropy(16.0f);

    //create diffuse image
    m_diffuseImage = new Qt3DRender::QTextureImage(m_diffuseTexture2D);
    m_diffuseImage->setSource(m_diffuseTextureSource);

    //create texture parameter
    m_diffuseTexture2D->addTextureImage(m_diffuseImage);
    m_diffuseTextureParam = new Qt3DRender::QParameter("diffuseTexture", m_diffuseTexture2D, this);

    m_normalTexture2D = new Qt3DRender::QTexture2D();
    m_normalTexture2D->setMinificationFilter(Qt3DRender::QAbstractTexture::Linear);
    m_normalTexture2D->setMagnificationFilter(Qt3DRender::QAbstractTexture::Linear);
    m_normalTexture2D->wrapMode()->setX(Qt3DRender::QTextureWrapMode::Repeat);
    m_normalTexture2D->wrapMode()->setY(Qt3DRender::QTextureWrapMode::Repeat);
    m_normalTexture2D->setMaximumAnisotropy(16.0f);

    //create normal image
    m_normalImage = new Qt3DRender::QTextureImage(m_normalTexture2D);
    m_normalImage->setSource(m_normalTextureSource);

    //create normal parameter
    m_normalTexture2D->addTextureImage(m_normalImage);
    m_normalTextureParam = new Qt3DRender::QParameter("normalTexture", m_normalTexture2D, this);

    addParameter(m_ambientColorParam);
    addParameter(m_specularColorParam);
    addParameter(m_shininessParam);
    addParameter(m_textureScaleParam);
    addParameter(m_opacityParam);
    addParameter(m_diffuseTextureParam);
    addParameter(m_normalTextureParam);
}

QColor SolarSystem::SolarMaterial::ambientColor() const
{
    return m_ambientColor;
}

QColor SolarSystem::SolarMaterial::specularColor() const
{
    return m_specularColor;
}

QString SolarSystem::SolarMaterial::diffuseTextureSource() const
{
    return m_diffuseTextureSource;
}

QString SolarSystem::SolarMaterial::normalTextureSource() const
{
    return m_normalTextureSource;
}

float SolarSystem::SolarMaterial::shininess() const
{
    return m_shininess;
}

float SolarSystem::SolarMaterial::textureScale() const
{
    return m_textureScale;
}

float SolarSystem::SolarMaterial::opacity() const
{
    return m_opacity;
}

void SolarSystem::SolarMaterial::setAmbient(QColor color)
{
    m_ambientColor = color;
    m_ambientColorParam->setValue(QVector3D(color.redF(), color.blueF(), color.greenF()));
}

void SolarSystem::SolarMaterial::setSpecular(QColor color)
{
    m_specularColor = color;
    m_specularColorParam->setValue(QVector3D(color.redF(), color.blueF(), color.greenF()));
}

void SolarSystem::SolarMaterial::setDiffuseTextureSource(const QString& source)
{
    m_diffuseTextureSource = source;
    m_diffuseImage->setSource(QUrl::fromLocalFile(source));
}

void SolarSystem::SolarMaterial::setNormalTextureSource(const QString &source)
{
    m_normalTextureSource = source;
    m_normalImage->setSource(QUrl::fromLocalFile(source));
}

void SolarSystem::SolarMaterial::setSnininess(float value)
{
    m_shininess = value;
    m_shininessParam->setValue(value);
}

void SolarSystem::SolarMaterial::setTextureScale(float scale)
{
    m_textureScale = scale;
    m_textureScaleParam->setValue(scale);
}

void SolarSystem::SolarMaterial::setOpacity(float opacity)
{
    m_opacity = opacity;
    m_opacityParam->setValue(opacity);
}
