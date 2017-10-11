#ifndef EMPTYSOLAROBJECT_H
#define EMPTYSOLAROBJECT_H

#include "solar3dobject.h"

namespace SolarSystem
{
    //empty object can be placed on the scene without any rendering, but with some interesting features
    class EmptySolarObject: public Solar3dObject
    {
        Q_OBJECT

    public:
        EmptySolarObject(Qt3DCore::QNode* parent = nullptr);

    protected:
        virtual void update(float deltaTime) override;
    };
}

#endif // EMPTYSOLAROBJECT_H
