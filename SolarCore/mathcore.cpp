#include "mathcore.h"
#include <QtMath>
#include <QTransform>
#include <Qt3DRender/QCamera>
#include <Parser/solarparser.h>
#include <SolarCore/utils.h>
#include <SolarCore/cameracontroller.h>
#include <SolarCore/object3dcontainer.h>
#include <SolarCore/solarobjectscontainer.h>

// Main Math data
struct SolarSystem::MathCore::Data
{
    bool ready = false;
    float cameraDistance = 1.0f;

    QVector3D oldCameraPosition;
    QVector3D oldFocusedPlanetPosition;
    QVector3D startPos;

    // Time variables
    int year = SolarValues::year;
    int month = SolarValues::month;
    int day = SolarValues::day;
    int hours = 0;
    int minutes = 0;
    float seconds = 0;

    // main date and time
    QDateTime solarTime = QDateTime(QDate(year, month, day), QTime(hours, minutes));

    // frame dt
    float deltaTime = 0;

    // Time scale formula based on http://www.stjarnhimlen.se/comp/ppcomp.html
    double startD;
    double oldTimeD;
    double currentTimeD;
    double deltaTimeD = 0;
    double daysPerFrame = 0;
    double daysPerFrameScale = 0;
    double planetScale;
    bool focusedScaling = false;
    int focusedMinimumScale = 20;
    double actualScale;
    double ultraSpeed = 1.0;
    double ultraSpeedStep = 2.0;
    double ultraSpeedMax = 64.0;

    // inner and outer radius
    double saturnRingInnerRadius = 0;
    double saturnRingOuterRadius = 0;
    double uranusRingInnerRadius = 0;
    double uranusRingOuterRadius = 0;

    // earth cloud
    double earthCloudRModifier = 1.010;     //1.010

    // view
    Qt3DRender::QCamera* camera = nullptr;

    // math solar objects
    SolarSystem::SolarObjectsContainer solarContainer;

    // planet container elements
    SolarSystem::Object3DContainer* container = nullptr;

    // orbit camera controller
    SolarSystem::CameraController* cameraController = nullptr;

    Data();
    ~Data();
};

SolarSystem::MathCore::Data::Data()
{
    using StartDateType = decltype(startD);

    // calculating start time
    startD = static_cast<StartDateType>(Utils::calculateTimeScale(year, month, day));
    startD += static_cast<StartDateType>(Utils::calculateUT(hours, minutes, seconds));
    oldTimeD = startD;
    currentTimeD = startD;

    // calcualting saturn and uranus rings
    auto saturn = solarContainer.solarObject(SolarObjects::Saturn);
    saturnRingOuterRadius = saturn->radius() + static_cast<double>(SolarValues::saturnOuterRadius);
    saturnRingInnerRadius = saturn->radius() + 6.630;

    auto uranus = solarContainer.solarObject(SolarObjects::Uranus);
    uranusRingOuterRadius = uranus->radius() + static_cast<double>(SolarValues::uranusOuterRadius);
    uranusRingInnerRadius = uranus->radius() + 2.0;
}

SolarSystem::MathCore::Data::~Data()
{
    if (camera)
        camera = nullptr;

    if (cameraController)
        cameraController = nullptr;
}

SolarSystem::MathCore::MathCore(QObject* parent):
    QObject(parent),
    m_data(new Data())
{
}

SolarSystem::MathCore::~MathCore()
{
    delete m_data;
}

SolarSystem::MathCore* SolarSystem::MathCore::instance()
{
    static MathCore core;
    return &core;
}

void SolarSystem::MathCore::setSolarView(Qt3DRender::QCamera* camera)
{
    m_data->camera = camera;
}

Qt3DRender::QCamera* SolarSystem::MathCore::solarView() const
{
    return m_data->camera;
}

float SolarSystem::MathCore::getOuterRadius(SolarSystem::SolarObjects object)
{
    double outerRadius = SolarValues::solarDistance;

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
            outerRadius += SolarObjectsValues::Saturn::radius + static_cast<double>(SolarValues::saturnOuterRadius);
            break;

        case SolarObjects::Uranus:
            outerRadius += SolarObjectsValues::Uranus::radius + static_cast<double>(SolarValues::uranusOuterRadius);
            break;

        case SolarObjects::Moon:
            outerRadius += SolarObjectsValues::Moon::radius;
            break;

        case SolarObjects::Pluto:
            outerRadius += SolarObjectsValues::Pluto::radius;
            break;

        case SolarObjects::Sun:
            outerRadius = SolarObjectsValues::Sun::radius / static_cast<double>(SolarValues::sunOuterRadiusDelimiter);
            break;

        default:
            break;

    }

    return static_cast<float>(outerRadius);
}

