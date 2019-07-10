#ifndef ANIMATOR_H
#define ANIMATOR_H

#include <QObject>

#include <solarsystemcore.h>

namespace SolarSystem
{
    // animates and controlls mathcore
    class Animator : public QObject
    {
        Q_OBJECT

    public:
        explicit Animator(QObject* parent = nullptr);
        ~Animator() = default;

        // returns current animated solar object
        SolarObjects currentObject() const;

    protected:
        bool isAnimated() const;
        void enableAnimation();
        void disableAnimation();

    public slots:

        // main call for solar system animation
        void animate(float deltaTime);

        // sets camera view center to solar object and animates it
        void animateCamera(SolarObjects object);

    signals:
        void currentObjectChanged(SolarObjects);

    private:
        void animation(float deltaTime);
        void checkAnimation();

        // selected solar object
        SolarObjects m_currentSolarObject = SolarObjects::SolarSystemView;
        bool m_animated = false;
    };
}

#endif // ANIMATOR_H
