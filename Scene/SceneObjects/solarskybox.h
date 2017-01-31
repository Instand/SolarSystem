#ifndef SOLARSKYBOX_H
#define SOLARSKYBOX_H

#include <Qt3DExtras/QSkyboxEntity>

namespace SolarSystem {

    //represents space
    class SolarSkyBox : public Qt3DExtras::QSkyboxEntity {

        Q_OBJECT

    public:
        explicit SolarSkyBox(Qt3DCore::QNode *parent = nullptr);
    };

}

#endif // SOLARSKYBOX_H
