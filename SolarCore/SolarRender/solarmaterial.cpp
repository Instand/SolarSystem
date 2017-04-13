#include "solarmaterial.h"

SolarSystem::SolarMaterial::SolarMaterial(Qt3DCore::QNode* parent):
    QMaterial(parent)
{
    //main params
    ambientColorParam = new Qt3DRender::QParameter(this);
    ambientColorParam->setName("ambient");
    ambientColorParam->setValue(QVector3D(_ambientColor.redF(), _ambientColor.blueF(), _ambientColor.greenF()));

    specularColorParam = new Qt3DRender::QParameter(this);
    specularColorParam->setName("specular");
    specularColorParam->setValue(QVector3D(_specularColor.redF(), _specularColor.blueF(), _specularColor.greenF()));

    shininessParam = new Qt3DRender::QParameter(this);
    shininessParam->setName("shininess");
    shininessParam->setValue(_shininess);

    textureScaleParam = new Qt3DRender::QParameter(this);
    textureScaleParam->setName("texCoordScale");
    textureScaleParam->setValue(_textureScale);

    opacityParam = new Qt3DRender::QParameter(this);
    opacityParam->setName("opacity");
    opacityParam->setValue(_opacity);

    //create diffuse texture
    diffuseTexture2D = new Qt3DRender::QTexture2D();
    diffuseTexture2D->setMinificationFilter(Qt3DRender::QAbstractTexture::LinearMipMapLinear);
    diffuseTexture2D->setMagnificationFilter(Qt3DRender::QAbstractTexture::Linear);
    diffuseTexture2D->wrapMode()->setX(Qt3DRender::QTextureWrapMode::Repeat);
    diffuseTexture2D->wrapMode()->setY(Qt3DRender::QTextureWrapMode::Repeat);
    diffuseTexture2D->setGenerateMipMaps(true);
    diffuseTexture2D->setMaximumAnisotropy(16.0f);

    //create diffuse image
    diffuseImage = new Qt3DRender::QTextureImage(diffuseTexture2D);
    diffuseImage->setSource(_diffuseTextureSource);

    //create texture parameter
    diffuseTexture2D->addTextureImage(diffuseImage);
    diffuseTextureParam = new Qt3DRender::QParameter("diffuseTexture", diffuseTexture2D, this);

    normalTexture2D = new Qt3DRender::QTexture2D();
    normalTexture2D->setMinificationFilter(Qt3DRender::QAbstractTexture::Linear);
    normalTexture2D->setMagnificationFilter(Qt3DRender::QAbstractTexture::Linear);
    normalTexture2D->wrapMode()->setX(Qt3DRender::QTextureWrapMode::Repeat);
    normalTexture2D->wrapMode()->setY(Qt3DRender::QTextureWrapMode::Repeat);
    normalTexture2D->setMaximumAnisotropy(16.0f);

    //create normal image
    normalImage = new Qt3DRender::QTextureImage(normalTexture2D);
    normalImage->setSource(_normalTextureSource);

    //create normal parameter
    normalTexture2D->addTextureImage(normalImage);
    normalTextureParam = new Qt3DRender::QParameter("normalTexture", normalTexture2D, this);

    addParameter(ambientColorParam);
    addParameter(specularColorParam);
    addParameter(shininessParam);
    addParameter(textureScaleParam);
    addParameter(opacityParam);
    addParameter(diffuseTextureParam);
    addParameter(normalTextureParam);
}

QColor SolarSystem::SolarMaterial::ambientColor() const
{
    return _ambientColor;
}

QColor SolarSystem::SolarMaterial::specularColor() const
{
    return _specularColor;
}

QString SolarSystem::SolarMaterial::diffuseTextureSource() const
{
    return _diffuseTextureSource;
}

QString SolarSystem::SolarMaterial::normalTextureSource() const
{
    return _normalTextureSource;
}

float SolarSystem::SolarMaterial::shininess() const
{
    return _shininess;
}

float SolarSystem::SolarMaterial::textureScale() const
{
    return _textureScale;
}

float SolarSystem::SolarMaterial::opacity() const
{
    return _opacity;
}

void SolarSystem::SolarMaterial::setAmbient(QColor color)
{
    _ambientColor = color;
    ambientColorParam->setValue(QVector3D(color.redF(), color.blueF(), color.greenF()));
}

void SolarSystem::SolarMaterial::setSpecular(QColor color)
{
    _specularColor = color;
    specularColorParam->setValue(QVector3D(color.redF(), color.blueF(), color.greenF()));
}

void SolarSystem::SolarMaterial::setDiffuseTextureSource(const QString& source)
{
    _diffuseTextureSource = source;
    diffuseImage->setSource(QUrl::fromLocalFile(source));
}

void SolarSystem::SolarMaterial::setNormalTextureSource(const QString &source)
{
    _normalTextureSource = source;
    normalImage->setSource(QUrl::fromLocalFile(source));
}

void SolarSystem::SolarMaterial::setSnininess(float value)
{
    _shininess = value;
    shininessParam->setValue(value);
}

void SolarSystem::SolarMaterial::setTextureScale(float scale)
{
    _textureScale = scale;
    textureScaleParam->setValue(scale);
}

void SolarSystem::SolarMaterial::setOpacity(float opacity)
{
    _opacity = opacity;
    opacityParam->setValue(opacity);
}
