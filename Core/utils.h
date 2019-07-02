#ifndef UTILS_H
#define UTILS_H

#include <algorithm>
#include <QVector3D>

namespace SolarSystem
{
    // Additional class with solar system common helper methods
    class Utils
    {
        Utils() = delete;
        Utils(const Utils&) = delete;

    public:

        // days time scale calculation
        static float calculateUT(int h, int m = 0, float s = 0)
        {
            return (h + m/60.0f + s/3600.0f)/24.0f;
        }

        // time scale calculation
        static float calculateTimeScale(int year, int month, int day)
        {
            return 367 * year - 7 * (year + (month + 9) / 12) / 4 + 275 * month / 9 + day - 730530;
        }

        // linear interpolation, time range [0, 1]
        static QVector3D lerp(const QVector3D& start, const QVector3D& end, float time)
        {
            return (start + (end - start) * time);
        }

        // spherical linear interpolation from https://en.wikipedia.org/wiki/Slerp
        static QVector3D slerp(const QVector3D& start, const QVector3D& end, float time)
        {
            auto dot = QVector3D::dotProduct(start, end);
            auto dotValue = std::clamp(dot, -1.0f, 1.0f);

            auto theta = std::acos(dotValue) * time;
            auto relativeVector = (end - start * dotValue).normalized();

            return (start * std::cos(theta)) + (relativeVector * std::sin(theta));
        }
    };
}

#endif // UTILS_H
