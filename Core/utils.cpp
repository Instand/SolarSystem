#include "utils.h"

SolarSystem::Utils::Utils(QObject* parent):
    QObject(parent)
{
}

QObject* SolarSystem::utilsProvider(QQmlEngine*, QJSEngine*)
{
    return new Utils();
}
