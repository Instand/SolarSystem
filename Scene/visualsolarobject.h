#ifndef VISUALSOLAROBJECT_H
#define VISUALSOLAROBJECT_H

#include <Qt3DLogic/QFrameAction>
#include "Interface/ivisualsolarobject.h"

namespace SolarSystem {

    //class that represents logic programming for visual object on the scene
    class VisualSolarObject : public IVisualSolarObject {

        Q_OBJECT

    public:
        VisualSolarObject(Qt3DCore::QNode* parent = 0);

    protected:
        virtual void update(float deltaTime) = 0;

    public:
        virtual Qt3DCore::QTransform& transform() const = 0;
        virtual Qt3DRender::QMesh& mesh() const = 0;
        virtual Qt3DRender::QObjectPicker& picker() const = 0;

        //realize some proterties
        virtual void addLogic(LogicPtr func) override final;
        virtual void clearLogic() override final;

    private:
        Logic logic;
        Qt3DLogic::QFrameAction* _frameAction;

    private slots:
        void frameTick(float deltaTime);

    signals:
        void tick(float);
    };

}

#endif // VISUALSOLAROBJECT_H
