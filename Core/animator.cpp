#include "animator.h"

#include <Qt3DRender/QCamera>
#include <Qt3DCore/QTransform>

#include <QPropertyAnimation>
#include <QParallelAnimationGroup>

#include <Core/mathcore.h>
#include <Core/cameracontroller.h>

#include <Core/utils.h>

SolarSystem::Animator::Animator(QObject* parent):
    QObject(parent)
{
}

SolarSystem::SolarObjects SolarSystem::Animator::currentObject() const
{
    return m_currentSolarObject;
}

void SolarSystem::Animator::animate(float deltaTime)
{
    if (m_animated)
    {
        checkAnimation();
        animation(deltaTime);
    }

    MathCore::instance()->calculate(deltaTime, m_currentSolarObject);
}

void SolarSystem::Animator::animateCamera(SolarObjects object)
{
    if (object != m_currentSolarObject)
    {
        m_currentSolarObject = object;

        // object for animation changed
        emit currentObjectChanged(m_currentSolarObject);

        MathCore::instance()->cameraController()->setEnabled(false);
        MathCore::instance()->updateSolarViewZoomLimit(m_currentSolarObject);

        m_animated = true;
    }
}

void SolarSystem::Animator::onAnimationFinished()
{
    MathCore::instance()->cameraController()->setEnabled(true);
    m_animated = false;
}

void SolarSystem::Animator::animation(float deltaTime)
{
    static constexpr float positionSpeed = 1.25f;
    static constexpr float viewSpeed = 1.35f;

    static constexpr float defaultCameraRoll = 0.0f;
    static constexpr float cameraAngleThreshold = 30.0f;

    auto camera = MathCore::instance()->camera();
    auto object = m_currentSolarObject != SolarObjects::SolarSystemView ? m_currentSolarObject : SolarObjects::Sun;

    // animate view
    auto center = MathCore::instance()->objectPosition(m_currentSolarObject);
    camera->setViewCenter(Utils::lerp(camera->viewCenter(), center, deltaTime * viewSpeed));

    // correct roll
    const auto roll = camera->transform()->rotationZ();
    camera->rollAboutViewCenter(defaultCameraRoll - roll);

    if (m_currentSolarObject != SolarObjects::SolarSystemView)
    {
        if (!MathCore::instance()->checkAngleThreshold(object, cameraAngleThreshold))
            return;
    }

    // animate position
    auto position = MathCore::instance()->viewPositionOfObject(m_currentSolarObject);
    camera->setPosition(Utils::lerp(camera->position(), position, deltaTime * positionSpeed));
}

void SolarSystem::Animator::checkAnimation()
{
    static constexpr float cameraAngleThreshold = 3.5f;

    bool result = m_currentSolarObject == SolarObjects::SolarSystemView || m_currentSolarObject == SolarObjects::Sun;
    const float coeff = !result ? 1.05f : 1.15f;

    auto camera = MathCore::instance()->camera();
    auto position = (m_currentSolarObject != SolarObjects::SolarSystemView) ?
                MathCore::instance()->objectPosition(m_currentSolarObject) : CameraSettings::defaultCameraPosition;

    auto needDistance = (MathCore::instance()->viewPositionOfObject(m_currentSolarObject) - position).length();
    auto currentDistance = (camera->position() - position).length();

    auto object = m_currentSolarObject != SolarObjects::SolarSystemView ? m_currentSolarObject : SolarObjects::Sun;
    auto angleResult = MathCore::instance()->checkAngleThreshold(object, cameraAngleThreshold);

    if (m_currentSolarObject == SolarObjects::SolarSystemView)
        needDistance += coeff + 2.0f;

    if (currentDistance/coeff <= needDistance && angleResult)
        onAnimationFinished();
}
