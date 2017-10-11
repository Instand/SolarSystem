#ifndef DIFFUSEOBJECT_H
#define DIFFUSEOBJECT_H

#include <solar3dobject.h>
#include <QDiffuseMapMaterial>

namespace SolarSystem
{
    //Represents solar3dobject with diffuse material
    class DiffuseObject : public Solar3dObject
    {
        Q_OBJECT

    public:
        DiffuseObject(Qt3DCore::QNode* parent = nullptr);

    protected:
        virtual void update(float deltaTime) = 0;
    };
}

#endif // DIFFUSEOBJECT_H
