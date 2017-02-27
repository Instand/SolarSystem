#include "planetring.h"

SolarSystem::PlanetRing::PlanetRing(Qt3DCore::QNode* parent):
    Solar3dObject(parent)
{
    mesh().setSource(QUrl::fromLocalFile(":/Resources/Meshes/ring.obj"));
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

    transform().setMatrix(matrix);
}
