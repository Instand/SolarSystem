#include "planetscontainer.h"
#include <Scene/SceneObjects/planet.h>
#include <Scene/SceneObjects/planetring.h>
#include <Scene/SceneObjects/earthcloud.h>
#include <SolarCore/SolarRender/solarlight.h>
#include <SolarCore/SolarRender/solarobjecteffect.h>
#include <SolarCore/SolarRender/solarshadoweffect.h>
#include <SolarCore/SolarRender/solardiffuseeffect.h>
#include <Qt3DRender/QTexture>
#include <Qt3DRender/QPickEvent>

SolarSystem::PlanetsContainer::PlanetsContainer(Qt3DCore::QNode* root, QObject* parent):
    QObject(parent)
{
    initialize(root);
}

SolarSystem::PlanetsContainer::~PlanetsContainer()
{
    if (rootNode == nullptr)
    {
        for (auto& elem : planetContainer)
        {
            if (elem.second)
                delete elem.second;
        }
    }
}

void SolarSystem::PlanetsContainer::initialize(Qt3DCore::QNode* root)
{
    int shininess = 50.0f;

    //base effect
    _baseEffect = new SolarObjectEffect(root);
    _shadowEffect = new SolarShadowEffect(root);
    _diffuseEffect = new SolarDiffuseEffect(root);

    QColor sunAmbient = QColor("#ffffff");
    QColor planetAmbient = QColor("#222222");
    QColor planetSpecular = QColor(QColor::fromRgbF(0.2f, 0.2f, 0.2f, 1.0f));
    QColor ringAmbient = QColor("#111111");
    QColor planetCloudAmbient = QColor("#000000");

    //create sun
    Planet* sun = new Planet(root);
    sun->material().setEffect(_diffuseEffect);
    sun->material().setDiffuseTextureSource(":/Resources/Images/sun_map.jpg");
    sun->material().setAmbient(sunAmbient);
    sun->setTilt(SolarObjectsValues::Sun::tilt);

    //create mercury
    Planet* mercury = new Planet(root);
    mercury->material().setEffect(_baseEffect);
    mercury->material().setDiffuseTextureSource(":/Resources/Images/mercurymap.jpg");
    mercury->material().setNormalTextureSource(":/Resources/Images/mercurynormal.jpg");
    mercury->material().setAmbient(planetAmbient);
    mercury->material().setSpecular(planetSpecular);
    mercury->material().setSnininess(shininess);
    mercury->setTilt(SolarObjectsValues::Mercury::tilt);

    //create venus
    Planet* venus = new Planet(root);
    venus->material().setEffect(_baseEffect);
    venus->material().setDiffuseTextureSource(":/Resources/Images/venus_atmo.jpg");
    venus->material().setNormalTextureSource(":/Resources/Images/venus_atmonormal.jpg");
    venus->material().setAmbient(planetAmbient);
    venus->material().setSpecular(planetSpecular);
    venus->material().setSnininess(shininess);
    venus->setTilt(SolarObjectsValues::Venus::tilt);

    //create earth
    Planet* earth = new Planet(root);
    earth->material().setEffect(_baseEffect);
    earth->material().setDiffuseTextureSource(":/Resources/Images/earthmap1k.jpg");
    earth->material().setNormalTextureSource(":/Resources/Images/earthnormal1k.jpg");
    earth->material().setAmbient(planetAmbient);
    earth->material().setSpecular(planetSpecular);
    earth->material().setSnininess(shininess);
    earth->setTilt(SolarObjectsValues::Earth::tilt);

    //create moon
    Planet* moon = new Planet(root);
    moon->material().setEffect(_baseEffect);
    moon->material().setDiffuseTextureSource(":/Resources/Images/moonmap1k.jpg");
    moon->material().setNormalTextureSource(":/Resources/Images/moonnormal1k.jpg");
    moon->material().setAmbient(planetAmbient);
    moon->material().setSpecular(planetSpecular);
    moon->material().setSnininess(shininess);
    moon->setTilt(SolarObjectsValues::Moon::tilt);

    //create mars
    Planet* mars = new Planet(root);
    mars->material().setEffect(_baseEffect);
    mars->material().setDiffuseTextureSource(":/Resources/Images/marsmap1k.jpg");
    mars->material().setNormalTextureSource(":/Resources/Images/marsnormal1k.jpg");
    mars->material().setAmbient(planetAmbient);
    mars->material().setSpecular(planetSpecular);
    mars->material().setSnininess(shininess);
    mars->setTilt(SolarObjectsValues::Mars::tilt);

    //create jupiter
    Planet* jupiter = new Planet(root);  
    jupiter->material().setEffect(_baseEffect);
    jupiter->material().setDiffuseTextureSource(":/Resources/Images/jupitermap.jpg");
    jupiter->material().setNormalTextureSource(":/Resources/Images/jupiternormal.jpg");
    jupiter->material().setAmbient(planetAmbient);
    jupiter->material().setSpecular(planetSpecular);
    jupiter->material().setSnininess(1.0f);
    jupiter->setTilt(SolarObjectsValues::Jupier::tilt);

    //create saturn
    Planet* saturn = new Planet(root);
    saturn->material().setEffect(_shadowEffect);
    saturn->material().setDiffuseTextureSource(":/Resources/Images/saturnmap.jpg");
    saturn->material().setNormalTextureSource(":/Resources/Images/saturnnormal.jpg");
    saturn->material().setAmbient(planetAmbient);
    saturn->material().setSpecular(planetSpecular);
    saturn->material().setSnininess(1.0f);
    saturn->setTilt(SolarObjectsValues::Saturn::tilt);

    //create uranus
    Planet* uranus = new Planet(root);
    uranus->material().setEffect(_shadowEffect);
    uranus->material().setDiffuseTextureSource(":/Resources/Images/uranusmap.jpg");
    uranus->material().setNormalTextureSource(":/Resources/Images/uranusnormal.jpg");
    uranus->material().setAmbient(planetAmbient);
    uranus->material().setSpecular(planetSpecular);
    uranus->material().setSnininess(1.0f);
    uranus->setTilt(SolarObjectsValues::Uranus::tilt);

    //create neptune
    Planet* neptune = new Planet(root);
    neptune->material().setEffect(_baseEffect);
    neptune->material().setDiffuseTextureSource(":/Resources/Images/neptunemap.jpg");
    neptune->material().setNormalTextureSource(":/Resources/Images/neptunenormal.jpg");
    neptune->material().setAmbient(planetAmbient);
    neptune->material().setSpecular(planetSpecular);
    neptune->material().setSnininess(1.0f);
    neptune->setTilt(SolarObjectsValues::Neptune::tilt);

    //create pluto
    Planet* pluto = new Planet(root);
    pluto->material().setEffect(_baseEffect);
    pluto->material().setDiffuseTextureSource(":/Resources/Images/plutomap.jpg");
    pluto->material().setNormalTextureSource(":/Resources/Images/plutonormal.jpg");
    pluto->material().setAmbient(planetAmbient);
    pluto->material().setSpecular(planetSpecular);
    pluto->material().setSnininess(1.0f);
    pluto->setTilt(SolarObjectsValues::Pluto::tilt);

    //create planet rings
    PlanetRing* saturnRing = new PlanetRing(root);
    saturnRing->material().setEffect(_shadowEffect);
    saturnRing->material().setDiffuseTextureSource(":/Resources/Images/saturnringcolortrans.png");
    saturnRing->material().setAmbient(ringAmbient);
    saturnRing->material().setSpecular(QColor::fromRgbF(0.01f, 0.01f, 0.01f, 1.0f));
    saturnRing->material().setSnininess(1.0f);
    saturnRing->material().setOpacity(0.4f);
    saturnRing->setTilt(SolarObjectsValues::Saturn::tilt);

    PlanetRing* uranusRing = new PlanetRing(root);
    uranusRing->material().setEffect(_shadowEffect);
    uranusRing->material().setDiffuseTextureSource(":/Resources/Images/uranusringcolortrans.png");
    uranusRing->material().setAmbient(ringAmbient);
    uranusRing->material().setSpecular(QColor::fromRgbF(0.01f, 0.01f, 0.01f, 1.0f));
    uranusRing->material().setSnininess(1.0f);
    uranusRing->material().setOpacity(0.4f);
    uranusRing->setTilt(SolarObjectsValues::Uranus::tilt);

    //earth clouds
    EarthCloud* earthClouds = new EarthCloud(root);
    earthClouds->material().setEffect(_shadowEffect);
    earthClouds->material().setOpacity(0.8f);
    earthClouds->material().setSnininess(10.0f);
    earthClouds->material().setAmbient(planetCloudAmbient);
    earthClouds->material().setSpecular(QColor("#ffffff"));

    //add planets to map, to interface IVisualSolarObject
    planetContainer[SolarObjects::Sun] = sun;
    planetContainer[SolarObjects::Mercury] = mercury;
    planetContainer[SolarObjects::Venus] = venus;
    planetContainer[SolarObjects::Earth] = earth;
    planetContainer[SolarObjects::Moon] = moon;
    planetContainer[SolarObjects::Mars] = mars;
    planetContainer[SolarObjects::Jupiter] = jupiter;
    planetContainer[SolarObjects::Saturn] = saturn;
    planetContainer[SolarObjects::Uranus] = uranus;
    planetContainer[SolarObjects::Neptune] = neptune;
    planetContainer[SolarObjects::Pluto] = pluto;
    planetContainer[SolarObjects::SaturnRing] = saturnRing;
    planetContainer[SolarObjects::UranusRing] = uranusRing;
    planetContainer[SolarObjects::EarthCloud] = earthClouds;

    rootNode = root;

    auto sunPicker = planetContainer[SolarObjects::Jupiter];
    QObject::connect(&sunPicker->picker(), &Qt3DRender::QObjectPicker::clicked, this, &PlanetsContainer::onObjectPick);
}

