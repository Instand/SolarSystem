#ifndef SOLARGUI_H
#define SOLARGUI_H

#include <QMainWindow>
#include <QMdiArea>
#include <viewportwidget.h>
#include <solar3dviewport.h>
#include <QMdiSubWindow>
#include <memory>

namespace SolarSystem {

    //main application ui
    class SolarGUI : public QMainWindow {

        Q_OBJECT

    public:
        explicit SolarGUI(QWidget *parent = 0);
        ~SolarGUI();

    private:

        //base visual types
        std::unique_ptr<QMdiArea> mainViewer;
        std::unique_ptr<ViewPortWidget> viewPortWidget;
        std::unique_ptr<Solar3dViewPort> solar3dViewer;

        //pointer to 3d subviwer
        QMdiSubWindow* baseViewer;
    };
}


#endif // SOLARGUI_H
