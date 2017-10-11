#ifndef PLANETRING_H
#define PLANETRING_H

#include <Scene/MaterialObjects/normaldiffusealphaobject.h>

namespace SolarSystem
{
    //Represents a planet ring, for example saturn and uranus rings
    class PlanetRing : public NormalDiffuseAlphaObject
    {
        Q_OBJECT

    public:
        PlanetRing(Qt3DCore::QNode* parent = nullptr);

    protected:
        virtual void update(float deltaTime) override;
    };
}

#endif // PLANETRING_H
