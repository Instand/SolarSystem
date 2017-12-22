#include "earthcloud.h"
#include <Qt3DExtras/QSphereGeometry>
#include <QTextureImage>

SolarSystem::EarthCloud::EarthCloud(Qt3DCore::QNode* parent):
    NormalDiffuseAlphaObject(parent)
{
    _renderer = new Qt3DRender::QGeometryRenderer(this);
    addComponent(_renderer);

    auto sphereGeometry = new Qt3DExtras::QSphereGeometry();

    //setup geometry
    sphereGeometry->setRadius(PlanetSettings::radius);
//    sphereGeometry->setGenerateTangents(PlanetSettings::generateTangents);
    sphereGeometry->setRings(PlanetSettings::rings);
    sphereGeometry->setSlices(PlanetSettings::slices);

    _renderer->setGeometry(sphereGeometry);

    auto mat = qobject_cast<Qt3DExtras::QNormalDiffuseMapAlphaMaterial*>(_material);

    Qt3DRender::QTextureImage* diffuseMap = new Qt3DRender::QTextureImage();
    diffuseMap->setSource(QUrl::fromLocalFile(":/Resources/Images/earthcloudmapcolortrans.png"));
    mat->diffuse()->addTextureImage(diffuseMap);

    Qt3DRender::QTextureImage* normalMap = new Qt3DRender::QTextureImage();
    normalMap->setSource(QUrl::fromLocalFile(":/Resources/Images/earthcloudmapcolortransnormal.png"));
    mat->normal()->addTextureImage(normalMap);
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

    _transform->setMatrix(matrix);
}
