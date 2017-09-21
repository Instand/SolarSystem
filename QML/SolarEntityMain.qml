import Qt3D.Core 2.0
import Qt3D.Extras 2.0
import SolarSystem 1.0

//QML/C++ code connection
Entity {
    id: rootEntity

    //Solar Animator ref
    property alias animator: solarSystem.animator

    //Solar time ref
    property date solarDate: animator.solarTime

    //Input settings ref
    property alias inputSettings: solarSystem.inputSettings

    //solar system
    SolarEntity {
        id: solarSystem
    }
}
