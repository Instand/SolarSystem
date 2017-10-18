#ifndef UNLITOBJECT_H
#define UNLITOBJECT_H

#include <solar3dobject.h>
#include <QTextureMaterial>

namespace SolarSystem
{
    //Represents solar 3d object with unlit material
    class UnlitObject : public Solar3dObject
    {
        Q_OBJECT

    public:
        UnlitObject(Qt3DCore::QNode* parent = nullptr);

    protected:
        virtual void update(float deltaTime) = 0;
    };
}

#endif // UNLITOBJECT_H
