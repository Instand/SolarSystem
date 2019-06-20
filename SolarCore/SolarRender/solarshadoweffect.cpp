#include "solarshadoweffect.h"
#include <Qt3DRender/QParameter>
#include <Qt3DRender/QFilterKey>
#include <Qt3DRender/QTechnique>
#include <Qt3DRender/QShaderProgram>
#include <Qt3DRender/QPolygonOffset>
#include <Qt3DRender/QDepthTest>
#include <Qt3DRender/QGraphicsApiFilter>
#include <Qt3DRender/QCamera>

SolarSystem::SolarShadowEffect::SolarShadowEffect(Qt3DCore::QNode* parent):
    Qt3DRender::QEffect(parent)
{
}

SolarSystem::SolarLight* SolarSystem::SolarShadowEffect::light() const
{
    return m_lightObject;
}

void SolarSystem::SolarShadowEffect::setLight(SolarSystem::SolarLight* light)
{
    m_lightObject = light;
}

Qt3DRender::QTexture2D* SolarSystem::SolarShadowEffect::shadowTexture() const
{
    return m_shadowTexture;
}

void SolarSystem::SolarShadowEffect::setShadowTexture(Qt3DRender::QTexture2D* texture)
{
    m_shadowTexture = texture;
}

void SolarSystem::SolarShadowEffect::initialization()
{
    if (m_lightObject != nullptr && m_shadowTexture != nullptr)
    {
        // create params
        auto* lightViewParam = new Qt3DRender::QParameter(this);
        lightViewParam->setName("lightViewProjection");
        lightViewParam->setValue(m_lightObject->lightViewProjection());

        auto* lightPos = new Qt3DRender::QParameter(this);
        lightPos->setName("lightPosition");
        lightPos->setValue(m_lightObject->camera()->position());

        auto* lightInt = new Qt3DRender::QParameter(this);
        lightInt->setName("lightIntensity");
        lightInt->setValue(m_lightObject->intensity());

        auto* shadowMap = new Qt3DRender::QParameter("shadowMapTexture", m_shadowTexture, this);

        // add params
        addParameter(lightViewParam);
        addParameter(lightPos);
        addParameter(lightInt);
        addParameter(shadowMap);

        // create filter keys
        auto* desktopKey = new Qt3DRender::QFilterKey(this);
        desktopKey->setName("name");
        desktopKey->setValue("Desktop");

        auto* shadowKey = new Qt3DRender::QFilterKey(this);
        shadowKey->setName("pass");
        shadowKey->setValue("shadowmap");

        auto* forwardKey = new Qt3DRender::QFilterKey(this);
        forwardKey->setName("pass");
        forwardKey->setValue("forward");

        // first render pass

        // create shadow render pass
        m_shadowPass = new Qt3DRender::QRenderPass(this);
        m_shadowPass->setObjectName("shadowPass");
        m_shadowPass->addFilterKey(shadowKey);

        // shadow map shader program
        Qt3DRender::QShaderProgram* shadowProgram = new Qt3DRender::QShaderProgram(m_shadowPass);
        shadowProgram->setVertexShaderCode(Qt3DRender::QShaderProgram::loadSource(QUrl::fromLocalFile(":/Resources/Shaders/shadowmap.vert")));
        shadowProgram->setFragmentShaderCode(Qt3DRender::QShaderProgram::loadSource(QUrl::fromLocalFile(":/Resources/Shaders/shadowmap.frag")));

        // add shadow program
        m_shadowPass->setShaderProgram(shadowProgram);

        // create render states
        auto* shadowPolygonOffset = new Qt3DRender::QPolygonOffset(m_shadowPass);
        shadowPolygonOffset->setScaleFactor(4.0f);
        shadowPolygonOffset->setDepthSteps(4.0f);

        auto* shadowDepthTest = new Qt3DRender::QDepthTest(m_shadowPass);
        shadowDepthTest->setDepthFunction(Qt3DRender::QDepthTest::Less);

        // add shadow render states to shadow render pass
        m_shadowPass->addRenderState(shadowPolygonOffset);
        m_shadowPass->addRenderState(shadowDepthTest);

        // second render pass

        // create standard gl pass
        m_glPass = new Qt3DRender::QRenderPass(this);
        m_glPass->setObjectName("glPass");
        m_glPass->addFilterKey(forwardKey);

        // standard gl pass shader program
        Qt3DRender::QShaderProgram* glPassProgram = new Qt3DRender::QShaderProgram(m_glPass);
        glPassProgram->setVertexShaderCode(Qt3DRender::QShaderProgram::loadSource(QUrl::fromLocalFile(":/Resources/Shaders/diffuseshadow.vert")));
        glPassProgram->setFragmentShaderCode(Qt3DRender::QShaderProgram::loadSource(QUrl::fromLocalFile(":/Resources/Shaders/diffuseshadow.frag")));

        // add gl pass program
        m_glPass->setShaderProgram(glPassProgram);

        //**************************
        // tecnique
        //**************************

        // create tecniques
        Qt3DRender::QTechnique* openglTechnique = new Qt3DRender::QTechnique(this);

        auto* api = openglTechnique->graphicsApiFilter();
        api->setApi(Qt3DRender::QGraphicsApiFilter::OpenGL);
        api->setProfile(Qt3DRender::QGraphicsApiFilter::CoreProfile);
        api->setMajorVersion(3);
        api->setMinorVersion(2);

        openglTechnique->addFilterKey(desktopKey);
        openglTechnique->addRenderPass(m_shadowPass);
        openglTechnique->addRenderPass(m_glPass);

        addTechnique(openglTechnique);
    }
}
