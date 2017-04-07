#ifndef SOLARFORWARDFRAMEGRAPH_H
#define SOLARFORWARDFRAMEGRAPH_H

#include <Qt3DRender/QRenderSettings>

namespace Qt3DRender {
    class QCamera;
    class QSortPolicy;
    class QClearBuffers;
    class QCameraSelector;
    class QViewport;
    class QRenderSurfaceSelector;
    class QTechniqueFilter;
    class QFrustumCulling;
}

namespace SolarSystem {

    //represents simple forward frame graph
    class SolarForwardFrameGraph : public Qt3DRender::QRenderSettings
    {
        Q_OBJECT

    public:
        explicit SolarForwardFrameGraph(Qt3DCore::QNode* parent = nullptr);
        void setCamera(Qt3DRender::QCamera* camera);

    private:

        //render frame graph elements
        Qt3DRender::QSortPolicy* sortPolicy;
        Qt3DRender::QClearBuffers* clearBuffers;
        Qt3DRender::QCameraSelector* cameraSelector;
        Qt3DRender::QViewport* viewPort;
        Qt3DRender::QRenderSurfaceSelector* surfaceSelector;
        Qt3DRender::QTechniqueFilter* filter;
        Qt3DRender::QFrustumCulling* frustum;
    };
}

#endif // SOLARFORWARDFRAMEGRAPH_H
