import Qt3D.Core 2.0
import Qt3D.Extras 2.0
import SolarSystem 1.0
import QtQml 2.2

// QML/C++ code connection
Entity {
    id: rootEntity

    property alias entity: solarSystem
    property alias counter: solarSystem.counter

    SolarEntity {
        id: solarSystem
    }

    function dbState() {
        return solarSystem.databaseStatus ? "Ok" : "Failured";
    }
}
