#include "solarobjecteffect.h"
#include <Qt3DRender/QParameter>
#include <Qt3DRender/QFilterKey>
#include <Qt3DRender/QTechnique>
#include <Qt3DRender/QShaderProgram>
#include <Qt3DRender/QGraphicsApiFilter>
#include <Qt3DRender/QCamera>
#include <QUrl>

SolarSystem::SolarObjectEffect::SolarObjectEffect(Qt3DCore::QNode* parent):
    Qt3DRender::QEffect(parent)
{
    m_vertexShaderGL = ":/Resources/Shaders/diffusenormal.vert";
    m_fragShaderGL = ":/Resources/Shaders/diffusenormal.frag";
}

SolarSystem::SolarLight* SolarSystem::SolarObjectEffect::light() const
{
    return m_lightObject;
}

void SolarSystem::SolarObjectEffect::setLight(SolarSystem::SolarLight* light)
{
    m_lightObject = light;
}

void SolarSystem::SolarObjectEffect::initialization()
{
    if (m_lightObject != nullptr)
    {
        //create params
        auto* lightViewParam = new Qt3DRender::QParameter(this);
        lightViewParam->setName("lightViewProjection");
        lightViewParam->setValue(m_lightObject->lightViewProjection());

        auto* lightPos = new Qt3DRender::QParameter(this);
        lightPos->setName("lightPosition");
        lightPos->setValue(m_lightObject->camera()->position());

        auto* lightInt = new Qt3DRender::QParameter(this);
        lightInt->setName("lightIntensity");
        lightInt->setValue(m_lightObject->intensity());

        //add params
        addParameter(lightViewParam);
        addParameter(lightPos);
        addParameter(lightInt);

        //create filter keys
        auto* desktopKey = new Qt3DRender::QFilterKey(this);
        desktopKey->setName("name");
        desktopKey->setValue("Desktop");

        auto* forwardKey = new Qt3DRender::QFilterKey(this);
        forwardKey->setName("pass");
        forwardKey->setValue("forward");

        //create standard gl pass
        m_glPass = new Qt3DRender::QRenderPass(this);
        m_glPass->setObjectName("glPass");
        m_glPass->addFilterKey(forwardKey);

        //standard gl pass shader program
        Qt3DRender::QShaderProgram* glPassProgram = new Qt3DRender::QShaderProgram(m_glPass);
        glPassProgram->setVertexShaderCode(Qt3DRender::QShaderProgram::loadSource(QUrl::fromLocalFile(m_vertexShaderGL)));
        glPassProgram->setFragmentShaderCode(Qt3DRender::QShaderProgram::loadSource(QUrl::fromLocalFile(m_fragShaderGL)));

        //add gl pass program
        m_glPass->setShaderProgram(glPassProgram);

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
        openglTechnique->addRenderPass(m_glPass);

        addTechnique(openglTechnique);
    }
}

QString SolarSystem::SolarObjectEffect::vertexShaderSource() const
{
    return m_vertexShaderGL;
}

QString SolarSystem::SolarObjectEffect::fragmentShaderSource() const
{
    return m_fragShaderGL;
}

void SolarSystem::SolarObjectEffect::setVertexShaderSource(const QString& source)
{
    m_vertexShaderGL = source;
}

void SolarSystem::SolarObjectEffect::setFragmentShaderSource(const QString& source)
{
    m_fragShaderGL = source;
}
