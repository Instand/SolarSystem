#include "animator.h"

#include <Qt3DRender/QCamera>

#include <QPropertyAnimation>
#include <QParallelAnimationGroup>

#include <Core/mathcore.h>
#include <Core/cameracontroller.h>

#include <Parser/solarparser.h>

SolarSystem::Animator::Animator(QObject* parent):
    QObject(parent)
{
    m_viewCenterAnimation = new QPropertyAnimation(this);
    m_viewPositionAnimation = new QPropertyAnimation(this);
    m_solarSpeedAnimation = new QPropertyAnimation(this);
    m_cameraAnimation = new QParallelAnimationGroup(this);

    m_viewCenterAnimation->setEasingCurve(QEasingCurve(QEasingCurve::InOutQuint));
    m_viewPositionAnimation->setEasingCurve(QEasingCurve(QEasingCurve::InOutQuint));
    m_solarSpeedAnimation->setEasingCurve(QEasingCurve(QEasingCurve::InExpo));

    m_cameraAnimation->addAnimation(m_viewCenterAnimation);
    m_cameraAnimation->addAnimation(m_viewPositionAnimation);

    // animation actions
    QObject::connect(m_cameraAnimation, &QParallelAnimationGroup::finished, this, &Animator::onAnimationFinished);
    QObject::connect(m_solarSpeedAnimation, &QPropertyAnimation::finished, this, &Animator::onSpeedAnimationFinished);
}

SolarSystem::SolarObjects SolarSystem::Animator::currentObject() const
{
    return m_currentSolarObject;
}

void SolarSystem::Animator::animate(float deltaTime)
{
    if (!m_animated)
    {
        MathCore::instance()->calculate(deltaTime, m_currentSolarObject);
        emit solarTimeChanged(MathCore::instance()->getTime());
    }
}

void SolarSystem::Animator::setCameraViewCenter(int index)
{
    if (!m_animated)
    {
        auto obj = SolarParser::parsePlanetListIndex(index);

        if (obj != m_currentSolarObject)
        {
            m_currentSolarObject = obj;
            m_solarSpeed = MathCore::instance()->solarSystemSpeed();

            // top speed animation
            if (m_solarSpeedAnimation->state() == QAbstractAnimation::State::Running)
                m_solarSpeedAnimation->stop();

            // object for animation changed
            emit currentObjectChanged(m_currentSolarObject);

            MathCore::instance()->setSolarSystemSpeed(0);
            MathCore::instance()->updateSolarViewZoomLimit(m_currentSolarObject);

            m_animated = true;

            auto camera = MathCore::instance()->solarView();

            // setup view animation
            m_viewCenterAnimation->setTargetObject(camera);
            m_viewCenterAnimation->setPropertyName("viewCenter");
            m_viewCenterAnimation->setDuration(1500);
            m_viewCenterAnimation->setStartValue(camera->viewCenter());
            m_viewCenterAnimation->setEndValue(MathCore::instance()->objectPosition(m_currentSolarObject));

            m_viewPositionAnimation->setTargetObject(camera);
            m_viewPositionAnimation->setPropertyName("position");
            m_viewPositionAnimation->setStartValue(camera->position());

            if (obj != SolarObjects::SolarSystemView)
            {
                m_viewPositionAnimation->setDuration(2500);
                m_viewPositionAnimation->setEndValue(MathCore::instance()->viewPositionOfObject(m_currentSolarObject));
            }
            else
            {
                m_viewCenterAnimation->setDuration(3000);

                m_viewPositionAnimation->setDuration(2500);
                m_viewPositionAnimation->setEndValue(CameraSettings::defaultCameraPosition);
            }

            MathCore::instance()->viewController()->setEnabled(false);

            m_cameraAnimation->start();
        }
    }
}

void SolarSystem::Animator::onAnimationFinished()
{
    // speed animation
    m_solarSpeedAnimation->setTargetObject(MathCore::instance());
    m_solarSpeedAnimation->setPropertyName("solarSystemSpeed");
    m_solarSpeedAnimation->setDuration(60);
    m_solarSpeedAnimation->setStartValue(0);
    m_solarSpeedAnimation->setEndValue(m_solarSpeed);
    m_solarSpeedAnimation->start();

    MathCore::instance()->viewController()->setEnabled(true);
}

void SolarSystem::Animator::onSpeedAnimationFinished()
{
    m_animated = false;
}
