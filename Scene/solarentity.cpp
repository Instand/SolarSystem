#include "solarentity.h"
#include <Qt3DRender/QFilterKey>
#include <Qt3DExtras/QFirstPersonCameraController>
#include <Qt3DExtras/QOrbitCameraController>

SolarSystem::SolarEntity::SolarEntity(QNode* parent):
    Qt3DCore::QEntity(parent),
    solarAnimator(new SolarAnimator()),
    rootAction(new Qt3DLogic::QFrameAction())
{
    addComponent(rootAction);

    //scene camera setup
    mainCamera = new Qt3DRender::QCamera(this);
    mainCamera->setProjectionType(Qt3DRender::QCameraLens::PerspectiveProjection);
    //_camera->setAspectRatio(width() / height());
    mainCamera->setViewCenter(QVector3D(0.0f, 3.5f, 0.0f));

    mainCamera->setFieldOfView(CameraSettings::fieldOfView);
    mainCamera->setNearPlane(CameraSettings::nearPlane * 0.0001f);
    mainCamera->setFarPlane(CameraSettings::farPlane);
    mainCamera->setUpVector(CameraSettings::defaultUp);
    mainCamera->setPosition(CameraSettings::defaultCameraPosition);

    Qt3DExtras::QFirstPersonCameraController* controller = new Qt3DExtras::QFirstPersonCameraController(this);
    controller->setCamera(mainCamera);
    controller->setLookSpeed(controller->lookSpeed() * 1.5f);
    controller->setLinearSpeed(controller->linearSpeed() * 150000.0f);

    //render
    filter = new Qt3DRender::QTechniqueFilter();

    auto* key = new Qt3DRender::QFilterKey();
    key->setName("renderingStyle");
    key->setValue("forward");
    filter->addMatch(key);

    surfaceSelector = new Qt3DRender::QRenderSurfaceSelector(filter);

    viewPort = new Qt3DRender::QViewport(surfaceSelector);
    viewPort->setNormalizedRect(QRectF(0.0, 0.0, 1.0, 1.0));

    cameraSelector = new Qt3DRender::QCameraSelector(viewPort);

    clearBuffers = new Qt3DRender::QClearBuffers(cameraSelector);
    clearBuffers->setBuffers(Qt3DRender::QClearBuffers::ColorDepthBuffer);
    clearBuffers->setClearColor(QColor(Qt::black));

    sortPolicy = new Qt3DRender::QSortPolicy(clearBuffers);

    QVector<Qt3DRender::QSortPolicy::SortType> sortedVector;
    sortedVector.push_back(Qt3DRender::QSortPolicy::StateChangeCost);
    sortedVector.push_back(Qt3DRender::QSortPolicy::Material);

    sortPolicy->setSortTypes(sortedVector);

    settings = new Qt3DRender::QRenderSettings();
    settings->setActiveFrameGraph(filter);

    input = new Qt3DInput::QInputSettings();

    cameraSelector->setCamera(mainCamera);

    addComponent(settings);
    addComponent(input);

    //create all planets
    PlanetsContainer::initialize(this);

    //math core control
    solarAnimator->mathCore()->setPlanetsContainer(PlanetsContainer::planets());
    solarAnimator->setDefaultValues();

    //animate scene on tick
    QObject::connect(rootAction, &Qt3DLogic::QFrameAction::triggered, solarAnimator, &SolarAnimator::animate);
}

SolarSystem::SolarEntity::~SolarEntity()
{
    PlanetsContainer::destruct();
    delete solarAnimator;
}

SolarSystem::SolarAnimator *SolarSystem::SolarEntity::animator() const
{
    return solarAnimator;
}
