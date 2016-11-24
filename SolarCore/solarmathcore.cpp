#include "solarmathcore.h"
#include <QtMath>

//Main Math data
struct SolarSystem::SolarMathCore::Data
{
    //Time variables
    int year = 2000;
    int month = 1;
    int day = 1;

    // Time scale formula based on http://www.stjarnhimlen.se/comp/ppcomp.html
    float startD;
    float oldTimeD;
    float currentTimeD;
    float deltaTimeD = 0;
    float daysPerFrame;
    float daysPerFrameScale;
    float planetScale;
    bool focusedScaling = false;
    int focusedMinimumScale = 20;
    float actualScale;
};

SolarSystem::SolarMathCore::SolarMathCore(QObject* parent):
    ISolarMathCore(parent),
    data(new Data())
{

}

SolarSystem::SolarMathCore::~SolarMathCore()
{
    if (camera)
        camera = nullptr;

    delete data;
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
            outerRadius += SolarObjectsValues::Mercury::radius;
            break;

        case SolarObjects::Venus:
            outerRadius += SolarObjectsValues::Venus::radius;
            break;

        case SolarObjects::Earth:
            outerRadius += SolarObjectsValues::Earth::radius;
            break;

        case SolarObjects::Mars:
            outerRadius += SolarObjectsValues::Mars::radius;
            break;

        case SolarObjects::Jupiter:
            outerRadius += SolarObjectsValues::Jupier::radius;
            break;

        case SolarObjects::Neptune:
            outerRadius += SolarObjectsValues::Neptune::radius;
            break;

        case SolarObjects::Saturn:
            outerRadius += SolarObjectsValues::Saturn::radius + SolarValues::saturnOuterRadius;
            break;

        case SolarObjects::Uranus:
            outerRadius += SolarObjectsValues::Uranus::radius + SolarValues::uranusOuterRadius;
            break;

        case SolarObjects::Moon:
            outerRadius += SolarObjectsValues::Moon::radius;
            break;

        case SolarObjects::Sun:
            outerRadius = SolarObjectsValues::Sun::radius / 100.0;
            break;

        default:
            break;

    }

    return outerRadius;
}

QVector3D SolarSystem::SolarMathCore::solarObjectPosition(SolarSystem::SolarObjects object)
{
    //get planet
    auto solarObj = solarContainer.solarObject(object);

    //calculation only for solar system planets
    if (object != SolarObjects::Sun)
    {
        //we have an object
        if (solarObj)
        {
            // Calculate the planet orbital elements from the current time in days
            auto N = (solarObj->N1() + solarObj->N2() * data->currentTimeD) * M_PI/ 180;
            auto iPlanet = (solarObj->i1() + solarObj->i2() * data->currentTimeD) * M_PI / 180;
            auto w = (solarObj->w1() + solarObj->w2() * data->currentTimeD) * M_PI / 180;
            auto a = solarObj->a1() + solarObj->a2() * data->currentTimeD;
            auto e = solarObj->e1() + solarObj->e2() * data->currentTimeD;
            auto M = (solarObj->M1() + solarObj->M2() * data->currentTimeD) * M_PI / 180;
            auto E = M + e * std::sin(M) * (1.0 + e * std::cos(M));

            auto xv = a * (std::cos(E) - e);
            auto yv = a * (std::sqrt(1.0 - e * e) * std::sin(E));
            auto v = std::atan2(yv, xv);

            // Calculate the distance (radius)
            auto r = std::sqrt(xv * xv + yv * yv);

            // From http://www.davidcolarusso.com/astro/
            // Modified to compensate for the right handed coordinate system of OpenGL
            auto xh = r * (std::cos(N) * std::cos(v + w)
                          - std::sin(N) * std::sin(v + w) * std::cos(iPlanet));
            auto zh = -r * (std::sin(N) * std::cos(v + w)
                           + std::cos(N) * std::sin(v + w) * std::cos(iPlanet));
            auto yh = r * (std::sin(w + v) * std::sin(iPlanet));

            // Apply the position offset from the center of orbit to the bodies
            SolarObjects centerOfOrbit = solarObj->centerOfOrbit();
            auto centerObj = solarContainer.solarObject(centerOfOrbit);

            solarObj->setX(centerObj->x() + xh * SolarValues::auScale);
            solarObj->setY(centerObj->y() + yh * SolarValues::auScale);
            solarObj->setZ(centerObj->z() + zh * SolarValues::auScale);
        }

    }

    solarObj->setRoll(data->deltaTimeD/ solarObj->period() * 360);

    return QVector3D(solarObj->x(), solarObj->y(), solarObj->z());
}

QVector3D SolarSystem::SolarMathCore::getNewSolarViewPosition(SolarSystem::SolarObjects object, double radius)
{
    QVector3D pos;

    if (object == SolarObjects::Sun)
    {
        pos = QVector3D(radius * data->planetScale * 2, radius * data->planetScale * 2, radius * data->planetScale * 2);
    }
}
