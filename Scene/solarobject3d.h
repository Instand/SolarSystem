#ifndef SOLAROBJECT3D_H
#define SOLAROBJECT3D_H

#include <functional>
#include <solarsystemcore.h>
#include <Qt3DCore/QEntity>

namespace Qt3DCore
{
    class QTransform;
}

namespace Qt3DLogic
{
    class QFrameAction;
}

namespace Qt3DRender
{
    class QGeometryRenderer;
    class QObjectPicker;
    class QMaterial;
}

namespace SolarSystem
{
    //types
    using LogicPtr = std::function<void(float)>;
    using Logic = std::vector<LogicPtr>;

    ///base visual object on the scene
    class SolarObject3D : public Qt3DCore::QEntity
    {
        Q_OBJECT

    public:

        ///creates 3d object
        explicit SolarObject3D(Qt3DCore::QNode* parent = nullptr);

    protected:

        //frame tick for solar object logic programming
        virtual void update(float deltaTime) = 0;

        //sets material type
        void setMaterialType(SolarMaterials material);

    public:

        //logic
        void addLogic(LogicPtr func);
        void clearLogic();

        //position in space
        Qt3DCore::QTransform* transform() const;

        //get renderer
        Qt3DRender::QGeometryRenderer* renderer() const;

        //get picker
        Qt3DRender::QObjectPicker* picker() const;

        //returns current object type
        SolarObjects solarType() const;

        //set solar type
        void setSolarType(SolarObjects type);

        //returns object material type
        SolarMaterials materialType() const;

        //returns object material
        Qt3DRender::QMaterial* material() const;

        //control
        double r() const;
        void setR(double r);

        double x() const;
        void setX(double x);

        double y() const;
        void setY(double y);

        double z() const;
        void setZ(double z);

        double roll() const;
        void setRoll(double roll);

        double tilt() const;
        void setTilt(double tilt);

    protected:

        //logical
        SolarSystem::Logic logic_;
        Qt3DLogic::QFrameAction* frameAction_;
        Qt3DRender::QObjectPicker* picker_;

        //Qt3D components
        Qt3DCore::QTransform* transform_;
        Qt3DRender::QGeometryRenderer* renderer_;
        Qt3DRender::QMaterial* material_;

        //main data
        SolarSystem::SolarObjects solarType_;
        SolarSystem::SolarMaterials materialType_ = SolarMaterials::None;
        double r_ = 0;
        double x_ = 0;
        double y_ = 0;
        double z_ = 0;
        double roll_ = 0;
        double tilt_ = 0;
    };
}

#endif // SOLAROBJECT3D_H
