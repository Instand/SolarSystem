#ifndef SOLARMATHCORE_H
#define SOLARMATHCORE_H

#include "SolarCore/isolarmathcore.h"
#include "SolarCore/solarobjectscontainer.h"

namespace SolarSystem
{
    //base solar math model
    //some realizations used from Qt QML Planets example
    class SolarMathCore : public ISolarMathCore
    {
        Q_OBJECT

    public:
        SolarMathCore(QObject* parent = nullptr);
        ~SolarMathCore();

        //realize interface
        virtual void setSolarView(Qt3DRender::QCamera *camera) override final;
        virtual float getOuterRadius(SolarObjects object) override final;
        virtual void solarObjectPosition(SolarObjects object) override final;
        virtual QVector3D getNewSolarViewPosition(SolarObjects object, double radius) override final;
        virtual void advanceTime(SolarObjects object) override final;
        virtual float setSolarObjectScale(float scale, bool focused) override final;
        virtual void checkSolarObjectScaling(SolarObjects object) override final;
        virtual void changeSolarObjectScale(float scale, bool focused) override final;
        virtual void updateSolarView(SolarObjects object) override final;
        virtual void changeSolarObjectsSpeed(float speed) override final;
        virtual void changeSolarViewDistance(double distance) override final;
        virtual void setPlanetsContainer(PlanetArray array) override final;
        virtual void changeSolarSystemScale(float scale, bool focused) override final;
        virtual void setDeltaTime(float dt) override final;
        virtual QDateTime getTime() const override final;
        virtual void ringsCalculation() override final;
        virtual void setCameraController(CameraController *controller) override final;
        virtual void updateSolarViewZoomLimit(SolarObjects object) override final;
        virtual void setSolarViewCenter(QVector3D center) override final;
        virtual QVector3D viewCenter() const override final;
        virtual QVector3D objectPosition(SolarObjects object) override final;
        virtual QVector3D viewPositionOfObject(SolarObjects object) override final;
        virtual QVector3D viewPosition() const override final;
        virtual void setSolarViewPosition(QVector3D position) override final;
        virtual float solarSystemSpeed() const override final;
        virtual QVector3D solarViewStartPositon() const override final;
        virtual void changeExtraSpeed() const override final;
        virtual double extraSpeed() const override final;
        virtual void resetExtraSpeed() const override final;

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

        //orbit camera controller
        CameraController* cameraController = nullptr;

        ///helper methods

        //days time scale calculation
        float calculateUT(int h, int m = 0, float s = 0);

        //time scale calculation
        float calculateTimeScale(int year, int month, int day);

        //rings setup
        void setupPlanetRings();

        //earth cloud calculation
        void additionalCalculations();

        //zoom limit calculation
        float calculateZoomLimit(SolarObjects object, float limit);

        //zoom limit calcualtion base
        float calculateZoomLimit(SolarObjects object);
    };
}

#endif // SOLARMATHCORE_H
