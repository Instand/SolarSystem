#include "solaranimator.h"
#include <dbconnector.h>
#include <SolarCore/mathcore.h>
#include <SolarCore/cameracontroller.h>
#include <Parser/solarparser.h>
#include <QPropertyAnimation>
#include <QParallelAnimationGroup>
#include <QTimer>
#include <Qt3DRender/QCamera>

SolarSystem::SolarAnimator::SolarAnimator(QObject* parent):
    QObject(parent)
{
    m_viewCenterAnimation = new QPropertyAnimation(this);
    m_viewPositionAnimation = new QPropertyAnimation(this);
    m_solarSpeedAnimation = new QPropertyAnimation(this);
    m_cameraAnimation = new QParallelAnimationGroup(this);

    m_viewCenterAnimation->setTargetObject(this);
    m_viewCenterAnimation->setEasingCurve(QEasingCurve(QEasingCurve::InOutQuint));

    m_viewPositionAnimation->setTargetObject(this);
    m_viewPositionAnimation->setEasingCurve(QEasingCurve(QEasingCurve::InOutQuint));

    m_solarSpeedAnimation->setTargetObject(this);
    m_solarSpeedAnimation->setEasingCurve(QEasingCurve(QEasingCurve::InExpo));

    m_cameraAnimation->addAnimation(m_viewCenterAnimation);
    m_cameraAnimation->addAnimation(m_viewPositionAnimation);

    // wrapper
    QObject::connect(MathCore::instance()->solarView(), &Qt3DRender::QCamera::positionChanged, this, &SolarAnimator::cameraPositionChanged);
    QObject::connect(MathCore::instance()->solarView(), &Qt3DRender::QCamera::viewCenterChanged, this, &SolarAnimator::cameraViewCenterChanged);

    // animation actions
    QObject::connect(m_cameraAnimation, &QParallelAnimationGroup::finished, this, &SolarAnimator::onAnimationFinished);
    QObject::connect(m_solarSpeedAnimation, &QPropertyAnimation::finished, this, &SolarAnimator::onSpeedAnimationFinished);
}

QString SolarSystem::SolarAnimator::viewSolarObjectString() const
{
    return m_solarObjStr;
}

QVector3D SolarSystem::SolarAnimator::cameraViewCenter() const
{
    return MathCore::instance()->solarView()->viewCenter();
}

QVector3D SolarSystem::SolarAnimator::cameraPosition() const
{
    return MathCore::instance()->solarView()->position();
}

float SolarSystem::SolarAnimator::solarSystemSpeed() const
{
    return MathCore::instance()->solarSystemSpeed();
}

double SolarSystem::SolarAnimator::solarSystemExtraSpeed() const
{
    return MathCore::instance()->extraSpeed();
}

QString SolarSystem::SolarAnimator::info() const
{
    auto columnNames = DBConnector::instance().columnNames();
    auto objParameters = DBConnector::instance().info(m_currentSolarObject);
    auto dbFieldsParamsCount = DbParams::paramList.size();
    auto str = QString();

    if (columnNames.size() != objParameters.size() || columnNames.size() != dbFieldsParamsCount
            || dbFieldsParamsCount != objParameters.size())
    {
        qDebug() << "Something wrong in DB connector";
        qDebug() << columnNames.size() << " != " << objParameters.size();
        return str;
    }

    // fill info sheet
    for (int i = 0; i < columnNames.size(); ++i)
        str.append(columnNames[i] + ":  " + objParameters[i] + " " + DbParams::paramList[i] + "\n\n");

    return str;
}

void SolarSystem::SolarAnimator::animate(float deltaTime)
{
    if (!m_animated)
    {
        // set delta time to math core
        MathCore::instance()->setDeltaTime(deltaTime);

        // calculate time
        MathCore::instance()->advanceTime(m_currentSolarObject);

        // update solar objects position
        MathCore::instance()->calculateAllSolarObjectsPosiitons();

        // additional calculations
        MathCore::instance()->additionalCalculation();

        // view on solar object
        MathCore::instance()->updateSolarView(m_currentSolarObject);

        emit solarTimeChanged(MathCore::instance()->getTime());
    }
}

void SolarSystem::SolarAnimator::setSolarSpeed(int value)
{
    auto coeff = 0.02f * value;
    MathCore::instance()->setSolarSystemSpeed(SolarValues::startSpeed * coeff);
}

void SolarSystem::SolarAnimator::setSolarSize(int value)
{
    float coeff = value/50.0f;
    MathCore::instance()->changeSolarSystemScale(SolarValues::startSize * coeff);
}

void SolarSystem::SolarAnimator::setCameraViewCenter(int index)
{
    if (!m_animated)
    {
        auto obj = SolarParser::parsePlanetListIndex(index);

        if (obj != m_currentSolarObject)
        {
            m_currentSolarObject = obj;
            m_solarObjStr = SolarParser::parseSolarObjectToString(m_currentSolarObject);

            m_solarSpeed = MathCore::instance()->solarSystemSpeed();

            //s top speed animation
            if (m_solarSpeedAnimation->state() == QAbstractAnimation::State::Running)
                m_solarSpeedAnimation->stop();

            // reset solar system speed
            MathCore::instance()->setSolarSystemSpeed(0);

            emit solarObjectStringChanged(m_solarObjStr);

            MathCore::instance()->updateSolarViewZoomLimit(m_currentSolarObject);

            m_animated = true;

            // setup view animation
            m_viewCenterAnimation->setPropertyName("viewCenter");
            m_viewCenterAnimation->setDuration(1500);
            m_viewCenterAnimation->setStartValue(MathCore::instance()->solarView()->viewCenter());
            m_viewCenterAnimation->setEndValue(MathCore::instance()->objectPosition(m_currentSolarObject));

            m_viewPositionAnimation->setPropertyName("viewPosition");
            m_viewPositionAnimation->setStartValue(MathCore::instance()->solarView()->position());

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

            // stop controller
            MathCore::instance()->viewController()->setEnabled(false);

            m_cameraAnimation->start();
        }
    }
}

void SolarSystem::SolarAnimator::setCameraViewCenter(const QVector3D& position)
{
    MathCore::instance()->solarView()->setViewCenter(position);
}

void SolarSystem::SolarAnimator::setCameraPositon(const QVector3D& position)
{
    MathCore::instance()->solarView()->setPosition(position);
}

void SolarSystem::SolarAnimator::setSolarSystemSpeed(float speed)
{
    MathCore::instance()->setSolarSystemSpeed(speed);

    emit solarSystemSpeedChanged(speed);
}

void SolarSystem::SolarAnimator::changeExtraSpeed()
{
    MathCore::instance()->changeExtraSpeed();

    emit extraSpeedChanged(MathCore::instance()->extraSpeed());
}

void SolarSystem::SolarAnimator::resetExtraSpeed()
{
    MathCore::instance()->resetExtraSpeed();

    emit extraSpeedChanged(MathCore::instance()->extraSpeed());
}

void SolarSystem::SolarAnimator::onAnimationFinished()
{
    // speed animation
    m_solarSpeedAnimation->setPropertyName("solarSystemSpeed");
    m_solarSpeedAnimation->setDuration(60);
    m_solarSpeedAnimation->setStartValue(0);
    m_solarSpeedAnimation->setEndValue(m_solarSpeed);
    m_solarSpeedAnimation->start();

    // activate controller
    MathCore::instance()->viewController()->setEnabled(true);
}

void SolarSystem::SolarAnimator::onSpeedAnimationFinished()
{
    m_animated = false;
}
