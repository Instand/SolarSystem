#include "solarcontrollerui.h"
#include <QVBoxLayout>

SolarSystem::SolarControllerUI::SolarControllerUI(QWidget* parent):
    QDockWidget(parent)
{
    QVBoxLayout* lay = new QVBoxLayout();
    QWidget* widget = new QWidget();

    const int notchLenght = 5;

    controlName = new QLabel("Solar System");

    speedDial = new QDial();
    speedBar = new QProgressBar();

    sizeDial = new QDial();
    sizeBar = new QProgressBar();

    speedLabel = new QLabel("Speed control");
    sizeLabel = new QLabel("Size control");

    lay->addWidget(controlName);
    lay->addSpacing(20);
    lay->addWidget(speedLabel);
    lay->addWidget(speedDial);
    lay->addWidget(speedBar);
    lay->addWidget(sizeLabel);
    lay->addWidget(sizeDial);
    lay->addWidget(sizeBar);
    lay->addStretch(1);

    speedDial->setRange(0, 100);
    sizeDial->setRange(0, 100);

    speedDial->setNotchTarget(notchLenght);
    sizeDial->setNotchTarget(notchLenght);

    speedDial->setNotchesVisible(true);
    sizeDial->setNotchesVisible(true);

    widget->setLayout(lay);
    setWidget(widget);

    QObject::connect(speedDial, SIGNAL(valueChanged(int)), speedBar, SLOT(setValue(int)));
    QObject::connect(sizeDial, SIGNAL(valueChanged(int)), sizeBar, SLOT(setValue(int)));

    speedDial->setValue(speedDial->maximum()/2);
    sizeDial->setValue(sizeDial->maximum()/2);

    //create controllers signals
    QObject::connect(speedDial, SIGNAL(valueChanged(int)), this, SIGNAL(speedChanged(int)));
    QObject::connect(sizeDial, SIGNAL(valueChanged(int)), this, SIGNAL(sizeChanged(int)));
}


