#ifndef PLANETRING_H
#define PLANETRING_H

#include <Scene/basevisualsolarobject.h>
#include <Qt3DExtras/QNormalDiffuseMapAlphaMaterial>
#include <Qt3DRender/QTextureImage>
#include <Qt3DRender/QTextureWrapMode>

namespace SolarSystem {

    //represents a planet ring, for example saturn and uranus rings
    class PlanetRing : public BaseVisualSolarObject
    {
        Q_OBJECT

    public:
        PlanetRing(Qt3DCore::QNode* parent = nullptr);

        //get object properties
        virtual Qt3DRender::QObjectPicker& picker() const override final;
        Qt3DExtras::QNormalDiffuseMapAlphaMaterial& material() const;
        Qt3DRender::QTextureImage& diffuse() const;

    protected:

        //main update
        virtual void update(float deltaTime) override;

    protected:

        //object picker
        Qt3DRender::QObjectPicker* _picker;

        //vizibility
        Qt3DExtras::QNormalDiffuseMapAlphaMaterial* _material;

        //main default texture
        Qt3DRender::QTextureImage* _diffuse;

        //texture setup
        Qt3DRender::QTextureWrapMode wrapMode;
    };
}

#endif // PLANETRING_H
