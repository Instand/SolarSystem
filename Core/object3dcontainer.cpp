#include "object3dcontainer.h"

#include <Scene/SceneObjects/planet.h>
#include <Scene/SceneObjects/planetring.h>
#include <Scene/SceneObjects/earthcloud.h>
#include <Scene/SceneObjects/sun.h>

#include <Core/object3dbuilder.h>

#include <Qt3DRender/QTexture>
#include <Qt3DRender/QPickEvent>

SolarSystem::Object3DContainer::Object3DContainer(Qt3DCore::QNode* root, QObject* parent):
    QObject(parent)
{
    initialize(root);
}

SolarSystem::Object3DContainer::~Object3DContainer()
{
    if (m_rootNode == nullptr)
    {
        for (auto& elem : m_objectContainer)
        {
            if (elem.second)
                delete elem.second;
        }
    }
}

void SolarSystem::Object3DContainer::initialize(Qt3DCore::QNode* root)
{
    constexpr auto shiness = 10.0f;

    /// create planets and add to map

    m_objectContainer[SolarObjects::Sun] = new Sun(root);

    // mercury
    m_objectContainer[SolarObjects::Mercury] = PlanetBuilder{":/Resources/Images/mercurymap.jpg", ":/Resources/Images/mercurynormal.jpg"}
                                                .setShiness(shiness)
                                                .setTilt(SolarObjectsValues::Mercury::tilt)
                                                .build(root);

    // venus
    m_objectContainer[SolarObjects::Venus] = PlanetBuilder{":/Resources/Images/venus_atmo.jpg", ":/Resources/Images/venus_atmonormal.jpg"}
                                                .setShiness(shiness)
                                                .setTilt(SolarObjectsValues::Venus::tilt)
                                                .build(root);

    // earth
    m_objectContainer[SolarObjects::Earth] = PlanetBuilder{":/Resources/Images/earthmap1k.jpg", ":/Resources/Images/earthnormal1k.jpg"}
                                                .setShiness(shiness)
                                                .setTilt(SolarObjectsValues::Earth::tilt)
                                                .build(root);

    // moon
    m_objectContainer[SolarObjects::Moon] = PlanetBuilder{":/Resources/Images/moonmap1k.jpg", ":/Resources/Images/moonnormal1k.jpg"}
                                                .setShiness(shiness)
                                                .setTilt(SolarObjectsValues::Moon::tilt)
                                                .build(root);

    // mars
    m_objectContainer[SolarObjects::Mars] = PlanetBuilder{":/Resources/Images/marsmap1k.jpg", ":/Resources/Images/marsnormal1k.jpg"}
                                                .setShiness(shiness)
                                                .setTilt(SolarObjectsValues::Mars::tilt)
                                                .build(root);

    // jupiter
    m_objectContainer[SolarObjects::Jupiter] = PlanetBuilder{":/Resources/Images/jupitermap.jpg", ":/Resources/Images/jupiternormal.jpg"}
                                                .setShiness(shiness)
                                                .setTilt(SolarObjectsValues::Jupier::tilt)
                                                .build(root);

    // saturn
    m_objectContainer[SolarObjects::Saturn] = PlanetBuilder{":/Resources/Images/saturnmap.jpg", ":/Resources/Images/saturnnormal.jpg"}
                                                .setShiness(shiness)
                                                .setTilt(SolarObjectsValues::Saturn::tilt)
                                                .build(root);

    // uranus
    m_objectContainer[SolarObjects::Uranus] = PlanetBuilder{":/Resources/Images/uranusmap.jpg", ":/Resources/Images/uranusnormal.jpg"}
                                                .setShiness(shiness)
                                                .setTilt(SolarObjectsValues::Uranus::tilt)
                                                .build(root);

    // neptune
    m_objectContainer[SolarObjects::Neptune] = PlanetBuilder{":/Resources/Images/neptunemap.jpg", ":/Resources/Images/neptunenormal.jpg"}
                                                .setShiness(shiness)
                                                .setTilt(SolarObjectsValues::Neptune::tilt)
                                                .build(root);

    // pluto
    m_objectContainer[SolarObjects::Pluto] = PlanetBuilder{":/Resources/Images/plutomap.jpg", ":/Resources/Images/plutonormal.jpg"}
                                                .setShiness(shiness)
                                                .setTilt(SolarObjectsValues::Pluto::tilt)
                                                .build(root);

    m_calculatedSolarObjectNumber = static_cast<int>(m_objectContainer.size());

    // add additional solar objects
    m_objectContainer[SolarObjects::SaturnRing] = PlanetRingBuilder{":/Resources/Images/saturnringcolortrans.png", ":/Resources/Images/saturnringcolortransnormal.png"}
                                                .setTilt(SolarObjectsValues::SaturnRing::tilt)
                                                .build(root);

    m_objectContainer[SolarObjects::UranusRing] = PlanetRingBuilder{":/Resources/Images/uranusringcolortrans.png", ":/Resources/Images/uranusringcolortransnormal.png"}
                                                .setTilt(SolarObjectsValues::UranusRing::tilt)
                                                .build(root);

    m_objectContainer[SolarObjects::EarthCloud] = new EarthCloud(root);
    m_rootNode = root;
}

int SolarSystem::Object3DContainer::planetsNumber() const
{
    return m_calculatedSolarObjectNumber;
}

SolarSystem::Object3DMap& SolarSystem::Object3DContainer::objects() const
{
    return m_objectContainer;
}

SolarSystem::Object3D* SolarSystem::Object3DContainer::object(SolarSystem::SolarObjects type) const
{
    auto iter = m_objectContainer.find(type);

    if (iter != m_objectContainer.end())
        return iter->second;

    return nullptr;
}
