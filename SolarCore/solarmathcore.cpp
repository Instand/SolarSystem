#include "solarmathcore.h"
#include <Parser/solarparser.h>
#include <QtMath>

//Main Math data
struct SolarSystem::SolarMathCore::Data
{
    bool ready = false;
    float cameraDistance = 1.0f;
    QVector3D oldCameraPosition;
    QVector3D oldFocusedPlanetPosition;

    //Time variables
    int year = SolarValues::year;
    int month = SolarValues::month;
    int day = SolarValues::day;
    int hours = 0;
    int minutes = 0;
    float seconds = 0;

    //main date and time
    QDateTime solarTime = QDateTime(QDate(year, month, day), QTime(hours, minutes));

    //frame dt
    float deltaTime = 0;

    // Time scale formula based on http://www.stjarnhimlen.se/comp/ppcomp.html
    float startD;
    float oldTimeD;
    float currentTimeD;
    float deltaTimeD = 0;
    float daysPerFrame = 0;
    float daysPerFrameScale = 0;
    float planetScale;
    bool focusedScaling = false;
    int focusedMinimumScale = 20;
    float actualScale;
};

SolarSystem::SolarMathCore::SolarMathCore(QObject* parent):
    ISolarMathCore(parent),
    data(new Data())
{
    //calculating start time
    data->startD = 367 * data->year - 7 * (data->year + (data->month + 9) / 12) / 4 + 275 * data->month / 9 + data->day - 730530;
    data->startD += calculateUT(data->hours, data->minutes, data->seconds);
    data->oldTimeD = data->startD;
    data->currentTimeD = data->startD;
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

void SolarSystem::SolarMathCore::solarObjectPosition(SolarSystem::SolarObjects object)
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

    solarObj->setRoll((solarObj->roll() + data->deltaTimeD/ solarObj->period() * 360));

    //tilt calculation
    auto radians = solarObj->tilt() * M_PI/180;

    //recalculation to 3D objects
    Planet* planet = planetContainer[object];
    planet->setX(solarObj->x());
    planet->setY(solarObj->y());
    planet->setZ(solarObj->z());
    planet->setRoll(solarObj->roll());
    planet->setTilt(radians);
}

QVector3D SolarSystem::SolarMathCore::getNewSolarViewPosition(SolarSystem::SolarObjects object, double radius)
{
    QVector3D pos;

    if (object == SolarObjects::SolarSystemView)
    {
        pos = CameraSettings::defaultCameraPosition;
        pos *= data->cameraDistance;
    }
    else if (object == SolarObjects::Sun)
    {
        pos = QVector3D(radius * data->planetScale * 2, radius * data->planetScale * 2, radius * data->planetScale * 2);
        pos *= data->cameraDistance;
    }
    else
    {
        auto solarObj = solarContainer.solarObject(object);
        auto vec1 = QVector3D(solarObj->x(), solarObj->y(), solarObj->z());
        auto vec2 = CameraSettings::defaultUp;

        vec1 = vec1.normalized();
        vec2 = QVector3D::crossProduct(vec1, vec2);
        vec2 *= radius * data->planetScale * data->cameraDistance * 4;
        vec2 += QVector3D(solarObj->x(), solarObj->y(), solarObj->z());

        vec1 = QVector3D(0, radius * data->planetScale, 0);
        vec2 += vec1;
    }

    return pos;
}

void SolarSystem::SolarMathCore::advanceTime(SolarSystem::SolarObjects object)
{
    if (object == SolarObjects::SolarSystemView)
        data->daysPerFrame = data->daysPerFrameScale * 10;
    else
        data->daysPerFrame = data->daysPerFrameScale * solarContainer.solarObject(object)->period()/100.0;

    //add solar time
    data->solarTime = data->solarTime.addMSecs(data->deltaTime * 1000 * data->daysPerFrameScale);

    //save helpers values
    data->hours = data->solarTime.time().hour();
    data->minutes = data->solarTime.time().minute();
    data->seconds = data->solarTime.time().second();
    data->year = data->solarTime.date().year();
    data->month = data->solarTime.date().month();
    data->day = data->solarTime.date().day();

    //Advance the time in days
    data->oldTimeD = data->currentTimeD;

    //update currentTimeD
    data->currentTimeD = calculateTimeScale(data->year, data->month, data->day);
    data->currentTimeD += calculateUT(data->hours, data->minutes, data->seconds);

    //data->currentTimeD = data->currentTimeD + data->daysPerFrame;

    //get deltaD
    data->deltaTimeD = data->currentTimeD - data->oldTimeD;
}

