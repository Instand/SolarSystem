#ifndef PLANETRING_H
#define PLANETRING_H

#include <solarsystemcore.h>

#ifdef QT3D_MATERIALS
#include <Scene/basevisualsolarobject.h>
#include <Qt3DExtras/QNormalDiffuseMapAlphaMaterial>
#include <Qt3DRender/QTextureImage>
#include <Qt3DRender/QTextureWrapMode>
#else
#include <SolarCore/SolarRender/solarmaterial.h>
#include <solar3dobject.h>
#endif

namespace SolarSystem
{
#ifndef QT3D_MATERIALS
    //represents a planet ring, for example saturn and uranus rings
    class PlanetRing : public Solar3dObject
    {
        Q_OBJECT

    public:
        PlanetRing(Qt3DCore::QNode* parent = nullptr);

    protected:

        //main update
        virtual void update(float deltaTime) override;
    };
#else
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
#endif
}

#endif // PLANETRING_H
