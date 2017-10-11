#ifndef VISUALSOLAROBJECT_H
#define VISUALSOLAROBJECT_H

#include <Qt3DLogic/QFrameAction>
#include "Interface/ivisualsolarobject.h"

namespace SolarSystem
{
    //class that represents logic programming for visual object on the scene
    class VisualSolarObject : public IVisualSolarObject
    {
        Q_OBJECT

    public:
        VisualSolarObject(Qt3DCore::QNode* parent = nullptr);

    protected:
        virtual void update(float deltaTime) = 0;

    public:
        virtual Qt3DCore::QTransform* transform() const = 0;
        virtual Qt3DRender::QMesh* mesh() const = 0;
        virtual Qt3DRender::QObjectPicker* picker() const = 0;
        virtual SolarObjects solarType() const = 0;
        virtual void setSolarType(SolarObjects type) = 0;
        virtual SolarMaterials materialType() const = 0;
        virtual Qt3DRender::QMaterial* material() const = 0;
        virtual double r() const = 0;
        virtual void setR(double r) = 0;
        virtual double x() const = 0;
        virtual void setX(double x) = 0;
        virtual double y() const = 0;
        virtual void setY(double y) = 0;
        virtual double z() const = 0;
        virtual void setZ(double z) = 0;
        virtual double roll() const = 0;
        virtual void setRoll(double roll) = 0;
        virtual double tilt() const = 0;
        virtual void setTilt(double tilt) = 0;

        //realize some proterties
        virtual void addLogic(LogicPtr func) override final;
        virtual void clearLogic() override final;

    private:
        Logic logic;
        Qt3DLogic::QFrameAction* _frameAction;

    private slots:
        void frameTick(float deltaTime);
    };
}

#endif // VISUALSOLAROBJECT_H
