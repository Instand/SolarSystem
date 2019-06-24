#ifndef SOLAROBJECTEFFECT_H
#define SOLAROBJECTEFFECT_H

#include <Qt3DRender/QEffect>
#include <Qt3DRender/QRenderPass>

#include <Core/Render/solarlight.h>

namespace SolarSystem
{
    // represents any solid solar system body effect
    class SolarObjectEffect : public Qt3DRender::QEffect
    {
        Q_OBJECT

    public:
        explicit SolarObjectEffect(Qt3DCore::QNode* parent = nullptr);

        SolarLight* light() const;
        void setLight(SolarLight* light);

        QString vertexShaderSource() const;
        QString fragmentShaderSource() const;

        void setVertexShaderSource(const QString& source);
        void setFragmentShaderSource(const QString& source);

        // init effect
        void initialization();

    private:

        // standard gl pass
        Qt3DRender::QRenderPass* m_glPass;

        // light
        SolarLight* m_lightObject = nullptr;

        // shaders source
        QString m_vertexShaderGL;
        QString m_fragShaderGL;
    };
}

#endif // SOLAROBJECTEFFECT_H
