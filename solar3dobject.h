#ifndef SOLAR3DOBJECT_H
#define SOLAR3DOBJECT_H

#include <SolarCore/SolarRender/solarmaterial.h>
#include "Scene/basevisualsolarobject.h"

namespace SolarSystem {

    //class for rendering base 3d object in solar system
    class Solar3dObject : public BaseVisualSolarObject {

        Q_OBJECT

    public:
        Solar3dObject(Qt3DCore::QNode* parent = 0);

        //get object properties
        virtual Qt3DRender::QObjectPicker& picker() const override final;
        SolarMaterial& material() const;

    protected:
        virtual void update(float deltaTime) = 0;

    protected:
        Qt3DRender::QObjectPicker* _picker;

        //vizibility
        SolarMaterial* _material;
    };

}

#endif // SOLAR3DOBJECT_H
