#ifndef SOLARMATERIAL_H
#define SOLARMATERIAL_H

#include <Qt3DRender/QMaterial>
#include <Qt3DRender/QTexture>
#include <Qt3DRender/QTextureImage>
#include <Qt3DRender/QParameter>
#include <QColor>
#include <QString>
#include <QVector3D>

namespace SolarSystem
{
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
        Qt3DRender::QParameter* m_ambientColorParam;
        Qt3DRender::QParameter* m_specularColorParam;
        Qt3DRender::QParameter* m_shininessParam;
        Qt3DRender::QParameter* m_diffuseTextureParam;
        Qt3DRender::QParameter* m_normalTextureParam;
        Qt3DRender::QParameter* m_textureScaleParam;
        Qt3DRender::QParameter* m_opacityParam;

        //data
        QColor m_ambientColor = QColor::fromRgbF(0.1f, 0.1f, 0.1f, 1.0f);
        QColor m_specularColor = QColor::fromRgbF(0.5f, 0.5f, 0.5f, 1.0f);
        float m_shininess = 150.0f;
        QString m_diffuseTextureSource;
        QString m_normalTextureSource;
        float m_textureScale = 1.0f;
        float m_opacity = 1.0f;

        //textures
        Qt3DRender::QTexture2D* m_diffuseTexture2D;
        Qt3DRender::QTexture2D* m_normalTexture2D;
        Qt3DRender::QTextureImage* m_diffuseImage;
        Qt3DRender::QTextureImage* m_normalImage;

    };
}

#endif // SOLARMATERIAL_H
