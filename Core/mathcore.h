#ifndef MATHCORE_H
#define MATHCORE_H

#include <QObject>
#include <QDateTime>
#include <solarsystemcore.h>

namespace Qt3DRender
{
    class QCamera;
}

namespace SolarSystem
{
    class Object3DContainer;
    class CameraController;
    class SolarObjectsContainer;

    // base solar math model
    // some realizations used from Qt QML Planets example
    class MathCore final : public QObject
    {
        Q_OBJECT

        Q_PROPERTY(float solarSystemSpeed READ solarSystemSpeed WRITE setSolarSystemSpeed NOTIFY solarSystemSpeedChanged)
        Q_PROPERTY(float cameraRoll READ cameraRoll WRITE setCameraRoll NOTIFY cameraRollChanged)

    private:
        explicit MathCore(QObject* parent = nullptr);
        ~MathCore();

        MathCore(const MathCore&) = delete;
        MathCore(MathCore&&) = delete;
        MathCore& operator=(const MathCore&) = delete;
        MathCore& operator=(MathCore&&) = delete;

    public:

        // creates solar math core only once
        static MathCore* instance();

        void setCamera(Qt3DRender::QCamera* camera);
        Qt3DRender::QCamera* camera() const;

        // returns outer radius of solar object
        float getOuterRadius(SolarObjects object);

        // calcualtes current time
        void advanceTime(SolarObjects object);

        // checks and sets solar objects actual scale
        void setSolarObjectsScale(float scale, bool focused = false);

        // sets camera view center to solar object
        void updateSolarView(SolarObjects object);

        // sets days per frame scale speed
        void setSolarSystemSpeed(float speed);

        // sets planets container with Object3D
        void setObject3DContainer(Object3DContainer* planetsContainer);

        // recalculates all system objects scale
        void changeSolarSystemScale(float scale, bool focused = false);

        // sets to math core tick delta time
        void setDeltaTime(float dt);

        // returns current calculated solar time
        QDateTime getTime() const;

        // calculates solar system non-planet positions
        void additionalCalculation();

        // sets camera controller
        void setCameraController(CameraController* controller);

        // returns camera controller
        CameraController* cameraController() const;

        // updates camera min zoom position
        void updateSolarViewZoomLimit(SolarObjects object);

        // returns solar object position
        QVector3D objectPosition(SolarObjects object);

        // returns position of solar view to solar object
        QVector3D viewPositionOfObject(SolarObjects object);

        // returns current solar system speed (days per frame)
        float solarSystemSpeed() const;

        // calcualtes next step of ultra speed
        void changeExtraSpeed() const;

        // returns utral speed
        double extraSpeed() const;

        // sets ultra speed to default value
        void resetExtraSpeed() const;

        // calculates all objects container solar objects position
        void calculateAllSolarObjectsPosiitons();

        // performs main calculation of math core
        void calculate(float deltaTime, SolarObjects object);

        // returns current camera Z rotation
        float cameraRoll() const;
        Q_INVOKABLE void setCameraRoll(float roll);

    signals:
        void solarSystemSpeedChanged(float);
        void solarTimeChanged(const QDateTime&);
        void cameraRollChanged(float);

    private:
        struct Data;
        Data* data;

        /// helper methods

        // calculates solar object current position
        void calculateObjectPosition(SolarObjects object);

        void setupPlanetRings();
        void atmosphereCalculations();

        float calculateZoomLimit(SolarObjects object, float limit);
        float calculateZoomLimit(SolarObjects object);
    };
}

#endif // MATHCORE_H
