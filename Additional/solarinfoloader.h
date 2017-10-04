#ifndef SOLARINFOLOADER_H
#define SOLARINFOLOADER_H

#include <QObject>
#include <QString>

namespace SolarSystem
{
    ///Loads info from file to QML
    class SolarInfoLoader final : public QObject
    {
        Q_OBJECT

    public:
        explicit SolarInfoLoader(QObject* parent = nullptr);

        //loads info
        Q_INVOKABLE QString loadInfo() const;

        //loads info and inserts version to it
        Q_INVOKABLE QString loadInfo(const QString& insertVersion) const;
    };

    QObject* infoLoaderProvider(class QQmlEngine* engine, class QJSEngine* scriptEngine);
}

#endif // SOLARINFOLOADER_H
