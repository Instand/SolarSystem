#include "planetscontainer.h"

void SolarSystem::PlanetsContainer::initialize(Qt3DCore::QNode *root)
{
    //can be called one time
    if (!initialized)
    {
        //create sun
        Planet* sun = new Planet(root);
        sun->diffuse().setSource(QUrl::fromLocalFile(":/sunmap.jpg"));

        //create mercury
        Planet* mercury = new Planet(root);
        mercury->diffuse().setSource(QUrl::fromLocalFile(":/mercurymap.jpg"));
        mercury->normal().setSource(QUrl::fromLocalFile(":/mercurynormal.jpg"));

        //create venus
        Planet* venus = new Planet(root);
        venus->diffuse().setSource(QUrl::fromLocalFile(":/venusmap.jpg"));
        venus->normal().setSource(QUrl::fromLocalFile(":/venusmap.jpgnormal.jpg"));

        //create earth
        Planet* earth = new Planet(root);
        earth->diffuse().setSource(QUrl::fromLocalFile(":/earthmap1k.jpg"));
        earth->normal().setSource(QUrl::fromLocalFile(":/earthnormal1k.jpg"));
        earth->specular().setSource(QUrl::fromLocalFile(":/earthspec1k.jpg"));

        //create moon
        Planet* moon = new Planet(root);
        moon->diffuse().setSource(QUrl::fromLocalFile(":/moonmap1k.jpg"));
        moon->normal().setSource(QUrl::fromLocalFile(":/moonnormal1k.jpg"));

        //create mars
        Planet* mars = new Planet(root);
        mars->diffuse().setSource(QUrl::fromLocalFile(":/marsmap1k.jpg"));
        mars->normal().setSource(QUrl::fromLocalFile(":/marsnormal1k.jpg"));

        //create jupiter
        Planet* jupiter = new Planet(root);
        jupiter->diffuse().setSource(QUrl::fromLocalFile(":/jupitermap.jpg"));

        //create saturn
        Planet* saturn = new Planet(root);
        saturn->diffuse().setSource(QUrl::fromLocalFile(":/saturnmap.jpg"));

        //create uranus
        Planet* uranus = new Planet(root);
        uranus->diffuse().setSource(QUrl::fromLocalFile(":/uranusmap.jpg"));

        //create neptune
        Planet* neptune = new Planet(root);
        neptune->diffuse().setSource(QUrl::fromLocalFile(":/neptunemap.jpg"));

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

//create static values
SolarSystem::PlanetArray SolarSystem::PlanetsContainer::planetContainer;
bool SolarSystem::PlanetsContainer::initialized = false;
