#ifndef PLANETSCONTAINER_H
#define PLANETSCONTAINER_H

#include <Interface/ivisualsolarobject.h>
#include <map>

namespace SolarSystem {

    //array type
    using PlanetArray = std::map<SolarObjects, IVisualSolarObject*>;

    //contains all 3D planets
    class PlanetsContainer
    {
        PlanetsContainer(QObject *parent = 0) = delete;
        PlanetsContainer(const PlanetsContainer& container) = delete;

        static PlanetArray planetContainer;
        static bool initialized;
        static Qt3DCore::QNode* rootNode;

    public:

        //call before class using
        static void initialize(Qt3DCore::QNode* root = nullptr);

        //destroy container objects
        static void destruct();

        //get planets number
        static int planetsNumber();

        //get all planets
        static PlanetArray planets();
    };
}

#endif // PLANETSCONTAINER_H
