#ifndef EARTHCLOUD_H
#define EARTHCLOUD_H

#include <solarsystemcore.h>
#include <Scene/MaterialObjects/normaldiffusealphaobject.h>

namespace SolarSystem
{
    //represents earth cloud mesh
    class EarthCloud : public NormalDiffuseAlphaObject
    {
        Q_OBJECT

    public:
        EarthCloud(Qt3DCore::QNode* parent = nullptr);

    protected:
        virtual void update(float deltaTime) override;
    };
}

#endif // EARTHCLOUD_H
