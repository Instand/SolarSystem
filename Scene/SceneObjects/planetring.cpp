#include "planetring.h"
#include <QMatrix4x4>
#include <QTransform>
#include <QMesh>

SolarSystem::PlanetRing::PlanetRing(Qt3DCore::QNode* parent):
    NormalDiffuseAlphaObject(parent)
{
    auto mesh = new Qt3DRender::QMesh(this);
    m_renderer = mesh;
    addComponent(m_renderer);

    mesh->setSource(QUrl::fromLocalFile(":/Resources/Meshes/ring.obj"));
}

void SolarSystem::PlanetRing::update(float deltaTime)
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
