#include "solarskybox.h"

SolarSystem::SolarSkyBox::SolarSkyBox(Qt3DCore::QNode* parent):
    QSkyboxEntity(parent)
{
    //create skybox from file
    setBaseName(QStringLiteral("qrc:/Resources/Skybox/stars"));
    setExtension(QStringLiteral(".webp"));
}

