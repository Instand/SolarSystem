#ifndef SOLAR3DOBJECT_H
#define SOLAR3DOBJECT_H

#include <SolarCore/SolarRender/solarmaterial.h>
#include <Qt3DExtras/QNormalDiffuseSpecularMapMaterial>
#include <Qt3DRender/QTextureImage>
#include "Scene/basevisualsolarobject.h"

namespace SolarSystem
{
    //class for rendering base 3d object in solar system
    class Solar3dObject : public BaseVisualSolarObject
    {
        Q_OBJECT

    public:
        Solar3dObject(Qt3DCore::QNode* parent = 0);

        //get object properties
        virtual Qt3DRender::QObjectPicker& picker() const override final;

#ifdef QT3D_MATERIALS
        Qt3DExtras::QNormalDiffuseSpecularMapMaterial& material() const;
        Qt3DRender::QTextureImage& diffuse() const;
#else
        SolarMaterial& material() const;
#endif

    protected:
        virtual void update(float deltaTime) = 0;

    protected:
        Qt3DRender::QObjectPicker* _picker;

#ifndef QT3D_MATERIALS
        //vizibility
        SolarMaterial* _material;
#else
        //vizibility
        Qt3DExtras::QNormalDiffuseSpecularMapMaterial* _material;

        //main default texture
        Qt3DRender::QTextureImage* _diffuse;
#endif
    };
}

#endif // SOLAR3DOBJECT_H
