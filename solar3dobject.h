#ifndef SOLAR3DOBJECT_H
#define SOLAR3DOBJECT_H

#include <Qt3DCore/QEntity>
#include <Qt3DCore/QTransform>
#include <Qt3DRender/QMesh>
#include <Qt3DExtras/QNormalDiffuseSpecularMapMaterial>
#include <Qt3DRender/QTexture>
#include <Qt3DLogic/QFrameAction>
#include <Qt3DRender/QObjectPicker>
#include <memory>
#include <functional>
#include <vector>

namespace SolarSystem {

    //types
    using LogicPtr = std::function<void(float)>;
    using Logic = std::vector<LogicPtr>;

    //class for rendering base 3d object in solar system
    class Solar3dObject : public Qt3DCore::QEntity {

        Q_OBJECT

    public:
        Solar3dObject(Qt3DCore::QNode* parent = 0);

        //get object properties
        Qt3DCore::QTransform& transform() const;
        Qt3DRender::QMesh& mesh() const;
        Qt3DRender::QObjectPicker& picker() const;
        Qt3DExtras::QNormalDiffuseSpecularMapMaterial& material() const;
        Qt3DRender::QTextureImage& diffuse() const;
        Qt3DRender::QTextureImage& normal() const;

        //add logic
        void addLogic(LogicPtr func);
        void clearLogic();

    protected:

        //frame tick for solar object logic programming
        virtual void update(float deltaTime) = 0;

    private:

        //transform + mesh
        std::unique_ptr<Qt3DCore::QTransform> _transform;
        std::unique_ptr<Qt3DRender::QMesh> _mesh;

        //logic
        std::unique_ptr<Qt3DLogic::QFrameAction> _frame;
        std::unique_ptr<Qt3DRender::QObjectPicker> _picker;

        //vizibility
        std::unique_ptr<Qt3DExtras::QNormalDiffuseSpecularMapMaterial> _material;
        std::unique_ptr<Qt3DRender::QTextureImage> _diffuseImage;
        std::unique_ptr<Qt3DRender::QTextureImage> _normalImage;

        //additional logic
        Logic additionalLogic;

    private slots:
        void frameTick(float deltaTime);

    signals:
        void tick(float);
    };

}

#endif // SOLAR3DOBJECT_H
