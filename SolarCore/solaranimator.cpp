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
    mathCorePtr = new SolarMathCore();
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
    delete mathCorePtr;
}

SolarSystem::ISolarMathCore *SolarSystem::SolarAnimator::mathCore() const
{
    return mathCorePtr;
}

QDateTime SolarSystem::SolarAnimator::solarTime() const
{
    return mathCorePtr->getTime();
}

QString SolarSystem::SolarAnimator::viewSolarObjectString() const
{
    return solarObjStr;
}

QVector3D SolarSystem::SolarAnimator::cameraViewCenter() const
{
    return mathCorePtr->viewCenter();
}

QVector3D SolarSystem::SolarAnimator::cameraPosition() const
{
    return mathCorePtr->viewPosition();
}

float SolarSystem::SolarAnimator::solarSystemSpeed() const
{
    return mathCorePtr->solarSystemSpeed();
}

double SolarSystem::SolarAnimator::solarSystemExtraSpeed() const
{
    return mathCorePtr->extraSpeed();
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
    mathCorePtr->changeSolarObjectsSpeed(SolarSystem::SolarValues::startSpeed);
    mathCorePtr->changeSolarSystemScale(SolarSystem::SolarValues::startSize);
}

void SolarSystem::SolarAnimator::animate(float deltaTime)
{
    if (!animated)
    {
        //set delta time to math core
        mathCorePtr->setDeltaTime(deltaTime);

        //calculate time
        mathCorePtr->advanceTime(currentSolarObject);

        //update solar objects position
        mathCorePtr->calculateAllSolarObjectsPosiitons();

        //additional calculations
        mathCorePtr->additionalCalculation();

        //view on solar object
        mathCorePtr->updateSolarView(currentSolarObject);

        emit solarTimeChanged(mathCorePtr->getTime());
    }
}

void SolarSystem::SolarAnimator::setSolarSpeed(int value)
{
    auto coeff = 0.02f * value;
    mathCorePtr->changeSolarObjectsSpeed(SolarValues::startSpeed * coeff);
}

void SolarSystem::SolarAnimator::setSolarSize(int value)
{
    float coeff = value/50.0f;
    mathCorePtr->changeSolarSystemScale(SolarValues::startSize * coeff);
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
            solarSpeed = mathCorePtr->solarSystemSpeed();

            //stop speed animation
            if (solarSpeedAnimation->state() == QAbstractAnimation::State::Running)
                solarSpeedAnimation->stop();

            //reset solar system speed
            mathCorePtr->changeSolarObjectsSpeed(0);

            emit solarObjectStringChanged(solarObjStr);

            mathCorePtr->updateSolarViewZoomLimit(currentSolarObject);

            animated = true;

            //setup view animation
            viewCenterAnimation->setPropertyName("viewCenter");
            viewCenterAnimation->setDuration(1500);
            viewCenterAnimation->setStartValue(mathCorePtr->viewCenter());
            viewCenterAnimation->setEndValue(mathCorePtr->objectPosition(currentSolarObject));

            viewPositionAnimation->setPropertyName("viewPosition");
            viewPositionAnimation->setStartValue(mathCorePtr->viewPosition());

            if (obj != SolarObjects::SolarSystemView)
            {
                viewPositionAnimation->setDuration(2500);
                viewPositionAnimation->setEndValue(mathCorePtr->viewPositionOfObject(currentSolarObject));
            }
            else
            {
                viewCenterAnimation->setDuration(3000);

                viewPositionAnimation->setDuration(2500);
                viewPositionAnimation->setEndValue(mathCorePtr->solarViewStartPositon());
            }

            cameraAnimation->start();
        }
    }
}

void SolarSystem::SolarAnimator::setCameraViewCenter(QVector3D position)
{
    mathCorePtr->setSolarViewCenter(position);

    emit cameraViewCenterChanged(position);
}

void SolarSystem::SolarAnimator::setCameraPositon(QVector3D position)
{
    mathCorePtr->setSolarViewPosition(position);

    emit cameraPositionChanged(position);
}

void SolarSystem::SolarAnimator::setSolarSystemSpeed(float speed)
{
    mathCorePtr->changeSolarObjectsSpeed(speed);

    emit solarSystemSpeedChanged(speed);
}

void SolarSystem::SolarAnimator::changeExtraSpeed()
{
    mathCorePtr->changeExtraSpeed();

    emit extraSpeedChanged(mathCorePtr->extraSpeed());
}

void SolarSystem::SolarAnimator::resetExtraSpeed()
{
    mathCorePtr->resetExtraSpeed();

    emit extraSpeedChanged(mathCorePtr->extraSpeed());
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
