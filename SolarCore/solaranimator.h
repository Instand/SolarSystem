#ifndef SOLARANIMATOR_H
#define SOLARANIMATOR_H

#include <SolarCore/isolarmathcore.h>

namespace SolarSystem {

    //contains ISolarMathCore, and dynamic use it
    class SolarAnimator : public QObject
    {
        Q_OBJECT

        Q_PROPERTY(QDateTime solarTime READ solarTime NOTIFY solarTimeChanged)
        Q_PROPERTY(QString solarObjectString READ viewSolarObjectString NOTIFY solarObjectStringChanged)

    public:

        explicit SolarAnimator(QObject *parent = 0);
        ~SolarAnimator();

        //for math core ref
        ISolarMathCore* mathCore() const;

        //get solar time
        QDateTime solarTime() const;

        //get planet string
        QString viewSolarObjectString() const;

    private:

        //math core interface
        ISolarMathCore* _mathCore = nullptr;

        //selected solar object
        SolarObjects currentSolarObject = SolarObjects::SolarSystemView;

        //stores string
        QString solarObjStr = SolarObjectsValues::SolarSystem::toString;

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

    signals:
        void solarTimeChanged(QDateTime time);
        void solarObjectStringChanged(QString str);
    };

}

#endif // SOLARANIMATOR_H
