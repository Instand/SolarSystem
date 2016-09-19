#ifndef ISOLARSYSTEMOBJECT_H
#define ISOLARSYSTEMOBJECT_H

#include <QObject>
#include "solarsystemcore.h"
#include <memory>

namespace SolarSystem {

    class ISolarSystemObject : public QObject {

        Q_OBJECT

    public:
        explicit ISolarSystemObject(QObject *parent = 0);
        virtual ~ISolarSystemObject();

        //base interface
        virtual void setDescription(const QString& description) = 0;
        virtual QString& description() const = 0;

        virtual void setStringType(const QString& type) = 0;
        virtual QString stringType() const = 0;

        virtual void setSolarObjectName(const QString& name) = 0;
        virtual QString solarObjectName() const = 0;

        virtual void setOrbitalSpeed(float speed) = 0;
        virtual float orbitalSpeed() const = 0;

        virtual void setMass(double mass) = 0;
        virtual double mass() const = 0;

        virtual void setMeanRadius(float radius) = 0;
        virtual float meanRadius() const = 0;

        virtual void setSurfaceTemperature(int temperature) = 0;
        virtual int surfaceTemperature() const = 0;

        virtual void setSurfaceGravity(float gravity) = 0;
        virtual float surfaceGravity() const = 0;

        virtual void setVolume(double volume) = 0;
        virtual double volume() const = 0;

        virtual void setSolarType(SolarSystemObjectType type) = 0;
        virtual SolarSystemObjectType solarType() const = 0;

        virtual void setSiderealPeriod(double period) = 0;
        virtual double siderealPeriod() const = 0;

        virtual void setOrbitalPeriod(double period) = 0;
        virtual double orbitalPeriod() const = 0;
    };

    //types
    using SolarSystemObjectPtr = std::shared_ptr<ISolarSystemObject>;

}

#endif // ISOLARSYSTEMOBJECT_H
