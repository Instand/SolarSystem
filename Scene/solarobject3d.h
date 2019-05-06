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

        QVector3D position() const;

    protected:

        //logical
        SolarSystem::Logic m_logic;
        Qt3DLogic::QFrameAction* m_frameAction;
        Qt3DRender::QObjectPicker* m_picker;

        //Qt3D components
        Qt3DCore::QTransform* m_transform;
        Qt3DRender::QGeometryRenderer* m_renderer;
        Qt3DRender::QMaterial* m_material;

        //main data
        SolarSystem::SolarObjects m_solarType;
        SolarSystem::SolarMaterials m_materialType = SolarMaterials::None;

        double m_r = 0;
        double m_x = 0;
        double m_y = 0;
        double m_z = 0;
        double m_roll = 0;
        double m_tilt = 0;
    };
}

#endif // SOLAROBJECT3D_H
