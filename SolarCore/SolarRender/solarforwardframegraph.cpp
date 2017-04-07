#include "solarforwardframegraph.h"
#include <Qt3DRender/QFilterKey>
#include <Qt3DRender/QCamera>
#include <Qt3DRender/QSortPolicy>
#include <Qt3DRender/QClearBuffers>
#include <Qt3DRender/QCameraSelector>
#include <Qt3DRender/QViewport>
#include <Qt3DRender/QRenderSurfaceSelector>
#include <Qt3DRender/QTechniqueFilter>
#include <Qt3DRender/QRenderSettings>
#include <Qt3DRender/QFrustumCulling>

SolarSystem::SolarForwardFrameGraph::SolarForwardFrameGraph(Qt3DCore::QNode* parent):
    QRenderSettings(parent)
{
    //render
    filter = new Qt3DRender::QTechniqueFilter();

    auto* key = new Qt3DRender::QFilterKey();
    key->setName("renderingStyle");
    key->setValue("forward");
    filter->addMatch(key);

    surfaceSelector = new Qt3DRender::QRenderSurfaceSelector(filter);

    viewPort = new Qt3DRender::QViewport(surfaceSelector);
    viewPort->setNormalizedRect(QRectF(0.0, 0.0, 1.0, 1.0));

    cameraSelector = new Qt3DRender::QCameraSelector(viewPort);

    clearBuffers = new Qt3DRender::QClearBuffers(cameraSelector);
    clearBuffers->setBuffers(Qt3DRender::QClearBuffers::ColorDepthBuffer);
    clearBuffers->setClearColor(QColor(Qt::black));

    frustum = new Qt3DRender::QFrustumCulling(clearBuffers);

    sortPolicy = new Qt3DRender::QSortPolicy(clearBuffers);

    QVector<Qt3DRender::QSortPolicy::SortType> sortedVector;
    sortedVector.push_back(Qt3DRender::QSortPolicy::StateChangeCost);
    sortedVector.push_back(Qt3DRender::QSortPolicy::Material);
    sortedVector.push_back(Qt3DRender::QSortPolicy::BackToFront);

    sortPolicy->setSortTypes(sortedVector);

    setActiveFrameGraph(filter);
}

void SolarSystem::SolarForwardFrameGraph::setCamera(Qt3DRender::QCamera *camera)
{
    cameraSelector->setCamera(camera);
}
