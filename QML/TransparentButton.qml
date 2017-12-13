import QtQuick 2.0
import QtQuick.Controls 2.1

//root element
Rectangle {
    id: root
    border.color: "white"
    color: "transparent"
    antialiasing: true

    //source ref
    property alias source: image.source

    //click signal
    signal clicked;

    //values
    property real lowOpacity: 0.1
    property real maxOpacity: 0.3

    //image on Rectangle surface
    Image {
        id: image
        anchors.verticalCenter: parent.verticalCenter
        anchors.horizontalCenter: parent.horizontalCenter
        width: parent.width/1.7
        height: parent.width/1.7
        smooth: true
        antialiasing: true
    }

    //opacity white rectangle
    Rectangle {
        id: coloredRECT
        anchors.fill: parent
        color: "white"
        opacity: lowOpacity

        //press area
        MouseArea {
            id: area
            anchors.fill: parent
            hoverEnabled: true

            //click event
            onClicked: {
                root.clicked()
            }

            //press event
            onPressed: {
                coloredRECT.opacity = root.lowOpacity
            }

            //release event
            onReleased: {
                if (area.containsMouse)
                    coloredRECT.opacity = root.maxOpacity
            }

            //enter event
            onEntered: {
                coloredRECT.opacity = root.maxOpacity
            }

            //exit event
            onExited: {
                coloredRECT.opacity = root.lowOpacity
            }
        }
    }
}
