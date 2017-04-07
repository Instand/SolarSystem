#include "solarframegraph.h"
#include <Qt3DRender/QCamera>
#include <Qt3DRender/QViewport>
#include <Qt3DRender/QRenderSurfaceSelector>
#include <Qt3DRender/QTechniqueFilter>
#include <Qt3DRender/QFilterKey>
#include <Qt3DRender/QRenderPassFilter>
#include <Qt3DRender/QRenderTargetSelector>
#include <Qt3DRender/QRenderTarget>
#include <Qt3DRender/QTexture>
#include <Qt3DRender/QRenderTargetOutput>
#include <Qt3DRender/QClearBuffers>
#include <Qt3DRender/QCameraSelector>

SolarSystem::SolarFrameGraph::SolarFrameGraph(Qt3DCore::QNode* parent):
    QRenderSettings(parent)
{
    viewPort = new Qt3DRender::QViewport(this);
    viewPort->setNormalizedRect(QRectF(0, 0, 1.0f, 1.0f));

    //create surface selector
    selector = new Qt3DRender::QRenderSurfaceSelector(viewPort);

    //create technique filter
    tFilter = new Qt3DRender::QTechniqueFilter(selector);

    auto* desktopFilter = new Qt3DRender::QFilterKey(tFilter);
    desktopFilter->setName("name");
    desktopFilter->setValue("Desktop");

    tFilter->addMatch(desktopFilter);

    //create render pass filter
    renderPassShadowFilter = new Qt3DRender::QRenderPassFilter(tFilter);

    auto* shadowMapFilter = new Qt3DRender::QFilterKey(renderPassShadowFilter);
    shadowMapFilter->setName("pass");
    shadowMapFilter->setValue("shadowmap");

    renderPassShadowFilter->addMatch(shadowMapFilter);

    //create target selector
    targetSelector = new Qt3DRender::QRenderTargetSelector(renderPassShadowFilter);

    //render target
    auto* renderTarget = new Qt3DRender::QRenderTarget(targetSelector);
    auto* targetOutput = new Qt3DRender::QRenderTargetOutput(renderTarget);
    targetOutput->setObjectName("depth");
    targetOutput->setAttachmentPoint(Qt3DRender::QRenderTargetOutput::Depth);

    //create shadow texture
    texture = new Qt3DRender::QTexture2D;
    texture->setFormat(Qt3DRender::QAbstractTexture::D24);
    texture->setGenerateMipMaps(false);
    texture->setMagnificationFilter(Qt3DRender::QAbstractTexture::Linear);
    texture->setMinificationFilter(Qt3DRender::QAbstractTexture::Linear);
    texture->wrapMode()->setX(Qt3DRender::QTextureWrapMode::ClampToEdge);
    texture->wrapMode()->setY(Qt3DRender::QTextureWrapMode::ClampToEdge);
    texture->setComparisonFunction(Qt3DRender::QAbstractTexture::CompareLessEqual);
    texture->setComparisonMode(Qt3DRender::QAbstractTexture::CompareRefToTexture);

    targetOutput->setTexture(texture);
    renderTarget->addOutput(targetOutput);

    //buffer
    auto* clearBuffer = new Qt3DRender::QClearBuffers(targetSelector);
    clearBuffer->setBuffers(Qt3DRender::QClearBuffers::DepthBuffer);
    lightCameraSelector = new Qt3DRender::QCameraSelector(clearBuffer);

    //forward render pass fitler
    renderPassForwardFilter = new Qt3DRender::QRenderPassFilter(selector);

    auto* forwardFilter = new Qt3DRender::QFilterKey(renderPassForwardFilter);
    forwardFilter->setName("pass");
    forwardFilter->setValue("forward");

    renderPassForwardFilter->addMatch(forwardFilter);

    //buffer
    auto* forwardClearBuffer = new Qt3DRender::QClearBuffers(renderPassForwardFilter);
    forwardClearBuffer->setBuffers(Qt3DRender::QClearBuffers::ColorDepthBuffer);
    viewCameraSelector = new Qt3DRender::QCameraSelector(forwardClearBuffer);

    setActiveFrameGraph(viewPort);
}

void SolarSystem::SolarFrameGraph::setViewCamera(Qt3DRender::QCamera* viewCamera)
{
    viewCameraSelector->setCamera(viewCamera);
}

void SolarSystem::SolarFrameGraph::setLightCamera(Qt3DRender::QCamera* lightCamera)
{
    lightCameraSelector->setCamera(lightCamera);
}

Qt3DRender::QCamera* SolarSystem::SolarFrameGraph::viewCamera() const
{
    return qobject_cast<Qt3DRender::QCamera*>(viewCameraSelector->camera());
}

Qt3DRender::QCamera* SolarSystem::SolarFrameGraph::lightCamera() const
{
    return qobject_cast<Qt3DRender::QCamera*>(lightCameraSelector->camera());
}

Qt3DRender::QTexture2D* SolarSystem::SolarFrameGraph::shadowTexture() const
{
    return texture;
}
