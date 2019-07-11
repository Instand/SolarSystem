#ifndef SOLARENTITY_H
#define SOLARENTITY_H

#include <QDateTime>

#include <Qt3DLogic/QFrameAction>
#include <Qt3DRender/QTexture>
#include <Qt3DInput/QInputSettings>
#include <Qt3DRender/QCamera>
#include <Qt3DCore/QEntity>

#include <solarsystemcore.h>

#include <Core/animator.h>

#include <Scene/fpscounter.h>

namespace SolarSystem
{
    class Object3DContainer;
    class Animator;
    class IFrameGraph;

    // represents chain of solar objects (root entity),
    // mediator for objects and QML/C++ code connector
    class SolarEntity : public Qt3DCore::QEntity
    {
        Q_OBJECT

        Q_PROPERTY(FpsCounter* counter READ counter)

        Q_PROPERTY(QString currentObjectString READ currentObjectString NOTIFY currentObjectStringChanged)
        Q_PROPERTY(double extraSpeed READ extraSpeed NOTIFY extraSpeedChanged)
        Q_PROPERTY(QDateTime time READ time NOTIFY timeChanged)
        Q_PROPERTY(bool databaseStatus READ databaseStatus)
        Q_PROPERTY(QString info READ info)

    public:
        explicit SolarEntity(QNode* parent = nullptr);
        ~SolarEntity() = default;

        Qt3DRender::QCamera* camera() const;
        FpsCounter* counter() const;
        bool databaseStatus() const;

        QDateTime time() const;
        QString currentObjectString() const;
        QString info() const;
        double extraSpeed() const;

        // mobile touch support by QML
        Q_INVOKABLE bool isAnimated() const;
        Q_INVOKABLE void setCameraControllerEnabled(bool state);
        Q_INVOKABLE void zoomCamera(float value);

    signals:
        void timeChanged(const QDateTime&);
        void currentObjectStringChanged(const QString&);
        void extraSpeedChanged(double);

    public slots:

        // sets current solar speed, in percents
        void setSolarSpeed(int value);

        // sets current planets size, in percents
        void setSolarSize(int value);

        // sets camera view center by ui planet index
        void setViewCenter(int index);

        // sets event source to qt3d input settings
        void setEventSource(QObject* object);

        void changeExtraSpeed();
        void resetExtraSpeed();

    private slots:
        void onAnimatedObjectChanged(SolarObjects object);

    private:
        Qt3DRender::QCamera* m_camera;
        Qt3DLogic::QFrameAction* m_rootAction;
        Qt3DInput::QInputSettings* m_inputSettings;

        Object3DContainer* m_object3DContainer;
        Animator* m_animator;
        FpsCounter* m_fpsCounter;
        IFrameGraph* m_frameGraph;
    };
}

#endif // SOLARENTITY_H
