#include <QApplication>
#include "solarsystemdbconnector.h"


int main(int argc, char *argv[])
{
    QApplication a(argc, argv);

    SolarSystem::SolarSystemDBConnector db("SolarDB.db");
    qDebug() << db.elementsCount();

    QStringList list;
    SolarSystem::SolarSystemObject object = db.info("Sun");
    list << object.description();
    qDebug() << list.at(0);

    return a.exec();
}

