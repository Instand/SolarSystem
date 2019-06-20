#ifndef UNLITOBJECT_H
#define UNLITOBJECT_H

#include <Scene/object3d.h>
#include <QTextureMaterial>

namespace SolarSystem
{
    // represents solar 3d object with unlit material
    class UnlitObject : public Object3D
    {
        Q_OBJECT

    public:
        explicit UnlitObject(Qt3DCore::QNode* parent = nullptr);

    protected:
        virtual void update(float deltaTime) = 0;
    };
}

#endif // UNLITOBJECT_H
