#ifndef SOLARANIMATOR_H
#define SOLARANIMATOR_H

#include <SolarCore/solarmathcore.h>
#include <QTimer>

class QPropertyAnimation;
class QParallelAnimationGroup;

namespace SolarSystem
{
    class SolarMathCore;

    //contains SolarMathCore, and dynamic use it
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
        ~SolarAnimator();

        //for math core ref
        SolarMathCore* mathCore() const;

        //get solar time
        QDateTime solarTime() const;

        //get planet string
        QString viewSolarObjectString() const;

        //get cam view center
        QVector3D cameraViewCenter() const;

        //get cam position
        QVector3D cameraPosition() const;

        //get solar system speed
        float solarSystemSpeed() const;

        //get solar extra speed
        double solarSystemExtraSpeed() const;

        //get solar object info
        QString info() const;

    private:

        //math core interface
        SolarMathCore* mathCorePtr = nullptr;

        //selected solar object
        SolarObjects currentSolarObject = SolarObjects::SolarSystemView;

        //stores string
        QString solarObjStr = SolarObjectsValues::SolarSystem::toString;

        //animation flag
        bool animated = false;

        //animation for view center
        QPropertyAnimation* viewCenterAnimation;

        //animation for position
        QPropertyAnimation* viewPositionAnimation;

        //group animation
        QParallelAnimationGroup* cameraAnimation;

        //speed animation
        QPropertyAnimation* solarSpeedAnimation;

        //store solar systme speed
        float solarSpeed = 0;

    public slots:

        //reset values
        void setDefaultValues();

        //main call for solar system animation
        void animate(float deltaTime);

        //set current solar speed, in percents
        void setSolarSpeed(int value);

        //set current planets size, in percents
        void setSolarSize(int value);

        //set cam view center
        void setCameraViewCenter(int index);

        //set camera view center
        void setCameraViewCenter(QVector3D position);

        //set camera view position
        void setCameraPositon(QVector3D position);

        //set solar system speed
        void setSolarSystemSpeed(float speed);

        //change solar system extra speed
        void changeExtraSpeed();

        //reset to x1
        void resetExtraSpeed();

    signals:
        void solarTimeChanged(QDateTime);
        void solarObjectStringChanged(QString);
        void cameraViewCenterChanged(QVector3D);
        void cameraPositionChanged(QVector3D);
        void solarSystemSpeedChanged(float);
        void extraSpeedChanged(double);
        void infoChanged(const QString&);

    private slots:
        void onAnimationFinished();
        void onSpeedAnimationFinished();
    };
}

#endif // SOLARANIMATOR_H
