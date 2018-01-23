#include "solarstandardframegraph.h"
#include <Qt3DExtras/QForwardRenderer>

SolarSystem::SolarStandardFrameGraph::SolarStandardFrameGraph(Qt3DCore::QNode* parent):
    IFrameGraph(parent),
    renderer(new Qt3DExtras::QForwardRenderer(parent))
{
    setActiveFrameGraph(renderer);

    renderer->setFrustumCullingEnabled(true);
    renderer->setClearColor(QColor(Qt::black));
}

void SolarSystem::SolarStandardFrameGraph::setCamera(Qt3DCore::QEntity* camera)
{
    renderer->setCamera(camera);
}
