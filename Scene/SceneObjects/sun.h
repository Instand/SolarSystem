#ifndef SUN_H
#define SUN_H

#include <Scene/MaterialObjects/unlitobject.h>

namespace SolarSystem
{
    // represents sun with diffuse material
    class Sun final : public UnlitObject
    {
        Q_OBJECT

    public:
        explicit Sun(Qt3DCore::QNode* parent = nullptr);
    };
}

#endif // SUN_H
