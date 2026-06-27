import QtQuick 2.15

Text {
    id: root

    property alias showInfo: showInfoAnim
    property alias unshowInfo: unshowInfoAnim

    font.family: "Comic Sans MS"
    font.italic: true
    verticalAlignment: Text.AlignVCenter
    horizontalAlignment: Text.AlignLeft
    font.pixelSize: 28 * dp
    fontSizeMode: Text.Fit
    minimumPixelSize: 8
    font.weight: Font.Light
    lineHeight: 1.35
    lineHeightMode: Text.ProportionalHeight
    color: "white"
    opacity: 0
    wrapMode: Text.Wrap
    clip: true
    topPadding: 12 * dp
    bottomPadding: 12 * dp
    leftPadding: 12 * dp
    rightPadding: 12 * dp
    style: Text.Sunken
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
