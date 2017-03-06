#ifndef SOLARQUICKUI_H
#define SOLARQUICKUI_H

#include <QQuickView>
#include <QOpenGLContext>
#include <Qt3DQuick/QQmlAspectEngine>
#include <QGuiApplication>
#include <QQmlEngine>
#include <QQmlContext>

namespace SolarSystem {

    //user interface based on qt quick
    class SolarQuickUI : public QObject {

        Q_OBJECT

    public:
        SolarQuickUI(QObject* parent = nullptr);

        //show QQuick
        void show();

        //show full size
        void showFullScreen();

    private:

        //screen format
        QSurfaceFormat format;

        //main quick view
        QQuickView view;

    private slots:
        void quit();
    };
}

#endif // SOLARQUICKUI_H
