#include "solaranimator.h"
#include <solarsystemdbconnector.h>
#include <SolarCore/solarmathcore.h>
#include <SolarCore/cameracontroller.h>
#include <Parser/solarparser.h>
#include <QPropertyAnimation>
#include <QParallelAnimationGroup>
#include <QTimer>
#include <Qt3DRender/QCamera>

SolarSystem::SolarAnimator::SolarAnimator(QObject* parent):
    QObject(parent)
{
    viewCenterAnimation = new QPropertyAnimation(this);
    viewPositionAnimation = new QPropertyAnimation(this);
    solarSpeedAnimation = new QPropertyAnimation(this);
    cameraAnimation = new QParallelAnimationGroup(this);

    viewCenterAnimation->setTargetObject(this);
    viewCenterAnimation->setEasingCurve(QEasingCurve(QEasingCurve::InOutQuint));

    viewPositionAnimation->setTargetObject(this);
    viewPositionAnimation->setEasingCurve(QEasingCurve(QEasingCurve::InOutQuint));

    solarSpeedAnimation->setTargetObject(this);
    solarSpeedAnimation->setEasingCurve(QEasingCurve(QEasingCurve::InExpo));

    //animation add
    cameraAnimation->addAnimation(viewCenterAnimation);
    cameraAnimation->addAnimation(viewPositionAnimation);

    //wrapper
    QObject::connect(SolarMathCore::instance()->solarView(), &Qt3DRender::QCamera::positionChanged, this, &SolarAnimator::cameraPositionChanged);
    QObject::connect(SolarMathCore::instance()->solarView(), &Qt3DRender::QCamera::viewCenterChanged, this, &SolarAnimator::cameraViewCenterChanged);

    //animation actions
    QObject::connect(cameraAnimation, &QParallelAnimationGroup::finished, this, &SolarAnimator::onAnimationFinished);
    QObject::connect(solarSpeedAnimation, &QPropertyAnimation::finished, this, &SolarAnimator::onSpeedAnimationFinished);
}

QDateTime SolarSystem::SolarAnimator::solarTime() const
{
    return SolarMathCore::instance()->getTime();
}

QString SolarSystem::SolarAnimator::viewSolarObjectString() const
{
    return solarObjStr;
}

QVector3D SolarSystem::SolarAnimator::cameraViewCenter() const
{
    return SolarMathCore::instance()->solarView()->viewCenter();
}

QVector3D SolarSystem::SolarAnimator::cameraPosition() const
{
    return SolarMathCore::instance()->solarView()->position();
}

float SolarSystem::SolarAnimator::solarSystemSpeed() const
{
    return SolarMathCore::instance()->solarSystemSpeed();
}

double SolarSystem::SolarAnimator::solarSystemExtraSpeed() const
{
    return SolarMathCore::instance()->extraSpeed();
}

QString SolarSystem::SolarAnimator::info() const
{
    auto columnNames = SolarSystemDBConnector::instance().columnNames();
    auto objParameters = SolarSystemDBConnector::instance().info(currentSolarObject);
    auto dbFieldsParamsCount = DbParams::paramList.size();
    auto str = QString();

    if (columnNames.size() != objParameters.size() || columnNames.size() != dbFieldsParamsCount
            || dbFieldsParamsCount != objParameters.size())
    {
        qDebug() << "Something wrong in DB connector";
        qDebug() << columnNames.size() << " != " << objParameters.size();
        return str;
    }

    //fill info sheet
    for (int i = 0; i < columnNames.size(); ++i)
        str.append(columnNames[i] + ":  " + objParameters[i] + " " + DbParams::paramList[i] + "\n\n");

    return str;
}

void SolarSystem::SolarAnimator::animate(float deltaTime)
{
    if (!animated)
    {
        //set delta time to math core
        SolarMathCore::instance()->setDeltaTime(deltaTime);

        //calculate time
        SolarMathCore::instance()->advanceTime(currentSolarObject);

        //update solar objects position
        SolarMathCore::instance()->calculateAllSolarObjectsPosiitons();

        //additional calculations
        SolarMathCore::instance()->additionalCalculation();

        //view on solar object
        SolarMathCore::instance()->updateSolarView(currentSolarObject);

        emit solarTimeChanged(SolarMathCore::instance()->getTime());
    }
}

