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
        explicit SolarObjectsContainer(QObject *parent = nullptr);

        //get math solar object
        SolarObjectPtr solarObject(SolarObjects object) const;

    private:

        //storage
        SolarObjectsMap m_solarObjects;
    };
}

#endif // SOLAROBJECTSCONTAINER_H