void SolarSystem::MathCore::solarObjectPosition(SolarSystem::SolarObjects object)
{
    auto solarObj = m_data->solarContainer.solarObject(object);

    if (solarObj)
    {
        // calculation only for solar system planets
        if (object != SolarObjects::Sun)
        {
            // Calculate the planet orbital elements from the current time in days
            auto N = (solarObj->N1() + solarObj->N2() * m_data->currentTimeD) * M_PI/ 180;
            auto iPlanet = (solarObj->i1() + solarObj->i2() * m_data->currentTimeD) * M_PI / 180;
            auto w = (solarObj->w1() + solarObj->w2() * m_data->currentTimeD) * M_PI / 180;
            auto a = solarObj->a1() + solarObj->a2() * m_data->currentTimeD;
            auto e = solarObj->e1() + solarObj->e2() * m_data->currentTimeD;
            auto M = (solarObj->M1() + solarObj->M2() * m_data->currentTimeD) * M_PI / 180;
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
            auto centerObj = m_data->solarContainer.solarObject(centerOfOrbit);

            solarObj->setX(centerObj->x() + xh * static_cast<double>(SolarValues::auScale));
            solarObj->setY(centerObj->y() + yh * static_cast<double>(SolarValues::auScale));
            solarObj->setZ(centerObj->z() + zh * static_cast<double>(SolarValues::auScale));
        }

        solarObj->setRoll((solarObj->roll() + m_data->deltaTimeD/ solarObj->period() * 360.0));

        // recalculation to 3D objects
        Object3D* visualSolarObject = m_data->container->objects()[object];

        if (visualSolarObject != nullptr)
        {
            visualSolarObject->setX(solarObj->x());
            visualSolarObject->setY(solarObj->y());
            visualSolarObject->setZ(solarObj->z());
            visualSolarObject->setRoll(solarObj->roll());
        }
    }
}

void SolarSystem::MathCore::advanceTime(SolarSystem::SolarObjects object)
{
    using CurrentDateType = decltype(m_data->currentTimeD);

    if (object == SolarObjects::SolarSystemView)
        m_data->daysPerFrame = m_data->daysPerFrameScale; //*10
    else if (object == SolarObjects::Mercury || object == SolarObjects::Venus)
        m_data->daysPerFrame = m_data->daysPerFrameScale * m_data->solarContainer.solarObject(object)->period()/15000.0;
    else
        m_data->daysPerFrame = m_data->daysPerFrameScale * m_data->solarContainer.solarObject(object)->period()/100.0;

    auto msec = static_cast<double>(m_data->deltaTime) * 1000.0 * m_data->daysPerFrame * m_data->ultraSpeed;

    // add solar time
    m_data->solarTime = m_data->solarTime.addMSecs(static_cast<qint64>(msec));

    // save helpers values
    m_data->hours = m_data->solarTime.time().hour();
    m_data->minutes = m_data->solarTime.time().minute();
    m_data->seconds = m_data->solarTime.time().second();
    m_data->year = m_data->solarTime.date().year();
    m_data->month = m_data->solarTime.date().month();
    m_data->day = m_data->solarTime.date().day();

    // Advance the time in days
    m_data->oldTimeD = m_data->currentTimeD;

    // update currentTimeD
    m_data->currentTimeD = static_cast<CurrentDateType>(Utils::calculateTimeScale(m_data->year, m_data->month, m_data->day));
    m_data->currentTimeD += static_cast<CurrentDateType>(Utils::calculateUT(m_data->hours, m_data->minutes, m_data->seconds));

    // get deltaD
    m_data->deltaTimeD = m_data->currentTimeD - m_data->oldTimeD;
}

void SolarSystem::MathCore::setSolarObjectsScale(float scale, bool focused)
{
    if (!focused)
        m_data->actualScale = static_cast<double>(scale);

    if (scale <= m_data->focusedMinimumScale && (m_data->focusedScaling || focused))
        m_data->planetScale = m_data->focusedMinimumScale;
    else
        m_data->planetScale = m_data->actualScale;
}

