#ifndef SOLARANIMATOR_H
#define SOLARANIMATOR_H

#include <SolarCore/isolarmathcore.h>

namespace SolarSystem {

    //contains ISolarMathCore, and dynamic use it
    class SolarAnimator : public QObject
    {
        Q_OBJECT

    public:

        explicit SolarAnimator(QObject *parent = 0);
        ~SolarAnimator();

        //for math core ref
        ISolarMathCore* mathCore() const;

    private:

        //math core interface
        ISolarMathCore* _mathCore = nullptr;

    public slots:

        //reset values
        void setDefaultValues();

        //main call for solar system animation
        void animate();

        //set current solar speed, in percents
        void setSolarSpeed(int value);

        //set current planets size, in percents
        void setSolarSize(int value);
    };

}

#endif // SOLARANIMATOR_H
