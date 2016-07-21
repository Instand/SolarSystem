#include "solar3dviewport.h"
#include <Qt3DExtras/QForwardRenderer>

SolarSystem::Solar3dViewPort::Solar3dViewPort(QScreen* screen) :
    Qt3DExtras::Qt3DWindow(screen),
    _camera(camera()),
    _root(new Qt3DCore::QEntity)
{
    //3d viewport setup
    defaultFramegraph()->setClearColor(Qt::black);

    //scene camera setup
    _camera->setProjectionType(Qt3DRender::QCameraLens::PerspectiveProjection);
    _camera->setAspectRatio(width() / height());
    _camera->setUpVector(QVector3D(0.0f, 1.0f, 0.0f));
    _camera->setViewCenter(QVector3D(0.0f, 3.5f, 0.0f));
    _camera->setPosition(QVector3D(0.0f, 0.5f, 35.0f));

    //solar rendering
    //....

    //set root
    setRootEntity(_root.get());
}
