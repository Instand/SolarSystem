#ifndef SOLARMATERIAL_H
#define SOLARMATERIAL_H

#include <Qt3DRender/QMaterial>
#include <Qt3DRender/QTexture>
#include <Qt3DRender/QTextureImage>
#include <Qt3DRender/QParameter>
#include <QColor>
#include <QString>
#include <QVector3D>

namespace SolarSystem {

    //represents base solar material
    class SolarMaterial : public Qt3DRender::QMaterial
    {
        Q_OBJECT

    public:
        SolarMaterial(Qt3DCore::QNode* parent = nullptr);

        //get interface
        QColor ambientColor() const;
        QColor specularColor() const;
        QString diffuseTextureSource() const;
        QString normalTextureSource() const;
        float shininess() const;
        float textureScale() const;
        float opacity() const;

        //set interface
        void setAmbient(QColor color);
        void setSpecular(QColor color);
        void setDiffuseTextureSource(const QString& source);
        void setNormalTextureSource(const QString& source);
        void setSnininess(float value);
        void setTextureScale(float scale);
        void setOpacity(float opacity);

    private:

        //main params
        Qt3DRender::QParameter* ambientColorParam;
        Qt3DRender::QParameter* specularColorParam;
        Qt3DRender::QParameter* shininessParam;
        Qt3DRender::QParameter* diffuseTextureParam;
        Qt3DRender::QParameter* normalTextureParam;
        Qt3DRender::QParameter* textureScaleParam;
        Qt3DRender::QParameter* opacityParam;

        //data
        QColor _ambientColor = QColor::fromRgbF(0.1f, 0.1f, 0.1f, 1.0f);
        QColor _specularColor = QColor::fromRgbF(0.5f, 0.5f, 0.5f, 1.0f);
        float _shininess = 150.0f;
        QString _diffuseTextureSource;
        QString _normalTextureSource;
        float _textureScale = 1.0f;
        float _opacity = 1.0f;

        //textures
        Qt3DRender::QTexture2D* diffuseTexture2D;
        Qt3DRender::QTexture2D* normalTexture2D;
        Qt3DRender::QTextureImage* diffuseImage;
        Qt3DRender::QTextureImage* normalImage;

    };
}

#endif // SOLARMATERIAL_H
