#ifndef PLANETRING_H
#define PLANETRING_H

#include <Scene/MaterialObjects/normaldiffusealphaobject.h>

namespace SolarSystem
{
    // represents a planet ring, for example saturn and uranus rings
    class PlanetRing : public NormalDiffuseAlphaObject
    {
        Q_OBJECT

    public:
        explicit PlanetRing(Qt3DCore::QNode* parent = nullptr);
    };
}

#endif // PLANETRING_H
