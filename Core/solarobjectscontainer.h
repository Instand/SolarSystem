#ifndef SOLAROBJECTSCONTAINER_H
#define SOLAROBJECTSCONTAINER_H

#include <Core/SolarObjects/abstractsolarobject.h>

namespace SolarSystem
{
    // solar math objects storage
    class SolarObjectsContainer final : public QObject
    {
        Q_OBJECT

    public:
        explicit SolarObjectsContainer(QObject* parent = nullptr);

        // get math solar object
        SolarObjectPtr solarObject(SolarObjects object) const;

    private:
        SolarObjectsMap m_solarObjects;
    };
}

#endif // SOLAROBJECTSCONTAINER_H
