#include <QApplication>
#include <UI/solarquickui.h>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);

    //show our beautiful solar system to us
    SolarSystem::SolarQuickUI ui;
    ui.show();

    return a.exec();
}

