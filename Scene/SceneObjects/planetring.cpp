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
    Object3D::baseBehaviour();
}
