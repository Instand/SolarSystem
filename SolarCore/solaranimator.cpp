#include "solaranimator.h"
#include <solarsystemdbconnector.h>
#include <SolarCore/solarmathcore.h>
#include <Parser/solarparser.h>
#include <QPropertyAnimation>
#include <QParallelAnimationGroup>
#include <QTimer>

SolarSystem::SolarAnimator::SolarAnimator(QObject *parent):
    QObject(parent)
{
    _mathCore = new SolarMathCore();
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

    QObject::connect(cameraAnimation, &QParallelAnimationGroup::finished, this, &SolarAnimator::onAnimationFinished);
    QObject::connect(solarSpeedAnimation, &QPropertyAnimation::finished, this, &SolarAnimator::onSpeedAnimationFinished);
}

SolarSystem::SolarAnimator::~SolarAnimator()
{
    delete _mathCore;
}

SolarSystem::ISolarMathCore *SolarSystem::SolarAnimator::mathCore() const
{
    return _mathCore;
}

QDateTime SolarSystem::SolarAnimator::solarTime() const
{
    return _mathCore->getTime();
}

QString SolarSystem::SolarAnimator::viewSolarObjectString() const
{
    return solarObjStr;
}

QVector3D SolarSystem::SolarAnimator::cameraViewCenter() const
{
    return _mathCore->viewCenter();
}

QVector3D SolarSystem::SolarAnimator::cameraPosition() const
{
    return _mathCore->viewPosition();
}

float SolarSystem::SolarAnimator::solarSystemSpeed() const
{
    return _mathCore->solarSystemSpeed();
}

double SolarSystem::SolarAnimator::solarSystemExtraSpeed() const
{
    return _mathCore->extraSpeed();
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

void SolarSystem::SolarAnimator::setDefaultValues()
{
    _mathCore->changeSolarObjectsSpeed(SolarSystem::SolarValues::startSpeed);
    _mathCore->changeSolarSystemScale(SolarSystem::SolarValues::startSize);
}

void SolarSystem::SolarAnimator::animate(float deltaTime)
{
    if (!animated)
    {
        //set delta time to math core
        _mathCore->setDeltaTime(deltaTime);

        //calculate time
        _mathCore->advanceTime(currentSolarObject);

        //update solar objects position
        _mathCore->calculateAllSolarObjectsPosiitons();

        //additional calculations
        _mathCore->additionalCalculation();

        _mathCore->updateSolarView(currentSolarObject);

        emit solarTimeChanged(_mathCore->getTime());
    }
}

void SolarSystem::SolarAnimator::setSolarSpeed(int value)
{
    //TO DO FIX solar speed
    auto coeff = 0.02f * value;
    _mathCore->changeSolarObjectsSpeed(SolarValues::startSpeed * coeff);
}

void SolarSystem::SolarAnimator::setSolarSize(int value)
{
    float coeff = value/50.0f;
    _mathCore->changeSolarSystemScale(SolarValues::startSize * coeff);
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
            solarSpeed = _mathCore->solarSystemSpeed();

            //stop speed animation
            if (solarSpeedAnimation->state() == QAbstractAnimation::State::Running)
                solarSpeedAnimation->stop();

            //reset solar system speed
            _mathCore->changeSolarObjectsSpeed(0);

            emit solarObjectStringChanged(solarObjStr);

            _mathCore->updateSolarViewZoomLimit(currentSolarObject);

            animated = true;

            //setup view animation
            viewCenterAnimation->setPropertyName("viewCenter");
            viewCenterAnimation->setDuration(1500);
            viewCenterAnimation->setStartValue(_mathCore->viewCenter());
            viewCenterAnimation->setEndValue(_mathCore->objectPosition(currentSolarObject));

            viewPositionAnimation->setPropertyName("viewPosition");
            viewPositionAnimation->setStartValue(_mathCore->viewPosition());

            if (obj != SolarObjects::SolarSystemView)
            {
                //setup position animation
                viewPositionAnimation->setDuration(2500);
                viewPositionAnimation->setEndValue(_mathCore->viewPositionOfObject(currentSolarObject));
            }
            else
            {
                //setup position animation
                viewCenterAnimation->setDuration(3000);

                viewPositionAnimation->setDuration(2500);
                viewPositionAnimation->setEndValue(_mathCore->solarViewStartPositon());
            }

            cameraAnimation->start();
        }
    }
}

void SolarSystem::SolarAnimator::setCameraViewCenter(QVector3D position)
{
    _mathCore->setSolarViewCenter(position);

    emit cameraViewCenterChanged(position);
}

void SolarSystem::SolarAnimator::setCameraPositon(QVector3D position)
{
    _mathCore->setSolarViewPosition(position);

    emit cameraPositionChanged(position);
}

void SolarSystem::SolarAnimator::setSolarSystemSpeed(float speed)
{
    _mathCore->changeSolarObjectsSpeed(speed);

    emit solarSystemSpeedChanged(speed);
}

void SolarSystem::SolarAnimator::changeExtraSpeed()
{
    _mathCore->changeExtraSpeed();

    emit extraSpeedChanged(_mathCore->extraSpeed());
}

void SolarSystem::SolarAnimator::resetExtraSpeed()
{
    _mathCore->resetExtraSpeed();

    emit extraSpeedChanged(_mathCore->extraSpeed());
}

void SolarSystem::SolarAnimator::onAnimationFinished()
{
    //speed animation
    solarSpeedAnimation->setPropertyName("solarSystemSpeed");
    solarSpeedAnimation->setDuration(60);
    solarSpeedAnimation->setStartValue(0);
    solarSpeedAnimation->setEndValue(solarSpeed);
    solarSpeedAnimation->start();
}

void SolarSystem::SolarAnimator::onSpeedAnimationFinished()
{
    animated = false;
}
