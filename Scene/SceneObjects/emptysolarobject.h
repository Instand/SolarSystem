#ifndef EMPTYSOLAROBJECT_H
#define EMPTYSOLAROBJECT_H

#include "Scene/basevisualsolarobject.h"

namespace SolarSystem {

    //empty object can be placed on the scene without any rendering, but with some interesting features
    class EmptySolarObject: public BaseVisualSolarObject {

        Q_OBJECT

    public:
        EmptySolarObject(Qt3DCore::QNode* parent = 0);

    protected:
        virtual void update(float deltaTime) override;
    };

}

#endif // EMPTYSOLAROBJECT_H
