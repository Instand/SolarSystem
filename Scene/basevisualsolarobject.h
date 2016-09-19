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

        //realize base visual methods
        virtual Qt3DCore::QTransform& transform() const override final;
        virtual Qt3DRender::QMesh& mesh() const override final;

    private:
        Qt3DCore::QTransform* _transform;
        Qt3DRender::QMesh* _mesh;
    };

}

#endif // BASEVISUALSOLAROBJECT_H
