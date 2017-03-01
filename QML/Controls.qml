import QtQuick 2.0

Column {
    id: root
    spacing: 3

    //size of every element
    property int elementWidth: 10
    property int elementHeght: 20

    //planet list button
    TransparentButton {
        id: planetButton
        width: root.elementWidth
        height: root.elementHeght
        radius: 4
        source: "qrc:/Resources/Images/planet_icon.png"
        toolTipText: qsTr("Planets list")
        toolTipWidth: 120
        toolTipHeight: 30
        toolTipVisibility: true
    }

    //calendar button
    TransparentButton {
        id: calendarButton
        width: root.elementWidth
        height: root.elementHeght
        radius: 4
        source: "qrc:/Resources/Images/calendar_icon.png"
        toolTipText: qsTr("Calendar")
        toolTipWidth: 120
        toolTipHeight: 30
        toolTipVisibility: true
    }

    //options button
    TransparentButton {
        id: optionsButton
        width: root.elementWidth
        height: root.elementHeght
        radius: 4
        source: "qrc:/Resources/Images/options_icon.png"
        toolTipText: qsTr("Options")
        toolTipWidth: 120
        toolTipHeight: 30
        toolTipVisibility: true
    }

    //options button
    TransparentButton {
        id: infoButton
        width: root.elementWidth
        height: root.elementHeght
        radius: 4
        source: "qrc:/Resources/Images/info_icon.png"
        toolTipText: qsTr("Info")
        toolTipWidth: 120
        toolTipHeight: 30
        toolTipVisibility: true
    }
}
