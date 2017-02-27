#ifndef PLANET_H
#define PLANET_H

#include <solar3dobject.h>

namespace SolarSystem {

    //base class for solar planets
    class Planet : public Solar3dObject {

        Q_OBJECT

    public:
        Planet(Qt3DCore::QNode* parent = nullptr);

    protected:
        virtual void update(float deltaTime) override;
    };
}


#endif // PLANET_H
