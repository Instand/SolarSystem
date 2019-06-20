#ifndef UTILS_H
#define UTILS_H

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
    };
}

#endif // UTILS_H
