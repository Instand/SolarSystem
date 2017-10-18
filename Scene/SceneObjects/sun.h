#ifndef SUN_H
#define SUN_H

#include <Scene/MaterialObjects/unlitobject.h>

namespace SolarSystem
{
    //Represents sun with diffuse material
    class Sun final : public UnlitObject
    {
        Q_OBJECT

    public:
        Sun(Qt3DCore::QNode* parent = nullptr);

    protected:
        virtual void update(float deltaTime) override;
    };
}

#endif // SUN_H
