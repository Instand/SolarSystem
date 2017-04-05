#include "solarshadoweffect.h"
#include <Qt3DRender/QParameter>
#include <Qt3DRender/QFilterKey>
#include <Qt3DRender/QTechnique>
#include <Qt3DRender/QShaderProgram>
#include <Qt3DRender/QPolygonOffset>
#include <Qt3DRender/QDepthTest>
#include <Qt3DRender/QGraphicsApiFilter>
#include <Qt3DCore/QTransform>

SolarSystem::SolarShadowEffect::SolarShadowEffect(Qt3DCore::QNode* parent):
    Qt3DRender::QEffect(parent)
{
}

SolarSystem::SolarLight* SolarSystem::SolarShadowEffect::light() const
{
    return lightObject;
}

void SolarSystem::SolarShadowEffect::setLight(SolarSystem::SolarLight* light)
{
    lightObject = light;
}

Qt3DRender::QTexture2D* SolarSystem::SolarShadowEffect::shadowTexture() const
{
    return shadowTex;
}

void SolarSystem::SolarShadowEffect::setShadowTexture(Qt3DRender::QTexture2D* texture)
{
    shadowTex = texture;
}

void SolarSystem::SolarShadowEffect::initialization()
{
    if (lightObject != nullptr && shadowTex != nullptr)
    {
        //create params
        auto* lightViewParam = new Qt3DRender::QParameter(this);
        lightViewParam->setName("lightViewProjection");
        lightViewParam->setValue(lightObject->lightViewProjection());

        auto* lightPos = new Qt3DRender::QParameter(this);
        lightPos->setName("lightPosition");
        lightPos->setValue(lightObject->transform()->translation());

        auto* lightInt = new Qt3DRender::QParameter(this);
        lightInt->setName("lightIntensity");
        lightInt->setValue(lightObject->intensity());

        auto* shadowMap = new Qt3DRender::QParameter("shadowMapTexture", shadowTex, this);

        //add params
        addParameter(lightViewParam);
        addParameter(lightPos);
        addParameter(lightInt);
        addParameter(shadowMap);

        //create filter keys
        auto* desktopKey = new Qt3DRender::QFilterKey(this);
        desktopKey->setName("name");
        desktopKey->setValue("Desktop");

        auto* shadowKey = new Qt3DRender::QFilterKey(this);
        shadowKey->setName("pass");
        shadowKey->setValue("shadowmap");

        auto* forwardKey = new Qt3DRender::QFilterKey(this);
        forwardKey->setName("pass");
        forwardKey->setValue("forward");

        //first render pass

        //create shadow render pass
        shadowPass = new Qt3DRender::QRenderPass(this);
        shadowPass->setObjectName("shadowPass");
        shadowPass->addFilterKey(shadowKey);

        //shadow map shader program
        Qt3DRender::QShaderProgram* shadowProgram = new Qt3DRender::QShaderProgram(shadowPass);
        shadowProgram->setVertexShaderCode(Qt3DRender::QShaderProgram::loadSource(QUrl::fromLocalFile(":/Resources/Shaders/shadowmap.vert")));
        shadowProgram->setFragmentShaderCode(Qt3DRender::QShaderProgram::loadSource(QUrl::fromLocalFile(":/Resources/Shaders/shadowmap.frag")));

        //add shadow program
        shadowPass->setShaderProgram(shadowProgram);

        //create render states
        auto* shadowPolygonOffset = new Qt3DRender::QPolygonOffset(shadowPass);
        shadowPolygonOffset->setScaleFactor(4.0f);
        shadowPolygonOffset->setDepthSteps(4.0f);

        auto* shadowDepthTest = new Qt3DRender::QDepthTest(shadowPass);
        shadowDepthTest->setDepthFunction(Qt3DRender::QDepthTest::Less);

        //add shadow render states to shadow render pass
        shadowPass->addRenderState(shadowPolygonOffset);
        shadowPass->addRenderState(shadowDepthTest);

        //second render pass

        //create standard gl pass
        glPass = new Qt3DRender::QRenderPass(this);
        glPass->setObjectName("glPass");
        glPass->addFilterKey(forwardKey);

        //standard gl pass shader program
        Qt3DRender::QShaderProgram* glPassProgram = new Qt3DRender::QShaderProgram(glPass);
        glPassProgram->setVertexShaderCode(Qt3DRender::QShaderProgram::loadSource(QUrl::fromLocalFile(":/Resources/Shaders/diffuseshadow.vert")));
        glPassProgram->setFragmentShaderCode(Qt3DRender::QShaderProgram::loadSource(QUrl::fromLocalFile(":/Resources/Shaders/diffuseshadow.frag")));

        //add gl pass program
        glPass->setShaderProgram(glPassProgram);

        //**************************
        //tecnique
        //**************************

        //create tecniques
        Qt3DRender::QTechnique* openglTechnique = new Qt3DRender::QTechnique(this);

        //setup api
        auto* api = openglTechnique->graphicsApiFilter();
        api->setApi(Qt3DRender::QGraphicsApiFilter::OpenGL);
        api->setProfile(Qt3DRender::QGraphicsApiFilter::CoreProfile);
        api->setMajorVersion(3);
        api->setMinorVersion(2);

        openglTechnique->addFilterKey(desktopKey);
        openglTechnique->addRenderPass(shadowPass);
        openglTechnique->addRenderPass(glPass);

        addTechnique(openglTechnique);
    }
}
