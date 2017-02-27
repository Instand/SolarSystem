#ifndef PLANETSCONTAINER_H
#define PLANETSCONTAINER_H

#include <QObject>
#include <Interface/ivisualsolarobject.h>
#include <map>

namespace SolarSystem {

    //array type
    using PlanetArray = std::map<SolarObjects, IVisualSolarObject*>;

    //contains all 3D planets
    class PlanetsContainer : public QObject
    {
        Q_OBJECT

    public:

        explicit PlanetsContainer(Qt3DCore::QNode* root = nullptr, QObject *parent = 0);
        ~PlanetsContainer();

    private:

        //main fields
        PlanetArray planetContainer;
        Qt3DCore::QNode* rootNode;

        //helper
        void initialize(Qt3DCore::QNode *root);

    public:

        //get planets number
        int planetsNumber() const;

        //get all planets
        PlanetArray planets() const;

    signals:

        //if we pressed on planet
        void planetClicked(IVisualSolarObject*);

        //pressed coords
        void coordClicked(QVector3D);

    private slots:

        //on planet pick
        void onPressed(Qt3DRender::QPickEvent* pick);
    };
}

#endif // PLANETSCONTAINER_H
