#ifndef SOLARSYSTEMDBCONNECTOR_H
#define SOLARSYSTEMDBCONNECTOR_H

#include <QObject>
#include <QString>
#include <QtSql>
#include <QApplication>
#include "solarsystemobject.h"
#include "solarsystemcore.h"

namespace SolarSystem {

    //class for connection and receive data from database (default SQLite 3)
    class SolarSystemDBConnector final : public QObject {
        Q_OBJECT

    public:
        explicit SolarSystemDBConnector(const QString& dbName, QObject* parent = 0);
        ~SolarSystemDBConnector();

        //check db state
        bool isOpen();

        //check db elements count
        int elementsCount();

        //get a full info about object
        const SolarSystem::SolarSystemObject&& info(const QString& objectName) const;

        //get all solar object names
        QStringList allSolarObjects() const;

        //get names of all planets
        QStringList allPlanetsNames() const;

    private:
        QSqlDatabase _database;

        //create object
        void createObjectFromQuery(QSqlQuery& query, SolarSystem::SolarSystemObject& object) const;
    };

}

#endif // SOLARSYSTEMDBCONNECTOR_H
