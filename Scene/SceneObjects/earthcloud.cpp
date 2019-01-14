#include "earthcloud.h"
#include <QGeometryRenderer>
#include <QSphereGeometry>
#include <QTextureImage>
#include <QTransform>
#include <QMatrix4x4>

SolarSystem::EarthCloud::EarthCloud(Qt3DCore::QNode* parent):
    NormalDiffuseAlphaObject(parent)
{
    m_renderer = new Qt3DRender::QGeometryRenderer(this);
    addComponent(m_renderer);

    auto sphereGeometry = new Qt3DExtras::QSphereGeometry();

    //setup geometry
    sphereGeometry->setRadius(PlanetSettings::radius);
    sphereGeometry->setGenerateTangents(PlanetSettings::generateTangents);
    sphereGeometry->setRings(PlanetSettings::rings);
    sphereGeometry->setSlices(PlanetSettings::slices);

    m_renderer->setGeometry(sphereGeometry);

    Qt3DExtras::QNormalDiffuseMapAlphaMaterial* mat = qobject_cast<Qt3DExtras::QNormalDiffuseMapAlphaMaterial*>(m_material);

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
    matrix.translate(QVector3D(m_x, m_y, m_z));

    //rotate
    matrix.rotate(m_tilt, SolarValues::tiltAxis);
    matrix.rotate(m_roll, SolarValues::rollAxis);

    //ring scale
    matrix.scale(m_r);

    m_transform->setMatrix(matrix);
}
