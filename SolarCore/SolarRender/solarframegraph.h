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
        Qt3DRender::QCamera* viewCamera() const;

        void setLightCamera(Qt3DRender::QCamera* lightCamera);
        Qt3DRender::QCamera* lightCamera() const;

        //shadow texture
        Qt3DRender::QTexture2D* shadowTexture() const;

    private:

        //view port
        Qt3DRender::QViewport* m_viewPort;

        //texture
        Qt3DRender::QTexture2D* m_texture;

        //selector
        Qt3DRender::QRenderSurfaceSelector* m_selector;

        //filter
        Qt3DRender::QTechniqueFilter* m_techniqueFilter;

        //pass
        Qt3DRender::QRenderPassFilter* m_renderPassShadowFilter;
        Qt3DRender::QRenderPassFilter* m_renderPassForwardFilter;

        //target selector
        Qt3DRender::QRenderTargetSelector* m_targetSelector;

        //camera selectors
        Qt3DRender::QCameraSelector* m_lightCameraSelector;
        Qt3DRender::QCameraSelector* m_viewCameraSelector;
    };
}

#endif // SOLARFRAMEGRAPH_H
