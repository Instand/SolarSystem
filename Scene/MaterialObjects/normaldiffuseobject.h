#ifndef NORMALDIFFUSEOBJECT_H
#define NORMALDIFFUSEOBJECT_H

#include <Scene/solarobject3d.h>
#include <QNormalDiffuseMapMaterial>

namespace SolarSystem
{
    //solar 3d object with normal diffuse map material
    class NormalDiffuseObject : public SolarObject3D
    {
        Q_OBJECT

    public:
        NormalDiffuseObject(Qt3DCore::QNode* parent = nullptr);

    protected:
        virtual void update(float deltaTime) = 0;
    };
}

#endif // NORMALDIFFUSEOBJECT_H
