#include <QGuiApplication>
#include <UI/solarquickui.h>

int main(int argc, char *argv[])
{
    QGuiApplication a(argc, argv);

    //show our beautiful solar system to us
    SolarSystem::SolarQuickUI ui;
    ui.showFullScreen();

    return a.exec();
}

