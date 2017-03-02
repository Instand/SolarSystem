#ifndef PLANETRINGALPHA_H
#define PLANETRINGALPHA_H

#include <Scene/basevisualsolarobject.h>
#include <Qt3DExtras/QNormalDiffuseMapAlphaMaterial>
#include <Qt3DRender/QTextureImage>
#include <Qt3DRender/QTextureWrapMode>

namespace SolarSystem {

    //Alpha material ring
    class PlanetRingAlpha : public BaseVisualSolarObject
    {
        Q_OBJECT

    public:
        PlanetRingAlpha(Qt3DCore::QNode* parent = nullptr);

        //get object properties
        virtual Qt3DRender::QObjectPicker& picker() const override final;
        Qt3DExtras::QNormalDiffuseMapAlphaMaterial& material() const;
        Qt3DRender::QTextureImage& diffuse() const;

    protected:
        virtual void update(float deltaTime);

    protected:
        Qt3DRender::QObjectPicker* _picker;

        //vizibility
        Qt3DExtras::QNormalDiffuseMapAlphaMaterial* _material;

        //main default texture
        Qt3DRender::QTextureImage* _diffuse;

        //texture setup
        Qt3DRender::QTextureWrapMode wrapMode;
    };
}

#endif // PLANETRINGALPHA_H
