#include "planet.h"
#include <Qt3DExtras/QSphereGeometry>
#include <solarsystemcore.h>

SolarSystem::Planet::Planet(Qt3DCore::QNode *parent):
    Solar3dObject(parent)
{
    Qt3DExtras::QSphereGeometry* sphereGeometry = new Qt3DExtras::QSphereGeometry();

    wrapMode.setX(Qt3DRender::QTextureWrapMode::WrapMode::Repeat);
    wrapMode.setY(Qt3DRender::QTextureWrapMode::WrapMode::Repeat);
    wrapMode.setZ(Qt3DRender::QTextureWrapMode::WrapMode::Repeat);

    //setup geometry
    sphereGeometry->setRadius(PlanetSettings::radius);
    sphereGeometry->setGenerateTangents(PlanetSettings::generateTangents);
    sphereGeometry->setRings(PlanetSettings::rings);
    sphereGeometry->setSlices(PlanetSettings::slices);

    mesh().setGeometry(sphereGeometry);

    _material->diffuse()->setWrapMode(wrapMode);
    _material->diffuse()->setGenerateMipMaps(true);
    _material->diffuse()->setMagnificationFilter(Qt3DRender::QAbstractTexture::Linear);
    _material->diffuse()->setMinificationFilter(Qt3DRender::QAbstractTexture::LinearMipMapLinear);
    _material->diffuse()->setMaximumAnisotropy(16.0f);

    _material->normal()->setWrapMode(wrapMode);
    _material->normal()->setMagnificationFilter(Qt3DRender::QAbstractTexture::Linear);
    _material->normal()->setMinificationFilter(Qt3DRender::QAbstractTexture::Linear);
    _material->normal()->setMaximumAnisotropy(16.0f);
}

void SolarSystem::Planet::update(float deltaTime)
{
    Q_UNUSED(deltaTime)

    //create matrix
    auto matrix = QMatrix4x4();

    //set position
    matrix.translate(QVector3D(_x, _y, _z));

    //rotate
    matrix.rotate(_tilt, SolarValues::tiltAxis);
    matrix.rotate(_roll, SolarValues::rollAxis);

    //planet scale
    matrix.scale(_r);

    transform().setMatrix(matrix);
}
