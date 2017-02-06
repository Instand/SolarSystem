#include "solargui.h"

SolarSystem::SolarGUI::SolarGUI(QWidget *parent):
    QMainWindow(parent),
    mainViewer(new QMdiArea()),
    viewPortWidget(new ViewPortWidget),
    solar3dViewer(new Solar3dViewPort),
    uiController(new SolarControllerUI)
{
    mainViewer->setViewMode(QMdiArea::ViewMode::TabbedView);
    mainViewer->setTabShape(QTabWidget::TabShape::Rounded);

    //mdi a central widget
    setCentralWidget(mainViewer);

    //convert 3dViwer to viewPort
    viewPortWidget->set3dViewPort(solar3dViewer);

    //add converted 3d window
    baseViewer = mainViewer->addSubWindow(viewPortWidget);

    //maximaze 3dviewer
    baseViewer->showMaximized();

    //add controller to dock
    addDockWidget(Qt::DockWidgetArea::RightDockWidgetArea, uiController);

    //get animator
    animator = solar3dViewer->animator();

    QObject::connect(uiController, &SolarControllerUI::speedChanged, animator, &SolarAnimator::setSolarSpeed);
    QObject::connect(uiController, &SolarControllerUI::sizeChanged, animator, &SolarAnimator::setSolarSize);
}

SolarSystem::SolarGUI::~SolarGUI()
{
    baseViewer = nullptr;
    animator = nullptr;
}
