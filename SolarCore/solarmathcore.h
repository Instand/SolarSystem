#ifndef SOLARMATHCORE_H
#define SOLARMATHCORE_H

#include "SolarCore/isolarmathcore.h"
#include "SolarCore/solarobjectscontainer.h"

namespace SolarSystem {

    //base solar math model
    //some realizations get from Qt QML Planets example
    class SolarMathCore : public ISolarMathCore {

        Q_OBJECT

    public:
        SolarMathCore(QObject* parent = nullptr);
        ~SolarMathCore();

        //realize interface
        virtual void setSolarView(Qt3DRender::QCamera *camera) override;
        virtual float getOuterRadius(SolarObjects object) override;
        virtual void solarObjectPosition(SolarObjects object) override;
        virtual QVector3D getNewSolarViewPosition(SolarObjects object, double radius) override;
        virtual void advanceTime(SolarObjects object) override;
        virtual float setSolarObjectScale(float scale, bool focused) override;
        virtual void checkSolarObjectScaling(SolarObjects object) override;
        virtual void changeSolarObjectScale(float scale, bool focused) override;
        virtual void updateSolarView(SolarObjects object) override;
        virtual void changeSolarObjectsSpeed(float speed) override;
        virtual void changeSolarViewDistance(double distance) override;
        virtual void setPlanetsContainer(PlanetArray array) override;
        virtual void changeSolarSystemScale(float scale, bool focused) override;

    private:

        //forward
        struct Data;

        //main math data
        Data* data;

        //view
        Qt3DRender::QCamera* camera;

        //math solar objects
        SolarObjectsContainer solarContainer;

        //planet container elements
        PlanetArray planetContainer;
    };

}

#endif // SOLARMATHCORE_H
