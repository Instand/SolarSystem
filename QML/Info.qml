import QtQuick 2.0

Text {
    id: root

    property alias showInfo: showInfoAnim
    property alias unshowInfo: unshowInfoAnim

    font.family: "Comic Sans MS"
    font.italic: true
    verticalAlignment: Text.AlignVCenter
    font.pixelSize: 15
    font.weight: Font.Light
    lineHeight: 1.4
    lineHeightMode: Text.ProportionalHeight
    color: "white"
    opacity: 0
    wrapMode: Text.Wrap
    style: Text.Sunken;
    styleColor: "black"
    visible: false

    PropertyAnimation {
        id: showInfoAnim
        target: root
        property: "opacity"
        to: 0.85
        duration: 1000
        onStarted: root.visible = true
    }

    PropertyAnimation {
        id: unshowInfoAnim
        target: root
        property: "opacity"
        to: 0
        duration: 1000
        onStopped: root.visible = false
    }
}
