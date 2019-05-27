#include "planetscontainer.h"

#include <Scene/SceneObjects/planet.h>
#include <Scene/SceneObjects/planetring.h>
#include <Scene/SceneObjects/earthcloud.h>
#include <Scene/SceneObjects/sun.h>

#include <SolarCore/objectbuilder.h>

#include <Qt3DRender/QTexture>
#include <Qt3DRender/QPickEvent>

SolarSystem::PlanetsContainer::PlanetsContainer(Qt3DCore::QNode* root, QObject* parent):
    QObject(parent)
{
    initialize(root);
}

SolarSystem::PlanetsContainer::~PlanetsContainer()
{
    if (m_rootNode == nullptr)
    {
        for (auto& elem : m_planetContainer)
        {
            if (elem.second)
                delete elem.second;
        }
    }
}

void SolarSystem::PlanetsContainer::initialize(Qt3DCore::QNode* root)
{
    constexpr auto shiness = 10.0f;

    /// create planets and add to map

    m_planetContainer[SolarObjects::Sun] = new Sun(root);

    // mercury
    m_planetContainer[SolarObjects::Mercury] = PlanetBuilder{":/Resources/Images/mercurymap.jpg", ":/Resources/Images/mercurynormal.jpg"}
                                                .setShiness(shiness)
                                                .setTilt(SolarObjectsValues::Mercury::tilt)
                                                .build(root);

    // venus
    m_planetContainer[SolarObjects::Venus] = PlanetBuilder{":/Resources/Images/venus_atmo.jpg", ":/Resources/Images/venus_atmonormal.jpg"}
                                                .setShiness(shiness)
                                                .setTilt(SolarObjectsValues::Venus::tilt)
                                                .build(root);

    // earth
    m_planetContainer[SolarObjects::Earth] = PlanetBuilder{":/Resources/Images/earthmap1k.jpg", ":/Resources/Images/earthnormal1k.jpg"}
                                                .setShiness(shiness)
                                                .setTilt(SolarObjectsValues::Earth::tilt)
                                                .build(root);

    // moon
    m_planetContainer[SolarObjects::Moon] = PlanetBuilder{":/Resources/Images/moonmap1k.jpg", ":/Resources/Images/moonnormal1k.jpg"}
                                                .setShiness(shiness)
                                                .setTilt(SolarObjectsValues::Moon::tilt)
                                                .build(root);

    // mars
    m_planetContainer[SolarObjects::Mars] = PlanetBuilder{":/Resources/Images/marsmap1k.jpg", ":/Resources/Images/marsnormal1k.jpg"}
                                                .setShiness(shiness)
                                                .setTilt(SolarObjectsValues::Mars::tilt)
                                                .build(root);

    // jupiter
    m_planetContainer[SolarObjects::Jupiter] = PlanetBuilder{":/Resources/Images/jupitermap.jpg", ":/Resources/Images/jupiternormal.jpg"}
                                                .setShiness(shiness)
                                                .setTilt(SolarObjectsValues::Jupier::tilt)
                                                .build(root);

    // saturn
    m_planetContainer[SolarObjects::Saturn] = PlanetBuilder{":/Resources/Images/saturnmap.jpg", ":/Resources/Images/saturnnormal.jpg"}
                                                .setShiness(shiness)
                                                .setTilt(SolarObjectsValues::Saturn::tilt)
                                                .build(root);

    // uranus
    m_planetContainer[SolarObjects::Uranus] = PlanetBuilder{":/Resources/Images/uranusmap.jpg", ":/Resources/Images/uranusnormal.jpg"}
                                                .setShiness(shiness)
                                                .setTilt(SolarObjectsValues::Uranus::tilt)
                                                .build(root);

    // neptune
    m_planetContainer[SolarObjects::Neptune] = PlanetBuilder{":/Resources/Images/neptunemap.jpg", ":/Resources/Images/neptunenormal.jpg"}
                                                .setShiness(shiness)
                                                .setTilt(SolarObjectsValues::Neptune::tilt)
                                                .build(root);

    // pluto
    m_planetContainer[SolarObjects::Pluto] = PlanetBuilder{":/Resources/Images/plutomap.jpg", ":/Resources/Images/plutonormal.jpg"}
                                                .setShiness(shiness)
                                                .setTilt(SolarObjectsValues::Pluto::tilt)
                                                .build(root);

    m_calculatedSolarObjectNumber = static_cast<int>(m_planetContainer.size());

    // add additional solar objects
    m_planetContainer[SolarObjects::SaturnRing] = PlanetRingBuilder{":/Resources/Images/saturnringcolortrans.png", ":/Resources/Images/saturnringcolortransnormal.png"}
                                                .setTilt(SolarObjectsValues::SaturnRing::tilt)
                                                .build(root);

    m_planetContainer[SolarObjects::UranusRing] = PlanetRingBuilder{":/Resources/Images/uranusringcolortrans.png", ":/Resources/Images/uranusringcolortransnormal.png"}
                                                .setTilt(SolarObjectsValues::UranusRing::tilt)
                                                .build(root);

    m_planetContainer[SolarObjects::EarthCloud] = new EarthCloud(root);
    m_rootNode = root;
}

int SolarSystem::PlanetsContainer::planetsNumber() const
{
    return m_calculatedSolarObjectNumber;
}

SolarSystem::PlanetArray& SolarSystem::PlanetsContainer::planets() const
{
    return m_planetContainer;
}
