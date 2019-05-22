#ifndef SOLARSTANDARDFRAMEGRAPH_H
#define SOLARSTANDARDFRAMEGRAPH_H

#include <Interface/iframegraph.h>

namespace Qt3DExtras
{
    class QForwardRenderer;
}

namespace SolarSystem
{
    //Represents standard forward frame graph
    class SolarStandardFrameGraph : public IFrameGraph
    {
        Q_OBJECT

    public:
        explicit SolarStandardFrameGraph(Qt3DCore::QNode* parent = nullptr);

        //sets camera to forward renderer
        virtual void setCamera(Qt3DCore::QEntity* camera) override;

    private:
        Qt3DExtras::QForwardRenderer* m_renderer;
    };
}

#endif // SOLARSTANDARDFRAMEGRAPH_H
