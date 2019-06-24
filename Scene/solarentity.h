#ifndef SOLARENTITY_H
#define SOLARENTITY_H

#include <Qt3DLogic/QFrameAction>
#include <Qt3DRender/QTexture>
#include <Qt3DInput/QInputSettings>
#include <Qt3DRender/QCamera>
#include <Qt3DCore/QEntity>

#include <solarsystemcore.h>

#include <Core/solaranimator.h>

#include <Scene/fpscounter.h>

namespace SolarSystem
{
    class SolarSkyBox;
    class Object3DContainer;
    class SolarAnimator;
    class IFrameGraph;

    // represents chain of solar objects (root entity)
    class SolarEntity : public Qt3DCore::QEntity
    {
        Q_OBJECT

        Q_PROPERTY(SolarAnimator* animator READ animator)
        Q_PROPERTY(FpsCounter* counter READ counter)
        Q_PROPERTY(Qt3DInput::QInputSettings* inputSettings READ inputSettings)
        Q_PROPERTY(bool databaseStatus READ databaseStatus)

        Q_PROPERTY(QDateTime time READ time NOTIFY timeChanged)

    public:
        explicit SolarEntity(QNode* parent = nullptr);
        ~SolarEntity() = default;

        SolarAnimator* animator() const;
        Qt3DRender::QCamera* camera() const;
        Qt3DInput::QInputSettings* inputSettings() const;
        FpsCounter* counter() const;
        bool databaseStatus() const;

        QDateTime time() const;

    signals:
        void timeChanged(const QDateTime&);

    private:
        Qt3DRender::QCamera* m_camera;
        Qt3DLogic::QFrameAction* m_rootAction;
        Qt3DInput::QInputSettings* m_inputSettings;

        Object3DContainer* m_object3DContainer;
        SolarAnimator* m_animator;
        FpsCounter* m_fpsCounter;
        IFrameGraph* m_frameGraph;
        SolarSkyBox* m_skybox;
    };
}

#endif // SOLARENTITY_H
