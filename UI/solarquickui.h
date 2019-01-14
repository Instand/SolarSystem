#ifndef SOLARQUICKUI_H
#define SOLARQUICKUI_H

#include <QQuickView>
#include <QOpenGLContext>
#include <QQmlEngine>

namespace SolarSystem
{
    //user interface based on qt quick
    class SolarQuickUI : public QObject
    {
        Q_OBJECT

    public:
        explicit SolarQuickUI(QObject* parent = nullptr);

        //show QQuick
        void show();

        //show full size
        void showFullScreen();

    private:

        //screen format
        QSurfaceFormat m_format;

        //main quick view
        QQuickView m_view;

    private slots:
        void quit();
    };
}

#endif // SOLARQUICKUI_H
