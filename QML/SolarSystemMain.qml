import QtQuick 2.6
import QtQuick.Scene3D 2.0
import QtQuick.Controls 2.1

Item {
    width: 1280
    height: 700

    Keys.onPressed: {
        scene.focus = true;
    }

    //planet list show flag
    property bool showPlanetList: false

    //3d viewport
    Scene3D {
        id: scene
        anchors.fill: parent
        aspects: ["render", "logic", "input"]
        focus: true

        //from c++ code
        SolarEntityMain {
            id: solarSystem
        }
    }

    //slider frame
    SolarFrame {
        anchors.right: parent.right
        anchors.verticalCenter: parent.verticalCenter
        anchors.rightMargin: 5
        height: 400
        width: 50
        radius: 4

        Slider {
            id: speedSlider
            orientation: Qt.Vertical
            anchors.fill: parent
            from: 0
            to: 100
            value: 50
            onValueChanged: {
                solarSystem.animator.setSolarSpeed(value);
            }
        }
    }

    //date label
    SolarFrame {
        anchors.top: parent.top
        anchors.horizontalCenter: parent.horizontalCenter
        anchors.topMargin: 5
        radius: 4
        width: 200
        height: 50

        DateText {
            id: timeLabel
            text: "Actual time"
            anchors.top: parent.top
            anchors.horizontalCenter: parent.horizontalCenter
        }

        //show current solar time
        DateText {
            id: solarTime
            anchors.top: timeLabel.bottom

            //show time to label
            function showTime() {
                var solarDate = solarSystem.solarDate;
                var hours = solarDate.getUTCHours();
                var minutes = solarDate.getUTCMinutes();
                var days  = solarDate.getUTCDate();
                var month = solarDate.getUTCMonth() + 1;
                var year = solarDate.getUTCFullYear();

                var str = "";

                if (hours.toString().length == 1)
                    str += "0"

                str += hours.toString()
                str += ":"

                if (minutes.toString().length == 1)
                    str += "0"

                str += minutes.toString()
                str += " "

                if (days.toString().length == 1)
                    str += " "

                str += days.toString()
                str += "/"

                if (month.toString().length == 1)
                    str += "0"

                str += month.toString()
                str += "/"
                str += year.toString()

                return str
            }

            text: showTime()
        }
    }

    //left side controls
    Controls {
        anchors.verticalCenter: parent.verticalCenter
        anchors.left: parent.left
        anchors.leftMargin: 5
        elementWidth: 80
        elementHeght: 100

        //slot
        onPlanetButtonClicked: {
            showPlanetList = !showPlanetList;

            if (showPlanetList)
                planetsList.visible = true
            else
                planetsList.visible = false
        }
    }

    //planets icons
    SolarFrame {
        id: planetsList
        anchors.bottom: parent.bottom
        anchors.left: parent.left
        anchors.right: parent.right
        height: 100
        anchors.leftMargin: 5
        anchors.bottomMargin: 10
        anchors.rightMargin: 5
        radius: 4
        visible: false

        //all planets
        PlanetList {
            id: planetsView
            anchors.fill: parent
            buttonSize: height - 5
        }
    }
}
