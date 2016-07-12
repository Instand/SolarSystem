#include "solarsystemcore.h"

const QString SolarSystem::SolarStrings::qSqlLite = "QSQLITE";

//db fields
const QString SolarSystem::SolarStrings::dbName = "SolarSystem";
const QString SolarSystem::SolarStrings::dbFileName = "SolarSystem.db";
const QString SolarSystem::SolarStrings::dbFolder = "/Database/";
const QString SolarSystem::SolarStrings::nameField = "Name";
const QString SolarSystem::SolarStrings::type = "SolarType";
const QString SolarSystem::SolarStrings::orbitalSpeed = "OrbitalSpeed";
const QString SolarSystem::SolarStrings::mass = "Mass";
const QString SolarSystem::SolarStrings::meanRadius = "MeanRadius";
const QString SolarSystem::SolarStrings::surfaceTemp = "Temperature";
const QString SolarSystem::SolarStrings::surfaceGravity = "Gravity";
const QString SolarSystem::SolarStrings::volume = "Volume";
const QString SolarSystem::SolarStrings::siderealPeriod = "SiderealPeriod";
const QString SolarSystem::SolarStrings::orbitalPeriod = "OrbitalPeriod";
const QString SolarSystem::SolarStrings::description = "Description";

//Sql query
const QString SolarSystem::SolarStrings::select = "SELECT ";
const QString SolarSystem::SolarStrings::from = " FROM ";
const QString SolarSystem::SolarStrings::where = " WHERE ";
const QString SolarSystem::SolarStrings::like = " LIKE";
const QString SolarSystem::SolarStrings::all = "*";

//values
const int SolarSystem::SolarValues::zero = 0;



QString SolarSystem::SolarStrings::likeObject(const QString &object)
{
    return "'" + object + "'";
}
