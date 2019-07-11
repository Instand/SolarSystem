#ifndef UTILS_H
#define UTILS_H

#include <algorithm>

#include <qmath.h>

#include <QObject>
#include <QVector2D>
#include <QVector3D>

class QQmlEngine;
class QJSEngine;

namespace SolarSystem
{
    // Additional class with solar system common helper methods
    class Utils final : public QObject
    {
        Q_OBJECT

        explicit Utils(QObject* parent = nullptr);

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

        // linear interpolation for primitive types, time range [0, 1]
        template<typename T, typename = std::enable_if_t<std::is_trivial_v<T>>>
        static T lerp(T start, T end, float time)
        {
            return (1.0f - time) * start + time * end;
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

        // calculates angle between two vectors 3d
        Q_INVOKABLE static float angle(const QVector3D& lhs, const QVector3D& rhs)
        {
            auto dot = QVector3D::dotProduct(lhs, rhs);
            auto dotValue = std::clamp(dot, -1.0f, 1.0f);
            auto cos = dotValue/(lhs.length() * rhs.length());

            // radians to degree
            return std::acos(cos) * 180.0f/static_cast<float>(M_PI);
        }

        // calculates angle between two vectors 2d
        Q_INVOKABLE static float angle(const QVector2D& lhs, const QVector2D& rhs)
        {
            return Utils::angle(lhs.toVector3D(), rhs.toVector3D());
        }

        // helper to QML, calculates distance between two vectors 3d
        Q_INVOKABLE static float distance(const QVector3D& lhs, const QVector3D& rhs)
        {
            return (lhs - rhs).length();
        }

        // helper to QML, calculates distance between two vectors 2d
        Q_INVOKABLE static float distance(const QVector2D& lhs, const QVector2D& rhs)
        {
            return distance(lhs.toVector3D(), rhs.toVector3D());
        }

        // calculates the shortest difference between two given angles given in degrees,
        // https://stackoverflow.com/questions/1878907/the-smallest-difference-between-2-angles
        Q_INVOKABLE static float deltaAngle(float current, float target)
        {
            float result = current - target;
            return -(static_cast<int>(result + 180) % 360 - 180);
        }

        Q_INVOKABLE static float specialAngle(const QVector2D& lhs, const QVector2D& rhs)
        {
            auto from = rhs - lhs;
            auto to = QVector2D(1, 0);

            auto result = Utils::angle(from, to);
            auto cross = QVector3D::crossProduct(from.toVector3D(), to.toVector3D());

            if (cross.z() > 0)
            {
                result = 360.0f - result;
            }

            return result;
        }

        friend QObject* utilsProvider(QQmlEngine*, QJSEngine*);
    };

    QObject* utilsProvider(QQmlEngine*, QJSEngine*);
}

#endif // UTILS_H
