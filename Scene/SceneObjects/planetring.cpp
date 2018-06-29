#include "planetring.h"
#include <QMatrix4x4>
#include <QTransform>
#include <QMesh>

SolarSystem::PlanetRing::PlanetRing(Qt3DCore::QNode* parent):
    NormalDiffuseAlphaObject(parent)
{
    auto mesh = new Qt3DRender::QMesh(this);
    m_Renderer = mesh;
    addComponent(m_Renderer);

    mesh->setSource(QUrl::fromLocalFile(":/Resources/Meshes/ring.obj"));
}

void SolarSystem::PlanetRing::update(float deltaTime)
{
    Q_UNUSED(deltaTime)

    //create matrix
    auto matrix = QMatrix4x4();

    //set position
    matrix.translate(QVector3D(m_X, m_Y, m_Z));

    //rotate
    matrix.rotate(m_Tilt, SolarValues::tiltAxis);
    matrix.rotate(m_Roll, SolarValues::rollAxis);

    //ring scale
    matrix.scale(m_R);

    m_Transform->setMatrix(matrix);
}
