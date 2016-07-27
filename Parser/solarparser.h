#ifndef SOLARPARSER_H
#define SOLARPARSER_H

#include <solarsystemobject.h>
#include <solarsystemcore.h>

namespace SolarSystem {

    //static realization of string solar object parser
    class SolarParser {
    public:
        static SolarSystemObject::SolarSystemObjectType parseString(const QString& str);
    };

}


#endif // SOLARPARSER_H
