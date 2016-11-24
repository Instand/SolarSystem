#ifndef SOLARPARSER_H
#define SOLARPARSER_H

#include <solarsystemcore.h>

namespace SolarSystem {

    //static realization of string solar object parser
    class SolarParser {
    public:

        //parse string to get solar object type
        static SolarSystemObjectType parseString(const QString& str);

        //get string from SolarObejcts type
        static QString parseSolarObjectToString(SolarObjects object);
    };

}


#endif // SOLARPARSER_H
