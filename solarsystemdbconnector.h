#ifndef SOLARSYSTEMDBCONNECTOR_H
#define SOLARSYSTEMDBCONNECTOR_H

#include <QObject>
#include <QString>
#include <QtSql>
#include <QApplication>
#include "solarsystemobject.h"
#include "solarsystemcore.h"

namespace SolarSystem {

    //class for connection and receive data from database (default SQLite 3) Singleton
    class SolarSystemDBConnector final : public QObject {
        Q_OBJECT

    private:
        explicit SolarSystemDBConnector(const QString& dbName, QObject* parent = 0);
        ~SolarSystemDBConnector();

        //for singleton
        SolarSystemDBConnector(const SolarSystemDBConnector& dbc) = delete;
        SolarSystemDBConnector(SolarSystemDBConnector&& dbc) = delete;
        SolarSystemDBConnector& operator= (const SolarSystemDBConnector& dbc) = delete;

    public:

        //get object
        static SolarSystemDBConnector& instance(const QString& str = "");

        //check db state
        bool isOpen();

        //check db elements count
        int elementsCount();

        //get a full info about object
        const SolarSystemObjectPtr info(const QString& objectName) const;

        //get all solar object names
        QStringList allSolarObjects() const;

        //get names of all planets
        QStringList allPlanetsNames() const;

    private:
        QSqlDatabase _database;

        //create object
        void createObjectFromQuery(QSqlQuery& query, SolarSystemObjectPtr& object) const;
    };

}

#endif // SOLARSYSTEMDBCONNECTOR_H
