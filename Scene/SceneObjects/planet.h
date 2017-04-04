#ifndef PLANET_H
#define PLANET_H

#include <solar3dobject.h>
#include <Qt3DRender/QTextureWrapMode>

namespace SolarSystem {

    //base class for solar planets
    class Planet : public Solar3dObject {

        Q_OBJECT

    public:
        Planet(Qt3DCore::QNode* parent = nullptr);

    protected:
        virtual void update(float deltaTime) override;

    private:

        //texture setup
        Qt3DRender::QTextureWrapMode wrapMode;
    };
}


#endif // PLANET_H
