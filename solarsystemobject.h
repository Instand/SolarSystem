#ifndef SOLARSYSTEMOBJECT_H
#define SOLARSYSTEMOBJECT_H

#include <QObject>
#include <QString>
#include "solarsystemcore.h"
#include <memory>

namespace SolarSystem
{
    //base object of solar system for storing info from database
    class SolarSystemObject : public QObject
    {
        Q_OBJECT

    public:
        explicit SolarSystemObject(QObject* parent = nullptr);
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
        void setDescription(const QString& description);
        QString& description() const;

        void setStringType(const QString& type);
        QString stringType() const;

        void setSolarObjectName(const QString& name);
        QString solarObjectName() const;

        void setOrbitalSpeed(float speed);
        float orbitalSpeed() const;

        void setMass(double mass);
        double mass() const;

        void setMeanRadius(float radius);
        float meanRadius() const;

        void setSurfaceTemperature(int temperature);
        int surfaceTemperature() const;

        void setSurfaceGravity(float gravity);
        float surfaceGravity() const;

        void setVolume(double volume);
        double volume() const;

        void setSolarType(SolarSystemObjectType type);
        SolarSystemObjectType solarType() const;

        void setSiderealPeriod(double period);
        double siderealPeriod() const;

        void setOrbitalPeriod(double period);
        double orbitalPeriod() const;
    };

    //swap two solar objects
    void swap(SolarSystemObject& ls, SolarSystemObject& rs);

    //types
    using SolarSystemObjectPtr = std::shared_ptr<SolarSystemObject>;
}

#endif // SOLARSYSTEMOBJECT_H
