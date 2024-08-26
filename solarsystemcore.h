#ifndef SOLARSYSTEMCORE_H
#define SOLARSYSTEMCORE_H

#include <QString>
#include <QStringList>
#include <QVector3D>

namespace SolarSystem
{
    // stores all query strings for db
    struct SolarStrings
    {
        // db type
        static const QString qSqlLite;

        // help
        static const QString dbName;
        static const QString dbFileName;
        static const QString dbFolder;

        // db fields
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

        // SQL commands
        static const QString select;
        static const QString from;
        static const QString where;
        static const QString like;
        static const QString all;
        static QString likeObject(const QString& object);

        // string representation of object type
        static const QString planet;
        static const QString dwarfPlanet;
        static const QString star;
        static const QString moon;
        static const QString ring;
        static const QString solarSystemBody;
        static const QString galaxy;
        static const QString asteroid;

        // add object types
    };

    // stores different values for code help
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

        // time scale values
        static const int year;
        static const int month;
        static const int day;

        // vector values
        static const QVector3D rollAxis;
        static const QVector3D tiltAxis;
    };

    // calculates value by solar system modifier
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

    // solar system object type
    enum class ObjectType
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

    // all solar objects
    // add new if you need
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

        // add here
        SaturnRing,
        UranusRing,
        EarthCloud,

        // number
        SolarSystemView
    };

    // all material types used in solar system project
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

    // stores default camera settings
    namespace CameraSettings
    {
        // camera up vector
        inline const QVector3D defaultUp(0, 1, 0);

        // default position
        inline const QVector3D defaultCameraPosition(SolarValues::solarDistance, SolarValues::solarDistance, SolarValues::solarDistance);

        // near plane/far plane settings
        inline const float nearPlane = modified<float>(2500000.0f);
        inline const float farPlane = modified<float>(20000000.0f);

        // fov
        inline const int fieldOfView = 60;
    }

    namespace PlanetSettings
    {
        inline const float radius = 1.0f;
        inline const bool generateTangents = true;
        inline const int rings = 64;
        inline const int slices = 64;
    }

    // params for DB fields
    namespace DbParams
    {
        inline const QStringList paramList = {"", "", "km/s", "kg", "km", "K", "m/s2", "km3", "d", "d", ""};
    }

    // planets math values
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

        namespace SolarSystem
        {
            inline constexpr auto toString = "Solar System";
        }

        namespace Sun
        {
            inline const double radius = 694.439;
            inline const double tilt = 63.87;
            inline const double period = 25.05;
            inline constexpr auto toString = "Sun";
        }

        namespace Mercury
        {
            inline const double radius = 2.433722;
            inline const double tilt = 0.04;
            inline const double N1 = 48.3313;
            inline const double N2 = 0.0000324587;
            inline const double i1 = 7.0047;
            inline const double i2 = 0.0000000500;
            inline const double w1 = 29.1241;
            inline const double w2 = 0.0000101444;
            inline const double a1 = 0.387098;
            inline const double a2 = 0;
            inline const double e1 = 0.205635;
            inline const double e2 = 0.000000000559;
            inline const double M1 = 168.6562;
            inline const double M2 = 4.0923344368;
            inline const double period = 58.646;
            inline const SolarObjects centerOfOrbit = SolarObjects::Sun;
            inline constexpr auto toString = "Mercury";
        }

        namespace Venus
        {
            inline const double radius = 6.046079;
            inline const double tilt = 177.36;
            inline const double N1 = 76.6799;
            inline const double N2 = 0.0000246590;
            inline const double i1 = 3.3946;
            inline const double i2 = 0.0000000275;
            inline const double w1 = 54.8910;
            inline const double w2 = 0.0000138374;
            inline const double a1 = 0.723330;
            inline const double a2 = 0;
            inline const double e1 = 0.006773;
            inline const double e2 = -0.000000001302;
            inline const double M1 = 48.0052;
            inline const double M2 = 1.6021302244;
            inline const double period = 243.0185;
            inline const SolarObjects centerOfOrbit = SolarObjects::Sun;
            inline constexpr auto toString = "Venus";
        }

        namespace Earth
        {
            inline const double radius = 6.371;
            inline const double tilt = 25.44;
            inline const double N1 = 174.873;
            inline const double N2 = 0;
            inline const double i1 = 0.00005;
            inline const double i2 = 0;
            inline const double w1 = 102.94719;
            inline const double w2 = 0;
            inline const double a1 = 1;
            inline const double a2 = 0;
            inline const double e1 = 0.01671022;
            inline const double e2 = 0;
            inline const double M1 = 357.529;
            inline const double M2 = 0.985608;
            inline const double period = 0.997;
            inline const SolarObjects centerOfOrbit = SolarObjects::Sun;
            inline constexpr auto toString = "Earth";
        }

        namespace Mars
        {
            inline const double radius = 3.389372;
            inline const double tilt = 25.19;
            inline const double N1 = 49.5574;
            inline const double N2 = 0.0000211081;
            inline const double i1 = 1.8497;
            inline const double i2 = -0.0000000178;
            inline const double w1 = 286.5016;
            inline const double w2 = 0.0000292961;
            inline const double a1 = 1.523688;
            inline const double a2 = 0;
            inline const double e1 = 0.093405;
            inline const double e2 = 0.000000002516;
            inline const double M1 = 18.6021;
            inline const double M2 = 0.5240207766;
            inline const double period = 1.025957;
            inline const SolarObjects centerOfOrbit = SolarObjects::Sun;
            inline constexpr auto toString = "Mars";
        }

        namespace Jupier
        {
            inline const double radius = 71.41254;
            inline const double tilt = 3.13;
            inline const double N1 = 100.4542;
            inline const double N2 = 0.0000276854;
            inline const double i1 = 1.3030;
            inline const double i2 = -0.0000001557;
            inline const double w1 = 273.8777;
            inline const double w2 = 0.0000164505;
            inline const double a1 = 5.20256;
            inline const double a2 = 0;
            inline const double e1 = 0.048498;
            inline const double e2 = 0.000000004469;
            inline const double M1 = 19.8950;
            inline const double M2 = 0.0830853001;
            inline const double period = 0.4135;
            inline const SolarObjects centerOfOrbit = SolarObjects::Sun;
            inline constexpr auto toString = "Jupiter";
        }

        namespace Saturn
        {
            inline const double radius = 60.19958;
            inline const double tilt = 26.73;
            inline const double N1 = 113.6634;
            inline const double N2 = 0.0000238980;
            inline const double i1 = 2.4886;
            inline const double i2 = -0.0000001081;
            inline const double w1 = 339.3939;
            inline const double w2 = 0.0000297661;
            inline const double a1 = 9.55475;
            inline const double a2 = 0;
            inline const double e1 = 0.055546;
            inline const double e2 = -0.000000009499;
            inline const double M1 = 316.9670;
            inline const double M2 = 0.0334442282;
            inline const double period = 0.4395;
            inline const SolarObjects centerOfOrbit = SolarObjects::Sun;
            inline constexpr auto toString = "Saturn";
        }

        namespace Uranus
        {
            inline const double radius = 25.5286;
            inline const double tilt = 97.77;
            inline const double N1 = 74.0005;
            inline const double N2 = 0.000013978;
            inline const double i1 = 0.7733;
            inline const double i2 = 0.000000019;
            inline const double w1 = 96.6612;
            inline const double w2 = 0.000030565;
            inline const double a1 = 19.18171;
            inline const double a2 = -0.0000000155;
            inline const double e1 = 0.047318;
            inline const double e2 = 0.00000000745;
            inline const double M1 = 142.5905;
            inline const double M2 = 0.011725806;
            inline const double period = 0.71833;
            inline const SolarObjects centerOfOrbit = SolarObjects::Sun;
            inline constexpr auto toString = "Uranus";
        }

        namespace Neptune
        {
            inline const double radius = 24.73859;
            inline const double tilt = 28.32;
            inline const double N1 = 131.7806;
            inline const double N2 = 0.000030173;
            inline const double i1 = 1.7700;
            inline const double i2 = -0.000000255;
            inline const double w1 = 272.8461;
            inline const double w2 = 0.000006027;
            inline const double a1 = 30.05826;
            inline const double a2 = 0.00000003313;
            inline const double e1 = 0.008606;
            inline const double e2 = 0.00000000215;
            inline const double M1 = 260.2471;
            inline const double M2 = 0.005995147;
            inline const double period = 0.6713;
            inline const SolarObjects centerOfOrbit = SolarObjects::Sun;
            inline constexpr auto toString = "Neptune";
        }

        namespace Pluto
        {
            inline const double radius = 1.187;            //radius
            inline const double tilt = 120.00;
            inline const double N1 = 110.30347;            //longitude
            inline const double N2 = 0;
            inline const double i1 = 17.14175;             //inclination
            inline const double i2 = 0;
            inline const double w1 = 113.834;              //perihelion
            inline const double w2 = 0;
            inline const double a1 = 39.48168677;          //semi-major axis
            inline const double a2 = 0;
            inline const double e1 = 0.24880766;           //eccentricity
            inline const double e2 = 0;
            inline const double M1 = 14.53;                //mean anomaly
            inline const double M2 = 0;
            inline const double period = 6.387230;         //siderial rotation period
            inline const SolarObjects centerOfOrbit = SolarObjects::Sun;
            inline constexpr auto toString = "Pluto";
        }

        namespace Moon
        {
            inline const double radius = 1.5424;
            inline const double tilt = 28.32;
            inline const double N1 = 125.1228;
            inline const double N2 = -0.0529538083;
            inline const double i1 = 5.1454;
            inline const double i2 = 0;
            inline const double w1 = 318.0634;
            inline const double w2 = 0.1643573223;
            inline const double a1 = 0.273;
            inline const double a2 = 0;
            inline const double e1 = 0.054900;
            inline const double e2 = 0;
            inline const double M1 = 115.3654;
            inline const double M2 = 13.0649929509;
            inline const double period = 27.321582;
            inline const SolarObjects centerOfOrbit = SolarObjects::Earth;
            inline constexpr auto toString = "Moon";
        }

        namespace SaturnRing = Saturn;
        namespace UranusRing = Uranus;
    }
}


#endif // SOLARSYSTEMCORE_H
