#ifndef CAMERACONTROLLER_H
#define CAMERACONTROLLER_H

#include <Qt3DCore/QEntity>
#include <QVector3D>

//forward
namespace Qt3DRender
{
    class QCamera;
}

namespace Qt3DLogic
{
    class QFrameAction;
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
        ~CameraController();

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
        Qt3DRender::QCamera* viewCamera = nullptr;

        //tick component
        Qt3DLogic::QFrameAction* frameAction;

        //logical device
        Qt3DInput::QLogicalDevice* logicalDevice;

        //mouse device
        Qt3DInput::QMouseDevice* mouseDevice;

        //input fields
        Qt3DInput::QAction* rightMouseButtonAction;
        Qt3DInput::QActionInput* rightMouseButtonInput;
        Qt3DInput::QAxis* mouseX_Axis;
        Qt3DInput::QAxis* mouseY_Axis;
        Qt3DInput::QAnalogAxisInput* mouseX_Input;
        Qt3DInput::QAnalogAxisInput* mouseY_Input;

        //wheel
        Qt3DInput::QAnalogAxisInput* mouseWheelX_Input;
        Qt3DInput::QAnalogAxisInput* mouseWheelY_Input;
        Qt3DInput::QAxis* mouseWheelX_Axis;
        Qt3DInput::QAxis* mouseWheelY_Axis;

        //values
        float lookSpeedValue = 180.0f;
        float defaultZoomLimitValue = 200000.0f;
        float defaultZoomSpeedValue = 5000000.0f;
        float zoomLimitValue = defaultZoomLimitValue;
        float zoomOutLimitValue = zoomLimitValue;
        float zoomSpeedValue = defaultZoomSpeedValue;

        //up
        QVector3D cameraUp = QVector3D(0.0f, 1.0f, 0.0f);

    private slots:

        //update camera
        void onFrameAction(float deltaTime);

    public slots:

        //camera view center update
        void changeViewCenter(QVector3D center);
    };
}

#endif // CAMERACONTROLLER_H
