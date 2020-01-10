#ifndef EARTHCLOUD_H
#define EARTHCLOUD_H

#include <solarsystemcore.h>
#include <Scene/MaterialObjects/normaldiffusealphaobject.h>

namespace SolarSystem
{
    // represents earth cloud mesh
    class EarthCloud : public NormalDiffuseAlphaObject
    {
        Q_OBJECT

    public:
        explicit EarthCloud(Qt3DCore::QNode* parent = nullptr);
    };
}

#endif // EARTHCLOUD_H
