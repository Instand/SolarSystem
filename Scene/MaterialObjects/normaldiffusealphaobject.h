#ifndef NORMALDIFFUSEALPHAOBJECT_H
#define NORMALDIFFUSEALPHAOBJECT_H

#include <solar3dobject.h>
#include <QNormalDiffuseMapAlphaMaterial>

namespace SolarSystem
{
    //Represents solar3dobject with normal diffuse alpha material
    class NormalDiffuseAlphaObject : public Solar3dObject
    {
        Q_OBJECT

    public:
        NormalDiffuseAlphaObject(Qt3DCore::QNode* parent = nullptr);

    protected:
        virtual void update(float deltaTime) = 0;
    };
}

#endif // NORMALDIFFUSEALPHAOBJECT_H
