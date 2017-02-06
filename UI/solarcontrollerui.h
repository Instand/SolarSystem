#ifndef SOLARCONTROLLERUI_H
#define SOLARCONTROLLERUI_H

#include <QDockWidget>
#include <QLabel>
#include <QDial>
#include <QProgressBar>

namespace SolarSystem {

    //docked UI
    class SolarControllerUI : public QDockWidget
    {
        Q_OBJECT

    public:

        explicit SolarControllerUI(QWidget* parent = nullptr);

    private:

        //top name
        QLabel* controlName;

        //controler for solar system speed
        QDial* speedDial;

        //show speed
        QProgressBar* speedBar;

        //controller for solar system size
        QDial* sizeDial;

        //show size
        QProgressBar* sizeBar;

        //text
        QLabel* speedLabel;
        QLabel* sizeLabel;

    signals:

        //using speed slider
        void speedChanged(int value);

        //using size slider
        void sizeChanged(int value);
    };
}

#endif // SOLARCONTROLLERUI_H
