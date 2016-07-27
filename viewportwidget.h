#ifndef VIEWPORTWIDGET_H
#define VIEWPORTWIDGET_H

#include <QWidget>
#include <QVBoxLayout>

namespace SolarSystem {

    //a widget for convert 3D window to widget style
    class ViewPortWidget : public QWidget {
        Q_OBJECT

    public:
        explicit ViewPortWidget(QWidget *parent = 0);
        void set3dViewPort(QWindow* viewPort);

    private:
        QVBoxLayout* lay;

    signals:
        void windowChanged();
    };
}

#endif // VIEWPORTWIDGET_H
