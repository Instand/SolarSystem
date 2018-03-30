#include "planetring.h"
#include <QMatrix4x4>
#include <QTransform>
#include <QMesh>

SolarSystem::PlanetRing::PlanetRing(Qt3DCore::QNode* parent):
    NormalDiffuseAlphaObject(parent)
{
    auto mesh = new Qt3DRender::QMesh(this);
    renderer_ = mesh;
    addComponent(renderer_);

    mesh->setSource(QUrl::fromLocalFile(":/Resources/Meshes/ring.obj"));
}

void SolarSystem::PlanetRing::update(float deltaTime)
{
    Q_UNUSED(deltaTime)

    //create matrix
    auto matrix = QMatrix4x4();

    //set position
    matrix.translate(QVector3D(x_, y_, z_));

    //rotate
    matrix.rotate(tilt_, SolarValues::tiltAxis);
    matrix.rotate(roll_, SolarValues::rollAxis);

    //ring scale
    matrix.scale(r_);

    transform_->setMatrix(matrix);
}
