#ifndef SOLARMATHCORE_H
#define SOLARMATHCORE_H

#include "SolarCore/isolarmathcore.h"

namespace SolarSystem {

    //base solar math model
    //some realizations get from Qt QML Planets example
    class SolarMathCore : public ISolarMathCore {

        Q_OBJECT

    public:
        SolarMathCore(QObject* parent = nullptr);
        ~ISolarMathCore();

        //realize interface
        virtual void setSolarView(Qt3DRender::QCamera *camera) override;
        virtual float getOuterRadius(SolarObjects object) override;
        virtual QVector3D solarObjectPosition(SolarObjects object) override;

    private:
        Qt3DRender::QCamera* camera;
    };

}

#endif // SOLARMATHCORE_H
