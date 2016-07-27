#ifndef SOLARSYSTEMCORE_H
#define SOLARSYSTEMCORE_H

#include <QString>

namespace SolarSystem {

    //store all query strings for db
    struct SolarStrings {

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
    struct SolarValues {
        static const int zero;

        //db fields
    };


    enum SolarFields {
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

    //depredecated
    template<typename Query, typename SolarF>
    const QString& dbValue(Query& query, SolarF type) {
        return query.value(type);
    }
}


#endif // SOLARSYSTEMCORE_H
