#ifndef SOLARSYSTEMCORE_H
#define SOLARSYSTEMCORE_H

//only Qt3D materials in use
#include <QString>
#include <QStringList>
#include <QVector3D>
#include <vector>

namespace SolarSystem
{
    //store all query strings for db
    struct SolarStrings
    {
        //db type
        static const QString qSqlLite;

        //help
        static const QString dbName;
        static const QString dbFileName;
        static const QString dbFolder;

        //db fields
        static const QString nameField;
        static const QString type;
        static const QString orbitalSpeed;
        static const QString mass;
        static const QString meanRadius;
        static const QString surfaceTemp;
        static const QString surfaceGravity;
        static const QString volume;
        static const QString siderealPeriod;
        static const QString orbitalPeriod;
        static const QString description;

        //SQL commands
        static const QString select;
        static const QString from;
        static const QString where;
        static const QString like;
        static const QString all;
        static QString likeObject(const QString& object);

        //string representation of object type
        static const QString planet;
        static const QString dwarfPlanet;
        static const QString star;
        static const QString moon;
        static const QString ring;
        static const QString solarSystemBody;
        static const QString galaxy;
        static const QString asteroid;

        //add object types
    };

    //store different values for code help
    struct SolarValues
    {
        static const float solarSystemModifier;
        static const int zero;
        static const int solarDistance;
        static const float auScale;
        static const float saturnOuterRadius;
        static const float uranusOuterRadius;
        static const float sunOuterRadiusDelimiter;
        static const double sunRadiusDelimeter;
        static const float startSize;
        static const float startSpeed;

        //time scale values
        static const int year;
        static const int month;
        static const int day;

        //vector values
        static const QVector3D rollAxis;
        static const QVector3D tiltAxis;
    };

    template<typename Result, typename T>
    constexpr Result modified(const T& value)
    {
        using ModifierType = decltype(SolarValues::solarSystemModifier);
        return static_cast<Result>(static_cast<ModifierType>(value)/SolarValues::solarSystemModifier);
    }

    enum SolarFields
    {
        SolarType,
        Name,
        OrbitalSpeed,
        Mass,
        MeanRadius,
        Temperature,
        Gravity,
        Volume,
        SiderealPeriod,
        OrbitalPeriod,
        Description
    };

    //solar system object type
    enum class SolarSystemObjectType
    {
        SolarSystemBody,
        Planet,
        DwarfPlanet,
        Moon,
        Ring,
        Star,
        Asteroid,
        Galaxy
    };

    //enum of all solar objects
    //add new if you need
    enum class SolarObjects
    {
        Sun,
        Mercury,
        Venus,
        Earth,
        Mars,
        Jupiter,
        Saturn,
        Uranus,
        Neptune,
        Moon,
        Pluto,

        //add here
        SaturnRing,
        UranusRing,
        EarthCloud,

        //calculate number
        SolarSystemView
    };

    //all material types used in solar system project
    enum class SolarMaterials
    {
        None,
        Diffuse,
        DiffuseSpecular,
        NormalDiffuse,
        NormalDiffiseSpecular,
        NormalDiffuseAplha,
        Phong,
        PhongAlpha,
        Unlit
    };

    //store default camera settings
    namespace CameraSettings
    {
        //camera up vector
        const QVector3D defaultUp(0, 1, 0);

        //default position
        const QVector3D defaultCameraPosition(SolarValues::solarDistance, SolarValues::solarDistance, SolarValues::solarDistance);

        //near plane/far plane settings
        const float nearPlane = modified<float>(2500000.0f);
        const float farPlane = modified<float>(20000000.0f);

        //fov
        const int fieldOfView = 60;
    }

    //for planet class
    namespace PlanetSettings
    {
        const float radius = 1.0f;
        const bool generateTangents = true;
        const int rings = 64;
        const int slices = 64;
    }

    //params for DB fields
    namespace DbParams
    {
        const QStringList paramList = {"", "", "km/s", "kg", "km", "K", "m/s2", "km3", "d", "d", ""};
    }

