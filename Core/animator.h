#ifndef ANIMATOR_H
#define ANIMATOR_H

#include <Core/mathcore.h>
#include <QTimer>

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

        // set cam view center
        void setCameraViewCenter(int index);

    signals:
        void solarTimeChanged(const QDateTime&);
        void currentObjectChanged(SolarObjects);

    private slots:
        void onAnimationFinished();
        void onSpeedAnimationFinished();

    private:

        // selected solar object
        SolarObjects m_currentSolarObject = SolarObjects::SolarSystemView;

        // animation flag
        bool m_animated = false;

        // store solar systme speed
        float m_solarSpeed = 0;

        // animation for view center
        QPropertyAnimation* m_viewCenterAnimation;

        // animation for position
        QPropertyAnimation* m_viewPositionAnimation;

        // speed animation
        QPropertyAnimation* m_solarSpeedAnimation;

        // group animation
        QParallelAnimationGroup* m_cameraAnimation;
    };
}

#endif // ANIMATOR_H
