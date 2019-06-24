#ifndef SOLARSHADOWEFFECT_H
#define SOLARSHADOWEFFECT_H

#include <Qt3DRender/QEffect>
#include <Qt3DRender/QRenderPass>
#include <Qt3DRender/QTexture>
#include <Core/Render/solarlight.h>

namespace SolarSystem
{
    // repsents shadow map effect
    class SolarShadowEffect : public Qt3DRender::QEffect
    {
        Q_OBJECT

    public:
        explicit SolarShadowEffect(Qt3DCore::QNode* parent = nullptr);

        SolarLight* light() const;
        void setLight(SolarLight* light);

        Qt3DRender::QTexture2D* shadowTexture() const;
        void setShadowTexture(Qt3DRender::QTexture2D* texture);

        // init effect
        void initialization();

    private:

        // 1t shadow pass
        Qt3DRender::QRenderPass* m_shadowPass;

        // 2d standard gl pass
        Qt3DRender::QRenderPass* m_glPass;

        // light
        SolarLight* m_lightObject = nullptr;

        // texture
        Qt3DRender::QTexture2D* m_shadowTexture = nullptr;
    };
}

#endif // SOLARSHADOWEFFECT_H