    //planets math values
    namespace SolarObjectsValues
    {
        // Planet Data
        // radius - planet radius
        // tilt - planet axis angle
        // N1/2 - longitude of the ascending node
        // i1/2 - inclination to the ecliptic (plane of the Earth's orbit)
        // w1/2 - argument of perihelion
        // a1/2 - semi-major axis, or mean distance from Sun
        // e1/2 - eccentricity (0=circle, 0-1=ellipse, 1=parabola)
        // M1/2 - mean anomaly (0 at perihelion; increases uniformly with time)
        // period - sidereal rotation period
        // centerOfOrbit - the planet in the center of the orbit
        // (orbital elements based on http://www.stjarnhimlen.se/comp/ppcomp.html)

        //solar system values
        namespace SolarSystem
        {
            const QString toString = "Solar System";
        }

        //sun values
        namespace Sun
        {
            const double radius = 694.439;
            const double tilt = 63.87;
            const double period = 25.05;
            const QString toString = "Sun";
        }

        //mercury values
        namespace Mercury
        {
            const double radius = 2.433722;
            const double tilt = 0.04;
            const double N1 = 48.3313;
            const double N2 = 0.0000324587;
            const double i1 = 7.0047;
            const double i2 = 0.0000000500;
            const double w1 = 29.1241;
            const double w2 = 0.0000101444;
            const double a1 = 0.387098;
            const double a2 = 0;
            const double e1 = 0.205635;
            const double e2 = 0.000000000559;
            const double M1 = 168.6562;
            const double M2 = 4.0923344368;
            const double period = 58.646;
            const SolarObjects centerOfOrbit = SolarObjects::Sun;
            const QString toString = "Mercury";
        }

        //venus values
        namespace Venus
        {
            const double radius = 6.046079;
            const double tilt = 177.36;
            const double N1 = 76.6799;
            const double N2 = 0.0000246590;
            const double i1 = 3.3946;
            const double i2 = 0.0000000275;
            const double w1 = 54.8910;
            const double w2 = 0.0000138374;
            const double a1 = 0.723330;
            const double a2 = 0;
            const double e1 = 0.006773;
            const double e2 = -0.000000001302;
            const double M1 = 48.0052;
            const double M2 = 1.6021302244;
            const double period = 243.0185;
            const SolarObjects centerOfOrbit = SolarObjects::Sun;
            const QString toString = "Venus";
        }

        //earth values
        namespace Earth
        {
            const double radius = 6.371;
            const double tilt = 25.44;
            const double N1 = 174.873;
            const double N2 = 0;
            const double i1 = 0.00005;
            const double i2 = 0;
            const double w1 = 102.94719;
            const double w2 = 0;
            const double a1 = 1;
            const double a2 = 0;
            const double e1 = 0.01671022;
            const double e2 = 0;
            const double M1 = 357.529;
            const double M2 = 0.985608;
            const double period = 0.997;
            const SolarObjects centerOfOrbit = SolarObjects::Sun;
            const QString toString = "Earth";
        }

        //mars values
        namespace Mars
        {
            const double radius = 3.389372;
            const double tilt = 25.19;
            const double N1 = 49.5574;
            const double N2 = 0.0000211081;
            const double i1 = 1.8497;
            const double i2 = -0.0000000178;
            const double w1 = 286.5016;
            const double w2 = 0.0000292961;
            const double a1 = 1.523688;
            const double a2 = 0;
            const double e1 = 0.093405;
            const double e2 = 0.000000002516;
            const double M1 = 18.6021;
            const double M2 = 0.5240207766;
            const double period = 1.025957;
            const SolarObjects centerOfOrbit = SolarObjects::Sun;
            const QString toString = "Mars";
        }

