import QtQuick 2.0

Rectangle {
    id: planetButton

    property alias text: planetText.text
    property alias source: planetImage.source
    property alias focusPlanet: planetImage.focusPlanet
    property Item planetSelector: parent.parent
    property int buttonSize: 70 * dp
    property int fontSize: 16

    signal clicked;

    width: buttonSize
    height: buttonSize
    color: "transparent"

    Image {
        id: planetImage
        anchors.fill: parent
        property int focusPlanet

        MouseArea {
            anchors.fill: parent
            hoverEnabled: true

            onClicked: {
                planetSelector.focusedPlanet = focusPlanet;
                planetButton.clicked();
            }

            onEntered: showTextAnim.start()
            onExited: hideTextAnim.start()
        }
    }

    PropertyAnimation {
        id: showTextAnim
        target: planetText
        property: "opacity"
        to: 1
    }

    PropertyAnimation {
        id: hideTextAnim
        target: planetText
        property: "opacity"
        to: 0
    }

    Text {
        id: planetText
        anchors.centerIn: parent
        font.family: "Helvetica"
        font.pixelSize: fontSize
        font.weight: Font.Light
        color: "white"
        opacity: 0
    }
}
