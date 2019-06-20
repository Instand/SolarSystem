#ifndef DBCONNECTOR_H
#define DBCONNECTOR_H

#include <QObject>
#include <QString>
#include <QtSql>

#include <object.h>
#include <solarsystemcore.h>

namespace SolarSystem
{
    // connection and receive data from database (default SQLite 3) Singleton
    class DBConnector final : public QObject
    {
        Q_OBJECT

    private:
        explicit DBConnector(QObject* parent = nullptr);
        ~DBConnector();

        DBConnector(const DBConnector& dbc) = delete;
        DBConnector(DBConnector&& dbc) = delete;
        DBConnector& operator= (const DBConnector& dbc) = delete;

    public:
        static DBConnector& instance();

        // checks db state
        bool isOpen();

        // checks db elements count
        int elementsCount();

        // returns database status
        bool status() const;

        // returns a full info about object
        const ObjectPtr info(const QString& objectName) const;

        // returns all solar object names
        QStringList allSolarObjects() const;

        // returns names of all planets
        QStringList allPlanetsNames() const;

        // returns names of all columns
        QStringList columnNames() const;

        // returns a full info about solar object from solarObject type
        QStringList info(SolarObjects object) const;

    private:
        QSqlDatabase m_dataBase;

        // creates object
        void createObjectFromQuery(QSqlQuery& query, ObjectPtr& object) const;
    };
}

#endif // DBCONNECTOR_H
