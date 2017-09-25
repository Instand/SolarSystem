#include "solarskybox.h"

#include <Qt3DRender/QFilterKey>
#include <Qt3DRender/QEffect>
#include <Qt3DRender/QTexture>
#include <Qt3DRender/QMaterial>
#include <Qt3DRender/QCullFace>
#include <Qt3DRender/QDepthTest>
#include <Qt3DRender/QParameter>
#include <Qt3DRender/QTechnique>
#include <Qt3DExtras/QCuboidMesh>
#include <Qt3DRender/QRenderPass>
#include <Qt3DRender/QGraphicsApiFilter>
#include <Qt3DRender/QShaderProgram>

using namespace Qt3DCore;
using namespace Qt3DRender;
using namespace Qt3DExtras;

SolarSystem::SolarSkyBox::SolarSkyBox(Qt3DCore::QNode* parent):
    SkyBoxBase(parent)
#ifndef QT3D_MATERIALS
   ,effect(new Qt3DRender::QEffect()),
    material(new Qt3DRender::QMaterial()),
    skyboxTexture(new QTextureCubeMap()),
    shaderProgram(new QShaderProgram()),
    technique(new QTechnique()),
    renderPass(new QRenderPass()),
    mesh(new QCuboidMesh()),
    textureParameter(new QParameter(QStringLiteral("skyboxTexture"), skyboxTexture)),
    posXImage(new QTextureImage()),
    posYImage(new QTextureImage()),
    posZImage(new QTextureImage()),
    negXImage(new QTextureImage()),
    negYImage(new QTextureImage()),
    negZImage(new QTextureImage()),
    extension(QStringLiteral(".png"))
#endif
{
#ifndef QT3D_MATERIALS
    shaderProgram->setVertexShaderCode(QShaderProgram::loadSource(QUrl::fromLocalFile(":/Resources/Shaders/skybox.vert")));
    shaderProgram->setFragmentShaderCode(QShaderProgram::loadSource(QUrl::fromLocalFile(":/Resources/Shaders/skybox.frag")));

    technique->graphicsApiFilter()->setApi(QGraphicsApiFilter::OpenGL);
    technique->graphicsApiFilter()->setMajorVersion(3);
    technique->graphicsApiFilter()->setMajorVersion(2);
    technique->graphicsApiFilter()->setProfile(QGraphicsApiFilter::CoreProfile);

    auto* filterKey = new Qt3DRender::QFilterKey(effect);
    filterKey->setName("name");
    filterKey->setValue("Desktop");

    technique->addFilterKey(filterKey);

    renderPass->setShaderProgram(shaderProgram);

    QCullFace* cullFront = new QCullFace();
    cullFront->setMode(QCullFace::Front);

    QDepthTest* depthTest = new QDepthTest();
    depthTest->setDepthFunction(QDepthTest::LessOrEqual);

    auto* renderKey = new Qt3DRender::QFilterKey(effect);
    renderKey->setName("pass");
    renderKey->setValue("forward");

    renderPass->addFilterKey(renderKey);
    renderPass->addRenderState(cullFront);
    renderPass->addRenderState(depthTest);

    technique->addRenderPass(renderPass);

    effect->addTechnique(technique);

    material->setEffect(effect);
    material->addParameter(textureParameter);

    mesh->setXYMeshResolution(QSize(2, 2));
    mesh->setXZMeshResolution(QSize(2, 2));
    mesh->setYZMeshResolution(QSize(2, 2));

    posXImage->setFace(QTextureCubeMap::CubeMapPositiveX);
    posYImage->setFace(QTextureCubeMap::CubeMapPositiveY);
    posZImage->setFace(QTextureCubeMap::CubeMapPositiveZ);
    negXImage->setFace(QTextureCubeMap::CubeMapNegativeX);
    negYImage->setFace(QTextureCubeMap::CubeMapNegativeY);
    negZImage->setFace(QTextureCubeMap::CubeMapNegativeZ);

    skyboxTexture->setMagnificationFilter(QTextureCubeMap::Linear);
    skyboxTexture->setMinificationFilter(QTextureCubeMap::Linear);
    skyboxTexture->setGenerateMipMaps(false);
    skyboxTexture->setWrapMode(QTextureWrapMode(QTextureWrapMode::ClampToEdge));

    skyboxTexture->addTextureImage(posXImage);
    skyboxTexture->addTextureImage(posYImage);
    skyboxTexture->addTextureImage(posZImage);
    skyboxTexture->addTextureImage(negXImage);
    skyboxTexture->addTextureImage(negYImage);
    skyboxTexture->addTextureImage(negZImage);

    addComponent(mesh);
    addComponent(material);

    //create skybox from file
    name = QStringLiteral("qrc:/Resources/Skybox/stars");
    extension = QStringLiteral(".webp");

    updateTexture();
#else
    //create skybox from file
    setBaseName(QStringLiteral("qrc:/Resources/Skybox/stars"));
    setExtension(QStringLiteral(".webp"));
#endif
}

#ifndef QT3D_MATERIALS
void SolarSystem::SolarSkyBox::updateTexture()
{
    posXImage->setSource(QUrl(name + QStringLiteral("_posx") + extension));
    posYImage->setSource(QUrl(name + QStringLiteral("_posy") + extension));
    posZImage->setSource(QUrl(name + QStringLiteral("_posz") + extension));
    negXImage->setSource(QUrl(name + QStringLiteral("_negx") + extension));
    negYImage->setSource(QUrl(name + QStringLiteral("_negy") + extension));
    negZImage->setSource(QUrl(name + QStringLiteral("_negz") + extension));
}
#endif

