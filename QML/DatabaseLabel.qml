import QtQuick 2.0

Item {
    id: root
    property string text: ""

    Text {
        anchors.fill: parent
        color: "white"
        font.pixelSize: 30 * dp
        style: Text.Sunken
        styleColor: "black"
        text: " Database status: " + root.text
    }
}
