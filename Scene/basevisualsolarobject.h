#ifndef BASEVISUALSOLAROBJECT_H
#define BASEVISUALSOLAROBJECT_H

#include "Scene/visualsolarobject.h"

namespace SolarSystem {

    //this class represets a simple visual object with transform and mesh
    class BaseVisualSolarObject : public VisualSolarObject {

        Q_OBJECT

    public:
        BaseVisualSolarObject(Qt3DCore::QNode* parent = 0);

    protected:
        virtual void update(float deltaTime) = 0;

    public:
        virtual Qt3DRender::QObjectPicker& picker() const = 0;

        //realize base visual methods
        virtual Qt3DCore::QTransform& transform() const override final;
        virtual Qt3DRender::QMesh& mesh() const override final;

        //setters/getters
        virtual SolarObjects solarType() const override final;
        virtual void setSolarType(SolarObjects type) override final;

        virtual float r() const override final;
        virtual void setR(float r) override final;

        virtual float x() const override final;
        virtual void setX(float x) override final;

        virtual float y() const override final;
        virtual void setY(float y) override final;

        virtual float z() const override final;
        virtual void setZ(float z) override final;

        virtual float roll() const override final;
        virtual void setRoll(float roll) override final;

        virtual float tilt() const override final;
        virtual void setTilt(float tilt) override final;

    private:

        //data
        Qt3DCore::QTransform* _transform;
        Qt3DRender::QMesh* _mesh;
        SolarObjects _solarType;
        float _r = 0;
        float _x = 0;
        float _y = 0;
        float _z = 0;
        float _roll = 0;
        float _tilt = 0;
    };

}

#endif // BASEVISUALSOLAROBJECT_H
