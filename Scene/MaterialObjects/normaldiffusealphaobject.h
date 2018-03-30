#ifndef NORMALDIFFUSEALPHAOBJECT_H
#define NORMALDIFFUSEALPHAOBJECT_H

#include <Scene/solarobject3d.h>
#include <QNormalDiffuseMapAlphaMaterial>

namespace SolarSystem
{
    //Represents solar3dobject with normal diffuse alpha material
    class NormalDiffuseAlphaObject : public SolarObject3D
    {
        Q_OBJECT

    public:
        NormalDiffuseAlphaObject(Qt3DCore::QNode* parent = nullptr);

    protected:
        virtual void update(float deltaTime) = 0;
    };
}

#endif // NORMALDIFFUSEALPHAOBJECT_H
