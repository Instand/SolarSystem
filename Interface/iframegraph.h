#ifndef IFRAMEGRAPH_H
#define IFRAMEGRAPH_H

#include <Qt3DRender/QRenderSettings>

namespace SolarSystem
{
    // represents abstract frame graph class
    class IFrameGraph : public Qt3DRender::QRenderSettings
    {
        Q_OBJECT

    public:
        explicit IFrameGraph(Qt3DCore::QNode* parent = nullptr):
            QRenderSettings(parent) {}

        virtual void setCamera(Qt3DCore::QEntity* camera) = 0;
    };
}

#endif // IFRAMEGRAPH_H
