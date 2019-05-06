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
    auto shiness = 10.0f;

    // mercury
    PlanetBuilder mercuryBuilder(":/Resources/Images/mercurymap.jpg", ":/Resources/Images/mercurynormal.jpg");

    mercuryBuilder.setShiness(shiness);
    mercuryBuilder.setTilt(SolarObjectsValues::Mercury::tilt);
    mercuryBuilder.build(root);

    // venus
    PlanetBuilder venusBuilder(":/Resources/Images/venus_atmo.jpg", ":/Resources/Images/venus_atmonormal.jpg");

    venusBuilder.setShiness(shiness);
    venusBuilder.setTilt(SolarObjectsValues::Venus::tilt);
    venusBuilder.build(root);

    // earth
    PlanetBuilder earthBuilder(":/Resources/Images/earthmap1k.jpg", ":/Resources/Images/earthnormal1k.jpg");

    earthBuilder.setShiness(shiness);
    earthBuilder.setTilt(SolarObjectsValues::Earth::tilt);
    earthBuilder.build(root);

    // moon
    PlanetBuilder moonBuilder(":/Resources/Images/moonmap1k.jpg", ":/Resources/Images/moonnormal1k.jpg");

    moonBuilder.setShiness(shiness);
    moonBuilder.setTilt(SolarObjectsValues::Moon::tilt);
    moonBuilder.build(root);

    // mars
    PlanetBuilder marsBuilder(":/Resources/Images/marsmap1k.jpg", ":/Resources/Images/marsnormal1k.jpg");

    marsBuilder.setShiness(shiness);
    marsBuilder.setTilt(SolarObjectsValues::Mars::tilt);
    marsBuilder.build(root);

    // jupiter
    PlanetBuilder jupiterBuilder(":/Resources/Images/jupitermap.jpg", ":/Resources/Images/jupiternormal.jpg");

    jupiterBuilder.setShiness(shiness);
    jupiterBuilder.setTilt(SolarObjectsValues::Jupier::tilt);
    jupiterBuilder.build(root);

    // saturn
    PlanetBuilder saturnBuilder(":/Resources/Images/saturnmap.jpg", ":/Resources/Images/saturnnormal.jpg");

    saturnBuilder.setShiness(shiness);
    saturnBuilder.setTilt(SolarObjectsValues::Saturn::tilt);
    saturnBuilder.build(root);

    // uranus
    PlanetBuilder uranusBuilder(":/Resources/Images/uranusmap.jpg", ":/Resources/Images/uranusnormal.jpg");

    uranusBuilder.setShiness(shiness);
    uranusBuilder.setTilt(SolarObjectsValues::Uranus::tilt);
    uranusBuilder.build(root);

    // neptune
    PlanetBuilder neptuneBuilder(":/Resources/Images/neptunemap.jpg", ":/Resources/Images/neptunenormal.jpg");

    neptuneBuilder.setShiness(shiness);
    neptuneBuilder.setTilt(SolarObjectsValues::Neptune::tilt);
    neptuneBuilder.build(root);

    // pluto
    PlanetBuilder plutoBuilder(":/Resources/Images/plutomap.jpg", ":/Resources/Images/plutonormal.jpg");

    plutoBuilder.setShiness(shiness);
    plutoBuilder.setTilt(SolarObjectsValues::Pluto::tilt);
    plutoBuilder.build(root);

    // saturn rings
    PlanetRingBuilder saturnRingBuilder(":/Resources/Images/saturnringcolortrans.png", ":/Resources/Images/saturnringcolortransnormal.png");

    saturnRingBuilder.setTilt(SolarObjectsValues::Saturn::tilt);
    saturnRingBuilder.build(root);

    // uranus rings
    PlanetRingBuilder uranusRingBuilder(":/Resources/Images/uranusringcolortrans.png", ":/Resources/Images/uranusringcolortransnormal.png");

    uranusRingBuilder.setTilt(SolarObjectsValues::Uranus::tilt);
    uranusRingBuilder.build(root);

    // add planets to map, to SolarObject3D
    m_planetContainer[SolarObjects::Sun] = new Sun(root);
    m_planetContainer[SolarObjects::Mercury] = mercuryBuilder.object();
    m_planetContainer[SolarObjects::Venus] = venusBuilder.object();
    m_planetContainer[SolarObjects::Earth] = earthBuilder.object();
    m_planetContainer[SolarObjects::Moon] = moonBuilder.object();
    m_planetContainer[SolarObjects::Mars] = marsBuilder.object();
    m_planetContainer[SolarObjects::Jupiter] = jupiterBuilder.object();
    m_planetContainer[SolarObjects::Saturn] = saturnBuilder.object();
    m_planetContainer[SolarObjects::Uranus] = uranusBuilder.object();
    m_planetContainer[SolarObjects::Neptune] = neptuneBuilder.object();
    m_planetContainer[SolarObjects::Pluto] = plutoBuilder.object();

    m_calculatedSolarObjectNumber = static_cast<int>(m_planetContainer.size());

    // add additional solar objects
    m_planetContainer[SolarObjects::SaturnRing] = saturnRingBuilder.object();
    m_planetContainer[SolarObjects::UranusRing] = uranusRingBuilder.object();
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
