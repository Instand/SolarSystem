#ifndef SOLAROBJECTSCONTAINER_H
#define SOLAROBJECTSCONTAINER_H

#include <QObject>
#include "SolarCore/SolarObjects/abstractsolarobject.h"

namespace SolarSystem
{
    //class for storage solar math objects
    class SolarObjectsContainer final : public QObject
    {
        Q_OBJECT

    public:
        explicit SolarObjectsContainer(QObject *parent = 0);

        //get math solar object
        SolarObjectPtr solarObject(SolarObjects object) const;

        //get all math solar obejcts
        const SolarObjectsArray& allSolarObjects() const;

    private:

        //storage
        SolarObjectsArray _solarObjects;
    };
}

#endif // SOLAROBJECTSCONTAINER_H
