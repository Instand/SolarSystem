#ifndef EMPTYSOLAROBJECT_H
#define EMPTYSOLAROBJECT_H

#include <Scene/object3d.h>

namespace SolarSystem
{
    // empty object can be placed on the scene without any rendering, but with some interesting features
    class EmptySolarObject: public Object3D
    {
        Q_OBJECT

    public:
        explicit EmptySolarObject(Qt3DCore::QNode* parent = nullptr);

    protected:
        virtual void update(float deltaTime) override;
    };
}

#endif // EMPTYSOLAROBJECT_H
