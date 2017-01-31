#ifndef SOLARANIMATOR_H
#define SOLARANIMATOR_H

#include <QObject>
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

        //main call for solar system animation
        void animate();
    };

}

#endif // SOLARANIMATOR_H
