#include "planetring.h"
#include <Qt3DRender/QMesh>

SolarSystem::PlanetRing::PlanetRing(Qt3DCore::QNode* parent):
    NormalDiffuseAlphaObject(parent)
{
    auto mesh = new Qt3DRender::QMesh(this);
    _renderer = mesh;
    addComponent(_renderer);

    mesh->setSource(QUrl::fromLocalFile(":/Resources/Meshes/ring.obj"));
}

void SolarSystem::PlanetRing::update(float deltaTime)
{
    Q_UNUSED(deltaTime)

    //create matrix
    auto matrix = QMatrix4x4();

    //set position
    matrix.translate(QVector3D(_x, _y, _z));

    //rotate
    matrix.rotate(_tilt, SolarValues::tiltAxis);
    matrix.rotate(_roll, SolarValues::rollAxis);

    //ring scale
    matrix.scale(_r);

    _transform->setMatrix(matrix);
}
