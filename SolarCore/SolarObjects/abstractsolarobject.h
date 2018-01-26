#ifndef ABSTRACTSOLAROBJECT_H
#define ABSTRACTSOLAROBJECT_H

#include <QObject>
#include "solarsystemcore.h"
#include <memory>

namespace SolarSystem
{
    //simple presentation of math solar object
    class AbstractSolarObject : public QObject
    {
        Q_OBJECT

    public:
        AbstractSolarObject(QObject* parent = nullptr);
        virtual ~AbstractSolarObject();

        //getters + setters
        double radius() const;
        void setRadius(double radius);

        double tilt() const;
        void setTilt(double tilt);

        double roll() const;
        void setRoll(double roll);

        double x() const;
        void setX(double x);

        double y() const;
        void setY(double y);

        double z() const;
        void setZ(double z);

        //only getters
        double N1() const;
        double N2() const;
        double i1() const;
        double i2() const;
        double w1() const;
        double w2() const;
        double a1() const;
        double a2() const;
        double e1() const;
        double e2() const;
        double M1() const;
        double M2() const;
        double period() const;
        SolarObjects centerOfOrbit() const;
        SolarObjects object() const;

    protected:

        //main data
        double _radius = 0;
        double _tilt = 0;
        double _N1 = 0;
        double _N2 = 0;
        double _i1 = 0;
        double _i2 = 0;
        double _w1 = 0;
        double _w2 = 0;
        double _a1 = 0;
        double _a2 = 0;
        double _e1 = 0;
        double _e2 = 0;
        double _M1 = 0;
        double _M2 = 0;
        double _period = 0;
        double _x = 0;
        double _y = 0;
        double _z = 0;
        double _roll = 0;
        SolarObjects _centerOfOrbit;
        SolarObjects _objectType;

        virtual void initialize() = 0;
    };

    //solar objects type
    using SolarObjectPtr = std::shared_ptr < AbstractSolarObject >;
    using SolarObjectsArray = std::vector < SolarObjectPtr >;
}

#endif // ABSTRACTSOLAROBJECT_H
