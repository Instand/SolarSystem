#include "solarinfoloader.h"
#include <QFile>
#include <QDebug>

SolarSystem::SolarInfoLoader::SolarInfoLoader(QObject* parent):
    QObject(parent)
{
}

QString SolarSystem::SolarInfoLoader::loadInfo() const
{
    QFile infoFile(QStringLiteral(":/Resources/Info.txt"));

    if (!infoFile.open(QIODevice::ReadOnly))
        qDebug() << "Can not open Info file";

    return static_cast<QString>(infoFile.readAll());
}

QString SolarSystem::SolarInfoLoader::loadInfo(const QString& insertVersion) const
{
    return loadInfo().replace("%%", insertVersion);
}

QObject* SolarSystem::infoLoaderProvider(class QQmlEngine* engine, class QJSEngine* scriptEngine)
{
    Q_UNUSED(engine)
    Q_UNUSED(scriptEngine)

    return new SolarSystem::SolarInfoLoader();
}
