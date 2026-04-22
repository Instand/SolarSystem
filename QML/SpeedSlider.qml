import QtQuick 2.10

// Custom vertical slider: QQC2 Slider on Android can give a very small handle;
// a ~48px-class touch target and full column hit area is easier to use.
Item {
    id: root

    property real from: 0
    property real to: 100
    property real value: 50

    readonly property real _hnd: Math.round(Math.min(52, Math.max(40, 0.58 * width)))
    readonly property real _pad: _hnd * 0.35
    readonly property real _trTop: _pad
    readonly property real _trBot: height - _pad
    readonly property real _ySpan: Math.max(0, _trBot - _trTop - _hnd)

    function v01() {
        if (to === from) {
            return 0.5
        }
        return (value - from) / (to - from)
    }

    function yFromV01(t) {
        if (root._ySpan <= 0) {
            return 0.5 * (height - _hnd)
        }
        return root._trTop + (1.0 - t) * root._ySpan
    }

    function tFromY(y) {
        if (root._ySpan <= 0) {
            return 0.5
        }
        return 1.0 - (y - root._trTop) / root._ySpan
    }

    function setFromY(handleTop) {
        var t = tFromY(handleTop)
        t = Math.max(0, Math.min(1, t))
        var nv = from + t * (to - from)
        var rounded = Math.round(nv)
        if (value !== rounded) {
            value = rounded
        }
    }

    Rectangle {
        id: track
        anchors {
            top: parent.top
            topMargin: root._pad
            bottom: parent.bottom
            bottomMargin: root._pad
            horizontalCenter: parent.horizontalCenter
        }
        width: Math.min(6, 0.08 * root.width) + 6
        radius: width * 0.3
        color: "#1effffff"
        border.color: "#7fffffff"
        border.width: 1
    }

    Rectangle {
        id: handle
        x: (parent.width - width) * 0.5
        y: parent.yFromV01(parent.v01())
        width: root._hnd
        height: root._hnd
        radius: width * 0.5
        color: "#d0d0d0"
        border.color: "#f0f0f0"
        border.width: 1
    }

    MouseArea {
        id: area
        anchors.fill: parent
        preventStealing: true
        onPressed: function (mouse) {
            root.setFromY(mouse.y - 0.5 * root._hnd)
        }
        onPositionChanged: function (mouse) {
            if (pressed) {
                root.setFromY(mouse.y - 0.5 * root._hnd)
            }
        }
    }

}
