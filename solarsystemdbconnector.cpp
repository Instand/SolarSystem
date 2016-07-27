#include "solarsystemdbconnector.h"
#include <Parser/solarparser.h>

//pseydo name
using SolarS = SolarSystem::SolarStrings;
using SolarV = SolarSystem::SolarValues;
using Types = SolarSystem::SolarFields;

SolarSystem::SolarSystemDBConnector::SolarSystemDBConnector(const QString &dbName, QObject *parent):
    QObject(parent),
    _database(QSqlDatabase::addDatabase(SolarS::qSqlLite))
{
    _database.setDatabaseName(QApplication::applicationDirPath() + SolarS::dbFolder + dbName);
    _database.open();
}

SolarSystem::SolarSystemDBConnector::~SolarSystemDBConnector()
{
    if (_database.isOpen())
        _database.close();
}

bool SolarSystem::SolarSystemDBConnector::isOpen()
{
    return _database.isOpen();
}

int SolarSystem::SolarSystemDBConnector::elementsCount()
{
    QStringList list;

    if (_database.isOpen()) {

        //make a query
        QSqlQuery query(SolarS::select + SolarS::nameField + SolarS::from + SolarS::dbName);

        while (query.next()) {
            list << query.value(SolarV::zero).toString();
        }
    }

    return list.size();
}

const SolarSystem::SolarSystemObject&& SolarSystem::SolarSystemDBConnector::info(const QString& objectName) const
{
    SolarSystem::SolarSystemObject object;

    if (_database.isOpen()) {

        //make a query
        QSqlQuery query(SolarS::select + SolarS::all + SolarS::from + SolarS::dbName + SolarS::where + SolarS::nameField +
                        SolarS::like + SolarS::likeObject(objectName));

        if (query.first()) {

            //collecting query data to local object
            createObjectFromQuery(query, object);

        }
    }

    return std::move(object);
}

QStringList SolarSystem::SolarSystemDBConnector::allSolarObjects() const
{
    QStringList objectList;

    if (_database.isOpen()) {

        //make a query
        QSqlQuery query(SolarS::select + SolarS::nameField + SolarS::from + SolarS::dbName);

        while (query.next()) {
            objectList << query.value(SolarV::zero).toString();
        }

    }

    return objectList;
}

QStringList SolarSystem::SolarSystemDBConnector::allPlanetsNames() const
{
    QStringList list;

    if (_database.isOpen()) {

        //make a query
        QSqlQuery query(SolarS::select + SolarS::nameField + SolarS::from + SolarS::dbName + SolarS::where +SolarS::type +
                        SolarS::like + SolarS::likeObject(SolarStrings::planet));

        while (query.next()) {
            list << query.value(SolarV::zero).toString();
        }
    }

    return list;
}

void SolarSystem::SolarSystemDBConnector::createObjectFromQuery(QSqlQuery &query, SolarSystem::SolarSystemObject &object) const
{
    object.setStringType(query.value(Types::SolarType).toString());
    object.setSolarObjectName(query.value(Types::Name).toString());
    object.setOrbitalSpeed(query.value(Types::OrbitalSpeed).toFloat());
    object.setMass(query.value(Types::Mass).toDouble());
    object.setMeanRadius(query.value(Types::MeanRadius).toFloat());
    object.setSurfaceTemperature(query.value(Types::Temperature).toInt());
    object.setSurfaceGravity(query.value(Types::Gravity).toFloat());
    object.setVolume(query.value(Types::Volume).toDouble());
    object.setSiderealPeriod(query.value(Types::SiderealPeriod).toDouble());
    object.setOrbitalPeriod(query.value(Types::OrbitalPeriod).toDouble());
    object.setDescription(query.value(Types::Description).toString());

    //programming type
    object.setSolarType(SolarParser::parseString(object.stringType()));
}
