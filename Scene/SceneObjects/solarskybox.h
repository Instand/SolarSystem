#ifndef SOLARSKYBOX_H
#define SOLARSKYBOX_H

#include <Qt3DExtras/QSkyboxEntity>
#include <Qt3DRender/QCamera>
#include <QTimer>

namespace SolarSystem {

    //represents space
    class SolarSkyBox : public Qt3DExtras::QSkyboxEntity {

        Q_OBJECT

    public:
        explicit SolarSkyBox(Qt3DCore::QNode *parent = nullptr);
        ~SolarSkyBox();
        void setCamera(Qt3DRender::QCamera* camera);

    private:
        Qt3DRender::QCamera* _camera = nullptr;
        QTimer* positionTimer;
        uint updateInterval = 15;
    };

}

#endif // SOLARSKYBOX_H
