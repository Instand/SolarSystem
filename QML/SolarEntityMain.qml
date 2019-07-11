import QtQml 2.2

import Qt3D.Core 2.0
import Qt3D.Extras 2.0

import SolarSystem 1.0
import SolarSystem.Utils 1.0

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

    // calculates possibility to use zoom by QML
    function zoom(touch1, touch2) {
        const minPitchDistance = 0.05
        const pitchRatio = 0.25

        var touch1Start = Qt.vector2d(touch1.previousX, touch1.previousY)
        var touch2Start = Qt.vector2d(touch2.previousX, touch2.previousY)

        var touch1Position = Qt.vector2d(touch1.x, touch1.y)
        var touch2Position = Qt.vector2d(touch2.x, touch2.y)

        var touchDelta1 = touch1Position.minus(touch1Start)
        var touchDelta2 = touch2Position.minus(touch2Start)

        var pitchDistance = Utils.distance(touch1Position, touch2Position)
        var previousDistance = Utils.distance(touch1Position.minus(touchDelta1), touch2Position.minus(touchDelta2))
        var pitchDistanceDelta = pitchDistance - previousDistance;

        if (Math.abs(pitchDistanceDelta) > minPitchDistance) {
            pitchDistanceDelta *= pitchRatio
        }
        else {
            pitchDistance = 0
            pitchDistanceDelta = 0
        }

        if (Math.abs(pitchDistanceDelta) > 0) {
            solarSystem.zoomCamera(pitchDistanceDelta)
        }
    }
}