        //jupiter values
        namespace Jupier
        {
            const double radius = 71.41254;
            const double tilt = 3.13;
            const double N1 = 100.4542;
            const double N2 = 0.0000276854;
            const double i1 = 1.3030;
            const double i2 = -0.0000001557;
            const double w1 = 273.8777;
            const double w2 = 0.0000164505;
            const double a1 = 5.20256;
            const double a2 = 0;
            const double e1 = 0.048498;
            const double e2 = 0.000000004469;
            const double M1 = 19.8950;
            const double M2 = 0.0830853001;
            const double period = 0.4135;
            const SolarObjects centerOfOrbit = SolarObjects::Sun;
            const QString toString = "Jupiter";
        }

        //saturn values
        namespace Saturn
        {
            const double radius = 60.19958;
            const double tilt = 26.73;
            const double N1 = 113.6634;
            const double N2 = 0.0000238980;
            const double i1 = 2.4886;
            const double i2 = -0.0000001081;
            const double w1 = 339.3939;
            const double w2 = 0.0000297661;
            const double a1 = 9.55475;
            const double a2 = 0;
            const double e1 = 0.055546;
            const double e2 = -0.000000009499;
            const double M1 = 316.9670;
            const double M2 = 0.0334442282;
            const double period = 0.4395;
            const SolarObjects centerOfOrbit = SolarObjects::Sun;
            const QString toString = "Saturn";
        }

        //uranus values
        namespace Uranus
        {
            const double radius = 25.5286;
            const double tilt = 97.77;
            const double N1 = 74.0005;
            const double N2 = 0.000013978;
            const double i1 = 0.7733;
            const double i2 = 0.000000019;
            const double w1 = 96.6612;
            const double w2 = 0.000030565;
            const double a1 = 19.18171;
            const double a2 = -0.0000000155;
            const double e1 = 0.047318;
            const double e2 = 0.00000000745;
            const double M1 = 142.5905;
            const double M2 = 0.011725806;
            const double period = 0.71833;
            const SolarObjects centerOfOrbit = SolarObjects::Sun;
            const QString toString = "Uranus";
        }

        //neptune values
        namespace Neptune
        {
            const double radius = 24.73859;
            const double tilt = 28.32;
            const double N1 = 131.7806;
            const double N2 = 0.000030173;
            const double i1 = 1.7700;
            const double i2 = -0.000000255;
            const double w1 = 272.8461;
            const double w2 = 0.000006027;
            const double a1 = 30.05826;
            const double a2 = 0.00000003313;
            const double e1 = 0.008606;
            const double e2 = 0.00000000215;
            const double M1 = 260.2471;
            const double M2 = 0.005995147;
            const double period = 0.6713;
            const SolarObjects centerOfOrbit = SolarObjects::Sun;
            const QString toString = "Neptune";
        }

        //pluto values
        namespace Pluto
        {
            const double radius = 1.187;            //radius
            const double tilt = 120.00;
            const double N1 = 110.30347;            //longitude
            const double N2 = 0;
            const double i1 = 17.14175;             //inclination
            const double i2 = 0;
            const double w1 = 113.834;              //perihelion
            const double w2 = 0;
            const double a1 = 39.48168677;          //semi-major axis
            const double a2 = 0;
            const double e1 = 0.24880766;           //eccentricity
            const double e2 = 0;
            const double M1 = 14.53;                //mean anomaly
            const double M2 = 0;
            const double period = 6.387230;         //siderial rotation period
            const SolarObjects centerOfOrbit = SolarObjects::Sun;
            const QString toString = "Pluto";
        }

        //moon values
        namespace Moon
        {
            const double radius = 1.5424;
            const double tilt = 28.32;
            const double N1 = 125.1228;
            const double N2 = -0.0529538083;
            const double i1 = 5.1454;
            const double i2 = 0;
            const double w1 = 318.0634;
            const double w2 = 0.1643573223;
            const double a1 = 0.273;
            const double a2 = 0;
            const double e1 = 0.054900;
            const double e2 = 0;
            const double M1 = 115.3654;
            const double M2 = 13.0649929509;
            const double period = 27.321582;
            const SolarObjects centerOfOrbit = SolarObjects::Earth;
            const QString toString = "Moon";
        }

        namespace SaturnRing = Saturn;
        namespace UranusRing = Uranus;
    }
}


#endif // SOLARSYSTEMCORE_H