float SolarSystem::SolarMathCore::setSolarObjectScale(float scale, bool focused)
{
    // Save actual scale
    if (!focused)
        data->actualScale = scale;

    // Limit minimum scaling in focus mode to avoid jitter caused by rounding errors
    if (scale <= data->focusedMinimumScale && (data->focusedScaling || focused))
        data->planetScale = data->focusedMinimumScale;
    else
        data->planetScale = data->actualScale;

    return data->planetScale;
}

void SolarSystem::SolarMathCore::checkSolarObjectScaling(SolarSystem::SolarObjects object)
{
    if (object != SolarObjects::SolarSystemView)
    {
        // Limit minimum scaling in focus mode to avoid jitter caused by rounding errors
        if (data->actualScale <= data->focusedMinimumScale)
        {
            data->planetScale = data->focusedMinimumScale;
            changeSolarObjectScale(data->focusedMinimumScale, true);
        }

        data->focusedScaling = true;
    }
    else if (data->focusedScaling == true)
    {
        // Restore normal scaling
        data->focusedScaling = false;
        changeSolarObjectScale(data->actualScale, false);
    }
}

void SolarSystem::SolarMathCore::changeSolarObjectScale(float scale, bool focused)
{
    if (!focused)
        data->actualScale = scale;

    if (scale <= data->focusedMinimumScale && (data->focusedScaling || focused))
        data->planetScale = data->focusedMinimumScale;
    else
        data->planetScale = data->actualScale;
}

void SolarSystem::SolarMathCore::updateSolarView(SolarSystem::SolarObjects object)
{
    Q_UNUSED(object)
}

void SolarSystem::SolarMathCore::changeSolarObjectsSpeed(float speed)
{
    data->daysPerFrameScale = speed;
}

void SolarSystem::SolarMathCore::changeSolarViewDistance(double distance)
{
    Q_UNUSED(distance)
}

void SolarSystem::SolarMathCore::setPlanetsContainer(SolarSystem::PlanetArray array)
{
    planetContainer = array;
}

void SolarSystem::SolarMathCore::changeSolarSystemScale(float scale, bool focused)
{
    changeSolarObjectScale(scale, focused);

    auto scaling = data->planetScale;

    for (auto& planet : planetContainer)
    {
        switch (planet.first)
        {
        case SolarObjects::Sun:
            planet.second->setR(SolarParser::parseSolarObjectRadius(planet.first) * scaling / 99.0f);
            break;

        case SolarObjects::Mercury:
        case SolarObjects::Venus:
        case SolarObjects::Earth:
        case SolarObjects::Mars:
        case SolarObjects::Jupiter:
        case SolarObjects::Saturn:
        case SolarObjects::Uranus:
        case SolarObjects::Neptune:
        case SolarObjects::Moon:
            planet.second->setR(SolarParser::parseSolarObjectRadius(planet.first) * scaling);
            break;
        default:
            break;
        }
    }
}

void SolarSystem::SolarMathCore::setDeltaTime(float dt)
{
    data->deltaTime = dt;
}

QDateTime SolarSystem::SolarMathCore::getTime() const
{
    return data->solarTime;
}

float SolarSystem::SolarMathCore::calculateUT(int h, int m, float s)
{
    return (h + m/60.0f + s/3600.0f)/24.0f;
}

float SolarSystem::SolarMathCore::calculateTimeScale(int year, int month, int day)
{
    return 367 * year - 7 * (year + (month + 9) / 12) / 4 + 275 * month / 9 + day - 730530;
}
