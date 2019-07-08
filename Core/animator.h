#ifndef ANIMATOR_H
#define ANIMATOR_H

#include <Core/mathcore.h>

class QPropertyAnimation;
class QParallelAnimationGroup;

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

    public slots:

        // main call for solar system animation
        void animate(float deltaTime);

        // sets camera view center to solar object and animates it
        void animateCamera(SolarObjects object);

    signals:
        void currentObjectChanged(SolarObjects);

    private slots:
        void onAnimationFinished();
        void onSpeedAnimationFinished();

    private:

        // ms
        constexpr static int viewCenterAnimationDuration = 1500;
        constexpr static int viewPositionAnimationDuration = 2500;

        void animation(float deltaTime);
        void checkAnimation();

        // selected solar object
        SolarObjects m_currentSolarObject = SolarObjects::SolarSystemView;

        bool m_animated = false;
        float m_solarSpeed = 0;

        QPropertyAnimation* m_viewCenterAnimation;
        QPropertyAnimation* m_cameraRollAnimation;
        QPropertyAnimation* m_viewPositionAnimation;
        QPropertyAnimation* m_solarSpeedAnimation;
        QParallelAnimationGroup* m_cameraAnimation;
    };
}

#endif // ANIMATOR_H
