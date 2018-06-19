#include "planetscontainer.h"
#include <Scene/SceneObjects/planet.h>
#include <Scene/SceneObjects/planetring.h>
#include <Scene/SceneObjects/earthcloud.h>
#include <Scene/SceneObjects/sun.h>
#include <Qt3DRender/QTexture>
#include <Qt3DRender/QPickEvent>

SolarSystem::PlanetsContainer::PlanetsContainer(Qt3DCore::QNode* root, QObject* parent):
    QObject(parent)
{
    initialize(root);
}

SolarSystem::PlanetsContainer::~PlanetsContainer()
{
    if (m_RootNode == nullptr)
    {
        for (auto& elem : m_PlanetContainer)
        {
            if (elem.second)
                delete elem.second;
        }
    }
}

void SolarSystem::PlanetsContainer::initialize(Qt3DCore::QNode* root)
{
    auto shiness = 10.0f;

    ///create sun
    Sun* sun = new Sun(root);

    ///create mercury
    Planet* mercury = new Planet(root);
    auto mercuryMaterial = qobject_cast<Qt3DExtras::QNormalDiffuseMapMaterial*>(mercury->material());

    //mercury diffuse
    Qt3DRender::QTextureImage* mercuryDiffuse = new Qt3DRender::QTextureImage();
    mercuryDiffuse->setSource(QUrl::fromLocalFile(":/Resources/Images/mercurymap.jpg"));
    mercuryMaterial->diffuse()->addTextureImage(mercuryDiffuse);

    //mercury normal
    Qt3DRender::QTextureImage* mercuryNormal = new Qt3DRender::QTextureImage();
    mercuryNormal->setSource(QUrl::fromLocalFile(":/Resources/Images/mercurynormal.jpg"));
    mercuryMaterial->normal()->addTextureImage(mercuryNormal);

    //mercury material setup
    mercuryMaterial->setShininess(mercuryMaterial->shininess() * shiness);
    mercury->setTilt(SolarObjectsValues::Mercury::tilt);

    ///create venus
    Planet* venus = new Planet(root);
    auto venusMaterial = qobject_cast<Qt3DExtras::QNormalDiffuseMapMaterial*>(venus->material());

    //venus diffuse
    Qt3DRender::QTextureImage* venusDiffuse = new Qt3DRender::QTextureImage();
    venusDiffuse->setSource(QUrl::fromLocalFile(":/Resources/Images/venus_atmo.jpg"));
    venusMaterial->diffuse()->addTextureImage(venusDiffuse);

    //venus normal
    Qt3DRender::QTextureImage* venusNormal = new Qt3DRender::QTextureImage();
    venusNormal->setSource(QUrl::fromLocalFile(":/Resources/Images/venus_atmonormal.jpg"));
    venusMaterial->normal()->addTextureImage(venusNormal);

    //venus material setup
    venusMaterial->setShininess(venusMaterial->shininess() * shiness);
    venus->setTilt(SolarObjectsValues::Venus::tilt);

    ///create earth
    Planet* earth = new Planet(root);
    auto earthMaterial = qobject_cast<Qt3DExtras::QNormalDiffuseMapMaterial*>(earth->material());

    //earth diffuse
    Qt3DRender::QTextureImage* earthDiffuse = new Qt3DRender::QTextureImage();
    earthDiffuse->setSource(QUrl::fromLocalFile(":/Resources/Images/earthmap1k.jpg"));
    earthMaterial->diffuse()->addTextureImage(earthDiffuse);

    //earth normal
    Qt3DRender::QTextureImage* earthNormal = new Qt3DRender::QTextureImage();
    earthNormal->setSource(QUrl::fromLocalFile(":/Resources/Images/earthnormal1k.jpg"));
    earthMaterial->normal()->addTextureImage(earthNormal);

    //earth material setup
    earthMaterial->setShininess(earthMaterial->shininess() * shiness);
    earth->setTilt(SolarObjectsValues::Earth::tilt);

    ///create moon
    Planet* moon = new Planet(root);
    auto moonMaterial = qobject_cast<Qt3DExtras::QNormalDiffuseMapMaterial*>(moon->material());

    //moon diffuse
    Qt3DRender::QTextureImage* moonDiffuse = new Qt3DRender::QTextureImage();
    moonDiffuse->setSource(QUrl::fromLocalFile(":/Resources/Images/moonmap1k.jpg"));
    moonMaterial->diffuse()->addTextureImage(moonDiffuse);

    //moon normal
    Qt3DRender::QTextureImage* moonNormal = new Qt3DRender::QTextureImage();
    moonNormal->setSource(QUrl::fromLocalFile(":/Resources/Images/moonnormal1k.jpg"));
    moonMaterial->normal()->addTextureImage(moonNormal);

    //moon material setup
    moonMaterial->setShininess(moonMaterial->shininess() * shiness);
    moon->setTilt(SolarObjectsValues::Moon::tilt);

    ///create mars
    Planet* mars = new Planet(root);
    auto marsMaterial = qobject_cast<Qt3DExtras::QNormalDiffuseMapMaterial*>(mars->material());

    //mars diffuse
    Qt3DRender::QTextureImage* marsDiffuse = new Qt3DRender::QTextureImage();
    marsDiffuse->setSource(QUrl::fromLocalFile(":/Resources/Images/marsmap1k.jpg"));
    marsMaterial->diffuse()->addTextureImage(marsDiffuse);

    //mars normal
    Qt3DRender::QTextureImage* marsNormal = new Qt3DRender::QTextureImage();
    marsNormal->setSource(QUrl::fromLocalFile(":/Resources/Images/marsnormal1k.jpg"));
    marsMaterial->normal()->addTextureImage(marsNormal);

    //mars material setup
    marsMaterial->setShininess(marsMaterial->shininess() * shiness);
    mars->setTilt(SolarObjectsValues::Mars::tilt);

    ///create jupiter
    Planet* jupiter = new Planet(root);
    auto jupiterMaterial = qobject_cast<Qt3DExtras::QNormalDiffuseMapMaterial*>(jupiter->material());

    //jupiter diffuse
    Qt3DRender::QTextureImage* jupiterDiffuse = new Qt3DRender::QTextureImage();
    jupiterDiffuse->setSource(QUrl::fromLocalFile(":/Resources/Images/jupitermap.jpg"));
    jupiterMaterial->diffuse()->addTextureImage(jupiterDiffuse);

    //jupiter normal
    Qt3DRender::QTextureImage* jupiterNormal = new Qt3DRender::QTextureImage();
    jupiterNormal->setSource(QUrl::fromLocalFile(":/Resources/Images/jupiternormal.jpg"));
    jupiterMaterial->normal()->addTextureImage(jupiterNormal);

    //jupiter material setup
    jupiterMaterial->setShininess(jupiterMaterial->shininess());
    jupiter->setTilt(SolarObjectsValues::Jupier::tilt);

    ///create saturn
    Planet* saturn = new Planet(root);
    auto saturnMaterial = qobject_cast<Qt3DExtras::QNormalDiffuseMapMaterial*>(saturn->material());

    //saturn diffuse
    Qt3DRender::QTextureImage* saturnDiffuse = new Qt3DRender::QTextureImage();
    saturnDiffuse->setSource(QUrl::fromLocalFile(":/Resources/Images/saturnmap.jpg"));
    saturnMaterial->diffuse()->addTextureImage(saturnDiffuse);

    //saturn normal
    Qt3DRender::QTextureImage* saturnNormal = new Qt3DRender::QTextureImage();
    saturnNormal->setSource(QUrl::fromLocalFile(":/Resources/Images/saturnnormal.jpg"));
    saturnMaterial->normal()->addTextureImage(saturnNormal);

    //saturn material setup
    saturnMaterial->setShininess(saturnMaterial->shininess() * shiness);
    saturn->setTilt(SolarObjectsValues::Saturn::tilt);

    ///create uranus
    Planet* uranus = new Planet(root);
    auto uranusMaterial = qobject_cast<Qt3DExtras::QNormalDiffuseMapMaterial*>(uranus->material());

    //uranus diffuse
    Qt3DRender::QTextureImage* uranusDiffuse = new Qt3DRender::QTextureImage();
    uranusDiffuse->setSource(QUrl::fromLocalFile(":/Resources/Images/uranusmap.jpg"));
    uranusMaterial->diffuse()->addTextureImage(uranusDiffuse);

    //uranus normal
    Qt3DRender::QTextureImage* uranusNormal = new Qt3DRender::QTextureImage();
    uranusNormal->setSource(QUrl::fromLocalFile(":/Resources/Images/uranusnormal.jpg"));
    uranusMaterial->normal()->addTextureImage(uranusNormal);

    //uranus material setup
    uranusMaterial->setShininess(uranusMaterial->shininess() * shiness);
    uranus->setTilt(SolarObjectsValues::Uranus::tilt);

    ///create neptune
    Planet* neptune = new Planet(root);
    auto neptuneMaterial = qobject_cast<Qt3DExtras::QNormalDiffuseMapMaterial*>(neptune->material());

    //neptune diffuse
    Qt3DRender::QTextureImage* neptuneDiffuse = new Qt3DRender::QTextureImage();
    neptuneDiffuse->setSource(QUrl::fromLocalFile(":/Resources/Images/neptunemap.jpg"));
    neptuneMaterial->diffuse()->addTextureImage(neptuneDiffuse);

    //neptune normal
    Qt3DRender::QTextureImage* neptuneNormal = new Qt3DRender::QTextureImage();
    neptuneNormal->setSource(QUrl::fromLocalFile(":/Resources/Images/neptunenormal.jpg"));
    neptuneMaterial->normal()->addTextureImage(neptuneNormal);

    //neptune material setup
    neptuneMaterial->setShininess(neptuneMaterial->shininess() * shiness);
    neptune->setTilt(SolarObjectsValues::Neptune::tilt);

    ///create pluto
    Planet* pluto = new Planet(root);
    auto plutoMaterial = qobject_cast<Qt3DExtras::QNormalDiffuseMapMaterial*>(pluto->material());

    //pluto diffuse
    Qt3DRender::QTextureImage* plutoDiffuse = new Qt3DRender::QTextureImage();
    plutoDiffuse->setSource(QUrl::fromLocalFile(":/Resources/Images/plutomap.jpg"));
    plutoMaterial->diffuse()->addTextureImage(plutoDiffuse);

    //pluto normal
    Qt3DRender::QTextureImage* plutoNormal = new Qt3DRender::QTextureImage();
    plutoNormal->setSource(QUrl::fromLocalFile(":/Resources/Images/plutonormal.jpg"));
    plutoMaterial->normal()->addTextureImage(plutoNormal);

    //pluto material setup
    plutoMaterial->setShininess(plutoMaterial->shininess() * shiness);
    pluto->setTilt(SolarObjectsValues::Pluto::tilt);

    ///create saturn rings
    PlanetRing* saturnRing = new PlanetRing(root);
    auto saturnRingMaterial = qobject_cast<Qt3DExtras::QNormalDiffuseMapAlphaMaterial*>(saturnRing->material());

    //saturn rings diffuse
    Qt3DRender::QTextureImage* saturnRingDiffuse = new Qt3DRender::QTextureImage();
    saturnRingDiffuse->setSource(QUrl::fromLocalFile(":/Resources/Images/saturnringcolortrans.png"));
    saturnRingMaterial->diffuse()->addTextureImage(saturnRingDiffuse);

    //saturn rings normal
    Qt3DRender::QTextureImage* saturnRingNormal = new Qt3DRender::QTextureImage();
    saturnRingNormal->setSource(QUrl::fromLocalFile(":/Resources/Images/saturnringcolortransnormal.png"));
    saturnRingMaterial->normal()->addTextureImage(saturnRingNormal);

    //saturn material setup
    saturnRing->setTilt(SolarObjectsValues::Saturn::tilt);

    ///create uranus rings
    PlanetRing* uranusRing = new PlanetRing(root);
    auto uranusRingMaterial = qobject_cast<Qt3DExtras::QNormalDiffuseMapAlphaMaterial*>(uranusRing->material());

    //uranus rings diffuse
    Qt3DRender::QTextureImage* uranusRingDiffuse = new Qt3DRender::QTextureImage();
    uranusRingDiffuse->setSource(QUrl::fromLocalFile(":/Resources/Images/uranusringcolortrans.png"));
    uranusRingMaterial->diffuse()->addTextureImage(uranusRingDiffuse);

    //uranus rings normal
    Qt3DRender::QTextureImage* uranusRingNormal = new Qt3DRender::QTextureImage();
    uranusRingNormal->setSource(QUrl::fromLocalFile(":/Resources/Images/uranusringcolortransnormal.png"));
    uranusRingMaterial->normal()->addTextureImage(uranusRingNormal);

    //uranus rings material setup
    uranusRing->setTilt(SolarObjectsValues::Uranus::tilt);

    ///create earth clouds
    EarthCloud* earthClouds = new EarthCloud(root);

    //add planets to map, to interface IVisualSolarObject
    m_PlanetContainer[SolarObjects::Sun] = sun;
    m_PlanetContainer[SolarObjects::Mercury] = mercury;
    m_PlanetContainer[SolarObjects::Venus] = venus;
    m_PlanetContainer[SolarObjects::Earth] = earth;
    m_PlanetContainer[SolarObjects::Moon] = moon;
    m_PlanetContainer[SolarObjects::Mars] = mars;
    m_PlanetContainer[SolarObjects::Jupiter] = jupiter;
    m_PlanetContainer[SolarObjects::Saturn] = saturn;
    m_PlanetContainer[SolarObjects::Uranus] = uranus;
    m_PlanetContainer[SolarObjects::Neptune] = neptune;
    m_PlanetContainer[SolarObjects::Pluto] = pluto;

    m_CalculatedSolarObjectNumber = static_cast<int>(m_PlanetContainer.size());

    //add additional solar objects
    m_PlanetContainer[SolarObjects::SaturnRing] = saturnRing;
    m_PlanetContainer[SolarObjects::UranusRing] = uranusRing;
    m_PlanetContainer[SolarObjects::EarthCloud] = earthClouds;

    m_RootNode = root;
}

int SolarSystem::PlanetsContainer::planetsNumber() const
{
    return m_CalculatedSolarObjectNumber;
}

SolarSystem::PlanetArray& SolarSystem::PlanetsContainer::planets() const
{
    return m_PlanetContainer;
}
