#include "solarobjecteffect.h"
#include <Qt3DRender/QParameter>
#include <Qt3DRender/QFilterKey>
#include <Qt3DRender/QTechnique>
#include <Qt3DRender/QShaderProgram>
#include <Qt3DRender/QGraphicsApiFilter>
#include <Qt3DCore/QTransform>
#include <QUrl>

SolarSystem::SolarObjectEffect::SolarObjectEffect(Qt3DCore::QNode* parent):
    Qt3DRender::QEffect(parent)
{
    vertexShaderGL = ":/Resources/Shaders/diffusenormal.vert";
    fragShaderGL = ":/Resources/Shaders/diffusenormal.frag";
}

SolarSystem::SolarLight* SolarSystem::SolarObjectEffect::light() const
{
    return lightObject;
}

void SolarSystem::SolarObjectEffect::setLight(SolarSystem::SolarLight* light)
{
    lightObject = light;
}

void SolarSystem::SolarObjectEffect::initialization()
{
    if (lightObject != nullptr)
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
        glPass = new Qt3DRender::QRenderPass(this);
        glPass->setObjectName("glPass");
        glPass->addFilterKey(forwardKey);

        //standard gl pass shader program
        Qt3DRender::QShaderProgram* glPassProgram = new Qt3DRender::QShaderProgram(glPass);
        glPassProgram->setVertexShaderCode(Qt3DRender::QShaderProgram::loadSource(QUrl::fromLocalFile(vertexShaderGL)));
        glPassProgram->setFragmentShaderCode(Qt3DRender::QShaderProgram::loadSource(QUrl::fromLocalFile(fragShaderGL)));

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
        api->setMajorVersion(4);
        api->setMinorVersion(0);

        openglTechnique->addFilterKey(desktopKey);
        openglTechnique->addRenderPass(glPass);

        addTechnique(openglTechnique);
    }
}

QString SolarSystem::SolarObjectEffect::vertexShaderSource() const
{
    return vertexShaderGL;
}

QString SolarSystem::SolarObjectEffect::fragmentShaderSource() const
{
    return fragShaderGL;
}

void SolarSystem::SolarObjectEffect::setVertexShaderSource(const QString& source)
{
    vertexShaderGL = source;
}

void SolarSystem::SolarObjectEffect::setFragmentShaderSource(const QString& source)
{
    fragShaderGL = source;
}