void SolarSystem::MathCore::updateSolarView(SolarSystem::SolarObjects object)
{
    Object3D* solarObj = nullptr;
    Object3DMap& planets = m_data->container->objects();

    if (object != SolarObjects::SolarSystemView)
        solarObj = planets[object];
    else
        solarObj = planets[SolarObjects::Sun];

    if (solarObj != nullptr)
        m_data->camera->setViewCenter(solarObj->position());
}

void SolarSystem::MathCore::setSolarSystemSpeed(float speed)
{
    m_data->daysPerFrameScale = static_cast<decltype(m_data->daysPerFrameScale)>(speed);
}

void SolarSystem::MathCore::setObject3DContainer(Object3DContainer* planetsContainer)
{
    m_data->container = planetsContainer;
}

void SolarSystem::MathCore::changeSolarSystemScale(float scale, bool focused)
{
    setSolarObjectsScale(scale, focused);

    auto scaling = m_data->planetScale;

    for (auto& planet : m_data->container->objects())
    {
        switch (planet.first)
        {
        case SolarObjects::Sun:
            planet.second->setR(SolarParser::parseSolarObjectRadius(planet.first) * scaling/SolarValues::sunRadiusDelimeter);
            break;

        case SolarObjects::Mercury:
        case SolarObjects::Venus:
        case SolarObjects::Earth:
        case SolarObjects::Mars:
        case SolarObjects::Jupiter:
        case SolarObjects::Saturn:
        case SolarObjects::Uranus:
        case SolarObjects::Neptune:
        case SolarObjects::Pluto:
        case SolarObjects::Moon:
            planet.second->setR(SolarParser::parseSolarObjectRadius(planet.first) * scaling);
            break;

        case SolarObjects::SaturnRing:
            m_data->saturnRingOuterRadius = m_data->saturnRingOuterRadius * scaling;
            m_data->saturnRingInnerRadius = m_data->saturnRingInnerRadius * scaling;
            break;

        case SolarObjects::UranusRing:
            m_data->uranusRingInnerRadius = m_data->uranusRingInnerRadius * scaling;
            m_data->uranusRingOuterRadius = m_data->uranusRingOuterRadius * scaling;
            break;
        default:
            break;
        }
    }
}

void SolarSystem::MathCore::setDeltaTime(float dt)
{
    m_data->deltaTime = dt;
}

QDateTime SolarSystem::MathCore::getTime() const
{
    return m_data->solarTime;
}

void SolarSystem::MathCore::additionalCalculation()
{
    setupPlanetRings();
    atmosphereCalculations();
}

void SolarSystem::MathCore::setCameraController(SolarSystem::CameraController *controller)
{
    m_data->cameraController = controller;
}

SolarSystem::CameraController* SolarSystem::MathCore::viewController() const
{
    return m_data->cameraController;
}

void SolarSystem::MathCore::updateSolarViewZoomLimit(SolarSystem::SolarObjects object)
{
    if (object == SolarObjects::SolarSystemView)
    {
        if (m_data->cameraController)
        {
            m_data->cameraController->setDefaultZoomLimit();
            m_data->cameraController->setDefaultZoomSpeed();
        }
    }
    else
    {
        auto solarObjRadius = SolarParser::parseSolarObjectRadius(object);
        auto zoomLimit = static_cast<float>(m_data->planetScale * solarObjRadius * 4.0);

        // empiricic calculations
        zoomLimit = calculateZoomLimit(object, zoomLimit);

        if (m_data->cameraController)
        {
            m_data->cameraController->setZoomLimit(zoomLimit);
            m_data->cameraController->setZoomSpeed(m_data->cameraController->defaultZoomSpeed()/3.0f);
        }
    }
}

QVector3D SolarSystem::MathCore::objectPosition(SolarSystem::SolarObjects object)
{
    QVector3D pos {0, 0, 0};

    if (object != SolarObjects::SolarSystemView)
    {
        auto obj = m_data->container->objects()[object];
        pos = QVector3D(obj->transform()->translation());
    }

    return pos;
}

QVector3D SolarSystem::MathCore::viewPositionOfObject(SolarSystem::SolarObjects object)
{
    auto solarObj = m_data->container->objects()[object];
    auto pos = QVector3D {0, 0, 0};

    if (solarObj != nullptr)
    {
        // vector on object
        auto onTarget = solarObj->position() - m_data->camera->position();

        // get dist
        auto dist = onTarget.length();

        // calculate need dist to camera
        auto limit = calculateZoomLimit(object);
        auto needDist = dist - limit;

        if (needDist <= 0)
            needDist = limit - dist;

        // get position
        auto onTargetLimit = onTarget.normalized() * needDist;

        // get need cam pos
        pos = onTargetLimit + m_data->camera->position();
    }

    return pos;
}

