import QtQuick 2.0
import QtQuick.Scene3D 2.0
import QtQuick.Controls 2.1

Item {
    width: 1280
    height: 640

    Scene3D {
        id: scene
        anchors.fill: parent
        aspects: ["render", "logic", "input"]
        focus: true

        SolarEntityMain {
            id: solarSystem
        }
    }

    MouseArea {
        anchors.fill: parent
        onClicked: {
            scene.focus = true
        }
    }

    Slider {
        orientation: Qt.Vertical
        anchors.right: parent.right
        height: 500
    }
}
