import QtQuick 2.0
import QtQuick.Scene3D 2.0
import QtQuick.Controls 2.1

Item {
    width: 1280
    height: 640

    Keys.onPressed: {
        scene.focus = true;
    }

    Scene3D {
        id: scene
        anchors.fill: parent
        aspects: ["render", "logic", "input"]
        focus: true

        SolarEntityMain {
            id: solarSystem
        }
    }

    Slider {
        orientation: Qt.Vertical
        anchors.right: parent.right
        height: 500
        from: 0
        to: 100
        value: 50
        onValueChanged: {
            solarSystem.animator.setSolarSpeed(value);
        }
    }

    //time label
    DateText {
        id: timeLabel
        text: "Actual time"
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
