#ifndef SOLARSHADOWEFFECT_H
#define SOLARSHADOWEFFECT_H

#include <Qt3DRender/QEffect>
#include <Qt3DRender/QParameter>
#include <Qt3DRender/QFilterKey>
#include <Qt3DRender/QRenderPass>
//#include <Qt3DRender/QTe
#include <SolarCore/SolarRender/solarlight.h>

namespace SolarSystem {

    //repsents shadow map effect
    class SolarShadowEffect : public Qt3DRender::QEffect
    {
    public:
        SolarShadowEffect(Qt3DCore::QNode* parent = nullptr);

    private:

        //1 shadow pass
        Qt3DRender::QRenderPass* shadowPass;

        //2 standart gl pass
        Qt3DRender::QRenderPass* glPass;
    };
}

#endif // SOLARSHADOWEFFECT_H
