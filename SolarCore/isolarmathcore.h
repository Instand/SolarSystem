#ifndef ISOLARMATHCORE_H
#define ISOLARMATHCORE_H

#include <QObject>
#include <QDateTime>
#include "solarsystemcore.h"
#include <Qt3DRender/QCamera>
#include <SolarCore/planetscontainer.h>

namespace SolarSystem {

    //forward
    class CameraController;

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

        //calcualte planet rings
        virtual void ringsCalculation() = 0;

        //add camera controller
        virtual void setCameraController(CameraController* controller) = 0;

        //zoom limit update
        virtual void updateSolarViewZoomLimit(SolarObjects object) = 0;

        //set solar camera view center
        virtual void setSolarViewCenter(QVector3D center) = 0;

        //get current view center
        virtual QVector3D viewCenter() const = 0;

        //returns coords of solar object
        virtual QVector3D objectPosition(SolarObjects object) = 0;

        //returns coords of camera to solar object
        virtual QVector3D viewPositionOfObject(SolarObjects object) = 0;

        //returns camera position
        virtual QVector3D viewPosition() const = 0;

        //set solar camera view position
        virtual void setSolarViewPosition(QVector3D positon) = 0;

        //get current solar delta time
        virtual float solarSystemSpeed() const = 0;

        //returns start cam pos
        virtual QVector3D solarViewStartPositon() const = 0;
    };

}

#endif // ISOLARMATHCORE_H
