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
    m_viewPort = new Qt3DRender::QViewport(this);
    m_viewPort->setNormalizedRect(QRectF(0, 0, 1.0, 1.0));

    m_selector = new Qt3DRender::QRenderSurfaceSelector(m_viewPort);

    m_techniqueFilter = new Qt3DRender::QTechniqueFilter(m_selector);

    auto* desktopFilter = new Qt3DRender::QFilterKey(m_techniqueFilter);
    desktopFilter->setName("name");
    desktopFilter->setValue("Desktop");

    m_techniqueFilter->addMatch(desktopFilter);

    // create render pass filter
    m_renderPassShadowFilter = new Qt3DRender::QRenderPassFilter(m_techniqueFilter);

    auto* shadowMapFilter = new Qt3DRender::QFilterKey(m_renderPassShadowFilter);
    shadowMapFilter->setName("pass");
    shadowMapFilter->setValue("shadowmap");

    m_renderPassShadowFilter->addMatch(shadowMapFilter);

    // create target selector
    m_targetSelector = new Qt3DRender::QRenderTargetSelector(m_renderPassShadowFilter);

    // render target
    auto* renderTarget = new Qt3DRender::QRenderTarget(m_targetSelector);
    auto* targetOutput = new Qt3DRender::QRenderTargetOutput(renderTarget);
    targetOutput->setObjectName("depth");
    targetOutput->setAttachmentPoint(Qt3DRender::QRenderTargetOutput::Depth);

    // create shadow texture
    m_texture = new Qt3DRender::QTexture2D;
    m_texture->setFormat(Qt3DRender::QAbstractTexture::D24);
    m_texture->setGenerateMipMaps(false);
    m_texture->setMagnificationFilter(Qt3DRender::QAbstractTexture::Linear);
    m_texture->setMinificationFilter(Qt3DRender::QAbstractTexture::Linear);
    m_texture->wrapMode()->setX(Qt3DRender::QTextureWrapMode::ClampToEdge);
    m_texture->wrapMode()->setY(Qt3DRender::QTextureWrapMode::ClampToEdge);
    m_texture->setComparisonFunction(Qt3DRender::QAbstractTexture::CompareLessEqual);
    m_texture->setComparisonMode(Qt3DRender::QAbstractTexture::CompareRefToTexture);

    targetOutput->setTexture(m_texture);
    renderTarget->addOutput(targetOutput);

    // buffer
    auto* clearBuffer = new Qt3DRender::QClearBuffers(m_targetSelector);
    clearBuffer->setBuffers(Qt3DRender::QClearBuffers::DepthBuffer);
    m_lightCameraSelector = new Qt3DRender::QCameraSelector(clearBuffer);

    // forward render pass fitler
    m_renderPassForwardFilter = new Qt3DRender::QRenderPassFilter(m_selector);

    auto* forwardFilter = new Qt3DRender::QFilterKey(m_renderPassForwardFilter);
    forwardFilter->setName("pass");
    forwardFilter->setValue("forward");

    m_renderPassForwardFilter->addMatch(forwardFilter);

    // buffer
    auto* forwardClearBuffer = new Qt3DRender::QClearBuffers(m_renderPassForwardFilter);
    forwardClearBuffer->setBuffers(Qt3DRender::QClearBuffers::ColorDepthBuffer);

    m_viewCameraSelector = new Qt3DRender::QCameraSelector(forwardClearBuffer);

    setActiveFrameGraph(m_viewPort);
}

void SolarSystem::SolarFrameGraph::setViewCamera(Qt3DRender::QCamera* viewCamera)
{
    m_viewCameraSelector->setCamera(viewCamera);
}

void SolarSystem::SolarFrameGraph::setLightCamera(Qt3DRender::QCamera* lightCamera)
{
    m_lightCameraSelector->setCamera(lightCamera);
}

Qt3DRender::QCamera* SolarSystem::SolarFrameGraph::viewCamera() const
{
    return qobject_cast<Qt3DRender::QCamera*>(m_viewCameraSelector->camera());
}

Qt3DRender::QCamera* SolarSystem::SolarFrameGraph::lightCamera() const
{
    return qobject_cast<Qt3DRender::QCamera*>(m_lightCameraSelector->camera());
}

Qt3DRender::QTexture2D* SolarSystem::SolarFrameGraph::shadowTexture() const
{
    return m_texture;
}
