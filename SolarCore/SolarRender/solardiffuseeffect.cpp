#include "solardiffuseeffect.h"

#include <Qt3DRender/QRenderPass>
#include <Qt3DRender/QParameter>
#include <Qt3DRender/QFilterKey>
#include <Qt3DRender/QTechnique>
#include <Qt3DRender/QShaderProgram>
#include <Qt3DRender/QGraphicsApiFilter>
#include <QUrl>

SolarSystem::SolarDiffuseEffect::SolarDiffuseEffect(Qt3DCore::QNode* parent):
    QEffect(parent)
{
    //create filter keys
    auto* desktopKey = new Qt3DRender::QFilterKey(this);
    desktopKey->setName("name");
    desktopKey->setValue("Desktop");

    auto* forwardKey = new Qt3DRender::QFilterKey(this);
    forwardKey->setName("pass");
    forwardKey->setValue("forward");

    //create standard gl pass
    Qt3DRender::QRenderPass* glPass = new Qt3DRender::QRenderPass(this);
    glPass->setObjectName("glPass");
    glPass->addFilterKey(forwardKey);

    //standard gl pass shader program
    Qt3DRender::QShaderProgram* glPassProgram = new Qt3DRender::QShaderProgram(glPass);
    glPassProgram->setVertexShaderCode(Qt3DRender::QShaderProgram::loadSource(QUrl::fromLocalFile(":/Resources/Shaders/diffuse.vert")));
    glPassProgram->setFragmentShaderCode(Qt3DRender::QShaderProgram::loadSource(QUrl::fromLocalFile(":/Resources/Shaders/diffuse.frag")));

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
    openglTechnique->addRenderPass(glPass);

    addTechnique(openglTechnique);
}