int SolarSystem::PlanetsContainer::planetsNumber() const
{
    return (int)planetContainer.size();
}

SolarSystem::PlanetArray SolarSystem::PlanetsContainer::planets() const
{
    return planetContainer;
}

SolarSystem::SolarObjectEffect *SolarSystem::PlanetsContainer::baseEffect() const
{
    return _baseEffect;
}

SolarSystem::SolarShadowEffect *SolarSystem::PlanetsContainer::shadowEffect() const
{
    return _shadowEffect;
}

void SolarSystem::PlanetsContainer::setLight(SolarSystem::SolarLight* light)
{
    _baseEffect->setLight(light);
    _shadowEffect->setLight(light);
}

void SolarSystem::PlanetsContainer::setShadowTexture(Qt3DRender::QTexture2D* texture)
{
    _shadowEffect->setShadowTexture(texture);
}

void SolarSystem::PlanetsContainer::initEffects()
{
    _baseEffect->initialization();
    _shadowEffect->initialization();
}

void SolarSystem::PlanetsContainer::onObjectPick(Qt3DRender::QPickEvent *pick)
{
    if (pick->button() == Qt3DRender::QPickEvent::LeftButton)
    {
        qDebug() << "Clicked";
        qDebug() << pick->worldIntersection();
        //emit coordClicked(pick->worldIntersection());
    }
}
