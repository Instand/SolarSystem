#include "solargui.h"

SolarSystem::SolarGUI::SolarGUI(QWidget *parent):
    QMainWindow(parent),
    mainViewer(new QMdiArea()),
    viewPortWidget(new ViewPortWidget),
    solar3dViewer(new Solar3dViewPort)
{
    mainViewer->setViewMode(QMdiArea::ViewMode::TabbedView);
    mainViewer->setTabShape(QTabWidget::TabShape::Rounded);

    //mdi a central widget
    setCentralWidget(mainViewer.get());

    //conver 3dViwer to viewPort
    viewPortWidget->set3dViewPort(solar3dViewer.get());

    //add converted 3d window
    baseViewer = mainViewer->addSubWindow(viewPortWidget.get());

    //maximaze 3dviewer
    baseViewer->showMaximized();
}

SolarSystem::SolarGUI::~SolarGUI()
{
    baseViewer = nullptr;
}
