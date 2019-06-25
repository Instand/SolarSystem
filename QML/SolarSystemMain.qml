import QtQuick 2.0
import QtQuick.Scene3D 2.0
import QtQuick.Controls 2.1
import SolarSystem.InfoLoader 1.0

Item {
    id: root

    // version property
    property string version: "3.8"

    // planet list show flag
    property bool showPlanetList: false

    // focused planet
    property int currentSelectedObject: 0

    // 3d viewport
    Scene3D {
        id: scene
        anchors.fill: parent
        aspects: ["render", "logic", "input"]
        focus: true
        cameraAspectRatioMode: Scene3D.AutomaticAspectRatio

        // from c++ code
        SolarEntityMain {
            id: solarSystem
            Component.onCompleted: {
                solarSystem.entity.setEventSource(root)
                databaseLabel.text = solarSystem.dbState()
            }
        }
    }

    // shows fps
    FpsLabel {
        id: fpsLabel
        anchors.top: root.top
        anchors.left: root.left
        width: 100
        height: 50
        text: solarSystem.counter.fps
    }

    // shows database status
    DatabaseLabel {
        id: databaseLabel
        anchors.top: fpsLabel.bottom
        anchors.left: root.left
        width: 200
        height: 50
        visible: false
    }

    // slider frame
    SolarFrame {
        id: speedSliderFrame
        anchors.right: parent.right
        anchors.verticalCenter: parent.verticalCenter
        anchors.rightMargin: 5
        height: 400
        width: 65
        radius: 4

        SpeedSlider {
            id: speedSlider
            orientation: Qt.Vertical
            anchors.fill: parent
            onValueChanged: {
                solarSystem.entity.setSolarSpeed(value);
            }
        }
    }

    // take a solar screenshot
    TransparentButton {
        id: screenButton
        anchors.right: parent.right
        anchors.top: speedSliderFrame.bottom
        anchors.topMargin: 5
        anchors.rightMargin: 5
        radius: 4
        height: width
        width: speedSliderFrame.width
        source: "qrc:/Resources/Images/screen_icon.png"
        onClicked: {
            root.grabToImage(function(result) {
                result.saveToFile("SolarSystemScreen.png");
            });
        }
    }

    // solar object info
    Info {
        id: infoText
        anchors.verticalCenter: parent.verticalCenter
        anchors.right: speedSliderFrame.left
        anchors.rightMargin: 5
        width: 600
        height: speedSliderFrame.height + 100
    }

    // extra speed button
    TransparentButton {
        id: extraButton
        anchors.right: parent.right
        anchors.bottom: speedSliderFrame.top
        anchors.rightMargin: 5
        anchors.bottomMargin: 5
        radius: 4
        height: width
        width: speedSliderFrame.width

        Text {
            id: extraText
            color: "#ffffff"
            anchors.fill: parent
            font.family: "Comic Sans MS"
            font.bold: true
            font.italic: true
            font.pointSize: 12
            styleColor: "black"
            style: Text.Sunken;
            verticalAlignment: Text.AlignVCenter
            horizontalAlignment: Text.AlignHCenter
            text: qsTr("x") + solarSystem.entity.extraSpeed.toString()
        }

        onClicked: solarSystem.entity.changeExtraSpeed()
    }

    // date label
    Item {
        id: timeFrame
        anchors.top: parent.top
        anchors.horizontalCenter: parent.horizontalCenter
        anchors.topMargin: 5
        width: 200
        height: 50

        DateText {
            id: timeLabel
            text: "Actual time"
            anchors.top: parent.top
            anchors.horizontalCenter: parent.horizontalCenter
        }

        // show current solar time
        DateText {
            id: solarTime
            anchors.top: timeLabel.bottom

            // show time to label
            function showTime() {
                var solarDate = solarSystem.entity.time;
                var hours = solarDate.getUTCHours();
                var minutes = solarDate.getUTCMinutes();
                var days  = solarDate.getUTCDate();
                var month = solarDate.getUTCMonth() + 1;
                var year = solarDate.getUTCFullYear();

                var str = "";

                if (hours.toString().length === 1)
                    str += "0"

                str += hours.toString()
                str += ":"

                if (minutes.toString().length === 1)
                    str += "0"

                str += minutes.toString()
                str += " "

                if (days.toString().length === 1)
                    str += " "

                str += days.toString()
                str += "/"

                if (month.toString().length === 1)
                    str += "0"

                str += month.toString()
                str += "/"
                str += year.toString()

                return str
            }

            text: showTime()
        }
    }

    // left side controls
    Controls {
        id: controlElements
        anchors.verticalCenter: parent.verticalCenter
        anchors.left: parent.left
        anchors.leftMargin: 5
        elementWidth: 100
        elementHeight: 120

        // store prev button object name
        property string prevName: ""

        // planets
        onPlanetButtonClicked: {
            showPlanetList = !showPlanetList;

            if (showPlanetList) {
                showAnimation.start();
                planetsView.visible = true;
            }
            else {
                unshowAnimation.start()
            }
        }

        // options
        onOptionButtonClicked: {
            showDataFrame(name, controlElements.prevName)
        }

        // info
        onInfoButtonClicked: {
            showDataFrame(name, controlElements.prevName)
        }
    }

    // shows ui with data frame
    function showDataFrame(name, prevName) {
        if (dataFrame.opacity == 0) {
            setEnabledFrames(false)
            checkFrameComponent(name)
            dataFrameShowAnimation.start()
        }
        else if (dataFrame.opacity == 1) {
            if (prevName === name) {
                dataFrameUnShowAnimation.start()
            }
            else {
                setEnabledFrames(false)
                checkFrameComponent(name)
            }
        }

        controlElements.prevName = name
    }

    // sets visible state for all frames
    function setEnabledFrames(state) {
        aboutText.visible = state
        options.visible = state
    }

    // checks which frame component should be visible
    function checkFrameComponent(name) {
        if (name === "optionsButton")
            options.visible = true
        else if (name === "infoButton")
            aboutText.visible = true
    }

    // planets icons
    SolarFrame {
        id: planetsList
        anchors.bottom: parent.bottom
        anchors.left: parent.left
        anchors.right: parent.right
        height: 110
        anchors.leftMargin: 5
        anchors.bottomMargin: 10
        anchors.rightMargin: 5
        radius: 4
        opacity: 0

        PropertyAnimation {
            id: showAnimation
            target: planetsList
            property: "opacity"
            to: 1
            duration: 500
        }

        PropertyAnimation {
            id: unshowAnimation
            target: planetsList
            property: "opacity"
            to: 0
            duration: 500
            onStopped: planetsView.visible = false
        }

        PlanetList {
            id: planetsView
            anchors.fill: parent
            buttonSize: height - 5
            visible: false
            onClicked:  {
                if (planetsView.focusedPlanet == 0) {
                    extraButton.visible = true
                    infoText.unshowInfo.start()
                }
                else {
                    extraButton.visible = false;
                    infoText.showInfo.start()
                }

                solarSystem.entity.resetExtraSpeed();
                solarSystem.entity.setViewCenter(planetsView.focusedPlanet);

                if (planetsView.focusedPlanet != 0)
                    infoText.text = solarSystem.entity.info;
            }
        }
    }

    // exit button
    TransparentButton {
        anchors.top: parent.top
        anchors.right: parent.right
        anchors.rightMargin: 5
        anchors.topMargin: 5
        radius: 4
        source: "qrc:/Resources/Images/exit_icon.png"
        width: 60
        height: 80
        onClicked: Qt.quit();
    }

    // left frame with data
    SolarFrame {
        id: dataFrame
        anchors.verticalCenter: parent.verticalCenter
        anchors.left: controlElements.right
        anchors.leftMargin: 10
        width: controlElements.height
        height: controlElements.height
        radius: 4
        opacity: 0

        PropertyAnimation {
            id: dataFrameShowAnimation
            target: dataFrame
            property: "opacity"
            to: 1
            duration: 500
        }

        PropertyAnimation {
            id: dataFrameUnShowAnimation
            target: dataFrame
            property: "opacity"
            to: 0
            duration: 500
            onStopped: setEnabledFrames(false)
        }

        // info text
        Text {
            id: aboutText
            width: dataFrame.width
            height: dataFrame.height
            anchors.fill: parent
            anchors.topMargin: 15
            color: "white"
            font.italic: true
            verticalAlignment: Text.AlignVCenter
            horizontalAlignment: Text.AlignHCenter
            lineHeight: 1.625 * 14
            lineHeightMode: Text.FixedHeight
            wrapMode: Text.Wrap
            font.pixelSize: 22
            style: Text.Sunken;
            styleColor: "black"
            text: InfoLoader.loadInfo(version)
            visible: false
        }

        // options
        UserOptions {
            id: options
            anchors.fill: dataFrame
            width: dataFrame.width
            height: dataFrame.height
            visible: false

            onDbButtonClicked: databaseLabel.visible = state
            onFpsButtonClicked: fpsLabel.visible = state
        }
    }

    // object text
    Text {
        id: planetText
        anchors.top: timeFrame.bottom
        anchors.topMargin: 10
        anchors.horizontalCenter: parent.horizontalCenter
        width: 200
        height: 60
        font.pointSize: 30
        font.wordSpacing: 2
        font.bold: true
        font.italic: true
        verticalAlignment: Text.AlignVCenter
        horizontalAlignment: Text.AlignHCenter
        color: "white"
        text: solarSystem.entity.currentObjectString
        font.family: "Century Gothic"
        style: Text.Sunken;
        styleColor: "black"
    }
}
