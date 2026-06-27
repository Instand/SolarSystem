import QtQuick 2.15
import QtQuick.Window 2.15

import QtQuick.Scene3D 2.0
import QtQuick.Controls 2.1

import SolarSystem.InfoLoader 1.0
import SolarSystem.Utils 1.0

Item {
    id: root

    // version property
    property string version: "4.1.0"

    // planet list show flag
    property bool showPlanetList: false

    // focused planet
    property int currentSelectedObject: 0

    // Android 1dp in physical pixels, converted to QML scene units (device-independent
    // pixels) so High-DPI (devicePixelRatio > 1) does not double-scale the UI.
    readonly property real dp: (Screen.pixelDensity * 25.4 / 160)
        / (Screen.devicePixelRatio > 0 ? Screen.devicePixelRatio : 1.0)

    readonly property real rightPanelWidth: 200 * dp

    // enables camera zoom on mobile devices, because of Qt3D Input does not support it
    // on desktop does nothing
    MultiPointTouchArea {
        anchors.fill: parent

        minimumTouchPoints: 2
        maximumTouchPoints: 2
        mouseEnabled: false
        enabled: true

        touchPoints: [
            TouchPoint { id: point1 },
            TouchPoint { id: point2 }
        ]

        // 3d viewport, handles mouse or one touch events thought MultiPointTouchArea
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

        onPressed: {
            if (!solarSystem.entity.isAnimated()) {
                solarSystem.entity.setCameraControllerEnabled(false)
            }
        }

        onReleased: {
            if (!solarSystem.entity.isAnimated()) {
                solarSystem.entity.setCameraControllerEnabled(true)
            }
        }

        onUpdated: {
            if (!solarSystem.entity.isAnimated()) {
                solarSystem.zoom(point1, point2)
            }
        }
    }

    // shows fps
    FpsLabel {
        id: fpsLabel
        anchors.top: root.top
        anchors.left: root.left
        width: 100 * dp
        height: 50 * dp
        text: solarSystem.counter.fps
    }

    // shows database status
    DatabaseLabel {
        id: databaseLabel
        anchors.top: fpsLabel.bottom
        anchors.left: root.left
        width: 200 * dp
        height: 50 * dp
        visible: false
    }

    // slider frame (wider = easier touch on phones)
    SolarFrame {
        id: speedSliderFrame
        anchors.right: parent.right
        anchors.verticalCenter: parent.verticalCenter
        anchors.rightMargin: 5 * dp
        height: Math.min(850 * dp, parent.height * 0.6)
        width: rightPanelWidth
        radius: 5 * dp

        SpeedSlider {
            id: speedSlider
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
        anchors.topMargin: 5 * dp
        anchors.rightMargin: 5 * dp
        radius: 4 * dp
        height: width
        width: speedSliderFrame.width
        source: "qrc:/Resources/Images/screen_icon.png"
        onClicked: {
            root.grabToImage(function(result) {
                result.saveToFile("SolarSystemScreen.jpg");
            });
        }
    }

    // solar object info (fill space between left toolbar and right slider)
    Info {
        id: infoText
        anchors.verticalCenter: parent.verticalCenter
        anchors.left: controlElements.right
        anchors.leftMargin: 10 * dp
        anchors.right: speedSliderFrame.left
        anchors.rightMargin: 5 * dp
        height: speedSliderFrame.height + 40 * dp
    }

    // extra speed button
    TransparentButton {
        id: extraButton
        anchors.right: parent.right
        anchors.bottom: speedSliderFrame.top
        anchors.rightMargin: 5 * dp
        anchors.bottomMargin: 5 * dp
        radius: 4 * dp
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

    // date label (Column so two lines reserve real height; avoids overlap with planet name)
    Column {
        id: timeFrame
        anchors.top: parent.top
        anchors.horizontalCenter: parent.horizontalCenter
        anchors.topMargin: 5 * dp
        width: Math.min(280 * dp, parent.width * 0.75)
        spacing: 2 * dp

        DateText {
            id: timeLabel
            text: "Actual time"
            width: parent.width
            horizontalAlignment: Text.AlignHCenter
        }

        // show current solar time
        DateText {
            id: solarTime
            width: parent.width
            horizontalAlignment: Text.AlignHCenter

            // show time to label
            function showTime() {
                var solarDate = solarSystem.entity.time;
                var hours = solarDate.getUTCHours();
                var minutes = solarDate.getUTCMinutes();
                var days  = solarDate.getUTCDate();
                var month = solarDate.getUTCMonth() + 1;
                var year = solarDate.getUTCFullYear();

                var str = "";

                if (hours.toString().length === 1) {
                    str += "0"
                }

                str += hours.toString()
                str += ":"

                if (minutes.toString().length === 1) {
                    str += "0"
                }

                str += minutes.toString()
                str += " "

                if (days.toString().length === 1) {
                    str += " "
                }

                str += days.toString()
                str += "/"

                if (month.toString().length === 1) {
                    str += "0"
                }

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
        anchors.leftMargin: 5 * dp
        elementWidth: rightPanelWidth // same as right
        elementHeight: 200 * dp

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
        onOptionButtonClicked: (name) => {
            showDataFrame(name, controlElements.prevName)
        }

        // info
        onInfoButtonClicked: (name) => {
            showDataFrame(name, controlElements.prevName)
        }
    }

    // shows ui with data frame
    function showDataFrame(name, prevName) {
        if (dataFrame.opacity === 0) {
            setEnabledFrames(false)
            checkFrameComponent(name)
            dataFrameShowAnimation.start()
        }
        else if (dataFrame.opacity === 1) {
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
        if (name === "optionsButton") {
            options.visible = true
        }
        else if (name === "infoButton") {
            aboutText.visible = true
        }
    }

    // planets icons
    SolarFrame {
        id: planetsList
        anchors.bottom: parent.bottom
        anchors.left: parent.left
        anchors.right: parent.right
        height: 200 * dp
        anchors.leftMargin: 5 * dp
        anchors.bottomMargin: 10 * dp
        anchors.rightMargin: 5 * dp
        radius: 4 * dp
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
            // height is already in scene units; do not multiply by dp again
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

                if (planetsView.focusedPlanet != 0) {
                    infoText.text = solarSystem.entity.info;
                }
            }
        }
    }

    // exit button
    TransparentButton {
        anchors.top: parent.top
        anchors.right: parent.right
        anchors.rightMargin: 5 * dp
        anchors.topMargin: 5 * dp
        radius: 4 * dp
        source: "qrc:/Resources/Images/exit_icon.png"
        width: rightPanelWidth
        height: 250 * dp
        onClicked: Qt.quit();
    }

    // left frame with data
    SolarFrame {
        id: dataFrame
        anchors.verticalCenter: parent.verticalCenter
        anchors.left: controlElements.right
        anchors.leftMargin: 10 * dp
        width: controlElements.height
        height: controlElements.height
        radius: 4 * dp
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
            anchors.topMargin: 15 * dp
            color: "white"
            font.italic: true
            verticalAlignment: Text.AlignVCenter
            horizontalAlignment: Text.AlignHCenter
            lineHeight: 1.45
            lineHeightMode: Text.ProportionalHeight
            wrapMode: Text.Wrap
            font.pixelSize: 30 * dp
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

            onDbButtonClicked: (state) => {
                databaseLabel.visible = state
            }

            onFpsButtonClicked: (state) => {
                fpsLabel.visible = state
            }
        }
    }

    Text {
        id: planetText
        anchors.top: timeFrame.bottom
        anchors.topMargin: 16 * dp
        anchors.horizontalCenter: parent.horizontalCenter
        width: Math.min(340 * dp, parent.width - 20 * dp)
        height: contentHeight
        font.pixelSize: 40 * dp
        font.wordSpacing: 1
        font.bold: true
        font.italic: true
        verticalAlignment: Text.AlignVCenter
        horizontalAlignment: Text.AlignHCenter
        wrapMode: Text.Wrap
        color: "white"
        text: solarSystem.entity.currentObjectString
        font.family: "Century Gothic"
        style: Text.Sunken;
        styleColor: "black"
    }
}
