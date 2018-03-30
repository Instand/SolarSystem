#include "planet.h"
#include <QMatrix4x4>
#include <QGeometryRenderer>
#include <QTransform>
#include <Qt3DExtras/QSphereGeometry>

SolarSystem::Planet::Planet(Qt3DCore::QNode *parent):
    NormalDiffuseObject(parent)
{
    renderer_ = new Qt3DRender::QGeometryRenderer(this);
    addComponent(renderer_);

    auto sphereGeometry = new Qt3DExtras::QSphereGeometry(this);

    //setup geometry
    sphereGeometry->setRadius(PlanetSettings::radius);
    sphereGeometry->setGenerateTangents(PlanetSettings::generateTangents);
    sphereGeometry->setRings(PlanetSettings::rings);
    sphereGeometry->setSlices(PlanetSettings::slices);

    renderer_->setGeometry(sphereGeometry);
}

void SolarSystem::Planet::update(float deltaTime)
{
    Q_UNUSED(deltaTime)

    //create matrix
    auto matrix = QMatrix4x4();

    //set position
    matrix.translate(QVector3D(x_, y_, z_));

    //rotate
    matrix.rotate(tilt_, SolarValues::tiltAxis);
    matrix.rotate(roll_, SolarValues::rollAxis);

    //planet scale
    matrix.scale(r_);

    transform_->setMatrix(matrix);
}
