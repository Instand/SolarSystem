#ifndef SOLARSYSTEMOBJECT_H
#define SOLARSYSTEMOBJECT_H

#include <QObject>
#include <QString>

#include <solarsystemcore.h>

#include <memory>

namespace SolarSystem
{
    // base object of solar system for storing info from database
    class Object : public QObject
    {
        Q_OBJECT

    public:
        explicit Object(QObject* parent = nullptr);
        ~Object();

        Object(const Object& obj);
        Object& operator=(Object obj);

    private:
        struct ObjectData;
        ObjectData* solarObjectData;

        friend void swap(Object&, Object&);

    public:

        // interface
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

        void setSolarType(ObjectType type);
        ObjectType solarType() const;

        void setSiderealPeriod(double period);
        double siderealPeriod() const;

        void setOrbitalPeriod(double period);
        double orbitalPeriod() const;
    };

    void swap(Object& lhs, Object& rhs);

    using ObjectPtr = std::shared_ptr<Object>;
}

#endif // SOLARSYSTEMOBJECT_H
