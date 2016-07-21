#include "viewportwidget.h"

SolarSystem::ViewPortWidget::ViewPortWidget(QWidget *parent) : QWidget(parent)
{
    lay = new QVBoxLayout();
    setWindowTitle("SolarSystem");
}

void SolarSystem::ViewPortWidget::set3dViewPort(QWindow *viewPort)
{
    QWidget* container = QWidget::createWindowContainer(viewPort);
    lay->addWidget(container);
    setLayout(lay);

    emit windowChanged();
}
