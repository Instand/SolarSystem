#ifndef PLANETSCONTAINER_H
#define PLANETSCONTAINER_H

#include <QObject>
#include <Scene/solarobject3d.h>
#include <map>

namespace Qt3DRender
{
    class QTexture2D;
}

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

    private:

        //main fields
        PlanetArray planetContainer;
        Qt3DCore::QNode* rootNode;
        int calculatedSolarObjectNumber = 0;

        //helper
        void initialize(Qt3DCore::QNode *root);

    public:

        //get planets number which should be calculated
        int planetsNumber() const;

        //get all planets
        PlanetArray planets() const;
    };
}

#endif // PLANETSCONTAINER_H
