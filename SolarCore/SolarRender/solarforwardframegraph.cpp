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
    IFrameGraph(parent)
{
    //render
    m_filter = new Qt3DRender::QTechniqueFilter();

    auto* key = new Qt3DRender::QFilterKey();
    key->setName("renderingStyle");
    key->setValue("forward");
    m_filter->addMatch(key);

    m_surfaceSelector = new Qt3DRender::QRenderSurfaceSelector(m_filter);

    m_viewPort = new Qt3DRender::QViewport(m_surfaceSelector);
    m_viewPort->setNormalizedRect(QRectF(0.0, 0.0, 1.0, 1.0));

    m_cameraSelector = new Qt3DRender::QCameraSelector(m_viewPort);

    m_clearBuffers = new Qt3DRender::QClearBuffers(m_cameraSelector);
    m_clearBuffers->setBuffers(Qt3DRender::QClearBuffers::ColorDepthBuffer);
    m_clearBuffers->setClearColor(QColor(Qt::black));

    m_frustum = new Qt3DRender::QFrustumCulling(m_clearBuffers);

    m_sortPolicy = new Qt3DRender::QSortPolicy(m_clearBuffers);

    QVector<Qt3DRender::QSortPolicy::SortType> sortedVector;
    sortedVector.push_back(Qt3DRender::QSortPolicy::BackToFront);
    sortedVector.push_back(Qt3DRender::QSortPolicy::StateChangeCost);
    sortedVector.push_back(Qt3DRender::QSortPolicy::Material);

    m_sortPolicy->setSortTypes(sortedVector);

    setActiveFrameGraph(m_filter);
}

void SolarSystem::SolarForwardFrameGraph::setCamera(Qt3DCore::QEntity *camera)
{
    m_cameraSelector->setCamera(camera);
}
