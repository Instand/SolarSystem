#ifndef CAMERACONTROLLER_H
#define CAMERACONTROLLER_H

#include <Qt3DCore/QEntity>
#include <QVector3D>

#include <solarsystemcore.h>

//forward
namespace Qt3DRender
{
    class QCamera;
}

namespace Qt3DInput
{
    class QLogicalDevice;
    class QMouseDevice;
    class QAction;
    class QActionInput;
    class QAxis;
    class QAnalogAxisInput;
}

namespace SolarSystem
{
    //view controll
    class CameraController : public Qt3DCore::QEntity
    {
        Q_OBJECT

    public:
        explicit CameraController(Qt3DCore::QNode* parent = nullptr);

        //camera setup
        void setCamera(Qt3DRender::QCamera* camera);
        Qt3DRender::QCamera* camera() const;

        void setLookSpeed(float lookSpeed);
        float lookSpeed() const;

        void setZoomLimit(float limit);
        float zoomLimit() const;

        void setZoomSpeed(float zoomSpeed);
        float zoomSpeed() const;

        void setDefaultZoomLimit();
        float defaultZoomLimit() const;

        void setDefaultZoomSpeed();
        float defaultZoomSpeed() const;

    private:

        //camera ref
        Qt3DRender::QCamera* m_viewCamera = nullptr;

        //logical device
        Qt3DInput::QLogicalDevice* m_logicalDevice;

        //mouse device
        Qt3DInput::QMouseDevice* m_mouseDevice;

        //input fields
        Qt3DInput::QAction* m_mouseButtonAction;
        Qt3DInput::QActionInput* m_mouseButtonInput;
        Qt3DInput::QAxis* m_mouseXAxis;
        Qt3DInput::QAxis* m_mouseYAxis;
        Qt3DInput::QAnalogAxisInput* m_mouseXInput;
        Qt3DInput::QAnalogAxisInput* m_mouseYInput;

        //wheel
        Qt3DInput::QAnalogAxisInput* m_mouseWheelXInput;
        Qt3DInput::QAnalogAxisInput* mouseWheelYInput;
        Qt3DInput::QAxis* m_mouseWheelXAxis;
        Qt3DInput::QAxis* m_mouseWheelYAxis;

        //values
        float m_lookSpeedValue = 180.0f;
        float m_defaultZoomLimitValue = modified<float>(200000.0f);
        float m_defaultZoomSpeedValue = modified<float>(5000000.0f);
        float m_zoomLimitValue = m_defaultZoomLimitValue;
        float m_zoomOutLimitValue = m_zoomLimitValue;
        float m_zoomSpeedValue = m_defaultZoomSpeedValue;

        //up
        QVector3D m_cameraUp = QVector3D(0.0f, 1.0f, 0.0f);

    private slots:

        //update camera
        void onFrameAction(float deltaTime);

    public slots:

        //camera view center update
        void changeViewCenter(const QVector3D& center);
    };
}

#endif // CAMERACONTROLLER_H
