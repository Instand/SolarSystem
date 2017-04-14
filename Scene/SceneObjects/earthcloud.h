#ifndef EARTHCLOUD_H
#define EARTHCLOUD_H

#include <solar3dobject.h>

namespace SolarSystem {

    //represents earth cloud mesh
    class EarthCloud : public Solar3dObject
    {
        Q_OBJECT

    public:
        EarthCloud(Qt3DCore::QNode* parent = nullptr);

    protected:
        virtual void update(float deltaTime) override;
    };
}

#endif // EARTHCLOUD_H
