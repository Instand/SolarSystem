#ifndef NORMALDIFFUSEALPHAOBJECT_H
#define NORMALDIFFUSEALPHAOBJECT_H

#include <Scene/object3d.h>
#include <QNormalDiffuseMapAlphaMaterial>

namespace SolarSystem
{
    // represents solar3dobject with normal diffuse alpha material
    class NormalDiffuseAlphaObject : public Object3D
    {
        Q_OBJECT

    public:
        explicit NormalDiffuseAlphaObject(Qt3DCore::QNode* parent = nullptr);

    protected:
        virtual void update(float deltaTime) = 0;
    };
}

#endif // NORMALDIFFUSEALPHAOBJECT_H
