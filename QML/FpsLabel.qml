import QtQuick 2.0

Item {
    id: root
    property string text: ""

    Text {
        anchors.fill: parent
        color: "white";
        font.pixelSize: 20
        style: Text.Sunken;
        styleColor: "black"
        text: " Fps: " + root.text;
    }
}
