#ifndef SOLARGUI_H
#define SOLARGUI_H

#include <QMainWindow>
#include <QMdiArea>
#include <viewportwidget.h>
#include <solar3dviewport.h>
#include <QMdiSubWindow>
#include "UI/solarcontrollerui.h"

namespace SolarSystem {

    //main application ui
    class SolarGUI : public QMainWindow {

        Q_OBJECT

    public:

        explicit SolarGUI(QWidget *parent = 0);
        ~SolarGUI();

    private:

        //base visual types
        QMdiArea* mainViewer;
        ViewPortWidget* viewPortWidget;
        Solar3dViewPort* solar3dViewer;

        //pointer to 3d subviewer
        QMdiSubWindow* baseViewer;

        //solar system controller
        SolarControllerUI* uiController;

        //animator ref
        SolarAnimator* animator = nullptr;
    };
}


#endif // SOLARGUI_H
