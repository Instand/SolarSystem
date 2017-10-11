#include "planetscontainer.h"
#include <Scene/SceneObjects/planet.h>
#include <Scene/SceneObjects/planetring.h>
#include <Scene/SceneObjects/earthcloud.h>

#ifdef QT3D_MATERIALS
    #include <Scene/SceneObjects/sun.h>
#else
    #include <SolarCore/SolarRender/solarlight.h>
    #include <SolarCore/SolarRender/solarobjecteffect.h>
    #include <SolarCore/SolarRender/solarshadoweffect.h>
    #include <SolarCore/SolarRender/solardiffuseeffect.h>
#endif

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
#ifdef QT3D_MATERIALS
    auto shiness = 10.0f;

    ///create sun
    Sun* sun = new Sun(root);
    auto sunMaterial = qobject_cast<Qt3DExtras::QDiffuseMapMaterial*>(sun->material());

    //sun diffuse
    Qt3DRender::QTextureImage* sunDiffuse = new Qt3DRender::QTextureImage();
    sunDiffuse->setSource(QUrl::fromLocalFile(":/Resources/Images/sun_map.jpg"));
    sunMaterial->diffuse()->addTextureImage(sunDiffuse);

    //sun material setup
    sunMaterial->setShininess(sunMaterial->shininess() * shiness);
    sun->setTilt(SolarObjectsValues::Sun::tilt);

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
#else
    auto shininess = 50.0f;
    auto giantShininess = 20.0f;

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
    jupiter->material().setSnininess(giantShininess);
    jupiter->setTilt(SolarObjectsValues::Jupier::tilt);

    //create saturn
    Planet* saturn = new Planet(root);
    saturn->material().setEffect(_shadowEffect);
    saturn->material().setDiffuseTextureSource(":/Resources/Images/saturnmap.jpg");
    saturn->material().setNormalTextureSource(":/Resources/Images/saturnnormal.jpg");
    saturn->material().setAmbient(planetAmbient);
    saturn->material().setSpecular(planetSpecular);
    saturn->material().setSnininess(giantShininess);
    saturn->setTilt(SolarObjectsValues::Saturn::tilt);

    //create uranus
    Planet* uranus = new Planet(root);
    uranus->material().setEffect(_shadowEffect);
    uranus->material().setDiffuseTextureSource(":/Resources/Images/uranusmap.jpg");
    uranus->material().setNormalTextureSource(":/Resources/Images/uranusnormal.jpg");
    uranus->material().setAmbient(planetAmbient);
    uranus->material().setSpecular(planetSpecular);
    uranus->material().setSnininess(giantShininess);
    uranus->setTilt(SolarObjectsValues::Uranus::tilt);

    //create neptune
    Planet* neptune = new Planet(root);
    neptune->material().setEffect(_baseEffect);
    neptune->material().setDiffuseTextureSource(":/Resources/Images/neptunemap.jpg");
    neptune->material().setNormalTextureSource(":/Resources/Images/neptunenormal.jpg");
    neptune->material().setAmbient(planetAmbient);
    neptune->material().setSpecular(planetSpecular);
    neptune->material().setSnininess(2000.0);
    neptune->setTilt(SolarObjectsValues::Neptune::tilt);

    //create pluto
    Planet* pluto = new Planet(root);
    pluto->material().setEffect(_baseEffect);
    pluto->material().setDiffuseTextureSource(":/Resources/Images/plutomap.jpg");
    pluto->material().setNormalTextureSource(":/Resources/Images/plutonormal.jpg");
    pluto->material().setAmbient(planetAmbient);
    pluto->material().setSpecular(planetSpecular);
    pluto->material().setSnininess(giantShininess);
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
    earthClouds->material().setSpecular(QColor("#000000"));
#endif

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
}

int SolarSystem::PlanetsContainer::planetsNumber() const
{
    return (int)planetContainer.size();
}

SolarSystem::PlanetArray SolarSystem::PlanetsContainer::planets() const
{
    return planetContainer;
}

#ifndef QT3D_MATERIALS
SolarSystem::SolarObjectEffect* SolarSystem::PlanetsContainer::baseEffect() const
{
    return _baseEffect;
}

SolarSystem::SolarShadowEffect* SolarSystem::PlanetsContainer::shadowEffect() const
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
#endif
