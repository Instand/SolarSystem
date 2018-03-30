#include "earthcloud.h"
#include <QGeometryRenderer>
#include <QSphereGeometry>
#include <QTextureImage>
#include <QTransform>
#include <QMatrix4x4>

SolarSystem::EarthCloud::EarthCloud(Qt3DCore::QNode* parent):
    NormalDiffuseAlphaObject(parent)
{
    renderer_ = new Qt3DRender::QGeometryRenderer(this);
    addComponent(renderer_);

    auto sphereGeometry = new Qt3DExtras::QSphereGeometry();

    //setup geometry
    sphereGeometry->setRadius(PlanetSettings::radius);
    sphereGeometry->setGenerateTangents(PlanetSettings::generateTangents);
    sphereGeometry->setRings(PlanetSettings::rings);
    sphereGeometry->setSlices(PlanetSettings::slices);

    renderer_->setGeometry(sphereGeometry);

    Qt3DExtras::QNormalDiffuseMapAlphaMaterial* mat = qobject_cast<Qt3DExtras::QNormalDiffuseMapAlphaMaterial*>(material_);

    Qt3DRender::QTextureImage* diffuseMap = new Qt3DRender::QTextureImage();
    diffuseMap->setSource(QUrl::fromLocalFile(":/Resources/Images/earthcloudmapcolortrans.png"));
    mat->diffuse()->addTextureImage(diffuseMap);

    Qt3DRender::QTextureImage* normalMap = new Qt3DRender::QTextureImage();
    normalMap->setSource(QUrl::fromLocalFile(":/Resources/Images/earthcloudmapcolortransnormal.png"));
    mat->normal()->addTextureImage(normalMap);

    mat->setShininess(100000.0f);
}

void SolarSystem::EarthCloud::update(float deltaTime)
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
