#ifndef SOLARMATHCORE_H
#define SOLARMATHCORE_H

#include <QObject>
#include <QDateTime>
#include <solarsystemcore.h>

namespace Qt3DRender
{
    class QCamera;
}

namespace SolarSystem
{
    class PlanetsContainer;
    class CameraController;
    class SolarObjectsContainer;

    //base solar math model
    //some realizations used from Qt QML Planets example
    class SolarMathCore : public QObject
    {
        Q_OBJECT

    private:
        explicit SolarMathCore(QObject* parent = nullptr);

    public:
        virtual ~SolarMathCore();

        //creates solar math core only once
        static SolarMathCore* instance();

        //sets camera
        void setSolarView(Qt3DRender::QCamera* camera);

        //returns camera
        Qt3DRender::QCamera* solarView() const;

        //returns outer radius of solar object
        float getOuterRadius(SolarObjects object);

        //calcualtes current time
        void advanceTime(SolarObjects object);

        //checks and sets solar objects actual scale
        void setSolarObjectsScale(float scale, bool focused = false);

        //sets camera view center to solar object
        void updateSolarView(SolarObjects object);

        //sets days per frame scale speed
        void setSolarSystemSpeed(float speed);

        //sets planets container with SolarObject3D
        void setPlanetsContainer(PlanetsContainer* planetsContainer);

        //recalculate all system objects scale
        void changeSolarSystemScale(float scale, bool focused = false);

        //sets to math core tick delta time
        void setDeltaTime(float dt);

        //returns current calculated solar time
        QDateTime getTime() const;

        //calculates solar system non-planet positions
        void additionalCalculation();

        //sets camera controller
        void setCameraController(CameraController* controller);

        //returns camera controller
        CameraController* viewController() const;

        //updates camera min zoom position
        void updateSolarViewZoomLimit(SolarObjects object);

        //returns solar object position
        QVector3D objectPosition(SolarObjects object);

        //returns position of solar view to solar object
        QVector3D viewPositionOfObject(SolarObjects object);

        //returns current solar system speed (days per frame)
        float solarSystemSpeed() const;

        //calcualtes next step of ultra speed
        void changeExtraSpeed() const;

        //returns utral speed
        double extraSpeed() const;

        //sets uultra speed to default value
        void resetExtraSpeed() const;

        //calculates all planets container solar objects position
        void calculateAllSolarObjectsPosiitons();

    private:

        //forward
        struct Data;

        //main math data
        Data* data;

        ///helper methods

        // calculates solar object current position
        void solarObjectPosition(SolarObjects object);

        //rings setup
        void setupPlanetRings();

        //earth cloud calculation
        void atmosphereCalculations();

        //zoom limit calculation
        float calculateZoomLimit(SolarObjects object, float limit);

        //zoom limit calcualtion base
        float calculateZoomLimit(SolarObjects object);
    };
}

#endif // SOLARMATHCORE_H
