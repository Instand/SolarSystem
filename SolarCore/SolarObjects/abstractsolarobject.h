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
        double m_Radius = 0;
        double m_Tilt = 0;
        double m_N1 = 0;
        double m_N2 = 0;
        double m_I1 = 0;
        double m_I2 = 0;
        double m_W1 = 0;
        double m_W2 = 0;
        double m_A1 = 0;
        double m_A2 = 0;
        double m_E1 = 0;
        double m_E2 = 0;
        double m_M1 = 0;
        double m_M2 = 0;
        double m_Period = 0;
        double m_X = 0;
        double m_Y = 0;
        double m_Z = 0;
        double m_Roll = 0;
        SolarObjects m_CenterOfOrbit;
        SolarObjects m_ObjectType;

        virtual void initialize() = 0;
    };

    //solar objects type
    using SolarObjectPtr = std::shared_ptr < AbstractSolarObject >;
    using SolarObjectsArray = std::vector < SolarObjectPtr >;
}

#endif // ABSTRACTSOLAROBJECT_H
