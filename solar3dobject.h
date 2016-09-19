#ifndef SOLAR3DOBJECT_H
#define SOLAR3DOBJECT_H

#include <Qt3DExtras/QNormalDiffuseSpecularMapMaterial>
#include <Qt3DRender/QObjectPicker>
#include <Qt3DRender/QTextureImage>
#include "Scene/basevisualsolarobject.h"

namespace SolarSystem {

    //class for rendering base 3d object in solar system
    class Solar3dObject : public BaseVisualSolarObject {

        Q_OBJECT

    public:
        Solar3dObject(Qt3DCore::QNode* parent = 0);

        //get object properties
        Qt3DRender::QObjectPicker& picker() const;
        Qt3DExtras::QNormalDiffuseSpecularMapMaterial& material() const;
        Qt3DRender::QTextureImage& diffuse() const;
        Qt3DRender::QTextureImage& normal() const;

    protected:
        virtual void update(float deltaTime) override;

    private:
        Qt3DRender::QObjectPicker* _picker;

        //vizibility
        Qt3DExtras::QNormalDiffuseSpecularMapMaterial* _material;
        Qt3DRender::QTextureImage* _diffuseImage;
        Qt3DRender::QTextureImage* _normalImage;

    };

}

#endif // SOLAR3DOBJECT_H
