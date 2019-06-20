#ifndef SOLARQUICKUI_H
#define SOLARQUICKUI_H

#include <QQuickView>
#include <QOpenGLContext>
#include <QQmlEngine>

namespace SolarSystem
{
    // user interface based on qt quick
    class SolarQuickUI : public QObject
    {
        Q_OBJECT

    public:
        explicit SolarQuickUI(QObject* parent = nullptr);

        void show();
        void showFullScreen();

    private:
        QSurfaceFormat m_format;
        QQuickView m_view;

    private slots:
        void quit();
    };
}

#endif // SOLARQUICKUI_H
