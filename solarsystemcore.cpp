#include "solarsystemcore.h"

const QString SolarSystem::SolarStrings::qSqlLite = "QSQLITE";

//db fields
const QString SolarSystem::SolarStrings::dbName = "SolarSystem";
const QString SolarSystem::SolarStrings::dbFileName = "SolarDB.db";
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

//types
const QString SolarSystem::SolarStrings::planet = "Planet";
const QString SolarSystem::SolarStrings::dwarfPlanet = "Dwarf planet";
const QString SolarSystem::SolarStrings::star = "Star";
const QString SolarSystem::SolarStrings::moon = "Moon";
const QString SolarSystem::SolarStrings::ring = "Ring";
const QString SolarSystem::SolarStrings::solarSystemBody = "Solar system body";
const QString SolarSystem::SolarStrings::galaxy = "Galaxy";
const QString SolarSystem::SolarStrings::asteroid = "Asteroid";

//values
const int SolarSystem::SolarValues::zero = 0;
const int SolarSystem::SolarValues::solarDistance = 2600000;
const float SolarSystem::SolarValues::auScale = 149597.870700f;
const float SolarSystem::SolarValues::saturnOuterRadius = 120.700f;
const float SolarSystem::SolarValues::uranusOuterRadius = 40.0f;
const float SolarSystem::SolarValues::startSize = 1800; //1200
const float SolarSystem::SolarValues::startSpeed = 1000000.0f;
const int SolarSystem::SolarValues::year = 2000;
const int SolarSystem::SolarValues::month = 1;
const int SolarSystem::SolarValues::day = 1;
const QVector3D SolarSystem::SolarValues::rollAxis = QVector3D(0, 1, 0);
const QVector3D SolarSystem::SolarValues::tiltAxis = QVector3D(0, 0, 1);

QString SolarSystem::SolarStrings::likeObject(const QString &object)
{
    return "'" + object + "'";
}