float SolarSystem::MathCore::solarSystemSpeed() const
{
    return static_cast<float>(m_data->daysPerFrameScale);
}

void SolarSystem::MathCore::changeExtraSpeed() const
{
    if (m_data->ultraSpeed * m_data->ultraSpeedStep <= m_data->ultraSpeedMax)
        m_data->ultraSpeed *= m_data->ultraSpeedStep;
    else
        m_data->ultraSpeed = 1.0;
}

double SolarSystem::MathCore::extraSpeed() const
{
    return m_data->ultraSpeed;
}

void SolarSystem::MathCore::resetExtraSpeed() const
{
    m_data->ultraSpeed = 1.0;
}

void SolarSystem::MathCore::calculateAllSolarObjectsPosiitons()
{
    auto updateCount = m_data->container->planetsNumber();

    for (int i = 0; i < updateCount; ++i)
        solarObjectPosition(SolarObjects(i));
}

void SolarSystem::MathCore::setupPlanetRings()
{
    Object3DMap& planets = m_data->container->objects();

    if (planets.count(SolarObjects::SaturnRing) && planets.count(SolarObjects::Saturn))
    {
        Object3D* saturn = planets[SolarObjects::Saturn];
        Object3D* saturnRing = planets[SolarObjects::SaturnRing];

        saturnRing->setX(saturn->x());
        saturnRing->setY(saturn->y());
        saturnRing->setZ(saturn->z());
        saturnRing->setTilt(saturn->tilt());
        saturnRing->setRoll(saturn->roll()/10.0);
        saturnRing->setR((m_data->saturnRingInnerRadius + m_data->saturnRingOuterRadius)/1.75);
    }

    if (planets.count(SolarObjects::UranusRing) && planets.count(SolarObjects::Uranus))
    {
        Object3D* uranus = planets[SolarObjects::Uranus];
        Object3D* uranusRings = planets[SolarObjects::UranusRing];

        uranusRings->setX(uranus->x());
        uranusRings->setY(uranus->y());
        uranusRings->setZ(uranus->z());
        uranusRings->setTilt(uranus->tilt());
        uranusRings->setRoll(uranus->roll()/10.0);
        uranusRings->setR((m_data->uranusRingInnerRadius + m_data->uranusRingOuterRadius)/1.75);
    }
}

void SolarSystem::MathCore::atmosphereCalculations()
{
    Object3DMap& planets = m_data->container->objects();

    if (planets.count(SolarObjects::EarthCloud) && planets.count(SolarObjects::Earth))
    {
        Object3D* earth = planets[SolarObjects::Earth];
        Object3D* earthCloud = planets[SolarObjects::EarthCloud];

        earthCloud->setX(earth->x());
        earthCloud->setY(earth->y());
        earthCloud->setZ(earth->z());
        earthCloud->setTilt(earth->tilt());
        earthCloud->setRoll(earth->roll()/1.2);
        earthCloud->setR(earth->r() * m_data->earthCloudRModifier);
    }
}

float SolarSystem::MathCore::calculateZoomLimit(SolarSystem::SolarObjects object, float limit)
{
    static constexpr float mercuryLimitModifier = 2.0f;
    static constexpr float jupiterLimitModifier = 1.6f;
    static constexpr float plutoLimitModifier = 1.8f;

    float finalLimit = limit;

    switch (object) {
    case SolarObjects::Sun:
        finalLimit = m_data->cameraController->defaultZoomLimit();
        break;

    case SolarObjects::Mercury:
        finalLimit *= mercuryLimitModifier;
        break;

    case SolarObjects::Jupiter:
        finalLimit /= jupiterLimitModifier;
        break;

    case SolarObjects::Pluto:
        finalLimit *= plutoLimitModifier;
        break;

    default:
        break;
    }

    return finalLimit;
}

float SolarSystem::MathCore::calculateZoomLimit(SolarSystem::SolarObjects object)
{
    auto solarObjRadius = SolarParser::parseSolarObjectRadius(object);
    auto zoomLimit = static_cast<float>(m_data->planetScale * solarObjRadius * 4.0);

    // empiricic calculations
    zoomLimit = calculateZoomLimit(object, zoomLimit);

    return zoomLimit;
}
