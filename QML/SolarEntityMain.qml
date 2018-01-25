import Qt3D.Core 2.0
import Qt3D.Extras 2.0
import SolarSystem 1.0
import QtQml 2.2

//QML/C++ code connection
Entity {
    id: rootEntity

    //Solar Animator ref
    property alias animator: solarSystem.animator

    //Solar time ref
    property date solarDate: animator.solarTime

    //Input settings ref
    property alias inputSettings: solarSystem.inputSettings

    //Counter ref
    property alias counter: solarSystem.counter

    //solar system
    SolarEntity {
        id: solarSystem
    }

    function dbState() {
        if (solarSystem.databaseStatus)
            return "Ok"
        else
            return "Failured"
    }
}
