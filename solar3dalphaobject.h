#ifndef SOLAR3DALPHAOBJECT_H
#define SOLAR3DALPHAOBJECT_H

#include <Qt3DExtras/QNormalDiffuseMapAlphaMaterial>
#include <Qt3DRender/QTextureImage>
#include "Scene/basevisualsolarobject.h"

namespace SolarSystem
{
    //just like solar3dobject but with different aplha material
    class Solar3DAlphaObject : public BaseVisualSolarObject
    {
        Q_OBJECT

    public:
        Solar3DAlphaObject(Qt3DCore::QNode* parent = nullptr);

        //get object properties
        virtual Qt3DRender::QObjectPicker& picker() const override final;
        Qt3DExtras::QNormalDiffuseMapAlphaMaterial& material() const;
        Qt3DRender::QTextureImage& diffuse() const;

    protected:
        virtual void update(float deltaTime) = 0;

        Qt3DRender::QObjectPicker* _picker;

        //vizibility
        Qt3DExtras::QNormalDiffuseMapAlphaMaterial* _material;

        //main default texture
        Qt3DRender::QTextureImage* _diffuse;
    };
}

#endif // SOLAR3DALPHAOBJECT_H
