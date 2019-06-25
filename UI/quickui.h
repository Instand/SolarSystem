#ifndef QUICKUI_H
#define QUICKUI_H

#include <QQuickView>
#include <QOpenGLContext>
#include <QQmlEngine>

namespace SolarSystem
{
    // user interface based on qt quick
    class QuickUi : public QObject
    {
        Q_OBJECT

    public:
        explicit QuickUi(QObject* parent = nullptr);

        Q_INVOKABLE void show();

    private:
        QSurfaceFormat m_format;
        QQuickView m_view;

    private slots:
        void quit();
    };
}

#endif // QUICKUI_H
