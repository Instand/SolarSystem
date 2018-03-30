#ifndef DIFFUSEOBJECT_H
#define DIFFUSEOBJECT_H

#include <Scene/solarobject3d.h>
#include <QDiffuseMapMaterial>

namespace SolarSystem
{
    //Represents solar3dobject with diffuse material
    class DiffuseObject : public SolarObject3D
    {
        Q_OBJECT

    public:
        DiffuseObject(Qt3DCore::QNode* parent = nullptr);

    protected:
        virtual void update(float deltaTime) = 0;
    };
}

#endif // DIFFUSEOBJECT_H
