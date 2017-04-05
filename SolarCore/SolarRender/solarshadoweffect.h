#ifndef SOLARSHADOWEFFECT_H
#define SOLARSHADOWEFFECT_H

#include <Qt3DRender/QEffect>
#include <Qt3DRender/QRenderPass>
#include <Qt3DRender/QTexture>
#include <SolarCore/SolarRender/solarlight.h>

namespace SolarSystem {

    //repsents shadow map effect
    class SolarShadowEffect : public Qt3DRender::QEffect
    {
        Q_OBJECT

    public:
        SolarShadowEffect(Qt3DCore::QNode* parent = nullptr);

        //get/set light
        SolarLight* light() const;
        void setLight(SolarLight* light);

        //get/set shadow texture
        Qt3DRender::QTexture2D* shadowTexture() const;
        void setShadowTexture(Qt3DRender::QTexture2D* texture);

        //init effect
        void initialization();

    private:

        //1t shadow pass
        Qt3DRender::QRenderPass* shadowPass;

        //2d standard gl pass
        Qt3DRender::QRenderPass* glPass;

        //light
        SolarLight* lightObject = nullptr;

        //texture
        Qt3DRender::QTexture2D* shadowTex = nullptr;
    };
}

#endif // SOLARSHADOWEFFECT_H
