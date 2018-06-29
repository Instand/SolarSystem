#include "solarsystemdbconnector.h"
#include <QGuiApplication>
#include <Parser/solarparser.h>

#ifdef ANDROID
    #include <QtAndroidExtras/QtAndroid>
#endif

//pseydo name
using SolarS = SolarSystem::SolarStrings;
using SolarV = SolarSystem::SolarValues;
using Types = SolarSystem::SolarFields;

SolarSystem::SolarSystemDBConnector::SolarSystemDBConnector(QObject* parent):
    QObject(parent),
    m_Database(QSqlDatabase::addDatabase(SolarS::qSqlLite))
{
    QString dbLocalPath;
#ifndef Q_OS_ANDROID
    dbLocalPath = QGuiApplication::applicationDirPath() + SolarS::dbFolder + SolarS::dbFileName;

    if (!QFile::exists(dbLocalPath))
    {
        QDir dir;
        dir.mkdir(QGuiApplication::applicationDirPath() + SolarS::dbFolder);

        QFile file(":/Resources" + SolarS::dbFolder + SolarS::dbFileName);
        file.copy(dbLocalPath);
    }
#endif

#ifdef Q_OS_ANDROID
    dbLocalPath = QStandardPaths::writableLocation(QStandardPaths::AppDataLocation) + SolarS::dbFileName;
    QFileInfo file(dbLocalPath);

    if (!file.exists())
    {
        QFile resourceFile(":/Resources" + SolarS::dbFolder + SolarS::dbFileName);

        if (resourceFile.exists())
        {
            if (!resourceFile.copy(dbLocalPath))
            {
                qDebug() << "Copy database from resources failed, try to copy from assets";

                QFile assetsFile("assets:/" + SolarS::dbFileName);

                if (assetsFile.exists())
                {
                    if (!assetsFile.copy(dbLocalPath))
                        qDebug() << "Copy database from assets failed";
                }
            }
        }
    }

    if (!QFile::setPermissions(dbLocalPath, QFile::WriteOwner | QFile::ReadOwner))
        qDebug() << "Database permissions failed";
#endif
    QFileInfo info(dbLocalPath);

    if (info.isFile() && info.exists())
    {
        m_Database.setDatabaseName(dbLocalPath);

       if (! m_Database.open())
           qDebug() << "Database opening failed";
    }
}

SolarSystem::SolarSystemDBConnector::~SolarSystemDBConnector()
{
    if (m_Database.isOpen())
        m_Database.close();
}

SolarSystem::SolarSystemDBConnector& SolarSystem::SolarSystemDBConnector::instance()
{
    static SolarSystemDBConnector connector;
    return connector;
}

bool SolarSystem::SolarSystemDBConnector::isOpen()
{
    return m_Database.isOpen();
}

int SolarSystem::SolarSystemDBConnector::elementsCount()
{
    QStringList list;

    if (m_Database.isOpen())
    {
        //make a query
        QSqlQuery query(SolarS::select + SolarS::nameField + SolarS::from + SolarS::dbName);

        while (query.next()) {
            list << query.value(SolarV::zero).toString();
        }
    }

    return list.size();
}

bool SolarSystem::SolarSystemDBConnector::status() const
{
    return m_Database.isValid();
}

const SolarSystem::SolarSystemObjectPtr SolarSystem::SolarSystemDBConnector::info(const QString& objectName) const
{
    SolarSystem::SolarSystemObjectPtr object(new SolarSystem::SolarSystemObject());

    if (m_Database.isOpen())
    {
        //make a query
        QSqlQuery query(SolarS::select + SolarS::all + SolarS::from + SolarS::dbName + SolarS::where + SolarS::nameField +
                        SolarS::like + SolarS::likeObject(objectName));

        //collecting query data to local object
        if (query.first())
            createObjectFromQuery(query, object);
    }

    return object;
}

QStringList SolarSystem::SolarSystemDBConnector::allSolarObjects() const
{
    QStringList objectList;

    if (m_Database.isOpen()) {

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

    if (m_Database.isOpen()) {

        //make a query
        QSqlQuery query(SolarS::select + SolarS::nameField + SolarS::from + SolarS::dbName + SolarS::where + SolarS::type +
                        SolarS::like + SolarS::likeObject(SolarStrings::planet));

        while (query.next()) {
            list << query.value(SolarV::zero).toString();
        }
    }

    return list;
}

QStringList SolarSystem::SolarSystemDBConnector::columnNames() const
{
    QStringList list;

    if (m_Database.isOpen())
    {
        //make a query
        QSqlQuery query("PRAGMA table_info('SolarSystem')");

        while (query.next())
            list << query.value(1).toString();
    }

    return list;
}

QStringList SolarSystem::SolarSystemDBConnector::info(SolarSystem::SolarObjects object) const
{
    auto objStr = SolarParser::parseSolarObjectToString(object);
    QStringList list;

    if (m_Database.isOpen())
    {
        //make a query
        QSqlQuery query("SELECT * FROM SolarSystem WHERE Name =" + SolarS::likeObject(objStr));

        //columns count
        auto size = query.record().count();

        while (query.next())
        {
            for (int i = 0; i < size; ++i)
                list << query.value(i).toString();
        }
    }

    return list;
}

void SolarSystem::SolarSystemDBConnector::createObjectFromQuery(QSqlQuery& query, SolarSystemObjectPtr& object) const
{
    object->setStringType(query.value(Types::SolarType).toString());
    object->setSolarObjectName(query.value(Types::Name).toString());
    object->setOrbitalSpeed(query.value(Types::OrbitalSpeed).toFloat());
    object->setMass(query.value(Types::Mass).toDouble());
    object->setMeanRadius(query.value(Types::MeanRadius).toFloat());
    object->setSurfaceTemperature(query.value(Types::Temperature).toInt());
    object->setSurfaceGravity(query.value(Types::Gravity).toFloat());
    object->setVolume(query.value(Types::Volume).toDouble());
    object->setSiderealPeriod(query.value(Types::SiderealPeriod).toDouble());
    object->setOrbitalPeriod(query.value(Types::OrbitalPeriod).toDouble());
    object->setDescription(query.value(Types::Description).toString());

    //programming type
    object->setSolarType(SolarParser::parseString(object->stringType()));
}
