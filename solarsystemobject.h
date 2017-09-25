#ifndef SOLARSYSTEMOBJECT_H
#define SOLARSYSTEMOBJECT_H

#include <QObject>
#include <QString>
#include "solarsystemcore.h"
#include "Interface/isolarsystemobject.h"

namespace SolarSystem
{
    //base object of solar system for storing info from database
    class SolarSystemObject : public ISolarSystemObject
    {
        Q_OBJECT

    public:
        explicit SolarSystemObject(QObject* parent = 0);
        ~SolarSystemObject();

        //copy constructor
        SolarSystemObject(const SolarSystemObject& obj);

        //copy operator
        SolarSystemObject& operator=(SolarSystemObject obj);

    private:

        //base data
        struct SolarObjectData;
        SolarObjectData* solarObjectData;

        //swap for copy operator
        friend void swap(SolarSystemObject& ls, SolarSystemObject& rs);

    public:

        //interface
        virtual void setDescription(const QString& description) override;
        virtual QString& description() const override;

        virtual void setStringType(const QString& type) override;
        virtual QString stringType() const override;

        virtual void setSolarObjectName(const QString& name) override;
        virtual QString solarObjectName() const override;

        virtual void setOrbitalSpeed(float speed) override;
        virtual float orbitalSpeed() const override;

        virtual void setMass(double mass) override;
        virtual double mass() const override;

        virtual void setMeanRadius(float radius) override;
        virtual float meanRadius() const override;

        virtual void setSurfaceTemperature(int temperature) override;
        virtual int surfaceTemperature() const override;

        virtual void setSurfaceGravity(float gravity) override;
        virtual float surfaceGravity() const override;

        virtual void setVolume(double volume) override;
        virtual double volume() const override;

        virtual void setSolarType(SolarSystemObjectType type) override;
        virtual SolarSystemObjectType solarType() const override;

        virtual void setSiderealPeriod(double period) override;
        virtual double siderealPeriod() const override;

        virtual void setOrbitalPeriod(double period) override;
        virtual double orbitalPeriod() const override;
    };

    //swap two solar objects
    void swap(SolarSystemObject& ls, SolarSystemObject& rs);
}

#endif // SOLARSYSTEMOBJECT_H
