#ifndef SOLARSYSTEMDBCONNECTOR_H
#define SOLARSYSTEMDBCONNECTOR_H

#include <QObject>
#include <QString>
#include <QtSql>
#include "solarsystemobject.h"
#include "solarsystemcore.h"

namespace SolarSystem
{
    //class for connection and receive data from database (default SQLite 3) Singleton
    class SolarSystemDBConnector final : public QObject
    {
        Q_OBJECT

    private:
        explicit SolarSystemDBConnector(QObject* parent = nullptr);
        ~SolarSystemDBConnector();

        //for singleton
        SolarSystemDBConnector(const SolarSystemDBConnector& dbc) = delete;
        SolarSystemDBConnector(SolarSystemDBConnector&& dbc) = delete;
        SolarSystemDBConnector& operator= (const SolarSystemDBConnector& dbc) = delete;

    public:

        //get object
        static SolarSystemDBConnector& instance();

        //check db state
        bool isOpen();

        //check db elements count
        int elementsCount();

        //returns database status
        bool status() const;

        //get a full info about object
        const SolarSystemObjectPtr info(const QString& objectName) const;

        //get all solar object names
        QStringList allSolarObjects() const;

        //get names of all planets
        QStringList allPlanetsNames() const;

        //get names of all columns
        QStringList columnNames() const;

        //get a full info about solar object from solarObject type
        QStringList info(SolarObjects object) const;

    private:
        QSqlDatabase _database;

        //create object
        void createObjectFromQuery(QSqlQuery& query, SolarSystemObjectPtr& object) const;
    };
}

#endif // SOLARSYSTEMDBCONNECTOR_H
