#ifndef ISOLARMATHCORE_H
#define ISOLARMATHCORE_H

#include <QObject>
#include <QDateTime>
#include "solarsystemcore.h"
#include <Qt3DRender/QCamera>
#include <SolarCore/planetscontainer.h>

namespace SolarSystem {

    //mathcore interface
    class ISolarMathCore : public QObject {

        Q_OBJECT

    public:

        //base
        ISolarMathCore(QObject* parent = 0);
        virtual ~ISolarMathCore();

        //set camera to control math operation
        virtual void setSolarView(Qt3DRender::QCamera* camera) = 0;

        //update camera settings
        virtual void updateSolarView(SolarObjects object) = 0;

        //update camera new position
        virtual QVector3D getNewSolarViewPosition(SolarObjects object, double radius) = 0;

        //out raiuds of solar object
        virtual float getOuterRadius(SolarObjects object) = 0;

        //calculate current solar object position in space
        virtual void solarObjectPosition(SolarObjects object) = 0;

        //set solar object current scale
        virtual float setSolarObjectScale(float scale, bool focused = false) = 0;

        //check solar object scale
        virtual void checkSolarObjectScaling(SolarObjects object) = 0;

        //dynamic change solar object scale
        virtual void changeSolarObjectScale(float scale, bool focused = false) = 0;

        //change current speed of solar object
        virtual void changeSolarObjectsSpeed(float speed) = 0;

        //change camera distance
        virtual void changeSolarViewDistance(double distance) = 0;

        //calculate time
        virtual void advanceTime(SolarObjects object) = 0;

        //add 3d container to math core
        virtual void setPlanetsContainer(PlanetArray array) = 0;

        //set all solar objects scale
        virtual void changeSolarSystemScale(float scale, bool focused = false) = 0;

        //set time between frames
        virtual void setDeltaTime(float dt) = 0;

        //get solar time
        virtual QDateTime getTime() const = 0;
    };

}

#endif // ISOLARMATHCORE_H
