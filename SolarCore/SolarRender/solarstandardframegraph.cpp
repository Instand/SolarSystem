#include "solarstandardframegraph.h"
#include <Qt3DExtras/QForwardRenderer>

SolarSystem::SolarStandardFrameGraph::SolarStandardFrameGraph(Qt3DCore::QNode* parent):
    IFrameGraph(parent),
    m_renderer(new Qt3DExtras::QForwardRenderer(parent))
{
    setRenderPolicy(QRenderSettings::RenderPolicy::Always);
    setActiveFrameGraph(m_renderer);

    m_renderer->setFrustumCullingEnabled(true);
    m_renderer->setClearColor(QColor(Qt::black));
}

void SolarSystem::SolarStandardFrameGraph::setCamera(Qt3DCore::QEntity* camera)
{
    m_renderer->setCamera(camera);
}
