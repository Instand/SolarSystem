#include <QApplication>
#include <UI/solargui.h>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);

    SolarSystem::SolarGUI gui;
    gui.show();

    return a.exec();
}

