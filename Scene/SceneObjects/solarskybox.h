#ifndef SOLARSKYBOX_H
#define SOLARSKYBOX_H

#include <QVector3D>
#include <Qt3DCore/QEntity>

//forward
namespace Qt3DRender {
    class QFilterKey;
    class QTextureCubeMap;
    class QShaderProgram;
    class QSkyboxEntity;
    class QTextureImage;
    class QRenderPass;
    class QTechnique;
    class QParameter;
    class QMaterial;
    class QEffect;
}

namespace Qt3DExtras {
    class QCuboidMesh;
}

namespace SolarSystem {

    //represents space
    class SolarSkyBox : public Qt3DCore::QEntity
    {
        Q_OBJECT

    public:
        explicit SolarSkyBox(Qt3DCore::QNode* parent = nullptr);

    private:

        //material + effect + shaders
        Qt3DRender::QEffect* effect;
        Qt3DRender::QMaterial* material;
        Qt3DRender::QTextureCubeMap* skyboxTexture;
        Qt3DRender::QShaderProgram* shaderProgram;
        Qt3DRender::QTechnique* technique;
        Qt3DRender::QRenderPass* renderPass;
        Qt3DExtras::QCuboidMesh* mesh;
        Qt3DRender::QParameter* textureParameter;

        //images
        Qt3DRender::QTextureImage* posXImage;
        Qt3DRender::QTextureImage* posYImage;
        Qt3DRender::QTextureImage* posZImage;
        Qt3DRender::QTextureImage* negXImage;
        Qt3DRender::QTextureImage* negYImage;
        Qt3DRender::QTextureImage* negZImage;

        //strings
        QString extension;
        QString name;
        QVector3D position;

        //helper
        void updateTexture();
    };

}

#endif // SOLARSKYBOX_H