void SolarSystem::SolarAnimator::setSolarSpeed(int value)
{
    auto coeff = 0.02f * value;
    SolarMathCore::instance()->setSolarSystemSpeed(SolarValues::startSpeed * coeff);
}

void SolarSystem::SolarAnimator::setSolarSize(int value)
{
    float coeff = value/50.0f;
    SolarMathCore::instance()->changeSolarSystemScale(SolarValues::startSize * coeff);
}

void SolarSystem::SolarAnimator::setCameraViewCenter(int index)
{
    if (!animated)
    {
        auto obj = SolarParser::parsePlanetListIndex(index);

        if (obj != currentSolarObject)
        {
            currentSolarObject = obj;
            solarObjStr = SolarParser::parseSolarObjectToString(currentSolarObject);

            //save speed
            solarSpeed = SolarMathCore::instance()->solarSystemSpeed();

            //stop speed animation
            if (solarSpeedAnimation->state() == QAbstractAnimation::State::Running)
                solarSpeedAnimation->stop();

            //reset solar system speed
            SolarMathCore::instance()->setSolarSystemSpeed(0);

            emit solarObjectStringChanged(solarObjStr);

            SolarMathCore::instance()->updateSolarViewZoomLimit(currentSolarObject);

            animated = true;

            //setup view animation
            viewCenterAnimation->setPropertyName("viewCenter");
            viewCenterAnimation->setDuration(1500);
            viewCenterAnimation->setStartValue(SolarMathCore::instance()->solarView()->viewCenter());
            viewCenterAnimation->setEndValue(SolarMathCore::instance()->objectPosition(currentSolarObject));

            viewPositionAnimation->setPropertyName("viewPosition");
            viewPositionAnimation->setStartValue(SolarMathCore::instance()->solarView()->position());

            if (obj != SolarObjects::SolarSystemView)
            {
                viewPositionAnimation->setDuration(2500);
                viewPositionAnimation->setEndValue(SolarMathCore::instance()->viewPositionOfObject(currentSolarObject));
            }
            else
            {
                viewCenterAnimation->setDuration(3000);

                viewPositionAnimation->setDuration(2500);
                viewPositionAnimation->setEndValue(CameraSettings::defaultCameraPosition);
            }

            //stop controller
            SolarMathCore::instance()->viewController()->setEnabled(false);

            cameraAnimation->start();
        }
    }
}

void SolarSystem::SolarAnimator::setCameraViewCenter(const QVector3D& position)
{
    SolarMathCore::instance()->solarView()->setViewCenter(position);
}

void SolarSystem::SolarAnimator::setCameraPositon(const QVector3D& position)
{
    SolarMathCore::instance()->solarView()->setPosition(position);
}

void SolarSystem::SolarAnimator::setSolarSystemSpeed(float speed)
{
    SolarMathCore::instance()->setSolarSystemSpeed(speed);

    emit solarSystemSpeedChanged(speed);
}

void SolarSystem::SolarAnimator::changeExtraSpeed()
{
    SolarMathCore::instance()->changeExtraSpeed();

    emit extraSpeedChanged(SolarMathCore::instance()->extraSpeed());
}

void SolarSystem::SolarAnimator::resetExtraSpeed()
{
    SolarMathCore::instance()->resetExtraSpeed();

    emit extraSpeedChanged(SolarMathCore::instance()->extraSpeed());
}

void SolarSystem::SolarAnimator::onAnimationFinished()
{
    //speed animation
    solarSpeedAnimation->setPropertyName("solarSystemSpeed");
    solarSpeedAnimation->setDuration(60);
    solarSpeedAnimation->setStartValue(0);
    solarSpeedAnimation->setEndValue(solarSpeed);
    solarSpeedAnimation->start();

    //activate controller
    SolarMathCore::instance()->viewController()->setEnabled(true);
}

void SolarSystem::SolarAnimator::onSpeedAnimationFinished()
{
    animated = false;
}
