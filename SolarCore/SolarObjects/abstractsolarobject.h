#ifndef ABSTRACTSOLAROBJECT_H
#define ABSTRACTSOLAROBJECT_H

#include <QObject>
#include "solarsystemcore.h"

namespace SolarSystem {

    //simple presentation of math solar object
    class AbstractSolarObject : public QObject {

        Q_OBJECT

    public:
        AbstractSolarObject(QObject* parent = nullptr):QObject(parent){}
        virtual ~AbstractSolarObject(){}

        //interface

        //getters + setters
        virtual double radius() const = 0;
        virtual void setRadius(double radius) = 0;

        virtual double tilt() const = 0;
        virtual void setTilt(double tilt) = 0;

        virtual double roll() const = 0;
        virtual setRoll(double roll) = 0;

        virtual double x() const = 0;
        virtual void setX(double x) = 0;

        virtual double y() const = 0;
        virtual void setY(double y) = 0;

        virtual double z() const = 0;
        virtual void setZ(double z) = 0;

        //only getters
        virtual double N1() const = 0;
        virtual double N2() const = 0;
        virtual double i1() const = 0;
        virtual double i2() const = 0;
        virtual double w1() const = 0;
        virtual double w2() const = 0;
        virtual double a1() const = 0;
        virtual double a2() const = 0;
        virtual double e1() const = 0;
        virtual double e2() const = 0;
        virtual double M1() const = 0;
        virtual double M2() const = 0;
        virtual double period() = 0;
        virtual SolarObjects centerOfOrbit() = 0;

    protected:

        //main data
        double _radius;
        double _tilt;
        double _N1;
        double _N2;
        double _i1;
        double _i2;
        double _w1;
        double _w2;
        double _a1;
        double _a2;
        double _e1;
        double _e2;
        double _M1;
        double _M2;
        double _period;
        double _x;
        double _y;
        double _z;
        double _roll;
        SolarObjects _centerOfOrbit;

    };

}

#endif // ABSTRACTSOLAROBJECT_H
