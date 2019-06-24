import QtQuick 2.0
import QtQuick.Controls 2.1

Item {
    id: root

    signal fpsButtonClicked(bool state)
    signal dbButtonClicked(bool state)

    // title text
    Text {
        id: title
        anchors.top: root.top
        anchors.topMargin: 10
        width: parent.width
        height: 25
        color: "white"
        font.italic: true
        verticalAlignment: Text.AlignVCenter
        horizontalAlignment: Text.AlignHCenter
        wrapMode: Text.Wrap
        font.pixelSize: 24
        style: Text.Sunken;
        styleColor: "black"
        text: "Options"
    }

    Row {
        id: fpsRow
        anchors.left: root.left
        anchors.top: title.bottom
        anchors.topMargin: 30
        spacing: 15

        // fps title
        Text {
            wrapMode: Text.Wrap
            font.pixelSize: 18
            style: Text.Sunken;
            styleColor: "black"
            color: "white"
            text: "Show FPS: "
            width: 200
            height: fpsRow.height
            verticalAlignment: Text.AlignVCenter
            horizontalAlignment: Text.AlignRight
        }

        // fps button
        Button {
            id: fpsButton
            width: 170
            height: 50
            text: "On"
            font.pixelSize: 22
            property bool state: true

            onClicked: {
                state = !state
                root.fpsButtonClicked(state)
                fpsButton.text = state ? "On" : "Off"
            }
        }
    }

    Row {
        id: dbRow
        anchors.left: root.left
        anchors.top: fpsRow.bottom
        anchors.topMargin: 30
        spacing: 15

        // db title
        Text {
            wrapMode: Text.Wrap
            font.pixelSize: 18
            style: Text.Sunken;
            styleColor: "black"
            color: "white"
            text: "Show Database state: "
            width: 200
            height: dbRow.height
            verticalAlignment: Text.AlignVCenter
            horizontalAlignment: Text.AlignRight
        }

        // db button
        Button {
            id: dbButton
            width: 170
            height: 50
            text: "Off"
            font.pixelSize: 22
            property bool state: false

            onClicked: {
                state = !state
                root.dbButtonClicked(state)
                dbButton.text = state ? "On" : "Off"
            }
        }
    }
}
