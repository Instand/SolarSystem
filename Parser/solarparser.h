#ifndef SOLARPARSER_H
#define SOLARPARSER_H

#include <solarsystemcore.h>

namespace SolarSystem {

    //static realization of string solar object parser
    class SolarParser {
    public:
        static SolarSystemObjectType parseString(const QString& str);
    };

}


#endif // SOLARPARSER_H
