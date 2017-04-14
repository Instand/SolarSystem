#include "earthcloud.h"
#include <Qt3DExtras/QSphereGeometry>
#include <solarsystemcore.h>

SolarSystem::EarthCloud::EarthCloud(Qt3DCore::QNode* parent):
    Solar3dObject(parent)
{
    Qt3DExtras::QSphereGeometry* sphereGeometry = new Qt3DExtras::QSphereGeometry();

    //setup geometry
    sphereGeometry->setRadius(PlanetSettings::radius);
    sphereGeometry->setGenerateTangents(PlanetSettings::generateTangents);
    sphereGeometry->setRings(PlanetSettings::rings);
    sphereGeometry->setSlices(PlanetSettings::slices);

    mesh().setGeometry(sphereGeometry);

    _material->setDiffuseTextureSource(":/Resources/Images/earthcloudmapcolortrans.png");
}

void SolarSystem::EarthCloud::update(float deltaTime)
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
