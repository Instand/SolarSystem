#ifndef SOLARANIMATOR_H
#define SOLARANIMATOR_H

#include <SolarCore/isolarmathcore.h>
#include <QPropertyAnimation>

namespace SolarSystem {

    //contains ISolarMathCore, and dynamic use it
    class SolarAnimator : public QObject
    {
        Q_OBJECT

        Q_PROPERTY(QDateTime solarTime READ solarTime NOTIFY solarTimeChanged)
        Q_PROPERTY(QString solarObjectString READ viewSolarObjectString NOTIFY solarObjectStringChanged)
        Q_PROPERTY(QVector3D viewCenter READ cameraViewCenter WRITE setCameraViewCenter NOTIFY cameraViewCenterChanged)

    public:

        explicit SolarAnimator(QObject *parent = 0);
        ~SolarAnimator();

        //for math core ref
        ISolarMathCore* mathCore() const;

        //get solar time
        QDateTime solarTime() const;

        //get planet string
        QString viewSolarObjectString() const;

        //get cam view center
        QVector3D cameraViewCenter() const;

    private:

        //math core interface
        ISolarMathCore* _mathCore = nullptr;

        //selected solar object
        SolarObjects currentSolarObject = SolarObjects::SolarSystemView;

        //stores string
        QString solarObjStr = SolarObjectsValues::SolarSystem::toString;

        //for camera animation
        QVector3D currentCamViewCenter;

        //animation flag
        bool animated = false;

        QPropertyAnimation* viewCenterAnimation;

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

    signals:
        void solarTimeChanged(QDateTime time);
        void solarObjectStringChanged(QString str);
        void cameraViewCenterChanged(QVector3D);

    private slots:
        void onAnimationFinished();
    };

}

#endif // SOLARANIMATOR_H
