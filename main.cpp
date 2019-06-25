#include <QGuiApplication>
#include <UI/quickui.h>

int main(int argc, char *argv[])
{
    QGuiApplication a(argc, argv);

    // show our beautiful solar system to us
    SolarSystem::QuickUi ui;
    ui.show();

    return a.exec();
}

