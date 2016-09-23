#include "solarmathcore.h"

SolarSystem::SolarMathCore::SolarMathCore(QObject* parent):
    ISolarMathCore(parent)
{

}

void SolarSystem::SolarMathCore::setSolarView(Qt3DRender::QCamera *camera)
{
    this->camera = camera;
}

float SolarSystem::SolarMathCore::getOuterRadius(SolarSystem::SolarObjects object)
{
    float outerRadius = SolarValues::solarDistance;

    switch (object) {

        case SolarObjects::Mercury:
            outerRadius += PlanetsValues::Mercury::radius;
            break;

        case SolarObjects::Venus:
            outerRadius += PlanetsValues::Venus::radius;
            break;

        case SolarObjects::Earth:
            outerRadius += PlanetsValues::Earth::radius;
            break;

        case SolarObjects::Mars:
            outerRadius += PlanetsValues::Mars::radius;
            break;

        case SolarObjects::Jupiter:
            outerRadius += PlanetsValues::Jupier::radius;
            break;

        case SolarObjects::Neptune:
            outerRadius += PlanetsValues::Neptune::radius;
            break;

        case SolarObjects::Saturn:
            outerRadius += PlanetsValues::Saturn::radius + SolarValues::saturnOuterRadius;
            break;

        case SolarObjects::Uranus:
            outerRadius += PlanetsValues::Uranus::radius + SolarValues::uranusOuterRadius;
            break;

        case SolarObjects::Moon:
            outerRadius += PlanetsValues::Moon::radius;
            break;

        case SolarObjects::Sun:
            outerRadius = PlanetsValues::Sun::radius / 100.0;
            break;

        default:
            break;

    }

    return outerRadius;
}

QVector3D SolarSystem::SolarMathCore::solarObjectPosition(SolarSystem::SolarObjects object)
{

}
