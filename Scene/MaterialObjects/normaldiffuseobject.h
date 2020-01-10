#ifndef NORMALDIFFUSEOBJECT_H
#define NORMALDIFFUSEOBJECT_H

#include <Scene/object3d.h>
#include <QNormalDiffuseMapMaterial>

namespace SolarSystem
{
    // solar 3d object with normal diffuse map material
    class NormalDiffuseObject : public Object3D
    {
        Q_OBJECT

    public:
        explicit NormalDiffuseObject(Qt3DCore::QNode* parent = nullptr);
    };
}

#endif // NORMALDIFFUSEOBJECT_H
