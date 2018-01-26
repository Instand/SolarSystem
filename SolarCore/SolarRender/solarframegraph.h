#ifndef SOLARFRAMEGRAPH_H
#define SOLARFRAMEGRAPH_H

#include <Qt3DRender/QRenderSettings>

namespace Qt3DRender
{
    class QCamera;
    class QViewport;
    class QTexture2D;
    class QRenderSurfaceSelector;
    class QTechniqueFilter;
    class QRenderPassFilter;
    class QRenderTargetSelector;
    class QCameraSelector;
}

namespace SolarSystem
{
    //represents base active frame graph
    class SolarFrameGraph : public Qt3DRender::QRenderSettings
    {
        Q_OBJECT

    public:
        explicit SolarFrameGraph(Qt3DCore::QNode* parent = nullptr);

        //cameras
        void setViewCamera(Qt3DRender::QCamera* viewCamera);
        void setLightCamera(Qt3DRender::QCamera* lightCamera);
        Qt3DRender::QCamera* viewCamera() const;
        Qt3DRender::QCamera* lightCamera() const;

        //shadow texture
        Qt3DRender::QTexture2D* shadowTexture() const;

    private:

        //view port
        Qt3DRender::QViewport* viewPort;

        //texture
        Qt3DRender::QTexture2D* texture;

        //selector
        Qt3DRender::QRenderSurfaceSelector* selector;

        //filter
        Qt3DRender::QTechniqueFilter* tFilter;

        //pass
        Qt3DRender::QRenderPassFilter* renderPassShadowFilter;
        Qt3DRender::QRenderPassFilter* renderPassForwardFilter;

        //target selector
        Qt3DRender::QRenderTargetSelector* targetSelector;

        //camera selectors
        Qt3DRender::QCameraSelector* lightCameraSelector;
        Qt3DRender::QCameraSelector* viewCameraSelector;
    };
}

#endif // SOLARFRAMEGRAPH_H
