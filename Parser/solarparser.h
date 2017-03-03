#ifndef SOLARPARSER_H
#define SOLARPARSER_H

#include <solarsystemcore.h>
#include <SolarCore/SolarObjects/abstractsolarobject.h>

namespace SolarSystem {

    //static realization of string solar object parser
    class SolarParser {
    public:

        //parse string to get solar object type
        static SolarSystemObjectType parseString(const QString& str);

        //get string from SolarObejcts type
        static QString parseSolarObjectToString(SolarObjects object);

        //returns tilt of solar object
        static float parseSolarObjectTilt(SolarObjects object);

        //returns radius of solar object
        static float parseSolarObjectRadius(SolarObjects object);

        //returns solar object from planet list index
        static SolarObjects parsePlanetListIndex(int index);
    };

}


#endif // SOLARPARSER_H
