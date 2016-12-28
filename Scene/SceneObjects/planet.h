#ifndef PLANET_H
#define PLANET_H

#include <solarsystemcore.h>
#include <solar3dobject.h>

namespace SolarSystem {

    //base class for solar planets
    class Planet : public Solar3dObject {

        Q_OBJECT

    public:

        Planet(Qt3DCore::QNode* parent = 0);

        //returns current planet type
        SolarObjects solarType() const;

        //set solar type
        void setSolarType(SolarObjects type);

        float r() const;
        void setR(float r);

        float x() const;
        void setX(float x);

        float y() const;
        void setY(float y);

        float z() const;
        void setZ(float z);

        float roll() const;
        void setRoll(float roll);

        float tilt() const;
        void setTilt(float tilt);

    private:
        SolarObjects _solarType;
        float _r = 0;
        float _x = 0;
        float _y = 0;
        float _z = 0;
        float _roll = 0;
        float _tilt = 0;

    protected:
        virtual void update(float deltaTime);
    };
}


#endif // PLANET_H
