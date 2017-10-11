#ifndef NORMALDIFFUSEOBJECT_H
#define NORMALDIFFUSEOBJECT_H

#include <solar3dobject.h>
#include <QNormalDiffuseMapMaterial>

namespace SolarSystem
{
    //solar 3d object with normal diffuse map material
    class NormalDiffuseObject : public Solar3dObject
    {
        Q_OBJECT

    public:
        NormalDiffuseObject(Qt3DCore::QNode* parent = nullptr);

    protected:
        virtual void update(float deltaTime) = 0;
    };
}

#endif // NORMALDIFFUSEOBJECT_H
