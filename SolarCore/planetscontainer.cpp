#include "planetscontainer.h"
#include <Scene/SceneObjects/planet.h>
#include <Scene/SceneObjects/planetring.h>
#include <Qt3DRender/QPointLight>
#include <Qt3DRender/QPickEvent>

SolarSystem::PlanetsContainer::PlanetsContainer(Qt3DCore::QNode *root, QObject *parent):
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

void SolarSystem::PlanetsContainer::initialize(Qt3DCore::QNode *root)
{
    int shiness = 1000.0f;

    //create sun
    Planet* sun = new Planet(root);
    sun->diffuse().setSource(QUrl::fromLocalFile(":/Resources/Images/sunmap.jpg"));
    sun->material().setShininess(sun->material().shininess() * shiness);
    sun->setTilt(SolarObjectsValues::Sun::tilt);

    Qt3DRender::QPointLight* sunLight = new Qt3DRender::QPointLight();
    sunLight->setIntensity(1.8f);
    sun->addComponent(sunLight);
    sun->setObjectName(SolarObjectsValues::Sun::toString);

    //create mercury
    Planet* mercury = new Planet(root);
    mercury->diffuse().setSource(QUrl::fromLocalFile(":/Resources/Images/mercurymap.jpg"));
    mercury->material().setShininess(mercury->material().shininess() * shiness);
    mercury->setTilt(SolarObjectsValues::Mercury::tilt);

    Qt3DRender::QTextureImage* mercuryNormal = new Qt3DRender::QTextureImage();
    mercuryNormal->setSource(QUrl::fromLocalFile(":/Resources/Images/mercurynormal.jpg"));
    mercury->material().normal()->addTextureImage(mercuryNormal);

    //create venus
    Planet* venus = new Planet(root);
    venus->diffuse().setSource(QUrl::fromLocalFile(":/Resources/Images/venusmap.jpg"));
    venus->material().setShininess(venus->material().shininess() * shiness);
    venus->setTilt(SolarObjectsValues::Venus::tilt);

    /*Qt3DRender::QTextureImage* venusNormal = new Qt3DRender::QTextureImage();
        venusNormal->setSource(QUrl::fromLocalFile(":/Resources/Images/venusnormal.jpg"));
        venus->material().normal()->addTextureImage(venusNormal);*/

    //create earth
    Planet* earth = new Planet(root);
    earth->diffuse().setSource(QUrl::fromLocalFile(":/Resources/Images/earthmap1k.jpg"));
    earth->material().setShininess(earth->material().shininess() * shiness);
    earth->setTilt(SolarObjectsValues::Earth::tilt);

    Qt3DRender::QTextureImage* earthNormal = new Qt3DRender::QTextureImage();
    earthNormal->setSource(QUrl::fromLocalFile(":/Resources/Images/earthnormal1k.jpg"));
    earth->material().normal()->addTextureImage(earthNormal);

    /*Qt3DRender::QTextureImage* earthSpecular = new Qt3DRender::QTextureImage();
        earthSpecular->setSource(QUrl::fromLocalFile(":/Resources/Images/earthspec1k.jpg"));
        earth->material().specular()->addTextureImage(earthSpecular);*/

    //create moon
    Planet* moon = new Planet(root);
    moon->diffuse().setSource(QUrl::fromLocalFile(":/Resources/Images/moonmap1k.jpg"));
    moon->material().setShininess(moon->material().shininess() * shiness);
    moon->setTilt(SolarObjectsValues::Moon::tilt);

    Qt3DRender::QTextureImage* moonNormal = new Qt3DRender::QTextureImage();
    moonNormal->setSource(QUrl::fromLocalFile(":/Resources/Images/moonnormal1k.jpg"));
    moon->material().normal()->addTextureImage(moonNormal);

    //create mars
    Planet* mars = new Planet(root);
    mars->diffuse().setSource(QUrl::fromLocalFile(":/Resources/Images/marsmap1k.jpg"));
    mars->material().setShininess(mars->material().shininess() * shiness);
    mars->setTilt(SolarObjectsValues::Mars::tilt);

    Qt3DRender::QTextureImage* marsNormal = new Qt3DRender::QTextureImage();
    marsNormal->setSource(QUrl::fromLocalFile(":/Resources/Images/marsnormal1k.jpg"));
    mars->material().normal()->addTextureImage(marsNormal);

    //create jupiter
    Planet* jupiter = new Planet(root);
    jupiter->diffuse().setSource(QUrl::fromLocalFile(":/Resources/Images/jupitermap.jpg"));
    jupiter->material().setShininess(jupiter->material().shininess() * shiness);
    jupiter->setTilt(SolarObjectsValues::Jupier::tilt);

    //create saturn
    Planet* saturn = new Planet(root);
    saturn->diffuse().setSource(QUrl::fromLocalFile(":/Resources/Images/saturnmap.jpg"));
    saturn->material().setShininess(saturn->material().shininess() * shiness);
    saturn->setTilt(SolarObjectsValues::Saturn::tilt);

    //create uranus
    Planet* uranus = new Planet(root);
    uranus->diffuse().setSource(QUrl::fromLocalFile(":/Resources/Images/uranusmap.jpg"));
    uranus->material().setShininess(uranus->material().shininess() * shiness);
    uranus->setTilt(SolarObjectsValues::Uranus::tilt);

    //create neptune
    Planet* neptune = new Planet(root);
    neptune->diffuse().setSource(QUrl::fromLocalFile(":/Resources/Images/neptunemap.jpg"));
    neptune->material().setShininess(neptune->material().shininess() * shiness);
    neptune->setTilt(SolarObjectsValues::Neptune::tilt);

    //create planet rings
    PlanetRing* saturnRing = new PlanetRing(root);
    saturnRing->diffuse().setSource(QUrl::fromLocalFile(":Resources/Images/saturnringcolortrans.png"));
    saturnRing->setTilt(SolarObjectsValues::Saturn::tilt);

    PlanetRing* uranusRing = new PlanetRing(root);
    uranusRing->diffuse().setSource(QUrl::fromLocalFile(":Resources/Images/uranusringcolortrans.png"));
    uranusRing->setTilt(SolarObjectsValues::Uranus::tilt);

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
    planetContainer[SolarObjects::SaturnRing] = saturnRing;
    planetContainer[SolarObjects::UranusRing] = uranusRing;

    rootNode = root;

    auto sunPicker = planetContainer[SolarObjects::Sun];
    QObject::connect(&sunPicker->picker(), &Qt3DRender::QObjectPicker::clicked, this, &PlanetsContainer::onPressed);
}

int SolarSystem::PlanetsContainer::planetsNumber() const
{
    return (int)planetContainer.size();
}

SolarSystem::PlanetArray SolarSystem::PlanetsContainer::planets() const
{
    return planetContainer;
}

void SolarSystem::PlanetsContainer::onPressed(Qt3DRender::QPickEvent *pick)
{
    if (pick->button() == Qt3DRender::QPickEvent::LeftButton)
    {
        qDebug() << "Clicked";

        emit coordClicked(pick->worldIntersection());
    }
}
