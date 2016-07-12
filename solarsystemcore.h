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

    template<typename Query, typename SolarF>
    const QString& dbValue(Query& query, SolarF type) {
        return query.value(type);
    }
}


#endif // SOLARSYSTEMCORE_H
