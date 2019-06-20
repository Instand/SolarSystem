#ifndef PLANET_H
#define PLANET_H

#include <Scene/MaterialObjects/normaldiffuseobject.h>

namespace SolarSystem
{
    // base class for solar planets
    class Planet : public NormalDiffuseObject
    {
        Q_OBJECT

    public:
        explicit Planet(Qt3DCore::QNode* parent = nullptr);

    protected:
        virtual void update(float deltaTime) override;
    };
}

#endif // PLANET_H
