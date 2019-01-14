#ifndef SOLARFORWARDFRAMEGRAPH_H
#define SOLARFORWARDFRAMEGRAPH_H

#include <Interface/iframegraph.h>

namespace Qt3DRender
{
    class QCamera;
    class QSortPolicy;
    class QClearBuffers;
    class QCameraSelector;
    class QViewport;
    class QRenderSurfaceSelector;
    class QTechniqueFilter;
    class QFrustumCulling;
}

namespace SolarSystem
{
    //Represents simple forward frame graph
    class SolarForwardFrameGraph : public IFrameGraph
    {
        Q_OBJECT

    public:
        explicit SolarForwardFrameGraph(Qt3DCore::QNode* parent = nullptr);
        virtual void setCamera(Qt3DCore::QEntity* camera) override;

    private:

        //render frame graph elements
        Qt3DRender::QSortPolicy* m_sortPolicy;
        Qt3DRender::QClearBuffers* m_clearBuffers;
        Qt3DRender::QCameraSelector* m_cameraSelector;
        Qt3DRender::QViewport* m_viewPort;
        Qt3DRender::QRenderSurfaceSelector* m_surfaceSelector;
        Qt3DRender::QTechniqueFilter* m_filter;
        Qt3DRender::QFrustumCulling* m_frustum;
    };
}

#endif // SOLARFORWARDFRAMEGRAPH_H
