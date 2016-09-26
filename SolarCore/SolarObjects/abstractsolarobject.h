#ifndef ABSTRACTSOLAROBJECT_H
#define ABSTRACTSOLAROBJECT_H

#include <QObject>
#include "solarsystemcore.h"

namespace SolarSystem {

    //simple presentation of math solar object
    class AbstractSolarObject : public QObject {

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

        virtual void initialize() = 0;

    };

}

#endif // ABSTRACTSOLAROBJECT_H
