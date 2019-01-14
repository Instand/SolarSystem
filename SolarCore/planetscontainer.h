#ifndef PLANETSCONTAINER_H
#define PLANETSCONTAINER_H

#include <QObject>
#include <Scene/solarobject3d.h>
#include <map>

namespace SolarSystem
{
    //array type
    using PlanetArray = std::map<SolarObjects, SolarObject3D*>;

    //contains all 3D planets
    class PlanetsContainer : public QObject
    {
        Q_OBJECT

    public:
        explicit PlanetsContainer(Qt3DCore::QNode* root = nullptr, QObject* parent = nullptr);
        ~PlanetsContainer();

        //returns solar object count (planets + moons + start)
        int planetsNumber() const;

        //returns planet storage
        PlanetArray& planets() const;

    private:

        //main planet storage
        mutable PlanetArray m_planetContainer;

        //root entity
        Qt3DCore::QNode* m_rootNode = nullptr;

        //number of calculated planets in the planet container
        int m_calculatedSolarObjectNumber = 0;

        //initialization helper
        void initialize(Qt3DCore::QNode* root);
    };
}

#endif // PLANETSCONTAINER_H
