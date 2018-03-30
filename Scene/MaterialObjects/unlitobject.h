#ifndef UNLITOBJECT_H
#define UNLITOBJECT_H

#include <Scene/solarobject3d.h>
#include <QTextureMaterial>

namespace SolarSystem
{
    //Represents solar 3d object with unlit material
    class UnlitObject : public SolarObject3D
    {
        Q_OBJECT

    public:
        UnlitObject(Qt3DCore::QNode* parent = nullptr);

    protected:
        virtual void update(float deltaTime) = 0;
    };
}

#endif // UNLITOBJECT_H
