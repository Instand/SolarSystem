#ifndef SOLARLIGHT_H
#define SOLARLIGHT_H

#include <Qt3DCore/QEntity>
#include <QMatrix4x4>

namespace Qt3DRender
{
    class QCamera;
}

namespace SolarSystem
{
    //represents point light
    class SolarLight : public Qt3DCore::QEntity
    {
        Q_OBJECT

    public:
        SolarLight(Qt3DCore::QNode* parent = nullptr);

        //get camera
        Qt3DRender::QCamera* camera() const;

        //PV matrix
        QMatrix4x4 lightViewProjection() const;

        //get intensity
        QVector3D intensity() const;

        //set intensity
        void setIntensity(const QVector3D& intensity);

    private:
        Qt3DRender::QCamera* m_lightCamera;
        QVector3D m_intensity;
    };
}

#endif // SOLARLIGHT_H
