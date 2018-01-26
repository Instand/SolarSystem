import QtQuick 2.0

Column {
    id: root
    spacing: 3

    //size of every element
    property int elementWidth: 10
    property int elementHeight: 20

    //signals
    signal planetButtonClicked(string name)
    signal infoButtonClicked(string name)
    signal calendarButtonClicked(string name)
    signal optionButtonClicked(string name)

    //planet list button
    TransparentButton {
        id: planetButton
        width: root.elementWidth
        height: root.elementHeight
        radius: 4
        source: "qrc:/Resources/Images/planet_icon.png"
        objectName: "planetButton"

        onClicked: root.planetButtonClicked(planetButton.objectName)
    }

    //calendar button
    TransparentButton {
        id: calendarButton
        width: root.elementWidth
        height: root.elementHeight
        radius: 4
        source: "qrc:/Resources/Images/calendar_icon.png"
        objectName: "calendarButton"

        onClicked: root.calendarButtonClicked(calendarButton.objectName)
    }

    //options button
    TransparentButton {
        id: optionsButton
        width: root.elementWidth
        height: root.elementHeight
        radius: 4
        source: "qrc:/Resources/Images/options_icon.png"
        objectName: "optionsButton"

        onClicked: root.optionButtonClicked(optionsButton.objectName)
    }

    //info button
    TransparentButton {
        id: infoButton
        width: root.elementWidth
        height: root.elementHeight
        radius: 4
        source: "qrc:/Resources/Images/info_icon.png"
        objectName: "infoButton"

        onClicked: root.infoButtonClicked(infoButton.objectName)
    }
}
