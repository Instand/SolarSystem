#ifndef ABSTRACTSOLAROBJECT_H
#define ABSTRACTSOLAROBJECT_H

#include <QObject>
#include "solarsystemcore.h"
#include <memory>
#include <unordered_map>

namespace SolarSystem
{
    //simple presentation of math solar object
    class AbstractSolarObject : public QObject
    {
        Q_OBJECT

    public:
        explicit AbstractSolarObject(QObject* parent = nullptr);
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
        double m_radius = 0;
        double m_tilt = 0;
        double m_n1 = 0;
        double m_n2 = 0;
        double m_i1 = 0;
        double m_i2 = 0;
        double m_w1 = 0;
        double m_w2 = 0;
        double m_a1 = 0;
        double m_a2 = 0;
        double m_e1 = 0;
        double m_e2 = 0;
        double m_m1 = 0;
        double m_m2 = 0;
        double m_period = 0;
        double m_x = 0;
        double m_y = 0;
        double m_z = 0;
        double m_roll = 0;
        SolarObjects m_centerOfOrbit;
        SolarObjects m_objectType;

        virtual void initialize() = 0;
    };

    //solar objects type
    using SolarObjectPtr = std::shared_ptr<AbstractSolarObject>;
    using SolarObjectsArray = std::vector<SolarObjectPtr>;
    using SolarObjectsMap = std::unordered_map<SolarObjects, SolarObjectPtr>;
}

#endif // ABSTRACTSOLAROBJECT_H
