#ifndef SOLARANIMATOR_H
#define SOLARANIMATOR_H

#include <SolarCore/mathcore.h>
#include <QTimer>

class QPropertyAnimation;
class QParallelAnimationGroup;

namespace SolarSystem
{
    // animates and controlls mathcore
    class SolarAnimator : public QObject
    {
        Q_OBJECT

        Q_PROPERTY(QDateTime solarTime READ solarTime NOTIFY solarTimeChanged)
        Q_PROPERTY(QString solarObjectString READ viewSolarObjectString NOTIFY solarObjectStringChanged)
        Q_PROPERTY(QVector3D viewCenter READ cameraViewCenter WRITE setCameraViewCenter NOTIFY cameraViewCenterChanged)
        Q_PROPERTY(QVector3D viewPosition READ cameraPosition WRITE setCameraPositon NOTIFY cameraPositionChanged)
        Q_PROPERTY(float solarSystemSpeed READ solarSystemSpeed WRITE setSolarSystemSpeed NOTIFY solarSystemSpeedChanged)
        Q_PROPERTY(double extraSpeed READ solarSystemExtraSpeed NOTIFY extraSpeedChanged)
        Q_PROPERTY(QString info READ info NOTIFY infoChanged)

    public:
        explicit SolarAnimator(QObject* parent = nullptr);

        // returns solar time
        QDateTime solarTime() const;

        // returns planet string
        QString viewSolarObjectString() const;

        // returns cam view center
        QVector3D cameraViewCenter() const;

        // returns cam position
        QVector3D cameraPosition() const;

        // returns solar system speed
        float solarSystemSpeed() const;

        // returns solar extra speed
        double solarSystemExtraSpeed() const;

        // returns solar object info
        QString info() const;

    private:

        // selected solar object
        SolarObjects m_currentSolarObject = SolarObjects::SolarSystemView;

        // stores string
        QString m_solarObjStr = SolarObjectsValues::SolarSystem::toString;

        // animation flag
        bool m_animated = false;

        // animation for view center
        QPropertyAnimation* m_viewCenterAnimation;

        // animation for position
        QPropertyAnimation* m_viewPositionAnimation;

        // group animation
        QParallelAnimationGroup* m_cameraAnimation;

        // speed animation
        QPropertyAnimation* m_solarSpeedAnimation;

        // store solar systme speed
        float m_solarSpeed = 0;

    public slots:

        // main call for solar system animation
        void animate(float deltaTime);

        // set current solar speed, in percents
        void setSolarSpeed(int value);

        // set current planets size, in percents
        void setSolarSize(int value);

        // set cam view center
        void setCameraViewCenter(int index);

        // set camera view center
        void setCameraViewCenter(const QVector3D& position);

        // set camera view position
        void setCameraPositon(const QVector3D& position);

        // set solar system speed
        void setSolarSystemSpeed(float speed);

        // change solar system extra speed
        void changeExtraSpeed();

        // reset to x1
        void resetExtraSpeed();

    signals:
        void solarTimeChanged(const QDateTime&);
        void solarObjectStringChanged(const QString&);
        void cameraViewCenterChanged(const QVector3D&);
        void cameraPositionChanged(const QVector3D&);
        void solarSystemSpeedChanged(float);
        void extraSpeedChanged(double);
        void infoChanged(const QString&);

    private slots:
        void onAnimationFinished();
        void onSpeedAnimationFinished();
    };
}

#endif // SOLARANIMATOR_H
