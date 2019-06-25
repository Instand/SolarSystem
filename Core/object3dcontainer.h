#ifndef OBJECT3DCONTAINER_H
#define OBJECT3DCONTAINER_H

#include <QObject>
#include <map>

#include <Scene/object3d.h>

namespace SolarSystem
{
    using Object3DMap = std::map<SolarObjects, Object3D*>;

    // contains all 3D planets
    class Object3DContainer : public QObject
    {
        Q_OBJECT

    public:
        explicit Object3DContainer(Qt3DCore::QNode* root = nullptr, QObject* parent = nullptr);
        ~Object3DContainer();

        // returns solar object count (planets + moons + start)
        int planetsNumber() const;

        // returns planet storage
        Object3DMap& objects() const;
        Object3D* object(SolarObjects type) const;

    private:

        // main planet storage
        mutable Object3DMap m_objectContainer;

        // root entity
        Qt3DCore::QNode* m_rootNode = nullptr;

        // number of calculated planets in the planet container
        int m_calculatedSolarObjectNumber = 0;

        // initialization helper
        void initialize(Qt3DCore::QNode* root);
    };
}

#endif // OBJECT3DCONTAINER_H
