#ifndef DIFFUSEOBJECT_H
#define DIFFUSEOBJECT_H

#include <Scene/object3d.h>
#include <QDiffuseMapMaterial>

namespace SolarSystem
{
    // represents solar3dobject with diffuse material
    class DiffuseObject : public Object3D
    {
        Q_OBJECT

    public:
        explicit DiffuseObject(Qt3DCore::QNode* parent = nullptr);

    protected:
        virtual void update(float deltaTime) = 0;
    };
}

#endif // DIFFUSEOBJECT_H
