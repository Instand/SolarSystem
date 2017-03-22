import QtQuick 2.0

//planet item
Item {
    id: root

    //base property
    property int buttonSize: 70
    property int fontSize: 14
    property int focusedPlanet: 0

    signal clicked;

    //planet view model
    ListModel {
        id: planetModel

        //solar System
        ListElement {
            name: "Solar System"
            planetImageSource: "qrc:/Resources/Images/solarsystem.png"
            planetNumber: 0
        }

        //sun
        ListElement {
            name: "Sun"
            planetImageSource: "qrc:/Resources/Images/sun.png"
            planetNumber: 1
        }

        //mercury
        ListElement {
            name: "Mercury"
            planetImageSource: "qrc:/Resources/Images/mercury.png"
            planetNumber: 2
        }

        //venus
        ListElement {
            name: "Venus"
            planetImageSource: "qrc:/Resources/Images/venus.png"
            planetNumber: 3
        }

        //earth
        ListElement {
            name: "Earth"
            planetImageSource: "qrc:/Resources/Images/earth.png"
            planetNumber: 4
        }

        //mars
        ListElement {
            name: "Mars"
            planetImageSource: "qrc:/Resources/Images/mars.png"
            planetNumber: 5
        }

        //jupiter
        ListElement {
            name: "Jupiter"
            planetImageSource: "qrc:/Resources/Images/jupiter.png"
            planetNumber: 6
        }

        //saturn
        ListElement {
            name: "Saturn"
            planetImageSource: "qrc:/Resources/Images/saturn.png"
            planetNumber: 7
        }

        //uranus
        ListElement {
            name: "Uranus"
            planetImageSource: "qrc:/Resources/Images/uranus.png"
            planetNumber: 8
        }

        //neptune
        ListElement {
            name: "Neptune"
            planetImageSource: "qrc:/Resources/Images/neptune.png"
            planetNumber: 9
        }

        //pluto
        ListElement {
            name: "Pluto"
            planetImageSource: "qrc:/Resources/Images/pluto.png"
            planetNumber: 10
        }
    }

    //model delegate
    Component {
        id: modelDelegate

        //use button
        PlanetButton {
            source: planetImageSource
            text: name
            planetSelector: root
            buttonSize: root.buttonSize
            fontSize: root.fontSize
            focusPlanet: planetNumber

            onClicked: root.clicked()
        }
    }

    //view element
    ListView {
        id: planetButtonView
        anchors.fill: parent
        spacing: 10
        width: root.parent.width
        interactive: false
        model: planetModel
        delegate: modelDelegate
        orientation: Qt.Horizontal
    }

}
