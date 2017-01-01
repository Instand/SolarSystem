#include "planetscontainer.h"
#include <Qt3DRender/QPointLight>

void SolarSystem::PlanetsContainer::initialize(Qt3DCore::QNode *root)
{
    //can be called one time
    if (!initialized)
    {
        //create sun
        Planet* sun = new Planet(root);
        sun->diffuse().setSource(QUrl::fromLocalFile(":/Resources/Images/sunmap.jpg"));
        sun->material().setShininess(sun->material().shininess() * 1000.0f);

        Qt3DRender::QPointLight* sunLight = new Qt3DRender::QPointLight();
        sunLight->setIntensity(1.7f);
        sun->addComponent(sunLight);

        //create mercury
        Planet* mercury = new Planet(root);
        mercury->diffuse().setSource(QUrl::fromLocalFile(":/Resources/Images/mercurymap.jpg"));

        Qt3DRender::QTextureImage* mercuryNormal = new Qt3DRender::QTextureImage();
        mercuryNormal->setSource(QUrl::fromLocalFile(":/Resources/Images/mercurynormal.jpg"));
        mercury->material().normal()->addTextureImage(mercuryNormal);

        //create venus
        Planet* venus = new Planet(root);
        venus->diffuse().setSource(QUrl::fromLocalFile(":/Resources/Images/venusmap.jpg"));

        Qt3DRender::QTextureImage* venusNormal = new Qt3DRender::QTextureImage();
        venusNormal->setSource(QUrl::fromLocalFile(":/Resources/Images/venusnormal.jpg"));
        venus->material().normal()->addTextureImage(venusNormal);

        //create earth
        Planet* earth = new Planet(root);
        earth->diffuse().setSource(QUrl::fromLocalFile(":/Resources/Images/earthmap1k.jpg"));

        Qt3DRender::QTextureImage* earthNormal = new Qt3DRender::QTextureImage();
        earthNormal->setSource(QUrl::fromLocalFile(":/Resources/Images/earthnormal1k.jpg"));
        earth->material().normal()->addTextureImage(earthNormal);

        Qt3DRender::QTextureImage* earthSpecular = new Qt3DRender::QTextureImage();
        earthSpecular->setSource(QUrl::fromLocalFile(":/Resources/Images/earthspec1k.jpg"));
        earth->material().specular()->addTextureImage(earthSpecular);

        //create moon
        Planet* moon = new Planet(root);
        moon->diffuse().setSource(QUrl::fromLocalFile(":/Resources/Images/moonmap1k.jpg"));

        Qt3DRender::QTextureImage* moonNormal = new Qt3DRender::QTextureImage();
        moonNormal->setSource(QUrl::fromLocalFile(":/Resources/Images/moonnormal1k.jpg"));
        moon->material().normal()->addTextureImage(moonNormal);

        //create mars
        Planet* mars = new Planet(root);
        mars->diffuse().setSource(QUrl::fromLocalFile(":/Resources/Images/marsmap1k.jpg"));

        Qt3DRender::QTextureImage* marsNormal = new Qt3DRender::QTextureImage();
        marsNormal->setSource(QUrl::fromLocalFile(":/Resources/Images/marsnormal1k.jpg"));
        mars->material().normal()->addTextureImage(marsNormal);

        //create jupiter
        Planet* jupiter = new Planet(root);
        jupiter->diffuse().setSource(QUrl::fromLocalFile(":/Resources/Images/jupitermap.jpg"));

        //create saturn
        Planet* saturn = new Planet(root);
        saturn->diffuse().setSource(QUrl::fromLocalFile(":/Resources/Images/saturnmap.jpg"));

        //create uranus
        Planet* uranus = new Planet(root);
        uranus->diffuse().setSource(QUrl::fromLocalFile(":/Resources/Images/uranusmap.jpg"));

        //create neptune
        Planet* neptune = new Planet(root);
        neptune->diffuse().setSource(QUrl::fromLocalFile(":/Resources/Images/neptunemap.jpg"));

        //add planets to map
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

        initialized = true;
    }
}

int SolarSystem::PlanetsContainer::planetsNumber()
{
    return (int)planetContainer.size();
}

SolarSystem::PlanetArray SolarSystem::PlanetsContainer::planets()
{
    return planetContainer;
}

//create static values
SolarSystem::PlanetArray SolarSystem::PlanetsContainer::planetContainer;
bool SolarSystem::PlanetsContainer::initialized = false;
