#ifndef IVISUALSOLAROBJECT_H
#define IVISUALSOLAROBJECT_H

#include <Qt3DCore/QEntity>
#include <Qt3DCore/QTransform>
#include <Qt3DRender/QMesh>
#include <vector>
#include <functional>

namespace SolarSystem {

    //types
    using LogicPtr = std::function<void(float)>;
    using Logic = std::vector<LogicPtr>;

    //interface for base visual object on the scene
    class IVisualSolarObject : public Qt3DCore::QEntity {

        Q_OBJECT

    public:
        IVisualSolarObject(Qt3DCore::QNode* parent = 0);

    protected:

        //frame tick for solar object logic programming
        virtual void update(float deltaTime) = 0;

    public:

        //logic
        virtual void addLogic(LogicPtr func) = 0;
        virtual void clearLogic() = 0;

        //position in space
        virtual Qt3DCore::QTransform& transform() const = 0;

        //get mesh
        virtual Qt3DRender::QMesh& mesh() const =0;
    };

}

#endif // IVISUALSOLAROBJECT_H
